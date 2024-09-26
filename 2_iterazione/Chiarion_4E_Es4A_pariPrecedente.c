/* Dato N un numero intero positivo, generare e visualizzare in ordine
crescente i numeri pari minori o uguali a N. */

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

    /* parto da 2 e visualizzo i numeri dispari
    minori o uguali ad n*/
    printf("\n\nI numeri pari positivi minori o uguali a %d sono: \n", n);
    for (int i = 0; i <= n; i += 2)
    {
        printf("%d\t", i);
    }

    return 0;
}