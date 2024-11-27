/* Scrivi il codice sorgente di un programma che permette al processo padre di generare un processo figlio:
_ sia padre che figlio visualizzano il proprio PID e il PID del proprio parente
_ padre conta da 0 a 19 (visualizza i numeri da 0 a 19)
_  padre conta da 0 a 9 (visualizza i numeri da 0 a 9)
Manda in esecuzione più volte e descrivi il comportamento del programma */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    /* dichiarazione variabili */
    int pCorrente;

    /* genero un processo figlio */
    pCorrente = fork();

    /* il processo padre conta da 0 a 19 */
    if (pCorrente > 0)
    {
        /* dettagli del processo */
        printf("\n\nPROCESSO PADRE");
        printf("\nPID: %d\tPPID: %d", getpid(), getppid());

        /* output valori da 0 a 19*/
        printf("\n");
        for (int i = 0; i < 20; i++)
        {
            printf("%d\t", i);
        }
    }
    else if (pCorrente == 0)
    {
        /* dettagli del processo */
        printf("\n\nPROCESSO FIGLIO");
        printf("\nPID: %d\tPPID: %d", getpid(), getppid());

        /* output valori da 0 a 9 */
        printf("\n");
        for (int i = 0; i < 10; i++)
        {
            printf("%d\t", i);
        }

        exit(0);
    }

    return 0;
}

/* durante la fase di esecuzione può essere eseguito prima
il processo padre del processo figlio o viceversa.
Se viene eseguito prima il padre il PPID del processo figlio
non corrisponde */