/* Si vuole realizzare in linguaggio C un software monoprocesso che implementi il seguente comando:
$ cat file1.txt file2.txt file3.txt | grep “c”

Dove file[N].txt con N maggiore uguale a 1 sono una serie di files e il carattere "c" è a scopo esemplificativo e potrebbe essere
qualsiasi carattere.

Si utilizzino le system call al fine di leggere tutti i file di testo e, per ogni file, ricercare il carattere.
Al termine dell’esecuzione il software dovrà mostrare a video il numero di occorrenze del carattere trovate nei files e
dovrà contemporaneamente scrivere l’output su un file di testo il cui path sarà letto da argv.

Esempio:
$ ./a.out file1.txt file2.txt file3.txt k occorrenze.txt
$ Il carattere k compare 10 volte nei files: file1.txt, file2.txt, file3.txt
$ cat occorrenze.txt
$ Il carattere k compare 10 volte nei files: file1.txt, file2.txt, file3.txt

Osservazioni:
essendo il software monoprocesso non è necessario usare le pipe
prestare attenzione all’uso corretto di argv
si ricorda che il software deve funzionare per un numero arbitrario di files.
i percorsi dei files possono essere sia assoluti che relativi


Suggerimento:
Per facilitare la ricerca è possibile leggere un singolo carattere per volta usando la funzione read. */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    /* i parametri necessari sono quattro in quanto contengono:
     - il nome del file da eseguire
     - 3 percorsi di file in cui ricercare
     - il carattere da ricercare
     - il file dove salvare le occorrenze */
    if (argc < 6)
    {
        printf("Numero di argomenti non valido\n");
        exit(1);
    }

    /* dichiarazione variabili e array */
    int numOccorrenze = 0;
    char buf, carattere = argv[argc - 2][0];
    char output[1000];
    /* suddivido le stringhe in due parti
    da completare in seguito */
    int fd;

    for (int i = 1; i <= 3; i++)
    {
        fd = open(argv[i], O_RDONLY);
        /* controllo se il file è stato aperto */
        if (fd > 0)
        {
            /* leggo carattere per carattere */
            while (read(fd, &buf, sizeof(buf)) > 0)
            {
                if (buf == carattere)
                {
                    numOccorrenze++;
                }
            }
            close(fd); //chiudo il file
        }
        else
        {
            printf("Errore nell'apertura del file %s\n", argv[i]);
        }
    }

    /* concateno le stringhe per
    creare il risultato finale */
    sprintf(output, "Il carattere %c compare %d volte nei file %s, %s, %s", carattere, numOccorrenze, argv[1], argv[2], argv[3]);

    /* stampo il risultato finale a video e sul
    file indicato */
    write(1, output, strlen(output));
    fd = open(argv[argc-1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
    write(fd, output, strlen(output));
    close(fd);
    return 0;
}