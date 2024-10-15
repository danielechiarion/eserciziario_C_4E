/* Si legga da riga di comando una stringa e la si mostri in output
invertita. Per fare l'inversione si implementi la funzione inverti.

Esempio:
$./a.out ciao
oaic */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inversoStringa(char *stringa, char *stringa2)
{
    for (int i = 0; i < strlen(stringa); i++)
    {
        *(stringa2 + i) = *(stringa + strlen(stringa) - i - 1);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti errato\n");
        exit(0);
    }

    /* dichiarazione variabili */
    char *stringa = argv[1];
    char stringaInverso[strlen(stringa)];

    inversoStringa(stringa, stringaInverso); // inverso della stringa

    /* output risultati */
    printf("L'inverso della stringa %s e' %s", stringa, stringaInverso);

    return 0;
}