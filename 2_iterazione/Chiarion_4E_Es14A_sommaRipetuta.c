/* Dati due numeri interi positivi N1 ed N2 calcolare, mediante la somma
ripetuta, il prodotto dei due numeri e visualizzarli. */

#include <stdio.h>

int main(int argc, char *argv[])
{
    /* dichiarazione variabili */
    int n1, n2;
    int prodotto = 0;

    /* inserimento n1 e n2,
    controllando che i due valori siano positivi */
    do
    {
        printf("Inserisci N1: ");
        scanf("%d", &n1);
    } while (n1 <= 0);

    do
    {
        printf("Inserisci N2: ");
        scanf("%d", &n2);
    } while (n2 <= 0);

    /* eseguire N1*N2, è come
    sommare ripetutamente N1 per tante volte quanto è N2,
    o viceversa */
    for (int i = 0; i < n2; i++)
    {
        prodotto += n1;
    }

    /* output risultati */
    printf("\n\nIl prodotto tra %d e %d e' %d", n1, n2, prodotto);

    return 0;
}