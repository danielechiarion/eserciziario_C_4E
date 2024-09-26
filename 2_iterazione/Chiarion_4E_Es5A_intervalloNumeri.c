/* Dati due numeri interi positivi N1 e N2 con N2>N1, generare e
visualizzare in ordine crescente i numeri interi compresi
nell'intervallo chiuso [N1,N2]. */

#include <stdio.h>

int main(int argc, char *argv[])
{
    /* dichiarazione variabili */
    int n1, n2;

    /* richiesta inserimento dati */
    do
    {
        printf("\nInserisci il primo numero: ");
        scanf("%d", &n1);
        printf("Inserisci il secondo numero: ");
        scanf("%d", &n2);

        if (n2 <= n1)
        {
            printf("\nERRORE! N2 > N1"); // restitsco un messaggio di errore se n2>n1
        }
        if (n1 <= 0 || n2 <= 0)
        {
            printf("\nERRORE! Tutti i valori devono essere strettamente positivi");
        }
    } while (n2 <= n1 || n1 <= 0); // controllo che n2>n1 e che i numeri siano positivi

    /* visualizzo i numeri compresi
    nell'intervallo [N1, N2] */
    printf("\n\nI numeri compresi tra %d e %d sono: \n", n1, n2);
    for (int i = n1; i <= n2; i++)
    {
        printf("%d\t", i);
    }

    return 0;
}