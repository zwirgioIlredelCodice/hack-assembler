#include <stdio.h>
#include <string.h>
#include "ains.h"
#include "cins.h"

void traduci_ins(char sins[], char bins[]) {
    if (sins[0] == '\0') {
        // vuota
    }
    else if (sins[0] == '@') {
        // a instruction
        traduci_ains(sins, bins);
    } else {
        traduci_cins(sins, bins);
    }
}

void nametohack(char src[], char dest[]) {
    int len = strlen(src);
    strcpy(dest, src);
    // cancella quello che c'è davanti al . es ciao.bello -> ciao.
    for (int i = len; (i > 0 && src[i] != '.'); i--) {
        dest[i] = '\0';
    }
    strcat(dest, "hack");
}

void assembla(char fin[], char fout[]) {
    FILE* pfin;
    FILE* pfout;
    pfin = fopen(fin, "r");
    pfout = fopen(fout, "w");

    char bins[17];
    char linea[200];
    while (fgets(linea, 200, pfin) != NULL) {
        traduci_ins(linea, bins);
        fprintf(pfout, "%s\n", bins);
    }
    fclose(pfin);
    fclose(pfout);
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
