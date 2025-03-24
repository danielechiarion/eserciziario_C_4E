/* Scrivere un programma concorrente che realizzi il seguente comando:

cat costituzione.txt | more */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    /* controllo se il numero di argomenti è valido */
    if (argc != 2)
    {
        printf("Numero di argomenti non valido\n");
    }

    /* dichiarazione variabili e vettori */
    int p1, p2;
    int p1p2[2];

    pipe(p1p2);

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
        close(1);
        exit(0);
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

        execl("/usr/bin/more", "more", NULL);
        close(1);
        exit(0);
    }

    /* chiudo i file descriptor della pipe */
    close(p1p2[0]);
    close(p1p2[1]);

    while (wait(NULL) > 0)
        ;

    return 0;
}