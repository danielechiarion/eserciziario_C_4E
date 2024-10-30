/* Si scriva una funzione in linguaggio C che riceva in input una stringa
e un carattere.
La funzione deve contare le occorrenze del carattere all'interno della
stringa.
La funzione deve necessariamente essere di tipo void.
Nel main si richiami la funzione e si mostri a video il risultato.

Esempio di esecuzione:
$ ./a.out pippo p
Il carattere p compare 3 volte in pippo

$ ./a.out ciao b
Il carattere b compare 0 volte in ciao */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* funzione che conta i caratteri all'interno
di una stringa */
void contaCaratteri(char stringa[], char carattere, int *cont)
{
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] == carattere)
        {
            (*cont)++;
        }
    }
}

int main(int argc, char *argv[])
{
    /* controllo che il numero di argomenti
    sia valido */
    if (argc != 3)
    {
        printf("Numero di argomenti non valido");
        exit(0);
    }
    if (strlen(argv[2]) != 1)
    {
        printf("Non hai inserito un carattere da controllare");
        exit(0);
    }

    /* dichiarazione variabili */
    int cont = 0;

    contaCaratteri(argv[1], argv[2][0], &cont); // conto i caratteri nella stringa

    /* output risultati */
    printf("Il carattere %c e' contenuto %d volte in %s\n", argv[2][0], cont, argv[1]);

    return 0;
}