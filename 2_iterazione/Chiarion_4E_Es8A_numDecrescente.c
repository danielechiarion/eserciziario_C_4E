/* Dato N un numero intero positivo, generare e visualizzare in ordine
decrescente i primi N numeri interi positivi. */


int main(int argc, char *argv[]){
	/* dichiarazione variabili */
	int input;
	
	/* inserimento dati input */
	do{
		printf("Inserisci quanti numeri visualizzare: ");
		scanf("%d", &input);
	}while(input<=0);
	
	/* genero i primi N numeri positivi
	in  ordine decrescente */
	printf("\n\nI primi %d numeri in ordine decrescente sono: \n", input);
	for(int i=input, i>0;i--){
		printf("%d\t", i);
	}
    
    return 0;

}