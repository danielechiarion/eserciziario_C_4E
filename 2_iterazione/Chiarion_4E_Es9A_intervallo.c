/* Dati due numeri interi e positivi N1 e N2 con N2>N1, generare e
visualizzare in ordine decrescente i numeri compresi tra N1 e N2. */

#include <stdio.h>

int main(int argc, char *argv[]){
	/* dichiarazioni variabili */
	int n1,n2;
	
	/* richiesta inserimento dati input */
	do{
		printf("Inserisci il primo numero: ");
		scanf("%d", &n1);
		printf("Inserisci il secondo numero: ");
		scanf("%d", &n2);
		
		if(n2<=n1){
			printf("ERRORE! L'input deve essere N2>N1");
		}
	}while(n2<=n1);
	
	/* output risultati */
	printf("\nI numeri compresi tra %d e %d sono: \n", n1, n2);
	for(i=n1;i<=n2;i++){
		printf("%d\t", i);
	}
    
    return 0;

}
