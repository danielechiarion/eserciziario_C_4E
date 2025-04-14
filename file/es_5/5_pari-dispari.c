#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concatenaCarattere(char stringa[], char value)
{
    int length = strlen(stringa);
    stringa[length] = value;
    stringa[length + 1] = '\0';
}

int main(int argc, char *argv[])
{
    /* dichiarazione file */
    FILE *fileInput, *fileOutputPari, *fileOutputDispari;
    /* apertura file */
    fileInput = fopen("numeri.txt", "r");
    fileOutputPari = fopen("pari.txt", "w");
    fileOutputDispari = fopen("dispari.txt", "w");

    if (fileInput == NULL)
    {
        printf("\nErrore nell'apertura del file numeri.txt");
        exit(1);
    }
    if (fileInput == NULL)
    {
        printf("\nErrore nell'apertura del file pari.txt");
        exit(1);
    }
    if (fileInput == NULL)
    {
        printf("\nErrore nell'apertura del file dispari.txt");
        exit(1);
    }

    /* dichiarazione variabili */
    char buf[10], car;
    int valueRead;

    while ((valueRead = fgetc(fileInput)) != EOF)
    {
        car = (char)valueRead;
        if (car != ' ')
        {
            concatenaCarattere(buf, car);
        }
        else if (atoi(buf) % 2 != 0)
        {
            fputs(buf, fileOutputDispari);
            fputs(" ", fileOutputDispari);
            buf[0] = '\0';
        }
        else
        {
            fputs(buf, fileOutputPari);
            fputs(" ", fileOutputPari);
            buf[0] = '\0';
        }
    }

    fclose(fileInput);
    fclose(fileOutputPari);
    fclose(fileOutputDispari);

    return 0;
}