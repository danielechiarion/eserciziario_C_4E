/* Scrivi il codice sorgente di un programma in cui il processo padre genera tre processi figli.
Ciascun processo deve visualizzare sullo schermo, rispettivamente

_ Sono il processo padre , il mio PID=... mio figlio...ha PID=...
_ Sono un processo figlio , il mio PID=... , mio padre ha PID=..., "Ciao sono Qui"
_ Sono un processo figlio , il mio PID=... , mio padre ha PID=..., "Ciao sono Quo"
_ Sono unl processo figlio , il mio PID=... , mio padre ha PID=..., "Ciao sono Qua" */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    /* dichiarazione variabile */
    int p1, p2, p3;

    /* genero un processo figlio da p1 */
    p1 = fork();
    if (p1 == 0)
    {
        printf("\n\nCiao sono Qui");
        printf("\nmio PID: %d\tPID di mio padre: %d", getpid(), getppid());
    }
    else if (p1 > 0)
    {
        /* dettagli del padre */
        printf("\n\nCiao, sono Paperino");
        printf("\nmio PID: %d\tPID di mio figlio: %d", getpid(), p1);
        fflush(stdout); //svuoto il buffer

        /* genero il secondo figlio */
        p2 = fork();
        if (p2 == 0)
        {
            printf("\n\nCiao sono Quo");
            printf("\nmio PID: %d\tPID di mio padre: %d", getpid(), getppid());
        }
        else if (p2 > 0)
        {
            /* genero il terzo figlio */
            p3 = fork();
            if (p3 == 0)
            {
                printf("\n\nCiao sono Qua");
                printf("\nmio PID: %d\tPID di mio padre: %d", getpid(), getppid());
            }
        }
    }

    return 0;
}