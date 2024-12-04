#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void convertiStringaMaiuscolo(char stringa[])
{
    /* converto tutti i caratteri in maiuscolo */
    for (int i = 0; i < strlen(stringa); i++)
    {
        stringa[i] = toupper(stringa[i]);
    }
}

int main(int argc, char *argv[])
{
    /* controllo se il numero di argomenti
    è valido */
    if (argc != 2)
    {
        printf("Numero di argomenti non valido.");
        exit(0);
    }

    /* dichiarazione variabili */
    int p;

    p = fork();
    if (p == 0) // processo figlio
    {
        convertiStringaMaiuscolo(argv[1]);
        printf("La stringa convertita in maiuscolo e': %s", argv[1]);
        exit(0);
    }
    else // processo padre
    {
        wait(&p);
    }

    return 0;
}