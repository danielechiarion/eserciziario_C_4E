/* Scrivi il codice sorgente di un prg in cui
   il processo padre P genera due processi figli: F1 e F2.
   F1 somma 1+2;
   F2 somma 3+4.
   Entrambi restituiscono al processo padre P il risultato ottenuto dall'operazione compiuta.
   Padre P somma tra loro i risultati che i due figli gli hanno restituito e
   visalizza il valore di tale somma.

   La prima cosa che ciascun processo deve fare, appena genera un processo figlio,
   Ã¨ dichiararsi nel modo seguente:
   "P: mio PID=..., mio figlio F1 ha PID=...
   La prima cosa che ciascun processo figlio deve fare appena Ã¨ stato generato,
   Ã¨ dichiararsi nel modo seguente:
   "F1: mio PID=..., mio padre P ha PID=..."

   Ogni volta che un processo visualizza qualcosa sullo schermo deve dichiararsi nel modo seguente:
   "P: quello che P deve visualizzare"
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int somma = 0;
    int status;

    int f1 = fork();
    if (f1 == 0) // figlio F1
    {
        printf("\nF1: mio PID=%d, mio padre P ha PID=%d\n", getpid(), getppid());
        exit(1 + 2);
    }
    else if (f1 > 0) // padre P
    {
        printf("\nP: mio PID=%d, mio figlio F1 ha PID=%d\n", getpid(), f1);
        int f2 = fork();
        if (f2 == 0) // figlio F2
        {
            printf("\nF2: mio PID=%d, mio padre P ha PID=%d\n", getpid(), getppid());
            exit(3 + 4);
        }
        else if (f2 > 0) // padre P
        {
            printf("\nP: mio PID=%d, mio figlio F2 ha PID=%d\n", getpid(), f2);
            /* uso waitpid per esercitarmi con l'utilizzo della funzione*/
            waitpid(f1, &status, 1);
            somma += WEXITSTATUS(status);
            waitpid(f2, &status, 2);
            somma += WEXITSTATUS(status);
        }
        else
        {
            printf("\nF2 non generato correttamente\n");
        }

        printf("\nLa somma dei valori e': %d", somma);
    }
    else
    {
        printf("\nF1 non generato correttamente\n");
    }

    return 0;
}