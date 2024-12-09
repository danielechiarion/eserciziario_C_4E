#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    /* dichiarazione variabili */
    int status, p;

    p = fork();
    if (p == 0) // figlio
    {
        printf("\nSono il figlio con PID = %d\tMio padre ha PID = %d\n", getpid(), getppid());
        exit(25);
    }
    else // padre
    {
        printf("\nSono il padre con PID = %d\tMio figlio ha PID = %d\n", getpid(), p);
        printf("\nAspetto che mio figlio con PID = %d termini\n", wait(&status));

        printf("\n\nIl valore exit del figlio e' = %d\n", WEXITSTATUS(status));

        /* se provi a riscrivere il pid del figlio lo vede
        con la variabile p ma non con il ritorno del wait,
        in quanto il figlio è già terminato */
        printf("\nSono di nuovo il padre con PID = %d\tMio figlio ha PID = %d\n", getpid(), p);
        printf("\nAspetto che mio figlio con PID = %d termini\n", wait(&status));

        printf("\n\nIl valore exit del figlio e' = %d\n", WEXITSTATUS(status));
    }

    return 0;
}