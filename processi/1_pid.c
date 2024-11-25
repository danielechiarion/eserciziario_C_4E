#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int p = fork();
    /* se p>0 l'output è del processo padre*/
    if (p > 0)
    {
        printf("\nSono il padre con pid: %d", getpid());
        printf("\nIl pid del figlio e': %d", p);
    }
    else if (p == 0)
    { // altrimenti si ha un processo figlio
        printf("\nSono il figlio con pid: %d", getpid());
        printf("\nIl pid di mio padre e': %d", getppid());
    }
    else
    {
        printf("Errore di generazione del processo figlio");
    }

    return 0;
}