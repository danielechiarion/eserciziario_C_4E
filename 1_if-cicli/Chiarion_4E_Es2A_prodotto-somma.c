#include <stdio.h>

/* Progettare un algoritmo che effettui le seguenti operazioni:
- continui a leggere da tastiera due valori numerici, fermandosi quando uno dei due numeri è
0 (zero)
- per ogni coppia di numeri letti:
- calcoli il prodotto dei due numeri e ne stampi il valore
- sommi il prodotto calcolato ad una variabile che memorizzi la somma di tutti i prodotti
- all’uscita del ciclo, stampi il valore della somma */

void main(){
    /* dichiarazione variabili */
    int a,b;
    int prodotto, somma=0;

    do{
        /* richiesta inserimento dati input */
        printf("Inserisci primo numero: ");
        scanf("%d", &a);
        printf("Inserisci secondo numero: ");
        scanf("%d", &b);

        /* calcolo prodotto e somma */
        prodotto = a*b;
        somma+=prodotto;

        /* output prodotto */
        printf("Il prodotto tra i due numeri e': %d\n\n", prodotto);
    }while(a!=0 && b!=0);

    /* restituisco alla fine la somma dei valori */
    printf("\nLa somma totale dei prodotti e': %d", somma);
}
