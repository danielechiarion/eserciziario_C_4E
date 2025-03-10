#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *nome; // file è una struct di stdio.h
    nome = fopen("nome.txt", "w");
    fclose(nome);
    return 0;
}