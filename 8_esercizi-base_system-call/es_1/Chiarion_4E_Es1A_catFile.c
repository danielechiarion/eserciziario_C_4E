/* Utilizzando le system call open, read, write, close leggere il file rfc1918.txt e stamparlo a video.
Il programa deve essere cosi invocato:
$./a.out rfc1918.txt

Consiglio: leggere un carratere per volta */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero di argomenti non valido");
        exit(0);
    }
    char *buf;

    int fd = open(argv[1], O_RDONLY);
    int nRead;
    /* se trova sempre qualcosa
    da leggere lo scrive sullo
    schermo */
    while (nRead =read(fd, buf, sizeof(buf)) > 0)
    {
        write(1, buf, nRead); //se scrivo più di nRead vengono messi caratteri strani
    }

    close(fd);
}
