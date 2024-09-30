/*  Dato N un numero intero positivo, calcolare e visualizzare la somma dei
primi N numeri dispari. */

#include <stdio.h>

int main(int argc, char *argv[]){
    /* dichiarazione variabili */
    int input;
    
    /* input dati */
    do{
        printf("Inserisci quanti numeri dispari visualizzare: ");
        scanf("%d", &input);
	}while(input<0);
    
    /* visualizzazione numeri dispari */
    printf("\n\nI primi %d numeri dispari sono: \n", input);
    for(int i=1;i<input*2;i+=2){
        printf("%d\t", i);
    }
      
    return 0;
}