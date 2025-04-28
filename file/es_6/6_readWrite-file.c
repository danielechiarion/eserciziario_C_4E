#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Numero argomenti non valido\n");
        exit(1);
    }

    /* buffer per la lettura di file */
    const int BUFFER_DIM = 1024;
    unsigned char buf[BUFFER_DIM];
    /* puntatori a file */
    FILE *fileSrc, *fileDst;
    fileSrc = fopen(argv[1], "r");
    fileDst = fopen(argv[2], "w");
    /* controllo se i file sono stati
    aperti correttamente */
    if (fileSrc == NULL)
    {
        printf("Errore di apertura nel file sorgente\n");
        exit(2);
    }
    if (fileDst == NULL)
    {
        printf("Errore di apertura nel file destinazione\n");
        exit(2);
    }

    /* il secondo attributo della funzione
    indica il numero di byte occupati dalla singola unità */
    while (fread(buf, 1, BUFFER_DIM, fileSrc) > 0) // !feof(file) è una condizione alternativa
    {
        fwrite(buf, 1, strlen(buf), fileDst);
    }

    fclose(fileSrc);
    fclose(fileDst);

    return 0;
}