/* Scrivi il codice sorgente di un prg in cui
   il processo padre P genera due figli: F1 e  F2.

   A F1 assegna un tempo t di sleep(t) (ritardo) 2 secondi;
   F1 deve restituire al padre P il numero 2.
   A F2 assegna un tempo t di sleep(t) (ritardo) 4 secondi;
   F2 deve restituire al padre P il numero 4.

   Padre P deve attendere la terminazione del figlio che dorme di più, ossia F2, e
   deve scrivere quanti secondi ha dormito tale figlio.

   La prima cosa che ciascun processo deve fare, appena genera un processo figlio,
   è dichiararsi nel modo seguente:
   "P: mio PID=..., mio figlio F1 ha PID=...
   La prima cosa che ciascun processo figlio deve fare appena è stato generato,
   è dichiararsi nel modo seguente:
   "F1: mio PID=..., mio padre P ha PID=..."

   Ogni volta che un processo visualizza qualcosa sullo schermo deve dichiararsi nel modo seguente:
   "P: quello che P deve visualizzare"
   "..."Scrivi il codice sorgente di un prg in cui
   il processo padre P genera due figli: F1 e  F2.

   A F1 assegna un tempo t di sleep(t) (ritardo) 2 secondi;
   F1 deve restituire al padre P il numero 2.
   A F2 assegna un tempo t di sleep(t) (ritardo) 4 secondi;
   F2 deve restituire al padre P il numero 4.

   Padre P deve attendere la terminazione del figlio che dorme di più, ossia F2, e
   deve scrivere quanti secondi ha dormito tale figlio.

   La prima cosa che ciascun processo deve fare, appena genera un processo figlio,
   è dichiararsi nel modo seguente:
   "P: mio PID=..., mio figlio F1 ha PID=...
   La prima cosa che ciascun processo figlio deve fare appena è stato generato,
   è dichiararsi nel modo seguente:
   "F1: mio PID=..., mio padre P ha PID=..."

   Ogni volta che un processo visualizza qualcosa sullo schermo deve dichiararsi nel modo seguente:
   "P: quello che P deve visualizzare"
   "..."*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int status;

    int f1 = fork();
    if (f1 == 0) // figlio F1
    {
        printf("\nF1: mio PID=%d, mio padre P ha PID=%d\n", getpid(), getppid());
        int attesa = 2;
        sleep(attesa);
        exit(attesa);
    }
    else if (f1 > 0) // padre P
    {
        printf("\nP: mio PID=%d, mio figlio F1 ha PID=%d\n", getpid(), f1);
        int f2 = fork();
        if (f2 == 0) // figlio F2
        {
            printf("\nF2: mio PID=%d, mio padre P ha PID=%d\n", getpid(), getppid());
            int attesa = 4;
            sleep(attesa);
            exit(attesa);
        }
        else if (f2 > 0) // padre P
        {
            printf("\nP: mio PID=%d, mio figlio F2 ha PID=%d\n", getpid(), f2);
            /* uso waitpid perchè voglio decidere quale processo
            visualizzare prima */
            waitpid(f2, &status, 0); //occorre mettere sempre 0
            printf("\nP: Il figlio F2 ha dormito %d secondi", WEXITSTATUS(status));
        }
        else
        {
            printf("\nF2 non generato correttamente\n");
        }
    }
    else
    {
        printf("\nF1 non generato correttamente\n");
    }

    return 0;
}