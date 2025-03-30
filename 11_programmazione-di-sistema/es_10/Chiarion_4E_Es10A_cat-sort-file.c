/* Realizzare il comando cat file.txt | sort in linguaggio C utilizzando
le pipe e la programmazione concorrente

Osservazione:
P0 generi P1 e successivamente generi P2 */

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
    /* controllo il numero di argomenti */
    if (argc != 2)
    {
        printf("Numero di argomenti errato\n");
        exit(0);
    }

    /* dichiarazione variabili */
    int pid;

    /* creazione pipe */
    int p1p2[2];
    pipe(p1p2);

    pid = fork();

    if (pid == 0)
    {
        pipe_stdOut(p1p2);

        execl("/usr/bin/cat", "cat", argv[1], NULL);
        return -1;
    }

    pid = fork();

    if (pid == 0)
    {
        pipe_stdIn(p1p2);

        execl("/usr/bin/sort", "sort", NULL);
        return -1;
    }

    close_pipe(p1p2);

    return 0;
}