/* Scriva un programma C che dato un array prestabilito, prenda in input da
riga di comando un numero e lo ricerchi all'interno dell'array.
La ricerca deve essere demandata ad un processo figlio e deve essere
implementata attraverso un'apposita funzione di nome ricerca. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* metodo che ricerca un numero
all'interno di un array */
int ricerca(int array[], int arraySize, int num)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] == num)
        {
            return i;
        }
    }

    return -1;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero di argomenti non valido\n");
        exit(0);
    }

    /* dichiarazione variabili */
    int p, posizione, numInput = atoi(argv[1]);
    int array[] = {15, 8, 2, 3, 45, 78, 9, 65, 23};

    p = fork(); // creo il processo figlio

    if (p == 0) // figlio
    {
        posizione = ricerca(array, sizeof(array) / sizeof(array[0]), numInput);
        if (posizione >= 0)
        {
            printf("Il numero %d si trova nella posizione %d dell'array\n", numInput, posizione);
        }
        else
        {
            printf("Il numero non e' stato trovato\n");
        }

        exit(2);
    }
    else // padre
    {
        wait(&p);
    }

    return 0;
}