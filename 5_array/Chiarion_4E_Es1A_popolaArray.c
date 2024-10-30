/* Popolare un array di interi di dimensione 4, stamparne a video il
contenuto. */

#include <stdio.h>

int main(int argc, char *argv[])
{
    /* dichiaro un array di dimensione
    stabilita a priori */
    const int dimArray = 4;
    int array[dimArray];

    /* popolo l'array e
    stampo il contenuto */
    for (int i = 0; i < dimArray; i++)
    {
        array[i] = i + 1;
        printf("%d\t", array[i]);
    }

    return 0;
}