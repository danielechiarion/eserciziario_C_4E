/* Data una classe di 4 studenti, si vuole visualizzare il nome e il cognome
dello studente con la media più alta. Le materie su cui calcolare la
media sono: italiano, storia, informatica. Per ogni materia si memorizzi
la coppia di valori [nome materia , voto].
Possono essere utili le seguenti strutture dati:

typedef struct{
    char nome[20];
    int voto;
} materia_t;

typedef struct{
    char nome[20];
    char cognome[20];
    materia_t materie[3];
} studente_t;

Per accedere ad una struttura dati annidata vale la seguente sintassi:
studente.materie[i].voto
studente.materie[i].nome */

#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[20];
    double voto;
} materia_t;

typedef struct
{
    char nome[20];
    char cognome[20];
    materia_t materie[3];
} studente_t;

double calcolaMedia(materia_t materie[], int size)
{
    double somma = 0;

    for (int i = 0; i < size; i++)
    {
        somma += materie[i].voto;
    }

    return somma / size;
}

int mediaPiuAlta(studente_t arrayStudenti[], int size)
{
    int pos = 0;

    for (int i = 1; i < size; i++)
    {
        /* si confronta se la media dello studente nella posizione corrente
        è maggiore di quella che ha lo studente nella posizione attualmente salvata */
        if (calcolaMedia(arrayStudenti[i].materie, 3) > calcolaMedia(arrayStudenti[pos].materie, 3))
        {
            pos = i;
        }
    }

    return pos;
}

void popolaArray(studente_t arrayStudenti[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("\n\nStudente %d\n", i + 1);
        printf("Inserisci nome: ");
        scanf("%s", arrayStudenti[i].nome);
        printf("Inserisci cognome: ");
        scanf("%s", arrayStudenti[i].cognome);
        for (int j = 0; j < 3; j++)
        {
            printf("Inserisci voto materia: ");
            scanf("%f", &arrayStudenti[i].materie[j].voto);
        }

        /* per ogni materia inserisco il nome */
        strcpy(arrayStudenti[i].materie[0].nome, "italiano");
        strcpy(arrayStudenti[i].materie[1].nome, "storia");
        strcpy(arrayStudenti[i].materie[0].nome, "informatica");
    }
}

int main(int argc, char *argv[])
{
    /* definizione costanti */
    const int DIM = 3;
    studente_t classe[DIM];

    /* definisco la classe di studenti */
    popolaArray(classe, DIM);

    /* calcola la media più alta
    e mi calcolo il risultato */
    int posRisultato = mediaPiuAlta(classe, DIM);
    printf("Lo studente con la media piu' alta e' %s %s", classe[posRisultato].nome, classe[posRisultato].cognome);

    return 0;
}