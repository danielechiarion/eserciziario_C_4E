/* Progettare un algoritmo che effettui le seguenti operazioni:
- legga da tastiera una coppia di valori interi A e B con A<B;
- continui a leggere da tastiera una serie di valori interi, terminando
quando il valore letto è al di fuori dell’intervallo [A, B];
- conteggi la media dei valori letti;
- prima di terminare, stampi il valore calcolato. */

#include <stdio.h>

void main(){
    /* dichiarazione variabili */
    int a,b, numCorrente;
    int somma=0, contatore=0;
    double media;

    /* inserimento a e b come estremi dell'intervallo
    controllando che a<b */
    do{
        printf("Inserisci il primo estremo dell'intervallo: ");
        scanf("%d", &a);
        printf("Inserisci il secondo estremo dell'intervallo: ");
        scanf("%d", &b);

        if(a>=b)
            printf("ERRORE! il primo estremo deve essere necessariamente minore del secondo\n\n");
    }while(a>=b);

    /* ora richiedo l'inserimento di valori
    fin quando non ne viene inserito uno che superi l'intervallo */
    printf("\n");
    do{
        printf("Inserisci un numero: ");
        scanf("%d", &numCorrente);

        if(numCorrente>=a && numCorrente<=b){
            contatore++; //aumento il contatore
            somma+=numCorrente; //sommo i valori
        }
    }while(numCorrente>=a && numCorrente<=b);

    /* calcolo infine la media dei valori e
    stampo a video il risultato */
    media = (double)somma/contatore;
    printf("\n\nLa media di tutti i valori inseriti nell'intervallo da %d a %d e' %.2f", a,b,media);
}
