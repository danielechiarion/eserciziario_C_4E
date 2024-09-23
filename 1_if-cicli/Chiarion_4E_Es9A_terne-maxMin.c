/* Progettare un algoritmo che risolva il seguente problema. Si richieda
all’utente di inserire una serie di terne di dati numerici (A, B, C).
Il programma deve terminare quando uno dei valori inseriti è minore di
zero. Si scartino le terne nelle quali i valori non sono in ordine
strettamente crescente, ovvero quelle terne per cui non valga A < B < C.
Su tutte le terne non scartate si calcoli il massimo e il minimo dei
valori inseriti. Si stampino a video tali valori massimi e minimi prima
di terminare il programma. */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h> //libreria che serve a inserire il massimo valore possibile

/* funzione che ritorna TRUE se almeno uno dei numeri è minore di zero,
FALSE se nessuno dei numeri è minore di 0*/
bool controlloZeri(int a, int b, int c)
{
    if (a < 0)
        return true;
    if (b < 0)
        return true;
    if (c < 0)
        return true;

    return false;
}

/* funzione che controlla se A<B<C,
restituisce TRUE se tale condizione è vera,
FALSE se non viene rispettato quest'ordine */
bool controlloOrdine(int a, int b, int c)
{
    if (a < b && b < c)
        return true;

    return false;
}

/* funzione che determina il massimo e il minimo,
prendendo i due estremi, A e C */
void verificaMaxMin(int a, int c, int *max, int *min)
{
    if (a < *min)
        *min = a;
    if (c > *max)
        *max = c;
}

int main(int argc, char *argv[])
{
    /* dichiarazione variabili */
    int a, b, c;
    int max = -1, min = INT_MAX;

    /* ciclo che si ripete ogni volta */
    while (true)
    {
        /* inserimento dati input */
        printf("\nInserisci il primo valore: ");
        scanf("%d", &a);
        printf("Inserisci il secondo valore: ");
        scanf("%d", &b);
        printf("Inserisci il terzo valore: ");
        scanf("%d", &c);

        /* eseguo i controlli sulle terne */
        if (controlloZeri(a, b, c))
        {
            printf("\nAlmeno uno dei numeri inseriti e' minore di 0");
            break;
        }
        if (!controlloOrdine(a, b, c))
        {
            printf("Non e' stato rispettato l'ordine A<B<C");
            break;
        }

        verificaMaxMin(a, c, &max, &min); // se tutto va bene, verifico il massimo e il minimo
    }

    /* una volta finito,
    stampo a video i risultati */
    if (max < 0) // controllo anche il caso in cui non è stata inserita nemmeno una terna valida
        printf("\n\nNon e' stata inserita nessuna terna valida");
    else
    {
        printf("\nIl numero minimo e': %d", min);
        printf("\n\nIl numero massimo e': %d", max);
    }

    return 0;
}