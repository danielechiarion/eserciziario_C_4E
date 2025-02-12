/* Scrivere un programma in linguaggio C che usa il comando 
della shell rm per eliminare tutti files presenti
nell'intervallo [argv[1], argv[argc-1]]

esempio:
$ ./a.out /tmp/1.txt /tmp/3.txt /tmp/2.txt */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    /* controllo che ci sia un numero
    di argomenti minimo che possa eliminare il file */
    if(argc<2){
        printf("Numero di argomenti insufficiente\n");
        exit(0);
    }

    int pid1 = getpid();
    for(int i=1;i<argc && getpid()==pid1;i++){
        int p = fork();
        if(p==0){
            execl("/usr/bin/rm", "rm", argv[i], NULL);
            exit(0);
        }
    }
    
    return 0;
}