/* Il file.txt rappresenta le fatture dell’ultimo mese della ditta ProgrammatoriHero srl
e contiene 3 campi: codice, “pagato” o “insoluto”, l’importo

Si vuole realizzare un programma concorrente in linguaggio C che mostri a video l'importo totale delle fatture emesse.

Si usi la seguente procedura:
Si generi un processo figlio P1 che legge il file e lo manda al processo P2 il quale
estrapola la terza colonna del file, e la manda al processo P0.
Il processo P0 riceve quindi tutti gli importi, ne calcola il totale e lo mostra a video.

Note operative
Il processo P1 usi il comando cat per mostrare il contenuto del file e inviarlo a P2
Il processo P2 usi il comando: awk '{print $3}' per estrapolare la terza colonna
Il processo P2 deve inviare al processo P0 la terza colonna
Il processo P0 deve leggere in input tutti i valori e per ogni lettura deve incrementare la variabile accumulatore “totale”

Osservazione:
strncat(strimporto, &buffer[0], sizeof(buffer[0]))
Aggiunge in coda alla stringa strimporto il carattere buffer[0] la cui dimensione è sizeof(buffer[0])

Osservazione:
char *ptr;
double x = strtod(strimporto, &ptr);
strtod converte la stringa strimporto in double.

Osservazione:
strimporto[0] = '\0';
Pone in posizione 0 di una stringa il carattere terminatore, in questo modo si resetta a livello logico una string */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/* funzione che redireziona lo standard input
al file descriptor della pipe */
void pipe_stdIn(int pipe[])
{
    close(pipe[1]);
    close(0);
    dup(pipe[0]);
    close(pipe[0]);
}

/* funzione che redireziona lo standard output
al file descriptor della pipe */
void pipe_stdOut(int pipe[])
{
    close(pipe[0]);
    close(1);
    dup(pipe[1]);
    close(pipe[1]);
}

/* funzione che chiude tutti i file descriptor
della pipe */
void close_pipe(int pipe[])
{
    close(pipe[0]);
    close(pipe[1]);
}

int main(int argc, char *argv[])
{
    /* controllo il numero di argomenti */
    if (argc != 2)
    {
        printf("Numero di argomenti non validon\n");
        exit(0);
    }

    /* dichiarazione variabili */
    int pid;
    double sommaImporti = 0;

    /* creazione delle due pipe */
    int p1p2[2], p2p0[2];
    pipe(p1p2);

    pid = fork();
    if (pid == 0)
    {
        pipe_stdOut(p1p2);

        execl("/usr/bin/cat", "cat", argv[1], NULL);
        return -1;
    }

    pipe(p2p0);

    pid = fork();
    if (pid == 0)
    {
        pipe_stdIn(p1p2);
        pipe_stdOut(p2p0);

        execl("/usr/bin/awk", "awk", "{print $3}", NULL);
        return -1;
    }

    close_pipe(p1p2);
    close(p2p0[1]);

    /* leggo i dati dalla pipe con P2
    tramite una read() */
    char buf;
    char stringaImporto[100];
    double importoParziale;
    while (read(p2p0[0], &buf, sizeof(buf)))
    {
        strncat(stringaImporto, &buf, sizeof(buf));
        if (buf == '\n')
        {
            importoParziale = strtod(stringaImporto, NULL);
            sommaImporti += importoParziale;
            printf("L'importo di questa fattura e' di %.2f€\n", importoParziale);
            stringaImporto[0] = '\0'; // resetto la stringa una volta andato a capo
        }
    }
    close(p2p0[0]);

    printf("\nL'importo totale e' di %.2f€\n", sommaImporti);

    return 0;
}