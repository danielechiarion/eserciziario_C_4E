/* Utilizzando le chiamate di sistema si scriva un programma concorrente che possa
essere invocato nel seguente modo:
./esame risultati.txt

dove risultati.txt è un nome assoluto di file.

Il processo P0 deve generare 2 processi figli: P1 e P2.
P1 deve interagire con l'utente, richiedendo delle stringhe (ogni stringa di lunghezza
massima pari a 50 caratteri) che provvede ad inviare a P2 utilizzando una pipe.
Il processo P1 continua a ricevere stringhe fin quando non riceve la stringa
"esci".
Il processo P2 legge le stringhe dalla pipe e le scrive in
ordine alfabetico nel file risultati.txt


Osservazione:
il comando sort, che risiede in /usr/bin/sort, è un filtro che può leggere
in input un flusso di dati e stamparlo quindi a video oppure in qualsiasi
altro file descriptor purchè opportunamente redirezionato.

esempio di utilizzo:

$ ./esame risultati.txt
Inserisci una stringa:
paolo
Inserisci una stringa:
luca
Inserisci una stringa:
anna
Inserisci una stringa:
tommaso
Inserisci una stringa:
alberto
Inserisci una stringa:
esci
Esecuzione terminata, esco.

$ cat risultati.txt
alberto
anna
luca
paolo
tommaso

osservazione:
ad ogni iterazione è opportuno aggiungere il carattere newline al termine
della stringa, in modo che nel file vengano scritte le stringhe una per riga
come nell'esempio. strcat(stringa, "\n");

nota operativa:
si presti attenzione a non dimenticare processi zombie quando il padre termina
l'esecuzione. */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

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
        printf("Numero di argomenti non valido\n");
        exit(0);
    }

    /* dichiatazione variabili */
    int pid;
    char stringaInput[100];

    /* creazione pipe */
    int p1p2[2];
    pipe(p1p2);

    pid = fork();
    if (pid == 0)
    {
        close(p1p2[0]);

        while (1)
        {
            printf("Inserisci una nuova stringa: ");
            scanf("%s", stringaInput);

            if (strcmp(stringaInput, "esci") == 0)
            {
                printf("\nEsecuzione terminata. Esco\n");
                break;
            }

            strcat(stringaInput, "\n");
            write(p1p2[1], stringaInput, strlen(stringaInput));
        }

        exit(0); // esco dal processo
    }

    pid = fork();
    if (pid == 0)
    {
        pipe_stdIn(p1p2);

        /* apro il file con il percorso indicato
        e lo imposto come standard output */
        int fdFile = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
        close(1);
        dup(fdFile);
        close(fdFile);

        /* ordino le stringhe ottenute e le
        salvo sul file indicato */
        execl("/usr/bin/sort", "sort", NULL);
        return -1;
    }

    close_pipe(p1p2);
    wait(NULL); // il padre attende il processo P1

    return 0;
}