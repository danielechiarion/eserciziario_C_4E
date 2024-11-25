#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* la generazione dei processi deve seguire
il diagramma:
- P1 è il padre
- P1 genera a sua volta P2 e P3
- P2 genera P4
- P3 genera a sua volta P5 e P6 */
int main(int argc, char *argv[])
{
    /* dichiarazione variabili */
    int pCorrente, pid1, pid2, pid3, pid4, pid5, pid6;
    int ppid1, ppid2, ppid3, ppid4, ppid5, ppid6;

    /* prima creo il processo p2 da p1 */
    pid1 = getpid();
    ppid1 = getppid();
    pCorrente = fork();
    if (pCorrente == 0)
    {
        pid2 = getpid();
        ppid2 = getppid();
    }

    /* creo poi il processo p3, copiando il pid */
    if (pCorrente > 0)
    {
        pCorrente = fork();
        if (pCorrente == 0)
        {
            pid3 = getpid();
            ppid3 = getppid();
        }
    }

    /* dal processo p2 creo il processo p4 */
    if (getpid() == pid2)
    {
        pCorrente = fork();
        if (pCorrente == 0)
        {
            pid4 = getpid();
            ppid4 = getppid();
        }
    }

    /* dal processo p3 genera il genero prima
    p5 e poi p6 */
    if (getpid() == 3)
    {
        pCorrente = fork();
        if (pCorrente == 0)
        {
            pid5 = getpid();
            ppid5 = getppid();
        }
    }

    if (getpid() == 3)
    {
        pCorrente = fork();
        if (pCorrente == 0)
        {
            pid6 = getpid();
            ppid6 = getppid();
        }
    }

    /* output dei risultati,
    per ognuno scrivo padre e figlio */
    if (getpid() == pid1)
    {
        printf("PID processo 1: %d", pid1);
        printf("\n\nPID processo 2: %d", pid2);
        printf("\nProcesso padre: %d", ppid2);
        printf("\n\nPID processo 3: %d", pid3);
        printf("\nProcesso padre: %d", ppid3);
        printf("\n\nPID processo 4: %d", pid4);
        printf("\nProcesso padre: %d", ppid4);
        printf("\n\nPID processo 5: %d", pid5);
        printf("\nProcesso padre: %d", ppid5);
        printf("\n\nPID processo 6: %d", pid6);
        printf("\nProcesso padre: %d", ppid6);
    }
    return 0;
}