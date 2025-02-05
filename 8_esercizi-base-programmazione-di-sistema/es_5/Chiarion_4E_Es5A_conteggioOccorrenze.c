/* Si vuole realizzare in linguaggio C un software monoprocesso che implementi il seguente comando:
$ cat file1.txt file2.txt file3.txt /tmp/file4.txt | grep “c”

Dove file[N].txt con N maggiore uguale a 1 sono una serie di files scelti dall'utente e il carattere
"c" è a scopo esemplificativo e potrebbe essere qualsiasi carattere.

Si utilizzino le system call al fine di leggere tutti i file di testo e, per ogni file, ricercare il carattere.
Al termine dell’esecuzione il software dovrà mostrare a video il numero di occorrenze trovate nei files e
dovrà contemporaneamente scrivere l’output su un file di testo il cui path sarà letto da argv.

Esempio:
$ ./a.out file1.txt file2.txt file3.txt k occorrenze.txt
$ Il carattere k compare 10 volte nei files: file1.txt, file2.txt, file3.txt
$ cat occorrenze.txt
$ Il carattere k compare 10 volte nei files: file1.txt, file2.txt, file3.txt

Esempio:
$ ./a.out file1.txt file2.txt file3.txt /tmp/file3.txt q /tmp/occorrenze.txt                                                                     
$ Il carattere q compare 18 volte nei files: file1.txt file2.txt file3.txt /tmp/file3.txt 
$ cat /tmp/occorrenze.txt                                                                                             
$ Il carattere q compare 18 volte nei files: file1.txt file2.txt file3.txt /tmp/file3.txt


Osservazioni:
essendo il software monoprocesso non è necessario usare le pipe
prestare attenzione all’uso corretto di argv
si ricorda che il software deve funzionare per un numero arbitrario di files di input.
i percorsi dei files possono essere sia assoluti che relativi 
 

Suggerimento:
Per facilitare la ricerca è possibile leggere un singolo carattere per volta usando la funzione read.
Utilizzare la funzione strcat per concatenare due stringhe. */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

/* metodo che calcola la lunghezza della stringa per 
l'output */
int contaDimensioneStringhe(int argc, char *argv[]){
    const int dimensioneIntro = 50; //dimensione per l'introduzione dell'output
    int lunghezzaPercorsi = 0;

    /* scorro tutti i percorsi dei file e conto la lunghezza */
    for(int i=1;i<argc-2;i++){
        lunghezzaPercorsi += strlen(argv[i])+1; //il carattere in più è lo spazio
    }

    return lunghezzaPercorsi+dimensioneIntro;
}

/* metodo che concatena le stringhe di una lunghezza 
già impostata */
void concatenaStringhe(char base[], int argc, char *argv[], int occorrenze, char charRicerca){
    /* inserisco la prima stringa indica il carattere 
    e il numero occorrenze */
    sprintf(base, "Il carattere %c compare %d volte nei files: ", charRicerca, occorrenze);

    /* ora concateno i files */
    for(int i=1;i<argc-2;i++){
        strcat(base, argv[i]);
        strcat(base, " ");
    }
}

int main(int argc, char *argv[]){
    /* il numero minimo di argomenti è 4,
    in quanto:
    - 1 parametro è il file da eseguire
    - 1 o più sono i file da ricercare
    - 1 è il carattere da ricercare
    - 1 è il file doce salvare il risultato */
    if(argc<4){
        printf("Numero di argomenti insufficiente\n");
        exit(0);
    }

    /* dichiarazione variabili */
    int fd, cont = 0;
    char buf, charRicerca = argv[argc-2][0];
    char output[contaDimensioneStringhe(argc, argv)];

    /* scorro tutti i file indicati partendo dall'indice
    opportuno e conto le occorrenze del carattere */
    for(int i=1;i<argc-2;i++){
        fd = open(argv[i], O_RDONLY);
        /* leggo carattere per carattere e controllo se 
        sono uguali*/
        while(read(fd, &buf, sizeof(buf))){
            if(buf == charRicerca){
                cont++;
            }
        }
        close(fd); //è importante chiudere sempre il file
    }

    /* concateno le stringhe per poter salvare
    il risultato su file e stamparlo a video */
    concatenaStringhe(output, argc, argv, cont, charRicerca);

    /* trovo il file altrimenti lo creo */
    fd = open(argv[argc-1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    write(fd, output, strlen(output));
    close(fd);
    write(1, output, strlen(output));

    return 0;
}