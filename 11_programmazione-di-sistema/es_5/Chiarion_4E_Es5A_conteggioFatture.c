/* Un’applicazione multiprocesso in C deve presentare la seguente interfaccia:
controlloFatture nomeFileFatture 
dove nomeFileFatture è un nome assoluto di file.

A questo fine, l’addetto dell’azienda deve verificare, sul file passato 
come parametro, se un cliente ha ancora delle fatture in sospeso oppure se 
le ha pagate tutte.

Nel file passato come parametro sono memorizzate tutte le fatture, una per
ogni riga. Ogni riga è composta dal nome del cliente (un codice di 5 caratteri
alfanumerico che identifica univocamente ogni cliente), da un campo che 
contiene la stringa “pagato” per le fatture saldate oppure “insoluto”
per quelle ancora insolute, più altri campi con altre informazioni.

L’addetto dell’azienda inserisce a terminale il codice dei clienti (uno alla
volta) di cui vuole controllare lo stato dei pagamenti. Per ogni cliente
inserito, l’applicazione deve visualizzare il nome del cliente stesso e il
numero di fatture di tale cliente che risultano ancora da pagare.

Quando l’applicazione termina,a causa dell’inserimento della stringa “esci”,
il programma deve visualizzare il numero totale di richieste di servizio
eseguite fino a quel momento. */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]){
    /* controllo subito il numero di argomenti */
    if(argc != 2){
        printf("Numero di argomenti non valido\n");
        exit(0);
    }

    /* dichiarazione variabili e array */
    int richiestaDiServizio = 0;
    char codiceCliente[100], inputFatture[10];
    const char FLAGDAPAGARE[] = " insoluto";
    int pid;

    /* dichiaro la pipe */
    int p1p0[2];

    printf("Controllo fatture %s", argv[1]);
    while(1){
        printf("\n\nInserisci il codice del cliente (5 cifre): ");
        scanf("%s", codiceCliente);

        if(strcmp(codiceCliente, "esci")==0){
            printf("\n\nSono state fatte %d richieste di servizio\n", richiestaDiServizio);
        }

        pipe(p1p0); //assegno i fd alla pipe

        pid = fork();
        if(pid==0){
            /* redireziono lo standard output alla pipe */
            close(p1p0[0]);
            close(1);
            dup(p1p0[1]);
            close(p1p0[1]);
            execl("/usr/bin/grep", "grep", "-c", strcat(codiceCliente, FLAGDAPAGARE), argv[1], NULL);
            return -1;
        }

        close(p1p0[1]);
        read(p1p0[0], inputFatture, sizeof(inputFatture));
        close(p1p0[0]);
        printf("\nIl cliente ha %d fatture da pagare", atoi(inputFatture));
        richiestaDiServizio++;
    }

    return 0;
}