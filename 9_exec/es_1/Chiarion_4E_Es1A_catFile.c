/* Scrivere un programma in linguaggio C che usa il comando
della shell cat per mostrare a video un file di testo
presente in argv[1]

esempio:
$ ./a.out costituzione.txt */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    /* controllo che il numero di argomenti
    sia valido*/
    if (argc != 2)
    {
        printf("Numero di argomenti non valido\n");
        exit(0);
    }

    execl("/usr/bin/cat", "cat", argv[1], NULL);

    return 0;
}