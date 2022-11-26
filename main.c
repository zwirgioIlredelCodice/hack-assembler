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

#define LINEA_LEN 200

// pulisce la riga da whitespaces e commenti;
void insestrai(char linea[]) {
    linea[strlen(linea)-1] = '\0'; //rimuove \n all iniziio
    char pl[LINEA_LEN] = {'\0'};
    int i = 0;
    //cerca commenti
    int commento = 0;
    int tc = 0;
    while (linea[i] != '\0' && !commento) {
        if (linea[i] == '/') tc++;
        else tc = 0;

        if (tc >= 2) {
            linea[i-1] = '\0';
            commento = 1;
        }
        i++;
    }

    //rimuove gli spazi e le tabulazioni
    i = 0;
    int pi = 0;
    while (linea[i] != '\0') {
        if (linea[i] != ' ' && linea[i] != '\t') {
            pl[pi] = linea[i];
            pi++;
        }
        i++;
    }
    pl[pi] = '\0';

    strcpy(linea, pl);
}

void assembla(char fin[], char fout[]) {
    FILE* pfin;
    FILE* pfout;
    pfin = fopen(fin, "r");
    pfout = fopen(fout, "w");

    char bins[17];
    char linea[LINEA_LEN];
    while (fgets(linea, LINEA_LEN, pfin) != NULL) {
        insestrai(linea);

        if (strlen(linea) > 1) {
            printf("%s\n", linea);
            traduci_ins(linea, bins);
            fprintf(pfout, "%s\n", bins);
        }
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
