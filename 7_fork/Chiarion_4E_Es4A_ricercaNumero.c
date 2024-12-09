/* Scriva un programma C che dato un array prestabilito, prenda in input da
riga di comando un numero e lo ricerchi all'interno dell'array.
La ricerca deve essere demandata ad un processo figlio e deve essere
implementata attraverso un'apposita funzione di nome ricerca. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* metodo che ricerca un numero
all'interno di un array */
int ricerca(int array[], int arraySize, int num){
    for(int i=0; i<arraySize; i++){
        if(array[i] == num){
            return i;
        }
    }

    return -1;
}

int main(int argc, char *argv[]){
    int p = fork(); //creo il processo figlio

    if(p==0) //figlio
    {
        
    }

    return 0;
}