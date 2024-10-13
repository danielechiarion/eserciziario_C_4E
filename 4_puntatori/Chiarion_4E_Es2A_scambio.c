/* Dati due numeri si scriva in linguaggio C una funzione di tipo void denominata scambia,
che dati in input 2 numeri li scambi. */

#include <stdio.h>

/* funzione che scambia due valori */
void scambia(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main(int argc, char *argv[])
{
    /* dichiarazione variabili */
    int n1, n2;

    /* input dati */
    printf("Inserisci il primo numero: ");
    scanf("%d", &n1);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &n2);

    scambia(&n1, &n2); // scambio valori

    /* output risultati */
    printf("\nIl primo valore e': %d", n1);
    printf("\nIl secondo valore e': %d", n2);

    return 0;
}