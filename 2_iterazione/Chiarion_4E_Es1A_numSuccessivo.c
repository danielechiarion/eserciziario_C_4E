/* Dato N un numero intero positivo, generare e visualizzare il numero
successivo. */

#include <stdio.h>

int main(int argc, char *argv[])
{
    /* dichiarazione variabili */
    int num, numSuccessivo;

    /* richiesta inserimento numero,
    effettuando il controllo sulla positività */
    do
    {
        printf("Inserisci un numero positivo: ");
        scanf("%d", &num);
    } while (num <= 0);

    numSuccessivo = num + 1;                                        // genero il numero successivo
    printf("Il numero successivo di %d e' %d", num, numSuccessivo); // visualizzo il numero successivo

    return 0;
}