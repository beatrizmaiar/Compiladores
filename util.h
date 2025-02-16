#ifndef _UTIL_H_
#define _UTIL_H_

void printToken( TokenType, const char* );

/* Função newStmtNode cria um novo nó de declaração para a árvore sintática */
TreeNode * newStmtNode(StmtKind);

/* Função newExpNode cria um novo nó de expressão para a construção da árvore sintática */
TreeNode * newExpNode(ExpKind);

/* Função copyString aloca e faz uma nova cópia de uma String existente */
char * copyString( char * );

/* O procedimento printTree printa uma árvore sintática para o arquivo de listagem usando identação 
para indicar subárvores */
void printTree( TreeNode * );

#endif