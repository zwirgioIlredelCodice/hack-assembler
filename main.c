#include <stdio.h>
#include <string.h>


int stoint(char s[]) {
    // conta i numeri
    int nn = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        nn = nn * 10;
    }
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        nn = nn / 10;
        n += (s[i] - '0') * nn;
    }
    return n;
}

void inttob15(int n, char s[]) {
    int i = 14;
    for (i = 14; n > 0; i--) {
        s[i] = (n % 2) + '0';
        n /= 2;
    }
    while (i > 0) {
        s[i] = '0';
        i--;
    }
}

// funziona sono con i numeri positivi es @-11 non funziona
void traduci_ains(char sins[], char bins[]) {
    int n = stoint(sins+1);
    inttob15(n, bins);
    bins[0] = '0';
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
