#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char inputNome[20];
    FILE *file = fopen("output.txt", "a");

    for(int i=0;i<3;i++){
        printf("Inserisci un nome: ");
        scanf("%s", inputNome);

        fputs(inputNome, file);
        fputc('\n', file);
    }

    fclose(file);
    return 0;
}