/* Scrivere un programma in linguaggio C che legge da argv una serie di stringhe,
le ordina usando un algoritmo di ordinamento a scelta e scrive il risultato
sia a video che su un file il cui nome risiede in argv[1].

Esempio:

$ ./a.out file.txt ciao a tutti
a
ciao
tutti

$ cat file.txt
a
ciao
tutti */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

/* funzione che scambia le stringhe */
void scambio(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

/* funzione che ordina le stringhe utilizzando
il selection sort*/
void ordinaStringhe(char *argv[], int size)
{
    for (int i = 2; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(argv[i], argv[j]) > 0)
            {
                scambio(&argv[i], &argv[j]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Numero di argomenti non valido");
        exit(0);
    }

    ordinaStringhe(argv, argc);

    int fd = open(argv[1], O_CREAT | O_WRONLY, 0777);
    for (int i = 2; i < argc; i++)
    {
        /* salvo su file e stampo a video*/
        write(fd, argv[i], strlen(argv[i]));
        write(fd, "\n", strlen("\n"));
        write(1, argv[i], strlen(argv[i]));
        write(1, "\n", strlen("\n"));
    }
    close(fd);
    return 0;
}