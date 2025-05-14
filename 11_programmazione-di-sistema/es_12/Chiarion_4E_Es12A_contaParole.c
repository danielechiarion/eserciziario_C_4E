/* Si vuole realizzare un software concorrente in linguaggio C che legga un file di testo da argv[1] e conteggi il numero di parole presenti nel file.
Una volta effettuato il conteggio il programma principale deve mostrarlo a video.

Note operative:
P0 genera P1 il quale legge il contenuto del file usando il comando cat.
P2 legge da pipe il flusso di caratteri e capisce quando finisce una parola e ne inizia un'altra, in modo da poter aggiornare il contatore.
P2 invia a P0 il totale
P0 stampa a video il totale.

Esempio:
$ ./a.out file.txt
Nel file sono presenti 10 parole */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/* funzione che redireziona lo standard output
al file descriptor della pipe */
void pipe_stdOut(int pipe[])
{
    close(pipe[0]);
    close(1);
    dup(pipe[1]);
    close(pipe[1]);
}

/* funzione che chiude tutti i file descriptor
della pipe */
void close_pipe(int pipe[])
{
    close(pipe[0]);
    close(pipe[1]);
}

int main(int argc, char *argv[])
{
    /* controllo il numero di argomenti */
    if (argc != 2)
    {
        printf("Numero di argomenti non valido\n");
        exit(0);
    }

    /* dichiarazione variabili */
    int pid;
    char strParole[20];

    /* dichiaro le pipe */
    int p1p2[2], p2p0[2];
    pipe(p1p2);

    pid = fork();
    if (pid == 0)
    {
        pipe_stdOut(p1p2);

        execl("/usr/bin/cat", "cat", argv[1], NULL);
        return -1;
    }

    pipe(p2p0);
    pid = fork();
    if (pid == 0)
    {
        /* dichiaro le variabili per
        il conteggio delle parole */
        char buf;
        int cont = 0, checkCarattere = 0;

        close(p1p2[1]);
        close(p2p0[0]);

        while (read(p1p2[0], &buf, sizeof(buf)) > 0)
        {
            /* la variabile checkCarattere serve ad evitare che
            vengano conteggiate più parole in presenza di spazi doppi */
            if (buf == ' ' && checkCarattere)
            {
                checkCarattere = 0;
                cont++;
            }
            else if (buf != ' ')
            {
                checkCarattere = 1;
            }
        }
        close(p1p2[0]);

        sprintf(strParole, "%d", cont);
        write(p2p0[1], strParole, sizeof(strParole));
        close(p2p0[1]);
        

        exit(0);
    }

    close_pipe(p1p2);
    close(p2p0[1]);

    read(p2p0[0], strParole, sizeof(strParole));
    close(p2p0[0]);

    printf("Nel file sono presenti %s parole\n", strParole);

    wait(&pid); // attendo il processo P2
    return 0;
}