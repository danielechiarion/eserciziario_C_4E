#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *file = fopen("input.txt", "r");
    char buf[81];
    int nRighe=0, nChar=0;

    while(fgets(buf, sizeof(buf), file) != NULL){
        nRighe++;
        nChar += strlen(buf);
    }

    printf("\nNel file sono presenti %d righe", nRighe);
    printf("\nNel file sono presenti %d caratteri", nChar);

    return 0;
}