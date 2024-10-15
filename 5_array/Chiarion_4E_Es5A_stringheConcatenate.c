/* scrivere in C un programma che concatena in un unica stringa le stringhe
chieste in input da riga di comando.


Esempio:
$./a.out ciao a tutti gli studenti
ciao a tutti gli studenti */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Argomenti insufficienti");
        exit(0);
    }

    /* concatenazione fin quando
    non arriviamo all'ultima stringa */
    for (int i = 2; i < argc; i++)
    {
        strcat(argv[1], argv[i]);
    }

    /* output risultati */
    printf("La stringa di concatenazioni e' %s", argv[1]);

    return 0;
}