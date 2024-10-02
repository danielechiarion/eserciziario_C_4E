/* Dato un numero intero positivo N verificare se N è un numero primo. */

#include <stdio.h>

/* funzione che conta quanti divisori,
oltre a 0 e ad 1, sono presenti in un numero */
int contaDivisori(int num)
{
    int cont = 0;

    /* siccome 1 e num stesso sono già divisori,
    parto da 2 e mi fermo a num/2 */
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
            cont++;
    }

    return cont; // ritorno il contatore
}

int main(int argc, char *argv[])
{
    int input;
    int nDivisori;

    /* input valore, controllando
    che sia positivo */
    do
    {
        printf("Inserisci un numero intero positivo: ");
        scanf("%d", &input);
    } while (input <= 0);

    nDivisori = contaDivisori(input); // richiamo la funzione per ottenere il numero di divisori

    /* output risultati */
    if (nDivisori == 0)
    {
        printf("\n\nIl numero e' primo");
    }
    else
    {
        printf("\n\nIl numero non e' primo");
    }

    return 0;
}