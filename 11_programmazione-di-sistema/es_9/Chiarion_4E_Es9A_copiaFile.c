/* Si vuole realizzare un software concorrente in linguaggio C che si occupi di
copiare un file da un path ad un altro path utilizzando la seguente invocazione:

$ ./cp file.txt copy.txt

Il software deve essere cosi organizzato:
P0 genera il processo p1 che legge il file.txt e invia il suo
contenuto al processo P2
P0 genera P2 che riceve il contenuto del file.txt e lo scrive nel file copy.txt

Osservazione:
1) Il programmatore decida autonomamente la modalità di lettura del file.txt
scegliendo la system call più idonea.
2) Si usi argv

esempio di utilizzo:
$ ./cp file.txt copy.txt

$ cat file.txt
AB123 pagato 20,00
AB123 insoluto 120,00
AC123 insoluto 120,00
AC123 insoluto 100,00

$ cat copy.txt
AB123 pagato 20,00
AB123 insoluto 120,00
AC123 insoluto 120,00
AC123 insoluto 100,00 */

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
    if (argc != 3)
    {
        printf("Numero di argomenti non valido\n");
        exit(0);
    }

    /* dichiarazione variabili */
    int pid, fdFile;

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

        execl("/usr/bin/tee", "tee", argv[2], NULL);
        return -1;
    }

    close_pipe(p1p2);

    return 0;
}