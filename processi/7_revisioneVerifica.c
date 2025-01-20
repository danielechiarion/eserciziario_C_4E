/* stuttura PROCESSI

              P1
          /        \
        P2          P3
      /    \         |
    P4      P5      P6*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

/* funzione che popola l'array con numeri random
casuali */
void numeriRandomArray(int array[], int size, int minValue, int maxValue)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        array[i] = minValue + (rand() % (maxValue - minValue + 1));
    }
}

/* funzione che calcola il prodotto delle componenti dell'array */
int prodottoComponenti(int array[], int size)
{
    int prodotto = 1; // così non abbiamo errori nella moltiplicazione

    for (int i = 0; i < size; i++)
    {
        prodotto *= array[i];
    }

    return prodotto;
}

/* funzione che ritorna la somma delle componenti di un array */
int sommaComponenti(int array[], int size)
{
    int somma = 0;
    for (int i = 0; i < size; i++)
    {
        somma += array[i];
    }

    return somma;
}

/* funzione che calcola la media delle componenti in un array */
double mediaComponenti(int array[], int size)
{
    return (double)sommaComponenti(array, size) / size;
}

/* metodo che stampa le componenti di un array */
void stampaComponenti(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
}

int main(int argc, char *argv[])
{
    int array[3];
    int size = sizeof(array) / sizeof(array[0]);
    numeriRandomArray(array, size, 1, 5);
    stampaComponenti(array, size);

    int p2 = fork();
    if (p2 == 0) // figlio P2
    {
        printf("\nP2: mio PID: %d Mio padre P1 ha pid: %d\n", getpid(), getppid());
        int p4 = fork();
        if (p4 == 0) // figlio P4
        {
            printf("\nP4: mio PID: %d Mio padre P2 ha pid: %d\n", getpid(), getppid());
            printf("\nP4: il prodotto delle componenti e' %d\n", prodottoComponenti(array, size));
            exit(0);
        }
        else if (p4 > 0) // padre P2
        {
            printf("\nP2: mio PID: %d Mio figlio P4 ha pid: %d\n", getpid(), p4);
            int p5 = fork();
            if (p5 == 0) // figlio P5
            {
                printf("\nP5: mio PID: %d Mio padre P2 ha pid: %d\n", getpid(), getppid());
                printf("\nP5: la media delle componenti e' %.2f\n", mediaComponenti(array, size));
                exit(0);
            }
            else if (p5 > 0) // padre P2
            {
                printf("\nP2: mio PID: %d Mio figlio P5 ha pid: %d\n", getpid(), p5);
                while (wait(NULL) > 0)
                    ;    // attendo che tutti i processi di P2 terminino
                exit(0); // esco da P2
            }
            else
            {
                printf("\nIl processo P5 non e' stato generato correttamente\n");
            }
        }
        else
        {
            printf("\nIl processo P4 non e' stato generato correttamente\n");
        }
    }
    else if (p2 > 0) // padre P1
    {
        printf("\nP1: mio PID: %d Mio figlio P2 ha pid: %d\n", getpid(), p2);
        int p3 = fork();
        if (p3 == 0) // figlio P3
        {
            printf("\nP3: mio PID: %d Mio padre P1 ha pid: %d\n", getpid(), getppid());
            int p6 = fork();
            if (p6 == 0) // figlio P6
            {
                printf("\nP6: mio PID: %d Mio padre P3 ha pid: %d\n", getpid(), getppid());
                exit(sommaComponenti(array, size)); // ritorna il valore della somma quando esce
            }
            else if (p6 > 0) // padre P3
            {
                int statusP6;
                printf("\nP3: mio PID: %d Mio figlio P6 ha pid: %d\n", getpid(), p6);
                wait(&statusP6);
                printf("\nP3: la somma delle componenti e' %d\n", WEXITSTATUS(statusP6));
                exit(0);
            }
            else
            {
                printf("\nIl processo P6 non e' stato generato correttamente\n");
            }
        }
        else if (p3 > 0) // padre P1
        {
            printf("\nP1: mio PID: %d Mio figlio P3 ha pid: %d\n", getpid(), p3);
            while (wait(NULL) > 0)
                ; // attendo che terminino tutti i figli di P1
        }
        else
        {
            printf("\nIl processo P3 non e' stato generato correttamente\n");
        }
    }
    else
    {
        printf("\nIl processo P2 non e' stato generato correttamente\n");
    }

    return 0;
}