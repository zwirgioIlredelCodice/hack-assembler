#ifndef SYMBOLTABLE
#define SYMBOLTABLE

#define DEFAULT_SYMBOLS 18

typedef struct symbol {
    int value;
    char* name;
} symbol;

typedef struct symboltable {
    symbol* s;
    struct symboltable* next;
} symboltable;

typedef symboltable* pst;

pst s_insert(pst st, symbol* s);
pst s_init();
int s_get(pst st, char name[]);

#endif
