/* Progettare un algoritmo che effettui la lettura da tastiera di una serie di valori numerici. Il
 * programma termina quando il dato immesso è pari a zero. Calcolare e stampare la media dei valori
 * inseriri. Inoltre, stampare la sequenza di valori in ordine inverso rispetto a quello di inserimento. Un
 * valore dovrà essere stampato soltanto se maggiore della media calcolata. */

#include <stdio.h>

int main(int argc, char *argv[])
{
    /* dichiarazione array e indice relativo */
    const int sizeArray = 100;
    int array[sizeArray];
    int indexArray = 0;

    /* dichiarazioe variabili */
    int somma = 0;
    double media = 0;
    int input;

    /* ripeto l'inserimento fin quando l'input
    è diverso da 0 */
    do
    {
        printf("Inserisci un valore (0 per terminare): ");
        scanf("%d", &input);

        /* controllo se l'input è diverso da 0
        per sommare il valore e assegnarlo all'array */
        if (input != 0)
        {
            array[indexArray++] = input;
            somma += input;
        }
    } while (input != 0 && indexArray < sizeArray);

    /* eseguo il calcolo della media
    e fornisco l'output */
    media = (double)somma / indexArray;
    printf("Media: %.2f", media);

    /* stampo i numeri invertiti,
    ma solo quelli maggiori della media */
    if (indexArray > 0)
    {
        printf("\n\nNumeri invertiti superiori alla media:\n");
        for (int i = indexArray - 1; i >= 0; i--)
        {
            if ((double)array[i] > media)
            {
                printf("%d\t", array[i]);
            }
        }
    }

    return 0;
}