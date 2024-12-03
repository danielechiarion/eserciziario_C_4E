/* scrivere il codice sorgente di un programma
che generi dei processi seguendo la struttura indicata.

- con P1 si indica il processo padre
- P1 genera come figli P2 e P3
- P3 genera come figli P4, P5 e P6
- P5 genera come figlio P7 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    /* stampo le informazioni sul processo padre */
    printf("PADRE P1\tPID: %d", getpid());
    fflush(stdout);

    int p2 = fork();
    if (p2 == 0) // figlio P2
    {
        printf("\nFIGLIO P2\tPID: %d\tPID padre: %d\n", getpid(), getppid());
        exit(2);
    }
    else if (p2 > 0) // padre P1
    {
        printf("\nPADRE P1\tPID: %d\tPID figlio P2: %d\n", getpid(), p2);
        int p3 = fork();
        if (p3 == 0) // figlio P3
        {
            printf("\nFIGLIO P3\tPID: %d\tPID padre: %d\n", getpid(), getppid());
            int p4 = fork();
            if (p4 == 0) // figlio P4
            {
                printf("\nFIGLIO P4\tPID: %d\tPID padre: %d\n", getpid(), getppid());
                exit(2);
            }
            else if (p4 > 0) // padre P3
            {
                printf("\nPADRE P3\tPID: %d\tPID figlio P4: %d\n", getpid(), p4);
                int p5 = fork();
                if (p5 == 0) // figlio P5
                {
                    printf("\nFIGLIO P5\tPID: %d\tPID padre: %d\n", getpid(), getppid());
                    int p7 = fork();
                    if (p7 == 0) // figlio P7
                    {
                        printf("\nFIGLIO P7\tPID: %d\tPID padre: %d\n", getpid(), getppid());
                        exit(2);
                    }
                    else if (p7 > 0) // padre P5
                    {
                        printf("\nPADRE P5\tPID: %d\tPID figlio P7: %d\n", getpid(), p7);
                        while (wait(NULL) > 0); // aspetto che escano tutti i processi
                        exit(2);
                    }
                    else
                    {
                        printf("\nProcesso P7 non generato correttamente\n");
                    }
                }
                else if (p5 > 0) // padre P3
                {
                    printf("\nPADRE P3\tPID: %d\tPID figlio P5: %d\n", getpid(), p5);
                    int p6 = fork();
                    if (p6 == 0) // figlio P6
                    {
                        printf("\nFIGLIO P6\tPID: %d\tPID padre: %d\n", getpid(), getppid());
                        exit(2);
                    }
                    else if (p6 > 0) // padre P3
                    {
                        printf("\nPADRE P3\tPID: %d\tPID figlio P6: %d\n", getpid(), p6);
                        while (wait(NULL) > 0); //aspetto la terminazione dei figli
                        exit(2);
                    }
                    else
                    {
                        printf("\nProcesso P6 non generato correttamente\n");
                    }
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
        else if (p3 > 0) // padre P1
        {
            printf("\nPADRE P1\tPID: %d\tPID figlio P3: %d\n", getpid(), p3);
            while (wait(NULL) > 0); // attendo la terminazione di tutti i figli
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