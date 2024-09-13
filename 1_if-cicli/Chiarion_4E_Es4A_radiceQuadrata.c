/* Progettare un algoritmo che effettui la lettura da tastiera di una serie
di coppie di valori numerici reali (sia positivi che negativi che zero).
Per ciascuna coppia, l’algoritmo deve calcolare e stampare il valore
della radice quadrata del rapporto tra il valore maggiore e quello
minore dei due. Il programma termina quando vengono inseriti dei valori
che non permettono di svolgere il calcolo nel dominio dei numeri reali.
Prima di terminare si richiede di stampare un messaggio che indichi la
ragione per cui non è stato possibile svolgere il calcolo. */

#include <math.h> //serve per la radice quadrata
#include <stdio.h>

void main(){
    /* dichiarazione variabili */
    double a, b;
    double radice, rapporto;

    while(0==0){ //viene eseguito un loop all'infinito che viene interrotto dai singoli controlli applicati all'interno dell'esercizio
        /* richiesta inserimento dati input */
        printf("Inserisci il primo numero: ");
        scanf("%lf", &a);
        printf("Inserisci il secondo numero: ");
        scanf("%lf", &b);

        /* calcolo il rapporto tra due valori
        controllando quale è maggiore dei due, quindi
        quale sarà il dividendo */
        if(a>b){
            if(b==0){ //prima di fare la divisione controllo che il divisore sia diverso da 0
                printf("La divisione e' impossibile perchè il divisore e' 0");
                break;
            }
            rapporto=a/b;
        }
        else{
            if(a==0){ //prima di fare la divisione controllo che il divisore sia diverso da 0
                printf("La divisione e' impossibile perchè il divisore e' 0");
                break;
            }
            rapporto=b/a;
        }

        /* prima di fare la radice quadrata controllo che
        il radicando (il rapporto) sia maggiore o uguale a 0 */
        if(rapporto<0){
            printf("Il radicale e' impossibile in quanto il radicando e' negativo");
            break;
        }

        /* altrimenti calcolo la radice e stampo il risultato */
        radice=sqrt(rapporto);
        printf("La radice del rapporto tra i due numeri e' %.2f \n\n", radice);
    }
}
