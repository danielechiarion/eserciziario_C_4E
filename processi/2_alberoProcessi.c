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
    int pid1, pid2, pid3, pid4, pid5, pid6;
    int ppid1, ppid2, ppid3, ppid4, ppid5, ppid6;

    pid1 = getpid();
    ppid1 = getppid();
    /* creo il primo fork per ottenere p2 */
    int p1 = fork();
    if (p1 == 0)
    {
        pid2 = getpid();
        ppid2 = getppid();
    }
    else if (p1 > 0)
    {
        /* creo il secondo fork per ottenere p3,
        che è figlio di p2 */
        int p2 = fork();
        if (p2 == 0)
        {
            pid3 = getpid();
            ppid3 = getppid();
        }
    }

    /* se il pid è uguale a 2 genero p4 */
    if (getpid() == pid2)
    {
        int p3 = fork();
        if (p3 == 0)
        {
            pid4 = getpid();
            ppid4 = getppid();
        }
    }

    /* se il pid è uguale a p3 genero
    prima p5 */
    if (getpid() == pid3)
    {
        int p4 = fork();
        if (p4 == 0)
        {
            pid5 = getpid();
            ppid5 = getppid();
        }
        else if (p4 > 0)
        {
            /* se mi trovo nel processo padre p3 genero
            anche il processo figlio p6 */
            int p5 = fork();
            if (p5 == 0)
            {
                pid6 = getpid();
                ppid6 = getppid();
            }
        }
    }

    /* restituisco i risultati */
    int pidOutput, ppidOutput;
    printf("\n\n");
    if (getpid() == pid1)
    {
        printf("\n\nPROCESSO PADRE");
        pidOutput = pid1;
        ppidOutput = ppid1;
    }
    else if (getpid() == pid2)
    {
        printf("\n\nPROCESSO P2");
        pidOutput = pid2;
        ppidOutput = ppid2;
    }
    else if (getpid() == pid3)
    {
        printf("\n\nPROCESSO P3");
        pidOutput = pid3;
        ppidOutput = ppid3;
    }
    else if (getpid() == pid4)
    {
        printf("\n\nPROCESSO P4");
        pidOutput = pid4;
        ppidOutput = ppid4;
    }
    else if (getpid() == pid5)
    {
        printf("\n\nPROCESSO P5");
        pidOutput = pid5;
        ppidOutput = ppid5;
    }
    else if (getpid() == pid6)
    {
        printf("\n\nPROCESSO P6");
        pidOutput = pid6;
        ppidOutput = ppid6;
    }
    else
    {
        printf("\n\nProcesso non identificato");
        exit(1);
    }

    printf("\nIl pid del processo e': %d", pidOutput);
    printf("\nIl pid del processo padre e': %d", ppidOutput);

    /* chiudo tutti i processi creati,
    selezionando singolarmente tutti i processi */
    if (getpid() == pid2)
    {
        exit(0);
    }
    else if (getpid() == pid3)
    {
        exit(0);
    }
    else if (getpid() == pid4)
    {
        exit(0);
    }
    else if (getpid() == pid5)
    {
        exit(0);
    }
    else if (getpid() == pid6)
    {
        exit(0);
    }

    return 0;
}