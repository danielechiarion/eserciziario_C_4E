/* Dato un numero N calcolare e visualizzare tutte le coppie di numeri minori di N che
danno per somma il numero stesso. Non considerare la proprietà commutativa. */

#include <stdio.h>

int main(int argc, char *argv[])
{
    /* dichiarazione variabili */
    int input;

    /* richiesta inserimento numero,
    occorre averlo positivo in quanto con i numeri negativi
    nessuna coppia minore di esso sommata darà il numero stesso */
    do
    {
        printf("Inserisci un numero intero positivo: ");
        scanf("%d", &input);
    } while (input <= 0);

    /* output risultati */
    printf("\n\nLe coppie di numeri che danno %d come risultato sono: ", input);
    for (int i = 1; i <= input / 2; i++) //arrivo fino alla metà di input per non considerare la proprietà commutativa
    {
        printf("\n%d + %d", i, input - i);
    }

    return 0;
}