/* Chiedere in input 10 interi e inserirli in un array.
Stampare a video prima tutti i numeri pari e
in seguito tutti i numeri dispari

Esempio:
input 5 6 9 11 12 13 14 10 8 21
output
6 12 14 10 8
5 9 11 13 21 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    /* dichiarazione array della dimensione stabilita
    da consegna */
    int array[10];

    /* inserimento valori array */
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        printf("Inserisci un numero: ");
        scanf("%d", &array[i]);
    }

    /* stampa a video dei numeri pari */
    printf("\nNUMERI PARI:\n");
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        if (array[i] % 2 == 0)
        {
            printf("%d\t", array[i]);
        }
    }

    /* stampa a video dei numeri dispari */
    printf("\nNUMERI DISPARI:\n");
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        if (array[i] % 2 != 0)
        {
            printf("%d\t", array[i]);
        }
    }
    return 0;
}