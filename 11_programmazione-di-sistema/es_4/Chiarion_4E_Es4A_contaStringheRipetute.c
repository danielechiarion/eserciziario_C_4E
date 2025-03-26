/* Si scriva un’applicazione concorrente che presenti la seguente interfaccia:

cercaStringhe FileIn.txt

dove FileIn.txt è un nome assoluto di file.

L’applicazione deve contare il numero di volte in cui un insieme di stringhe
che l’utente inserisce da terminale (una alla volta) compaiono all’interno
del file passato come parametro in argv[1].
L’applicazione termina quando l’utente inserisce la stringa “fine”.

L’applicazione deve visualizzare il numero di volte in cui ogni stringa
compare nel file e anche, al termine dell’esecuzione, il numero totale di
stringhe trovate nel file.

L'applicazione dovrà tenere conto dell'eventuale molteplicità di una parola
dentro alla stessa stringa, per fare questo si consiglia di invocare grep
con il flag -ow e redirezionare il suo output in wc (invocato con il flag -l).*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    /* controllo se il numero di argomenti è valido */
    if (argc != 2)
    {
        printf("Numero di argomenti non valido\n");
        exit(0);
    }

    /* dichiarazione variabili e vettori */
    int occorrenzaStringa, occorrenzeTotali = 0;
    char stringaInput[50], inputOccorrenza[1000];
    int pid;

    /* creazione della pipe per
    la comunicazione tra processi figli */
    int p1p2[2];
    int p2p0[2];

    printf("Cerca stringhe %s", argv[1]);
    while (1)
    {
        printf("\n\nInserisci la parola da ricercare: ");
        scanf("%s", stringaInput);
        /* interrompo se trovo la parola fine*/
        if (strcmp(stringaInput, "fine") == 0)
        {
            close(p1p2[0]);
            close(p1p2[1]);
            close(p2p0[0]);
            close(p2p0[1]);
            printf("\nSono state trovate %d occorrenze\n", occorrenzeTotali);
            break;
        }

        pipe(p1p2);

        /* apro un processo figlio e
        conto il numero di occorrenze */
        pid = fork();
        if (pid == 0)
        {
            /* redireziono lo standard output
            al fd della pipe */
            close(p1p2[0]);
            close(1);
            dup(p1p2[1]);
            close(p1p2[1]);

            execl("/usr/bin/grep", "grep", "-ow", stringaInput, argv[1], NULL);
            return -1;
        }

        pipe(p2p0);
        /* nuovo processo per il wc */
        pid = fork();
        if (pid == 0)
        {
            /* redireziono lo standard output
            al fd della pipe verso P0 */
            close(p2p0[0]);
            close(1);
            dup(p2p0[1]);
            close(p2p0[1]);

            /* reindirzzamento dello standard input
            al fd della pipe da P1 */
            close(p1p2[1]);
            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            execl("/usr/bin/wc", "wc", "-l", (char *)0);
            return -1;
        }

        /* chiudo i file descriptor non utilizzati
        e leggo il numero di occorrenze trovate */
        close(p1p2[0]);
        close(p1p2[1]);
        close(p2p0[1]);
        read(p2p0[0], inputOccorrenza, sizeof(inputOccorrenza));
        close(p2p0[0]);
        occorrenzaStringa = atoi(inputOccorrenza);
        occorrenzeTotali += occorrenzaStringa;
        printf("\nLa stringa %s compare %d volte nel file", stringaInput, occorrenzaStringa);
    }

    return 0;
}