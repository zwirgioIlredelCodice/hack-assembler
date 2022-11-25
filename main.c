#include <stdio.h>
#include <string.h>
#include "ains.h"

void traduci_cins(char sins[], char bins[]) {
    strcpy(bins, "1110000000000000"); // partono con 111

    int cond = 0;
    int conj = 0;
    for (int i = 0; sins[i] != '\0'; i++) {
        if (sins[i] == '=') cond = 1;
        else if (sins[i] == ';') conj = 1;
    }
    int i = 0;
    if (cond) {
        while (sins[i] != '=') {
            if (sins[i] == 'M') bins[11] = 1;
            else if (sins[i] == 'D') bins[10] = 1;
            else if (sins[i] == 'A') bins[9] = 1;
            i++;
        }
        i++; //salta =
    }

    char  cpart[4] = "";
    int ci = 0;
    while (sins[i] != '\0' && sins[i] != ';') {
        cpart[ci] = sins[i];
        ci++;
        i++;
    }
    if (strcmp(cpart, "0") == 0) {
        bins[3] = '0';

        bins[4] = '1';
        bins[5] = '0';
        bins[6] = '1';
        bins[7] = '0';
        bins[8] = '1';
        bins[9] = '0';
    }
    else if (strcmp(cpart, "1") == 0) {
        bins[3] = '0';

        bins[4] = '1';
        bins[5] = '1';
        bins[6] = '1';
        bins[7] = '1';
        bins[8] = '1';
        bins[9] = '1';
    }
    else if (strcmp(cpart, "-1") == 0) {
        bins[3] = '0';

        bins[4] = '1';
        bins[5] = '1';
        bins[6] = '1';
        bins[7] = '0';
        bins[8] = '1';
        bins[9] = '0';
    }
    else if (strcmp(cpart, "D") == 0) {
        bins[3] = '0';

        bins[4] = '0';
        bins[5] = '0';
        bins[6] = '1';
        bins[7] = '1';
        bins[8] = '0';
        bins[9] = '0';
    }
    else if (strcmp(cpart, "A") == 0) {
        bins[3] = '0';

        bins[4] = '1';
        bins[5] = '1';
        bins[6] = '0';
        bins[7] = '0';
        bins[8] = '0';
        bins[9] = '0';
    }
    else if (strcmp(cpart, "!D") == 0) {
        bins[3] = '0';

        bins[4] = '0';
        bins[5] = '0';
        bins[6] = '1';
        bins[7] = '1';
        bins[8] = '0';
        bins[9] = '1';
    }
    else if (strcmp(cpart, "!A") == 0) {
        bins[3] = '0';

        bins[4] = '1';
        bins[5] = '1';
        bins[6] = '0';
        bins[7] = '0';
        bins[8] = '0';
        bins[9] = '1';
    }
    else if (strcmp(cpart, "-D") == 0) {
        bins[3] = '0';

        bins[4] = '0';
        bins[5] = '0';
        bins[6] = '1';
        bins[7] = '1';
        bins[8] = '1';
        bins[9] = '1';
    }
    else if (strcmp(cpart, "-A") == 0) {
        bins[3] = '0';

        bins[4] = '1';
        bins[5] = '1';
        bins[6] = '0';
        bins[7] = '0';
        bins[8] = '1';
        bins[9] = '1';
    }
    else if (strcmp(cpart, "D+1") == 0) {
        bins[3] = '0';

        bins[4] = '0';
        bins[5] = '1';
        bins[6] = '1';
        bins[7] = '1';
        bins[8] = '1';
        bins[9] = '1';
    }
    else if (strcmp(cpart, "A+1") == 0) {
        bins[3] = '0';

        bins[4] = '1';
        bins[5] = '1';
        bins[6] = '0';
        bins[7] = '1';
        bins[8] = '1';
        bins[9] = '1';
    }
    else if (strcmp(cpart, "D-1") == 0) {
        bins[3] = '0';

        bins[4] = '0';
        bins[5] = '0';
        bins[6] = '1';
        bins[7] = '1';
        bins[8] = '1';
        bins[9] = '0';
    }
    else if (strcmp(cpart, "A-1") == 0) {
        bins[3] = '0';

        bins[4] = '1';
        bins[5] = '1';
        bins[6] = '0';
        bins[7] = '0';
        bins[8] = '1';
        bins[9] = '0';
    }
    else if (strcmp(cpart, "D+A") == 0) {
        bins[3] = '0';

        bins[4] = '0';
        bins[5] = '0';
        bins[6] = '0';
        bins[7] = '0';
        bins[8] = '1';
        bins[9] = '0';
    }
    else if (strcmp(cpart, "D-A") == 0) {
        bins[3] = '0';

        bins[4] = '0';
        bins[5] = '1';
        bins[6] = '0';
        bins[7] = '0';
        bins[8] = '1';
        bins[9] = '1';
    }
    else if (strcmp(cpart, "A-D") == 0) {
        bins[3] = '0';

        bins[4] = '0';
        bins[5] = '0';
        bins[6] = '0';
        bins[7] = '1';
        bins[8] = '1';
        bins[9] = '1';
    }
    else if (strcmp(cpart, "D&A") == 0) {
        bins[3] = '0';

        bins[4] = '0';
        bins[5] = '0';
        bins[6] = '0';
        bins[7] = '0';
        bins[8] = '0';
        bins[9] = '0';
    }
    else if (strcmp(cpart, "D|A") == 0) {
        bins[3] = '0';

        bins[4] = '0';
        bins[5] = '1';
        bins[6] = '0';
        bins[7] = '1';
        bins[8] = '0';
        bins[9] = '1';
    }
    else if (strcmp(cpart, "M") == 0) {
        bins[3] = '1';

        bins[4] = '1';
        bins[5] = '1';
        bins[6] = '0';
        bins[7] = '0';
        bins[8] = '0';
        bins[9] = '0';
    }
    else if (strcmp(cpart, "!M") == 0) {
        bins[3] = '1';

        bins[4] = '1';
        bins[5] = '1';
        bins[6] = '0';
        bins[7] = '0';
        bins[8] = '0';
        bins[9] = '1';
    }
    else if (strcmp(cpart, "-M") == 0) {
        bins[3] = '1';

        bins[4] = '1';
        bins[5] = '1';
        bins[6] = '0';
        bins[7] = '0';
        bins[8] = '1';
        bins[9] = '1';
    }
    else if (strcmp(cpart, "M+1") == 0) {
        bins[3] = '1';

        bins[4] = '1';
        bins[5] = '1';
        bins[6] = '0';
        bins[7] = '1';
        bins[8] = '1';
        bins[9] = '1';
    }
    else if (strcmp(cpart, "M-1") == 0) {
        bins[3] = '1';

        bins[4] = '1';
        bins[5] = '1';
        bins[6] = '0';
        bins[7] = '0';
        bins[8] = '1';
        bins[9] = '0';
    }
    else if (strcmp(cpart, "D+M") == 0) {
        bins[3] = '1';

        bins[4] = '0';
        bins[5] = '0';
        bins[6] = '0';
        bins[7] = '0';
        bins[8] = '1';
        bins[9] = '0';
    }
    else if (strcmp(cpart, "D-M") == 0) {
        bins[3] = '1';

        bins[4] = '0';
        bins[5] = '1';
        bins[6] = '0';
        bins[7] = '0';
        bins[8] = '1';
        bins[9] = '1';
    }
    else if (strcmp(cpart, "M-D") == 0) {
        bins[3] = '1';

        bins[4] = '0';
        bins[5] = '0';
        bins[6] = '0';
        bins[7] = '1';
        bins[8] = '1';
        bins[9] = '1';
    }
    else if (strcmp(cpart, "D&M") == 0) {
        bins[3] = '1';

        bins[4] = '0';
        bins[5] = '0';
        bins[6] = '0';
        bins[7] = '0';
        bins[8] = '0';
        bins[9] = '0';
    }
    else if (strcmp(cpart, "D|M") == 0) {
        bins[3] = '1';

        bins[4] = '0';
        bins[5] = '1';
        bins[6] = '0';
        bins[7] = '1';
        bins[8] = '0';
        bins[9] = '1';
    }
    else {
        printf("la parte c dell espressione non è valida\n");
    }

    if (conj) {
        i++; // salta ;

        // avanti
    }

}

void traduci_ins(char sins[], char bins[]) {
    if (sins[0] == '\0') {
        // vuota
    }
    else if (sins[0] == '@') {
        // a instruction
        traduci_ains(sins, bins);
    } else {
        // c instruction
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("serve un file di input\n");
    }
    else if (argc > 2) {
        printf("troppi argomenti\n");
    } else {
        char* nomefile = argv[1];
        printf("lavoro sul file %s\n", nomefile);

        char a[] = "@1024";
        char out[16] = {' '};
        traduci_ins(a, out);
        printf("%s\n", out);
    }
}
