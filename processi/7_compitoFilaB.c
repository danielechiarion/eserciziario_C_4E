/* struttura dei processi:
- P1 genera due figli P2 e P3

- P2 genera due figli P4 e P5
    * P4 visualizza il conto alla rovescia da 0 a n con ritardo di 1s
    * P5 visualizza il conto progressivo da 0 a n con ritardo di un 1s

- P3 genera un figlio P6:
    * P6 calcola il quadrato e lo restituisce a P3 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char *argv[])
{
    /* dichiarazione variabili e costanti */
    int n;
    const int minValue = 0, maxValue = 10;

    /* richiedo l'input all'utente */
    do
    {
        printf("Inserisci un numero compreso tra %d e %d: ", minValue, maxValue);
        scanf("%d", &n);
    } while (n < minValue || n > maxValue);

    /* creazione dei processi */
    int p2 = fork();
    if (p2 == 0) // figlio P2
    {
        printf("\nP2: mio PID = %d mio padre P1 ha PID = %d\n", getpid(), getppid());
        int p4 = fork();
        if (p4 == 0) // figlio P4
        {
            printf("\nP4: mio PID = %d mio padre P2 ha PID = %d\n", getpid(), getppid());
            /* faccio il conto alla rovescia a partire da n */
            printf("P4: conto alla rovescia da %d:\t", n);
            for (int i = n; i >= 0; i--)
            {
                printf("%d\t", i);
                sleep(1);
            }
            printf("\n");
            exit(0);
        }
        else if (p4 > 0) // padre P2
        {
            printf("\nP2: mio PID = %d mio figlio P4 ha PID = %d\n", getpid(), p4);
            int p5 = fork();
            if (p5 == 0) // figlio P5
            {
                printf("\nP5: mio PID = %d mio padre P2 ha PID = %d\n", getpid(), getppid());
                /* faccio il conto progressivo da 0 a n */
                printf("\nP5: conto progressivo fino a %d:\t", n);
                for (int i = 0; i <= n; i++)
                {
                    printf("%d\t", i);
                    sleep(1);
                }
                printf("\n");
                exit(0); // esco dal processo
            }
            else if (p5 > 0) // padre P2
            {
                printf("\nP2: mio PID = %d mio figlio P5 ha PID = %d\n", getpid(), p5);
                while (wait(NULL) > 0)
                    ;
                exit(0);
            }
            else
            {
                printf("\nProcesso P5 non generato correttamente\n");
            }
        }
        else
        {
            printf("\nProcesso P4 non generato correttamente\n");
        }
    }
    else if (p2 > 0) // padre P1
    {
        printf("\nP1: mio PID = %d mio figlio P2 ha PID = %d\n", getpid(), p2);
        int p3 = fork();
        if (p3 == 0) // figlio P3
        {
            printf("\nP3: mio PID = %d mio padre P1 ha PID = %d\n", getpid(), getppid());
            int p6 = fork();
            if (p6 == 0) // figlio P6
            {
                printf("\nP6: mio PID = %d mio padre P3 ha PID = %d\n", getpid(), getppid());
                exit(n * n); // esco con il quadrato di n
            }
            else if (p6 > 0) // padre P3
            {
                int statusP6;
                printf("\nP3: mio PID = %d mio figlio P6 ha PID = %d\n", getpid(), p6);
                wait(&statusP6);
                printf("\nP3: quadrato di %d = %d\n", n, WEXITSTATUS(statusP6));
                exit(0);
            }
            else
            {
                printf("\nProcesso P6 non generato correttamente\n");
            }
        }
        else if (p3 > 0) // padre P1
        {
            printf("\nP1: mio PID = %d mio figlio P3 ha PID = %d\n", getpid(), p3);
            while (wait(NULL) > 0)
                ; // attendo la terminazione dei figli P2 e P3
        }
        else
        {
            printf("\nProcesso P2 non generato correttamente\n");
        }
    }
    else
    {
        printf("\nProcesso P2 non generato correttamente\n");
    }

    return 0;
}