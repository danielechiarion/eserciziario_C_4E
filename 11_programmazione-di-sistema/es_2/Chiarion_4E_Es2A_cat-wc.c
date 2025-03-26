/* Scrivere un programma concorrente che realizzi il seguente comando:

cat file.txt | wc

il processo p2 deve rimandare l'output di wc al padre, il quale lo scriverà
su un file chiamato wc.txt

il nome del file "file.txt" deve essere passato come argomento in argv[1] */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    /* controllo se il numero di argomenti è valido */
    if (argc != 3)
    {
        printf("Numero di argomenti non valido\n");
    }

    /* dichiarazione variabili e vettori */
    int p1, p2;
    int p1p2[2], p2p0[2];

    pipe(p1p2);
    pipe(p2p0);

    /* creo un primo processo che mi faccia il comando cat */
    p1 = fork();
    if (p1 == 0)
    {
        /* redireziono lo standard output,
        duplicando il fd della pipe */
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);
        close(p1p2[0]); // chiudo il fd della lettura

        execl("/usr/bin/cat", "cat", argv[1], NULL);
        return -1; // exec si prende il controllo del processo. L'unica cosa che possiamo fare è ritornare -1 una volta terminato
    }

    /* creo un secondo processo per il comando more */
    p2 = fork();
    if (p2 == 0)
    {
        /* redireziono lo standard input,
        duplicando il fd della pipe */
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);
        close(p1p2[1]); // chiudo il fd della scrittura

        /* redireziono lo standard output
        mettendo il file descriptor della pipe */
        close(p2p0[0]);
        close(1);
        dup(p2p0[1]);
        close(p2p0[1]);

        execl("/usr/bin/wc", "wc", NULL);
        return -1;
    }

    /* chiudo i file descriptor della pipe */
    close(p1p2[0]);
    close(p1p2[1]);
    close(p2p0[1]);

    /* leggo il l'output di p2 e lo scrivo su file */
    int fdFile = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    char buf;
    while (read(p2p0[0], &buf, sizeof(buf)) > 0)
    {
        write(fdFile, &buf, sizeof(buf));
    }
    close(fdFile);
    close(p2p0[0]); // chiudo il file descriptor dell'input

    wait(&p1); // aspetto che il processo p1 termini

    return 0;
}