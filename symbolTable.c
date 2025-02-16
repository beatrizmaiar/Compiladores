#include "symbolTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int Error; // Variável global para indicar erro semântico

// Criar a tabela de símbolos
SymbolTable* createSymbolTable() {
    SymbolTable *st = (SymbolTable*)malloc(sizeof(SymbolTable));
    for (int i = 0; i < SIZE; i++) {
        st->table[i] = NULL;
    }
    return st;
}

// Função de hashing
int hash(char *key) {
    int temp = 0;
    int i = 0;
    while (key[i] != '\0') {
        temp = ((temp << SHIFT) + key[i]) % SIZE;
        i++;
    }
    return temp;
}

// Inserir identificador na tabela de símbolos
void insertSymbol(SymbolTable *st, char *name, int lineno, char *type, char *scope, char *kind, IDType idType) {
    Symbol* existing = lookupSymbol(st, name);
    
    if (existing != NULL) {
        if (existing->idType == FUN_ID && idType != FUN_ID) {  
            printf("Erro Semântico: Declaração inválida - '%s' já foi declarado como função (linha %d)\n", 
                   name, existing->lineno+1);
            Error = 1;
            return;
        }
        //Se já existe no mesmo escopo, erro de redeclaração
        if (strcmp(existing->scope, scope) == 0 && existing->idType == idType) {
            printf("Erro Semântico: Redeclaração do identificador '%s' na linha %d (Escopo: %s)\n", 
                   name, lineno+1, scope);
            Error = 1;
            return;
        }
    }

    int index = hash(name);
    Symbol *newSymbol = (Symbol*)malloc(sizeof(Symbol));
    newSymbol->name = strdup(name);
    newSymbol->lineno = lineno;
    newSymbol->type = strdup(type);
    newSymbol->scope = strdup(scope);
    newSymbol->kind = strdup(kind);     
    newSymbol->idType = idType;
    newSymbol->declared = 1; // Novo campo para verificar se foi declarado
    newSymbol->next = st->table[index]; 
    st->table[index] = newSymbol;
}

// Procurar um identificador na tabela de símbolos
Symbol* lookupSymbol(SymbolTable *st, char *name) {
    int index = hash(name);
    Symbol *entry = st->table[index];
    while (entry != NULL) {
        if (strcmp(entry->name, name) == 0) {
            return entry; // Encontrado na tabela
        }
        entry = entry->next;
    }
    return NULL; // Não encontrado
}

// Verificar se há identificadores não declarados
void checkUndeclared(SymbolTable *st) {

    for (int i = 0; i < SIZE; i++) {
        Symbol *entry = st->table[i];
        while (entry != NULL) {
            // Ignorar funções pré-definidas
            if (strcmp(entry->name, "main") == 0 || strcmp(entry->name, "input") == 0 || strcmp(entry->name, "output") == 0) {
                entry = entry->next;
                continue;
            }

            if (!entry->declared) {  // Se o identificador não foi declarado
                printf("Erro semântico: Identificador '%s' usado, mas não declarado (LINHA %d, escopo %s)\n",
                       entry->name, entry->lineno+1, entry->scope);
                Error = 1;
            }
            entry = entry->next;
        }
    }
}

// Verificar erros de tipo nas variáveis e parâmetros
void checkTypeErrors(SymbolTable *st) {

    for (int i = 0; i < SIZE; i++) {
        Symbol *entry = st->table[i];
        while (entry != NULL) {
            if (strcmp(entry->kind, "Variável") == 0 || strcmp(entry->kind, "Parâmetro") == 0) {
                if (entry->type == NULL) {
                    printf("Erro Semântico: Tipo indefinido para '%s' (linha %d, escopo %s)\n",
                           entry->name, entry->lineno+1, entry->scope);
                    Error = 1;
                }
            }
            entry = entry->next;
        }
    }
}

void checkMainDeclared(SymbolTable *st) {
    Symbol *mainSymbol = lookupSymbol(st, "main");
    if (mainSymbol == NULL || mainSymbol->idType != FUN_ID) {
        printf("Erro Semântico: Função 'main()' não foi declarada.\n");
        Error = 1;
    }
}


// Imprimir a tabela de símbolos
void printSymbolTable(SymbolTable *st) {
    printf("\nTabela de Símbolos:\n");
    printf("------------------------------------------------------\n");
    printf("| Nome       | Linha  | Tipo         | Escopo        |\n");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < SIZE; i++) {
        Symbol *entry = st->table[i];
        while (entry != NULL) {
            printf("| %-10s | %-6d | %-10s | %-12s |\n", 
                   entry->name, entry->lineno+1, entry->type, entry->scope);
            entry = entry->next;
        }
    }
    printf("------------------------------------------------------\n");
}
