/* Scrivere un programma in linguaggio C che usa il comando
della shell cp per copiare un file da una posizione
sorgente ad una posizione destinazione

esempio:
$ ./a.out costituzione.txt /tmp/costituzione.txt */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    /* controllo che il numero di
    argomenti sia valido */
    if (argc != 3)
    {
        printf("Numero di argomenti non valido\n");
        exit(0);
    }

    execl("/usr/bin/cp", "cp", argv[1], argv[2], NULL);

    return 0;
}