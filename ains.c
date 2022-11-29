#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ains.h"
#include "symboltable.h"

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
pst traduci_ains(char sins[], char bins[], pst t,  int* vi) {
    int n = 0;
    if (sins[1] >= '0' && sins[1] <= '9') { // se @ seguita da un nymero es @12
        n = stoint(sins+1);
    } else {
        
        
        n = s_get(t, (sins+1));
        if (n == -1) { // non c'è nella tabella aggiungilo
            symbol* s = malloc(sizeof(symbol));
            char* pname = malloc(sizeof(char)*strlen(sins+1));
            strcpy(pname, sins+1);
            s->name = pname;
            s->value = *vi;

            t = s_insert(t, s);
            
            n = *vi;
            *vi = *vi + 1;
        }
    }
    inttob15(n, bins);
    bins[0] = '0';
    return t;
}
