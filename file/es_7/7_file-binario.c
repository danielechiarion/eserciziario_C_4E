#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Numero di argomenti non valido\n");
        exit(1);
    }

    /* creazione dei file
    e definizione modalità di apertura */
    FILE *file = fopen(argv[1], "wb+");
    if(file == NULL){
        printf("Apertura file %s non avvenuta correttamente", argv[1]);
        exit(2);
    }

    /* dichiatarazione variabili */
    int input;

    /* scrittura su file */
    for(int i=0;i<5;i++){
        printf("Inserisci il numero: ");
        scanf("%d", &input);
        fwrite(&input, sizeof(input), 1, file);
    }

    /* riporto il cursore del file all'inizio */
    fseek(file, 0, SEEK_SET);

    /* lettura da file e stampa a video */
    while(fread(&input, sizeof(input), 1, file)>0){
        printf("\nNumero letto: %d", input);
    }

    fclose(file);
    return 0;
}