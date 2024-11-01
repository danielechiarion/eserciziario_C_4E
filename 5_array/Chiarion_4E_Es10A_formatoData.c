/* Si scriva un programma che legga da riga di comando una stringa di 8 numeri
che rappresenta la data di nascita di uno studente, si verifichi che gli 8 numeri
siano coerenti con il formato di una data, quindi i primi 2 caratteri non devono
essere maggiori di 31, la seconda coppia di caretteri non deve essere maggiore da 12
e i restanti 4 caratteri non devono essere maggiori dell'anno corrente.
Si stampi a video la data nel seguente formato: %d/%m/%Y */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* funzione che separa una data scritta in formato stringa
in un array di 3 elementi */
void separaData(char stringa[], int array[])
{
    /* dichiarazione array per contenere le
    porzioni di stringa */
    char giorno[5], mese[5], anno[5];

    /* ricavo le varie porzioni della stringa */
    strncpy(giorno, stringa, 2); // copio il giorno
    giorno[2] = '\0';
    strncpy(mese, stringa + 2, 2); // copio il mese
    mese[2] = '\0';
    strncpy(anno, stringa + 4, 4); // copio l'anno
    anno[4] = '\0';

    /* converto le porzioni di stringa in numeri interi */
    array[0] = atoi(giorno);
    array[1] = atoi(mese);
    array[2] = atoi(anno);
}

/* funzione che ritorna se l'anno
è bisestile */
bool isAnnoBisestile(int anno)
{
    if ((anno % 4 == 0 && anno % 100 != 0) || anno % 400 == 0)
    {
        return true;
    }

    return false;
}

/* funzione che ritorna per mese
il numero di giorni preciso */
int giorniPerMese(int array[])
{
    int giorno;

    switch (array[1])
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        giorno = 31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        giorno = 30;
        break;

    case 2:
        if (isAnnoBisestile(array[2]))
        {
            giorno = 29;
        }
        else
        {
            giorno = 28;
        }
        break;
    }

    return giorno;
}

/* funzione che controlla se la data è valida */
bool isDataValida(int array[])
{
    bool check = true;

    /* controllo che il giorno vada da
    1 al numero massimo di giorni in quel mese*/
    if (array[0] < 1 || array[0] > giorniPerMese(array))
    {
        check = false;
    }
    /* controllo che il mese sia compreso tra 1 e 12 */
    if (array[1] < 1 || array[1] > 12)
    {
        check = false;
    }
    /* controllo che l'anno sia minore o uguale di
    quello corrente */
    if (array[2] > 2024)
    {
        check = false;
    }

    return check;
}

int main(int argc, char *argv[])
{
    /* controllo prima che il numero di argomenti
    sia valido */
    if (argc != 2)
    {
        printf("Numero di argomenti non valido");
        exit(0);
    }
    /* controllo anche che la data sia composta
    da 8 caratteri */
    if (strlen(argv[1]) != 8)
    {
        printf("Numero di cifre inserito non valido");
        exit(0);
    }

    /* divido la data in un array
    con giorno, mese e anno separati */
    int data[3];
    separaData(argv[1], data);

    /* controllo se la data è valida o meno e la
    stampo nel formato dd/mm/YYYY */
    if (isDataValida(data))
    {
        printf("%02d/%02d/%04d", data[0], data[1], data[2]);
    }
    else
    {
        printf("Formato data non valido");
    }
    return 0;
}