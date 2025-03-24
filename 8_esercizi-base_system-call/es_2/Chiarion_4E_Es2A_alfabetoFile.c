/* Scrivere un programma in linguaggio C che scriva l'alfabeto su un file
il cui nome deve essere letto da argv[1] */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti non valido");
        exit(0);
    }

    const char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    /* apro il file e lo creo se non esiste */
    int fd = open(argv[1], O_WRONLY | O_CREAT, 0777); // puoi mettere anche il contrario e prova a vedere se va

    /* scrivo carattere per carattere */
    write(fd, alfabeto, strlen(alfabeto));
    write(fd, "\n", strlen("\n"));
    close(fd);

    /* chiudo il file */
    return 0;
}
