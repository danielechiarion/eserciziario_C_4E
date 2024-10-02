/* Data una misura di tempo espressa in secondi S1, convertirla in ore H,
minuti M e secondi S.

Esempio: se il numero dei secondi è 1630, si dovrà ottenere, in uscita
dal programma, 0h 27m 10s. */

#include <stdio.h>

int main(int argc, char *argv[])
{
    /* dichiarazione variabili */
    int sec, h = 0, min = 0;

    /* richiesta inserimento secondi,
    controllando che sia un numero positivo */
    do
    {
        printf("Inserisci quanti secondi vuoi convertire: ");
        scanf("%d", &sec);
    } while (sec < 0);

    /* controllo se è possibile
    raggruppare i secondi in ore */
    while (sec / 3600 > 0)
    {
        h++;
        sec -= 3600;
    }

    /* controllo successivamente se è possibile
    raggruppare i secondi rimasti in minuti */
    while (sec / 60 > 0)
    {
        min++;
        sec -= 60;
    }
    /* gli ultimi secondi rimasti non saranno più raggruppabili */

    /* output risultati*/
    printf("\n\n%dh %dmin %ds", h, min, sec);

    return 0;
}