#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 211  // Tamanho da tabela hash
#define SHIFT 4   // Valor para deslocamento na função de hash

typedef enum { VAR_ID, FUN_ID, PARAM_ID  } IDType;  // Renomeado para evitar conflito

typedef struct Symbol {
    char *name;         
    int lineno;        
    char *type;       
    char *scope;   
    char *kind;    
    IDType idType;   // Agora usa VAR_ID e FUN_ID
    int declared;   
    struct Symbol *next; 
} Symbol;

typedef struct {
    Symbol *table[SIZE];
} SymbolTable;

// Funções para manipulação da tabela de símbolos
SymbolTable* createSymbolTable();
int hash(char *key);
void insertSymbol(SymbolTable *st, char *name, int lineno, char *type, char *scope, char *kind, IDType idType);
Symbol* lookupSymbol(SymbolTable *st, char *name);
void printSymbolTable(SymbolTable *st);
void checkUndeclared(SymbolTable *st);
void checkTypeErrors(SymbolTable *st);
void checkMainDeclared(SymbolTable *st);

#endif
