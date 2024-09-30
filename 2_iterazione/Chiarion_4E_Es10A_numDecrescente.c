/* Dato N un numero intero positivo, calcolare e visualizzare la somma dei
primi N numeri interi.  */

#include <stdio.h>

int main(int argc, char *argv[])
{
	/* dichiarazione variabili */
	int input;
	int somma = 0;

	/* inserimento dati input */
	do
	{
		printf("Inserisci un numero maggiore di 1: ");
		scanf("%d", &input);
	} while (input <= 0);

	/* calcolo la somma dei primi N
	numeri interi */
	for (int i = 1; i <= input; i++)
	{
		somma += i;
	}

	/* restituzione dati output */
	printf("La somma dei primi %d numeri interi e' %d", input, somma);

	return 0;
}
