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

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("serve un file di input\n");
    }
    else if (argc > 2) {
        printf("troppi argomenti\n");
    } else {
        char* nomefile = argv[1];
        printf("lavoro sul file %s\n", nomefile);

        char command[50] = "l";
        char out[20] = "";
        while (strcmp(command, ":q") != 0) {
            scanf("%s", command);
            traduci_ins(command, out);
            printf("%s\n", out);
        }
    }
}
