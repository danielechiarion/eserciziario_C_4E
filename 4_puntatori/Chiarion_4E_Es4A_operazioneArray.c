/* Dato un array di dimensione massima pari a SHRT_MAX,
inserire in input un numero arbitrario di interi positivi.
L'inserimento termina quando viene inserito il valore -1.

Si mostri quindi un menu cosi strutturato:
    premere 1 per mostrare il contenuto dell'array
    premere 2 per inserire un elemento in coda
    premere 3 per modificare un elemento, se presente
    premere 4 per eliminare un elemento, se presente
    premere 5 per ricercare un elemento
    premere 6 per inserire un elemento in una certa posizione
    premere 7 per mostrare il contenuto dell'array all'inverso
    premere 8 per mostrare il valore massimo dell'array
    premere 0 per terminare

dopo ogni operazione il menu deve essere nuovamente mostrato.

osservazione:
SHRT_MAX è dichiarata in limits.h

Vincolo:
è obbligatorio strutturare il programma in funzioni */

#include <stdio.h>
#include <limits.h>

/* funzione che inserisce un numero positivo all'interno
dell'array:
- se mode è 1 accetta anche -1 per terminare
- se mode è -2 accetta solo numeri positivi */
int inputNumPositivo(int mode)
{
    int input;

    do
    {
        printf("Inserisci un numero positivo: ");
        scanf("%d", &input);
    } while ((mode == 2 && input < 0) || (mode == 1 && input < -1));

    return input;
}

/* funzione per utilizzare un menu per
per le varie opzioni da selezionare */
int menu()
{
    int scelta;

    printf("\n\nScegli tra le seguenti opzioni: ");
    printf("\n[1] Mostra contenuto array");
    printf("\n[2] Inserire elemento in coda");
    printf("\n[3] Modifica elemento");
    printf("\n[4] Elimina un elemento");
    printf("\n[5] Ricerca elemento");
    printf("\n[6] Inserisci elemento in una certa posizione");
    printf("\n[7] Mostra contenuto array all'inverso");
    printf("\n[8] Mostra valore massimo");
    printf("\n[0] Fine\n");

    do
    {
        scanf("%d", &scelta);
        if (scelta > 8 || scelta < 0)
        {
            printf("Valore errato, riprova\n");
        }
    } while (scelta > 8 || scelta < 0);
}

/* funzione che permette di visualizzare il contenuto
di un array */
void visualizzaArray(int array[], int indexArray)
{
    printf("\n\nValori array:\n");
    for (int i = 0; i < indexArray; i++)
    {
        printf("%d\t", array[i]);
    }
}

/* funzione per visualizzare un array all'inverso */
void visualizzaArrayInverso(int array[], int indexArray)
{
    printf("\n\nValori array INVERSO:\n");
    for (int i = indexArray-1; i>=0; i--)
    {
        printf("%d\t", array[i]);
    }
}

/* funzione per inserire un elemento in coda */
void inserisciInCoda(int num, int array[], int *arrayIndex)
{
    array[*arrayIndex] = num;
    (*arrayIndex)++;
}

/* funzione per l'inserimento numeri
al primo popolamento del vettore */
void popolamentoVettore(int array[], int *indexArray)
{
    int input;

    do
    {
        input = inputNumPositivo(1);
        if (input != -1)
        {
            inserisciInCoda(input, array, indexArray);
        }
    } while (input != -1);
}

/* funzione che permette di ricercare un elemento.
Restituisce -1 se il valore non è stato trovato*/
int ricercaNumero(int num, int array[], int indexArray)
{
    for (int i = 0; i < indexArray; i++)
    {
        if (array[i] == num)
        {
            return i;
        }
    }

    return -1;
}

/* funzione che elimina un elemento all'interno di
un array */
void eliminaNumero(int posNumero, int array[], int *indexArray){
    for(int i=posNumero;i<(*indexArray)-1;i++){
        array[i]=array[i+1]; //scalo i valori
    }

    (*indexArray)--; //modifco l'indice array
}

/* funzione che permette di trovare il valore massimo
all'interno di un array */
int trovaMassimo(int array[], int indexArray){
    int max = 0;

    for(int i=0;i<indexArray;i++){
        if(array[i]>max){
            max=array[i];
        }
    }

    return max;
}

int main(int argc, char *argv[])
{
    /* dichiarazione array e relativo indice */
    int array[SHRT_MAX];
    int indexArray = 0;
    int scelta, input, input2, risultato;

    /* inserimento valori per
    la prima popolazione del vettore */
    popolamentoVettore(array, &indexArray);

    do
    {
        scelta = menu();
        switch (scelta)
        {
        case 1:
            visualizzaArray(array, indexArray);
            break;
        case 2:
            inserisciInCoda(inputNumPositivo(2), array, &indexArray);
            break;
        case 3:
            risultato = ricercaNumero(inputNumPositivo(2), array, indexArray);
            if (risultato < 0)
            {
                printf("Numero non trovato");
            }
            else
            {
                input = inputNumPositivo(2);
                array[risultato] = input;
            }
            break;
        case 4:
            input=inputNumPositivo(2); //input numero
            risultato=ricercaNumero(input, array, indexArray); //ricerca numero
            if(risultato<0){
                printf("Numero non trovato"); 
            }
            else{
                eliminaNumero(risultato, array, &indexArray);
            }
            break;
        case 5:
            input = inputNumPositivo(2);
            risultato= ricercaNumero(input, array, indexArray);
            if(risultato<0){
                printf("Numero non trovato"); 
            }
            else{
                printf("Numero presente nella posizione %d", risultato);
            }
            break; 
        case 6:
            input = inputNumPositivo(2);
            do{
                printf("Inserisci la posizione in cui vuoi mettere il numero: ");
                scanf("%d", &input2);
                if(input2<0 || input2>indexArray){
                    printf("Indice al di fuori della dimensione dell'array\n");
                }
            }while(input2<0 || input2>indexArray);
            array[input2]=input;
            break;    
        case 7:
            visualizzaArrayInverso(array, indexArray);
            break;           
        case 8:
            risultato = trovaMassimo(array, indexArray);
            printf("Il valore massimo dell'array e' %d", risultato);
            break;
        default:
            printf("Fine programma");
        }
    } while (scelta != 0);
    return 0;
}