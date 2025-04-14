#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    /* controllo gli argomen ti */
    if (argc != 3)
    {
        printf("\nNumero di argomenti non valido");
        exit(1);
    }

    FILE *fileInput, *fileOutput;
    /* apro i file in modalità
    di lettura e scrittura */
    fileInput = fopen(argv[1], "r");
    fileOutput = fopen(argv[2], "w");
    /* dichiarazione variabili */
    int value;

    /* controllo se l'apertura dei file
    è avvenuta correttamente */
    if (fileInput == NULL)
    {
        printf("\nErrore nell'apertura del file di input");
        exit(2);
    }
    if (fileOutput == NULL)
    {
        printf("\nErrore nell'apertura del file di output");
        exit(2);
    }

    while ((value = fgetc(fileInput)) != -1)
    {
        fputc(value, fileOutput);
    }

    fclose(fileInput);
    fclose(fileOutput);
    return 0;
}