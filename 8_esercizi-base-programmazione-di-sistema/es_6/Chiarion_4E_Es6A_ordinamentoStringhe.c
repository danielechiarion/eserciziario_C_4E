/* Scrivere un programma in linguaggio C che legge da argv una serie di stringhe,
le ordina in senso crescente o decrescente in funzione del flag usato in argv[2].
Si utilizzi un algoritmo di ordinamento a scelta. Si scriva il risultato
sia a video che su un file il cui nome risiede in argv[1].

Esempio:
$ ./a.out file.txt --asc ciao a tutti
a
ciao
tutti

$ cat file.txt 
a
ciao
tutti

Esempio:
$ ./a.out file.txt --desc ciao a tutti
tutti
ciao
a

$ cat file.txt 
tutti
ciao
a*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

const char FLAGCRESCENTE[] = "--asc";
const char FLAGDECRESCENTE[] = "--desc";

/* metodo che scambia due stringhe */
void scambia(char **a, char **b){
    char *temp = *a;
    *a=*b;
    *b=temp;
}

/* metodo che ordina le stringhe sfruttando 
il selection sort */
void ordinaStringhe(char *array[], int size, char *flag){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if((strcmp(flag, FLAGCRESCENTE) && strcmp(array[j], array[i])<0) || (strcmp(flag, FLAGDECRESCENTE) && strcmp(array[j], array[i])>0)){
                scambia(&array[i], &array[j]);
            }
        }
    }
}

int main(int argc, char *argv[]){
    /* prima di tutto controllo che il numero di argomenti
    sia valido. Perchè il codice funzioni occorre:
    - 1 parametro per il file da eseguire
    - 1 parametro per il file di destinazione in cui salvare i risultato
    - 1 parametro per il flag che indica l'ordinamento da considerare (crescente o decrescente)
    - 1 o più stringhe da ordinare
    
    Quindi occorrono almeno 4 parametri */
    if(argc < 4){
        printf("Numero di argomenti insufficiente\n");
        exit(0);
    }
    /* controllo inoltre che il flag inserito come
    terzo argomento sia uguale a quelli stabiliti di default
    per indicare un ordinamento crescente o decrescente */
    if(strcmp(argv[2], FLAGCRESCENTE)!=0 && strcmp(argv[2], FLAGDECRESCENTE)!=0){
        printf("Flag per l'ordinamento errato\n");
        exit(0);
    }

    /* creo un array di stringhe e copio
    le stringhe di interesse in argv */
    char *array[argc-3];
    for(int i=3;i<argc;i++){
        array[i-3] = argv[i];
    }

    ordinaStringhe(array, argc-3, argv[2]); //ordino le stringhe

    /* scrivo il risultato a video e sul file indicato */
    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    for(int i=0;i<argc-3;i++){
        write(fd, array[i], strlen(array[i]));
        write(fd, "\n", strlen("\n"));
        write(1, array[i], strlen(array[i]));
        write(1, "\n", strlen("\n"));
    }
    close(fd);

    return 0;
}