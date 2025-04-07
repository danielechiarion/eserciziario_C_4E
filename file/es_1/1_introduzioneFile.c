#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    /* dichiarazione variabili */
    char car;
    FILE *file;

    /* input caratteri con getc() */
    printf("Inserisci il carattere >> ");
    car = getc(stdin);
    putc(car, stdout);

    /* scrittura su file del carattere */
    if (file != NULL)
    {
        file = fopen("output.txt", "w");
        fprintf(file, "%c", car);
        fclose(file);
    }

    return 0;
}