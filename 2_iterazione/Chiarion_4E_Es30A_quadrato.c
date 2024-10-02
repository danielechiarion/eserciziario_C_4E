/* Dati due numeri interi positivi N1 e N2, verificare se N1 è il quadrato
di N2. */

#include <stdio.h>

int main(int argc, char *argv[])
{
    /* dichiarazione variabili */
    int n1, n2;

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

    /* output risultati */
    if (n1 == n2 * n2)
    {
        printf("\n\nN1 e' il quadrato di N2");
    }
    else
    {
        printf("\n\nN1 non e' il quadrato di N2");
    }

    return 0;
}