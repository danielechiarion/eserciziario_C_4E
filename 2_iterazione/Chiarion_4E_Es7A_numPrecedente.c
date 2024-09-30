/* Dato N un numero intero positivo maggiore di 1, generare e visualizzare
il numero precedente.  */

#include <stdio.h>

int main(int argc, char *argv[])
{
	/* dichiarazione variabili */
	int input, numPrecedente;

	/* input variabili */
	do
	{
		printf("Inserisci un numero maggiore di 1: ");
		scanf("%d", &input);
	} while (input <= 1);

	numPrecedente = input - 1; // imposto il numero successivo

	printf("\n\nIl numero precedente a %d e' %d: ", input, numPrecedente);

	return 0;
}
