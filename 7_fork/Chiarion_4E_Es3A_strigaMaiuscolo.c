#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void convertiStringaMaiuscolo(char string[])
{
    /* converto tutti i caratteri in maiuscolo */
    for (int i = 0; i < strlen(string); i++)
    {
        string[i] = toupper(string[i]);
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
    char string[strlen(argv[1])];
    strcpy(string, argv[1]);

    p = fork();
    if (p == 0) // processo figlio
    {
        convertiStringaMaiuscolo(string);
        printf("La stringa convertita in maiuscolo e': %s", string);
        exit(0);
    }
    else // processo padre
    {
        wait(&p);
    }

    return 0;
}