/* Dato N un numero intero positivo, generare e visualizzare in ordine
crescente i numeri compresi maggiori uguali di -N e minori uguali di N. */

#include <stdio.h>

int main(int argc, char *argv[])
{
    /* dichiarazione variabili */
    int n;

    /* richiesta inserimento numero.
    Controllo che sia positivo */
    do
    {
        printf("Inserisci quanti numeri vuoi visualizzare: ");
        scanf("%d", &n);
    } while (n <= 0);

    /* stampo i valori compresi nell'intervallo
    [-N;N] */
    printf("\n\nI valori compresi tra %d e %d sono: \n", -n, n);
    for (int i = -n; i <= n; i++)
    {
        printf("%d\t", i);
    }

    return 0;
}