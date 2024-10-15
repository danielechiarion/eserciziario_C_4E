/* Si scriva un programma in linguaggio C che implementi una funzione
denominata palindroma che prenda in input una stringa e restituisca
1 se la stringa è palindroma altrimenti -1

esempio:
$ ./a.out anna
$ anna è una stringa palindroma

esempio:
$ ./a.out ciao
$ ciao non è una stringa palindroma */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindroma(char stringa[])
{
    for (int i = 0; i < strlen(stringa) / 2; i++)
    {
        if (stringa[i] != stringa[strlen(stringa) - i - 1])
        {
            return -1;
        }

        return 1;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti non valido\n");
        exit(0);
    }

    if (palindroma(argv[1]) == 1)
    {
        printf("\nLa stringa e' palindroma");
    }
    else
    {
        printf("\nLa stringa non e' palindroma");
    }

    return 0;
}