#include <string.h>
#include <stdlib.h>
#include "symboltable.h"

pst s_insert(pst st, symbol* s) {
    pst tpst = malloc(sizeof(symboltable));
    tpst->s = s;
    tpst->next = st;
    return tpst;
}

const symbol ss[DEFAULT_SYMBOLS] = {
{.value = 16384, .name = "SCREEN"},
{.value = 24576, .name = "KBD"},
{.value = 0, .name = "R0"},
{.value = 1, .name = "R1"},
{.value = 2, .name = "R2"},
{.value = 3, .name = "R3"},
{.value = 4, .name = "R4"},
{.value = 5, .name = "R5"},
{.value = 6, .name = "R6"},
{.value = 7, .name = "R7"},
{.value = 8, .name = "R8"},
{.value = 9, .name = "R9"},
{.value = 10, .name = "R10"},
{.value = 11, .name = "R11"},
{.value = 12, .name = "R12"},
{.value = 13, .name = "R13"},
{.value = 14, .name = "R14"},
{.value = 15, .name = "R15"},
};

pst s_init() {
    pst s = NULL;
    for (int i = 0; i < DEFAULT_SYMBOLS; i++) {
        s = s_insert(s, &ss[i]);
    }
    return s;
}

int s_get(pst st, char name[]) {
    int val = -1;

    while (st != NULL && val == -1) {
        if (strcmp(st->s->name, name) == 0) val = st->s->value;
    }

    return val;
}