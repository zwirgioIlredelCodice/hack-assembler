#include <stdio.h>
#include <string.h>
#include "ains.h"

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
    int i = 15;
    for (i = 15; n > 0; i--) {
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
