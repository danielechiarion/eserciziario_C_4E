/* Scrivi un programma che legge da argv[1] un numero intero positivo (N) e poi
disegna a terminale un quadrato vuoto composto di asterischi (‘*’)
con il lato lungo N:

Per N pari a 3 il programma stampa:

***
* *
***
Per N pari a 5 il programma stampa:

*****
*   *
*   *
*   *
***** */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        exit(0);
    }

    int n = atoi(argv[1]); // ricavo il numero inserito in argv

    if (n <= 0)
    {
        exit(0);
    }

    for (int i = 0; i < n; i++)
    {
        printf("*");
        for (int j = 0; j < n - 2; j++)
        {
            if (i == 0 || i == n - 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("*\n");
    }

    return 0;
}