/* Scrivere un programma in linguaggio C che dato un array di interi mostri
in output se l'array è pari.
Esempio:
[1,1,2,1,2,1,2,2] => è pari
[1,1,2] => dispari
[3,3,4,5] => dispari
[1,2,1,2] => pari */

#include <stdio.h>

/* funzione che conta quante volte
un numero è presente all'interno di un array */
int contaRicorrenzeNumero(int array[], int dimensione, int numero)
{
    int cont = 0;

    for (int i = 0; i < dimensione; i++)
    {
        if (array[i] == numero)
        {
            cont++;
        }
    }

    return cont;
}

/* funzione che controlla se l'array è pari */
int isPari(int array[], int dimensione)
{
    for (int i = 0; i < dimensione; i++)
    {
        /* perchè un array sia pari vuol dire che tutti i numeri
        devono essere presenti un numero pari di volte */
        /* la prima volta che questa condizione non viene soddisfatta
        posso uscire dal metodo */
        if (contaRicorrenzeNumero(array, dimensione, array[i]) % 2 != 0)
        {
            return -1;
        }
    }

    return 1;
}

int main(int argc, char *argv[])
{
    /* creo un array e lo popolo
    con valori casuali */
    int array[] = {1, 2, 3, 1, 2, 3};

    /* output risultati */
    if (isPari(array, sizeof(array) / sizeof(array[0])) > 0)
    {
        printf("L'array e' pari");
    }
    else
    {
        printf("L'array non e' pari");
    }
}