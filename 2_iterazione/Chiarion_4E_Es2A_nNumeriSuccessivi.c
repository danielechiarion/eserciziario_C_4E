/* Dato N un numero intero positivo, generare e visualizzare in ordine crescente i primi N numeri
interi positivi. */

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

    /* stampo i primi N numeri interi positivi */
    printf("\n\nI primi %d numeri interi positivi sono: \n", n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d\t", i);
    }

    return 0;
}