/* Progettare un algoritmo che effettui la lettura da tastiera di una serie di coppie di valori numerici.
L’algoritmo deve calcolare e stampare il rapporto tra il valore minore e quello maggiore dei due. Il
programma termina quando uno dei due valori o entrambi sono uguali a zero. */

#include <stdio.h>

void main(){
    /* dichiarazione variabili */
    int a,b;
    double rapporto;

    do{
        /* richiesta inserimento dati */
        printf("Inserisci il primo numero: ");
        scanf("%d", &a);
        printf("Inserisci il secondo numero: ");
        scanf("%d", &b);

        /* calcolo rapporto */
        if(a<b){
            if(b==0){ //se il divisore è uguale a 0 non proseguo con il ciclo in quanto la divisione è impossibile
                printf("La divisione e' impossibile");
                break;
            }
            rapporto = (double)a/b; //il cast in double è importante per avere un risultato decimale, altrimenti si otterrà sempre 0
        }
        else{
            if(a==0){
                printf("La divisione e' impossibile");
                break;
            }
            rapporto = (double)b/a;
        }

        printf("Il rapporto tra i due numeri e' uguale a %.2f\n\n", rapporto); //output del risultato

    }while(a!=0 && b!=0);
}
