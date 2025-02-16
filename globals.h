#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef YYPARSER

#include "parser.tab.h"

#define ENDFILE 0

#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#define MAXRESERVED 8

typedef int TokenType;

extern FILE* source; /* arquivo texto do código fonte */
extern FILE* listing; /* listing output text file */
extern FILE* code; /* code text file for TM simulator */

extern int lineno; /* source line number for listing */

typedef enum {StmtK,ExpK} NodeKind;
typedef enum {IfK,WhileK,AssignK,ReturnINT,ReturnVOID} StmtKind;
typedef enum {OpK,ConstK,IdK,VarDeclK,VetDeclK,FunctionK,CallK,TypeK,VetorK,VarParamK,VetParamK} ExpKind;

/* ExpType é usado para checagem de tipo */
typedef enum {Void,Integer,Boolean} ExpType;
typedef enum {INTTYPE, VOIDTYPE, NULLL} dataTypes;
typedef enum {VAR, FUN, CALL, VET, RETT} IDTypes;

#define MAXCHILDREN 3

typedef struct treeNode {
  struct treeNode * child[MAXCHILDREN];
     struct treeNode * sibling;
     int lineno;
     int size;
     int add;
     NodeKind nodekind;
     union { StmtKind stmt; ExpKind exp;} kind;
     union { TokenType op;
             int val;
             char * name; } attr;
     char * idname;
     char *  scope;
     char * idtype;
     char * datatype;
     int vet;
     int declared;
     int params;
     dataTypes type;
   } TreeNode;


extern int EchoSource;   /* TraceScan = TRUE faz com que as informações do token sejam impressas no arquivo de listagem,
pois cada token é reconhecido pelo scanner */
extern int TraceScan;

/* TraceParse = TRUE faz com que a árvore sintática seja impressa no arquivo de listagem na
forma linearizada (usando recuos para filhos)
 */
extern int TraceParse;

/* Error = TRUE evita passagens adicionais se ocorrer um erro */
extern int Error;
#endif