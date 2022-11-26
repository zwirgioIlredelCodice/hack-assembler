#include <stdio.h>
#include <string.h>
#include "cins.h"

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
            if (sins[i] == 'M') bins[12] = '1';
            else if (sins[i] == 'D') bins[11] = '1';
            else if (sins[i] == 'A') bins[10] = '1';
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
        printf("la parte c:%s dell espressione non è valida\n", cpart);
    }

    if (conj) {
        i++; // salta ;
        char jpart[4] = "";
        int ji = 0;
        while (sins[i] != '\0') {
            jpart[ji] = sins[i];
            ji++;
            i++;
        }

        if (strcmp(jpart, "JGT") == 0) {
            bins[13] = '0';
            bins[14] = '0';
            bins[15] = '1';
        }
        else if (strcmp(jpart, "JEQ") == 0) {
            bins[13] = '0';
            bins[14] = '1';
            bins[15] = '0';
        }
        else if (strcmp(jpart, "JGE") == 0) {
            bins[13] = '0';
            bins[14] = '1';
            bins[15] = '1';
        }
        else if (strcmp(jpart, "JLT") == 0) {
            bins[13] = '1';
            bins[14] = '0';
            bins[15] = '0';
        }
        else if (strcmp(jpart, "JNE") == 0) {
            bins[13] = '1';
            bins[14] = '0';
            bins[15] = '1';
        }
        else if (strcmp(jpart, "JLE") == 0) {
            bins[13] = '1';
            bins[14] = '1';
            bins[15] = '0';
        }
        else if (strcmp(jpart, "JMP") == 0) {
            bins[13] = '1';
            bins[14] = '1';
            bins[15] = '1';
        }
    }
}
