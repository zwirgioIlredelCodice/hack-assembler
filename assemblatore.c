#include <stdio.h>
#include <string.h>
#include "assemblatore.h"
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

// pulisce la riga da whitespaces e commenti;
void insestrai(char linea[]) {
    char pl[LINEA_LEN] = "";
    // rimuovi spazi davanti
    int i = 0;
    while (linea[i] == ' ' || linea[i] == '\t' || linea[i] == '\r') i++;
    //metti l'istruzione in pl
    int pi = 0;
    while (linea[i] != '\n' && linea[i] != ' ' && linea[i] != '\t' && linea[i] != '/' && linea[i] != '\r') { // \r carriage return maremma maiala
        pl[pi] = linea[i];
        pi++;
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

        if (strlen(linea) > 0) {
            printf("%s\n", linea);
            traduci_ins(linea, bins);
            fprintf(pfout, "%s\n", bins);
        }
    }
    fclose(pfin);
    fclose(pfout);
}
