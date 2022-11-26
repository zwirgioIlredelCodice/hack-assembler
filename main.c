#include <stdio.h>
#include <string.h>
#include "assemblatore.h"

void nametohack(char src[], char dest[]) {
    int len = strlen(src);
    strcpy(dest, src);
    // cancella quello che c'è davanti al . es ciao.bello -> ciao.
    for (int i = len; (i > 0 && src[i] != '.'); i--) {
        dest[i] = '\0';
    }
    strcat(dest, "hack");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("serve un file di input\n");
    }
    else if (argc > 2) {
        printf("troppi argomenti\n");
    } else {
        char* infile = argv[1];
        char outfile[100] = "";
        nametohack(infile, outfile);
        printf("lavoro sul file %s\n", infile);
        printf("output sul file %s\n", outfile);
        assembla(infile, outfile);
    }
}
