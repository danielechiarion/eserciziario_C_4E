/* Si scriva un’applicazione concorrente che presenti la seguente interfaccia:

cercaStringhe FileIn

dove FileIn è un nome assoluto di file.

L’applicazione deve contare il numero di volte in cui un insieme di stringhe
che l’utente inserisce da terminale (una alla volta) compaiono all’interno
del file passato come parametro in argv[1].
Se in una riga del file una parola compare più volte, al fine del conteggio,
considerare solamente la prima occorrenza.
L’applicazione termina quando l’utente inserisce la stringa “fine”.
L’applicazione deve visualizzare il numero di volte in cui ogni stringa
compare nel file e anche, al termine dell’esecuzione, il numero totale di
stringhe trovate nel file. */

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
    int p1p0[2];
    pipe(p1p0);

    printf("Cerca stringhe %s", argv[1]);
    while (1)
    {
        printf("\n\nInserisci la parola da ricercare: ");
        scanf("%s", stringaInput);
        /* interrompo se trovo la parola fine*/
        if (strcmp(stringaInput, "fine") == 0)
        {
            close(p1p0[0]);
            close(p1p0[1]);
            printf("\nSono state trovate %d occorrenze\n", occorrenzeTotali);
            break;
        }

        /* apro un processo figlio e
        conto il numero di occorrenze */
        pid = fork();
        if (pid == 0)
        {
            /* redireziono lo standard output
            al fd della pipe */
            close(p1p0[0]);
            close(1);
            dup(p1p0[1]);
            close(p1p0[1]);

            execl("/usr/bin/grep", "grep", "-c", stringaInput, argv[1], (char *)0);
            return -1;
        }

        /* chiudo i file descriptor non utilizzati
        e leggo il numero di occorrenze trovate */
        read(p1p0[0], inputOccorrenza, sizeof(inputOccorrenza));
        occorrenzaStringa = atoi(inputOccorrenza);
        occorrenzeTotali += occorrenzaStringa;
        printf("\nLa stringa %s compare %d volte nel file", stringaInput, occorrenzaStringa);
    }

    return 0;
}