/* Si vuole realizzare un software concorrente in linguaggio C che legga un file di testo da argv[1] e conteggi il numero di vocali presenti nel file.
Una volta effettuato il conteggio il programma principale deve mostrarlo a video.

Note operative:
P0 genera P1 il quale legge il contenuto del file usando il comando cat.
P2 legge da pipe il flusso di caratteri e per ogni carattere verifica se è una vocale, in caso positivo aggiorna il conteggio.
P2 invia a P0 il totale
P0 stampa a video il totale.

Esempio:
$ ./a.out file.txt
Nel file sono presenti 10 vocali. */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/* funzione che redireziona lo standard input
al file descriptor della pipe */
void pipe_stdIn(int pipe[])
{
    close(pipe[1]);
    close(0);
    dup(pipe[0]);
    close(pipe[0]);
}

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
    /* verifico il numero di argomenti */
    if (argc != 2)
    {
        printf("Numero di argomenti inseriti errato\n");
        exit(0);
    }

    /* dichiarazione variabili */
    int pid;
    int contaVocali;
    char contaStringa[10];

    /* creazione pipe */
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
        pipe_stdIn(p1p2);
        pipe_stdOut(p2p0);

        /* dichiarazione e inizializzazione variabili */
        contaVocali = 0;
        char input;

        /* leggo finchè ci sono caratteri disponibili */
        while (scanf("%c", &input) > 0)
        {
            if (input == 'a' || input == 'e' || input == 'i' || input == 'o' || input == 'u')
            {
                contaVocali++;
            }
        }

        printf("%d", contaVocali);
        exit(0);
    }

    close_pipe(p1p2);

    /* leggo l'input del processo P2 e lo stampo a video */
    pipe_stdIn(p2p0);
    scanf("%d", &contaVocali);
    printf("\nIn %s sono presenti %d vocali\n", argv[1], contaVocali);

    wait(NULL);
    return 0;
}