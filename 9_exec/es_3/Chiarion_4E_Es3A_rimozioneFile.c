/* Scrivere un programma in linguaggio C che usa il comando
della shell rm per eliminare tutti files presenti
nell'intervallo [argv[1], argv[argc-1]]

esempio:
$ ./a.out /tmp/1.txt /tmp/3.txt /tmp/2.txt */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    /* controllo che ci sia un numero
    di argomenti minimo che possa eliminare il file */
    if (argc < 2)
    {
        printf("Numero di argomenti insufficiente\n");
        exit(0);
    }

    int pid1 = getpid();
    int gruppoPID[argc - 2];
    for (int i = 1; i < argc && getpid() == pid1; i++)
    {
        gruppoPID[i - 1] = fork();
        if (gruppoPID[i - 1] == 0)
        {
            execl("/usr/bin/rm", "rm", argv[i], NULL);
            exit(0);
        }
    }

    /* il padre aspetta tutti i figli */
    for(int i=0;i<argc-2;i++){
        wait(NULL);
    }

    return 0;
}