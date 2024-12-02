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
    printf("PADRE - P1 PID = %d\n", getpid());
    int p2 = fork();

    if (p2 == 0) // figlio P2
    {
        printf("\nFIGLIO - P2 PID = %d Mio padre ha PID = %d\n", getpid(), getppid());
        int p4 = fork();
        if (p4 == 0)
        { // figlio P4
            printf("\nFIGLIO - P4 PID = %d Mio padre ha PID = %d\n", getpid(), getppid());
        }
        else if (p4 > 0)
        { // padre P2
            printf("\nSono padre P2 PID = %d - mio figlio P4 ha PID %d\n", getpid(), p4);
        }
        else
        {
            printf("\nP4 non generato correttamente\n");
        }
    }
    else if (p2 > 0) // padre P1
    {
        printf("\nSono padre P1 PID = %d - mio figlio P2 ha PID %d\n", getpid(), p2);
        int p3 = fork();

        if (p3 == 0) // figlio P3
        {
            printf("\nFIGLIO - P3 PID = %d Mio padre ha PID = %d\n", getpid(), getppid());
            int p5 = fork();
            if (p5 == 0) // figlio p5
            {
                printf("\nFIGLIO - P5 PID = %d Mio padre ha PID = %d\n", getpid(), getppid());
            }
            else if (p5 > 0) // padre p3
            {
                printf("\nSono padre P3 PID = %d - mio figlio P5 ha PID %d\n", getpid(), p5);
                int p6 = fork();
                if (p6 == 0) // figlio P6
                {
                    printf("\nFIGLIO - P6 PID = %d Mio padre ha PID = %d\n", getpid(), getppid());
                }
                else if (p6 > 0) // padre P3
                {
                    printf("\nSono padre P3 PID = %d - mio figlio P6 ha PID %d mio padre ha pid = %d\n", getpid(), p6, getppid());
                }
                else
                {
                    printf("\nP6 non generato correttamente\n");
                }
            }
            else
            {
                printf("\nP4 non generato correttamente\n");
            }
        }
        else if (p3 > 0) // padre P1
        {
            printf("\nSono padre P1 PID = %d - mio figlio P3 ha PID %d\n", getpid(), p3);
        }
        else
        {
            printf("\nP3 non generato correttamente\n");
        }
    }
    else
    {
        printf("\nP2 non generato correttamente\n");
    }

    return 0;
}