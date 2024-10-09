/**
 * @brief Calcolo della somma delle radici quadrate
 *
 * Progettare un algoritmo che risolve il seguente problema. Si desidera
 * calcolare la somma delle radici quadrate di N valori numerici inseriti
 * dall’utente, con N inserito in input.
 * L’algoritmo deve stampare la somma calcolata. L’algoritmo deve terminare
 * con un messaggio di errore quando viene inserito un numero che non
 * permette di effettuare il calcolo (nel dominio dei numeri reali).
 */

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    /* dichiarazione variabili */
    int nValori, numCorrente;
    double somma = 0;

    /* richiedo inizialmente l'inserimento
    di quanti numeri da inserire */
    do
    {
        printf("Quanti numeri vuoi inserire? ");
        scanf("%d", &nValori);
    } while (nValori <= 0); // controllo che non venga inserito un valore minore o uguale a 0

    for (int i = 0; i < nValori; i++)
    {
        printf("Inserisci un numero: ");
        scanf("%d", &numCorrente);

        /* controllo se il numero è adatto per eseguire una radice quadrata,
        altrimenti restituisco un messaggio di errore */
        if (numCorrente < 0)
        {
            printf("\nNumero non valido perche' e' negativo");
            break;
        }

        somma += sqrt(numCorrente); // se il numero è valido eseguo la somma
    }

    /* output risultati */
    printf("\n\nLa somma delle radici quadrate dei numeri inseriti e': %.2f", somma);

    return 0;
}