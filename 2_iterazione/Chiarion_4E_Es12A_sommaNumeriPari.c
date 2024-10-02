/* Dato N un numero intero positivo, calcolare e visualizzare la
somma dei primi N numeri pari. */

#include <stdio.h>

int main(int argc, char *argv[])
{
    /* dichiarazione variabili */
    int n;
    int somma = 0;

    /* inserimento numero,
    controllo che sia positivo */
    do
    {
        printf("Inserisci un numero: ");
        scanf("%d", &n);
    } while (n <= 0);

    /* calcolo la somma dei primi N
    numeri pari */
    for (int i = 1; i <= n; i++)
    {
        somma += i * 2;
    }

    /* output risultati */
    printf("\n\nLa somma dei primi %d numeri pari e' %d", n, somma);

    return 0;
}