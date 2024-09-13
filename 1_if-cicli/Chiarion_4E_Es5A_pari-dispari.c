/* Progettare un algoritmo che effettui le seguenti operazioni:

- continui a leggere da tastiera una serie di terne di valori interi A ,
B e C finchè non vengono inseriti dei valori tali per cui A + B < C
- conteggi il numero di volte in cui la differenza tra A e B è pari, dispari, e quando è nulla
- prima di terminare, visualizzi il valore dei valori conteggiati */

#include <stdio.h>

void main(){
    /* dichiarazione variabili */
    int pari=0, dispari=0, nullo=0; //i contatori li inizializzo a 0
    int differenza;
    int a,b,c;

    do{
        /* input numeri */
        printf("\nInserisci il primo numero: ");
        scanf("%d", &a);
        printf("Inserisci il secondo numero: ");
        scanf("%d", &b);
        printf("Inserisci il terzo numero: ");
        scanf("%d", &c);

        /* calcolo la differenza e conteggio il risultato
        come pari, dispari o nullo */
        differenza=a-b;

        if(differenza==0)
            nullo++;
        else if(differenza%2==0)
            pari++;
        else
            dispari++;
    }while(a+b>=c);

    /* output dei contatori */
    printf("\nDifferenze pari: %d", pari);
    printf("\nDifferenze dispari: %d", dispari);
    printf("\nDifferenze nulle: %d", nullo);
}
