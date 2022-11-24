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

    if (cond) {
        int i = 0;
        while (sins[i] != '=') {
            if (sins[i] == 'M') bins[11] = 1;
            else if (sins[i] == 'D') bins[10] = 1;
            else if (sins[i] == 'A') bins[9] = 1;

            i++;
        }
    }
    if (conj) {
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
