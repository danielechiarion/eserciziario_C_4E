/* Leggere in input da tastiera due numeri maggiori di 0 e farne la somma. */

#include <stdio.h>

int somma(int a, int b)
{
    return a + b;
}

int main(int argc, char *argv[])
{
    int n1, n2;

    printf("Inserisci primo numero: ");
    scanf("%d", &n1);
    printf("Inserisci secondo numero: ");
    scanf("%d", &n2);

    printf("\n\nLa somma tra %d e %d e' %d", n1, n2, somma(n1, n2));

    return 0;
}