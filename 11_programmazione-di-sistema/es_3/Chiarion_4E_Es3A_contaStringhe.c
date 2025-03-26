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

int main(int argc, char *argv[]){
    /* controllo se il numero di argomenti è valido */
    if(argc != 2){
        printf("Numero di argomenti non valido\n");
        exit(0);
    }

    /* dichiarazione variabili e vettori */
    int occorrenzaStringa, occorrenzeTotali = 0;
    char stringaInput[50], inputOccorrenza[50];
    int pid;

    /* creazione della pipe per 
    la comunicazione tra processi figli */
    int p1p2[2];
    int p2p0[2];
    pipe(p1p2);
    pipe(p2p0);

    printf("Cerca Stringhe %s", argv[1]);
    do{
        /* inserisco la stringa */
        printf("\n\nInserisci la stringa da ricercare: ");
        scanf("%s", stringaInput);

        pid = fork();
        if(pid==0){
            /* redireziono lo standard input */
            close(p1p2[1]);
            close(0);
            dup(p1p2[0]);
            close(p1p2[0]);

            /* redireziono lo standard output */
            close(p2p0[0]);
            close(1);
            dup(p2p0[1]);
            close(p2p0[1]);

            execl("/usr/bin/wc", "wc", "-l", NULL);
            return -1;
        }

        close(p2p0[1]);
        close(p1p2[1]);
        close(p1p2[0]);

        /* leggo dalla pipe con p2 l'occorrenza della stringa 
        e aggiorno le variabili */
        read(p2p0[0], inputOccorrenza, strlen(inputOccorrenza));
        close(p2p0[0]);
        occorrenzaStringa = atoi(inputOccorrenza);
        occorrenzeTotali += occorrenzaStringa;
        printf("\nLa stringa %s e' presente nel file %d volte", stringaInput, occorrenzaStringa);

    }while(strcmp(stringaInput, "fine"));

    /* riporto il risultato finale */
    printf("\nIl numero totale di stringhe trovate e': %d", occorrenzeTotali);

    return 0;
}