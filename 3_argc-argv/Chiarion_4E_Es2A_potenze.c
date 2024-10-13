/* Si scriva un programma che calcoli l’elevazione a potenza del valore intero
passato come primo argomento per il secondo argomento intero.

Esempio:

$./es 2 3
2 ^ 3 = 8 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Errore argomenti"); // controllo se sono stati inseriti i giusti argomenti
        exit(0);
    }

    /* dichiarazione variabili */
    int a, b;
    int potenza = 1;

    /* conversione valori */
    a = atoi(argv[1]);
    b = atoi(argv[2]);

    if (b < 0)
    {
        printf("Passare un esponente positivo");
        exit(0);
    }

    /* calcolo la potenza */
    for (int i = 0; i < b; i++)
    {
        potenza *= a;
    }

    /* output risultati */
    printf("%d alla %d e' uguale a: %d\n", a, b, potenza);

    return 0;
}