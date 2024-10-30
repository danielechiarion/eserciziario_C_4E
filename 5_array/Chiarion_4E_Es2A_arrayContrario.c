/* Chiedere in input 5 interi e inserirli in un array.
Stampare a video l'array al contrario.
Esempio:
input 5 6 9 11 12
output 12 11 9 6 5 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    /* dichiarazione array */
    int array[5];

    /* inserimento valori array */
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        printf("Inserisci un numero: ");
        scanf("%d", &array[i]);
    }

    /* stampa dei valori a video al contrario */
    for (int i = sizeof(array) / sizeof(array[0]) - 1; i >= 0; i--)
    {
        printf("%d\t", array[i]);
    }

    return 0;
}