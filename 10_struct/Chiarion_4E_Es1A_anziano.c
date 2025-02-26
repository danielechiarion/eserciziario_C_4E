/* dati 3 array:
    char *names[] = {"Luca","Lorenzo","Davide", "Luca"};
    char *surnames[] = {"Montini","Canali","Fiorini", "Greggio"};
    int age[] = {22,24,24,26};

mostrare in output il nome della persona più vecchia */

#include <stdio.h>
#include <string.h>

typedef struct
{
    int eta;
    char nome[50];
    char cognome[50];
} persona_t;

void popolaArrayPersone(persona_t array[], char *nomi[], char *cognomi[], int eta[], int size)
{
    for (int i = 0; i < size; i++)
    {
        strcpy(array[i].nome, nomi[i]);
        strcpy(array[i].cognome, cognomi[i]);

        array[i].eta = eta[i];
    }
}

int personaPiuVecchia(persona_t array[], int size)
{
    int pos = 0;

    for (int i = 1; i < size; i++)
    {
        if (array[i].eta > array[pos].eta)
            pos = i;
    }

    return pos;
}

int main(int argc, char *argv[])
{
    /* definisco la dimensione */
    const int DIM = 4;

    /* dati di partenza*/
    char *names[] = {"Luca", "Lorenzo", "Davide", "Luca"};
    char *surnames[] = {"Montini", "Canali", "Fiorini", "Greggio"};
    int age[] = {22, 24, 24, 26};
    persona_t arrayPersone[DIM];

    /* popolo array è ritorno il risultato */
    popolaArrayPersone(arrayPersone, names, surnames, age, DIM);
    int posRisultato = personaPiuVecchia(arrayPersone, DIM);

    /* restituisco il risultato */
    printf("La persona piu' vecchia e' %s %s", arrayPersone[posRisultato].nome, arrayPersone[posRisultato].cognome);

    return 0;
}