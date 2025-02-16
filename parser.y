%{
  
#define YYPARSER

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"
#include "symbolTable.h"

#define YYSTYPE TreeNode *
static TreeNode * savedTree; 
static int yylex();

extern int lineno;
extern int tab;

char *scope = "";
char * idtype = "";
char * datatype = "";
char currentScope[100] = "Global";  
static char *savedname = "";
int flag = 0;
int params=0;

SymbolTable *st;

int yyerror(char *message);
%}


%start program
%token ELSE IF INT RETURN VOID WHILE
%token ID NUM 
%left ADD SUB MUL DIV 
%left MEQ MEIQ MAQ MAIQ EQ NEQ 
%token ASSIGN VIRG LPAR RPAR LCHA RCHA LCO RCO TB LINE SPACE NL
%token END FIM ERR


%%

program:  decla_seq{ savedTree = $1; }
;

decla_seq:  decla_seq decla {
            YYSTYPE t = $1;
              if (t != NULL){
                while (t->sibling != NULL)
                   t = t->sibling;
                t->sibling = $2;
                $$ = $1;
              }
              else $$ = $2;
          }| decla { $$ = $1; }
;

decla:  var_decla { $$ = $1;} | fun_decla { $$ = $1;}
;

var_decla: tipo ID END {
            $$ = newExpNode(VarDeclK);
            $$->attr.name = copyString(id);
            $$->child[0] = $1;
            $$->type = $1->type;
            $$->scope = currentScope;
            $$->kind.exp = VarDeclK;
            $$->lineno = lineno;

            char kindInfo[50];
            snprintf(kindInfo, sizeof(kindInfo), (strcmp(currentScope, "Global") == 0) ? "Global" : "Local (%s)", currentScope);
            if ($1->type == VOIDTYPE) {
                printf("Erro Semântico: '%s' declarado como 'void' na linha %d (Escopo: %s)\n", 
                        id, lineno+1, currentScope);
                Error = 1;
            } else {
            insertSymbol(st, id, lineno, $1->attr.name, currentScope, kindInfo, VAR_ID);
          }
        }

    | tipo ID LCO tam RCO END {  
            $$ = newExpNode(VetorK);
            $$->attr.name = copyString(id);
            $$->child[0] = $1;
            $$->child[1] = $4;
            $$->type = $1->type;
            $$->scope= currentScope;
            $$->kind.exp = VetorK;
            $$->lineno = lineno;

            char vetorType[20];
            snprintf(vetorType, sizeof(vetorType), "%s[]", $1->attr.name);  // 🔹 Agora todos os vetores são `INT[]`

            insertSymbol(st, id, lineno, vetorType, currentScope, "Vetor", VAR_ID);
          }
    | error {yyerror("");}
;


tam: NUM {
            $$ = newExpNode(ConstK);
            $$->type = INTTYPE;
            $$->attr.name = NULL;
            $$->attr.val = atoi(tokenString);
            };

tipo: INT {
            $$ = newExpNode(TypeK);
            $$->attr.name = "INT";
            $$->type = INTTYPE;
            $$->kind.exp = TypeK; }
    | VOID {
            $$ = newExpNode(TypeK);
            $$->attr.name = "VOID";
            $$->type = VOIDTYPE;
            $$->kind.exp = TypeK; }
;

fun-id:  ID {
            $$ = newExpNode(IdK);
            $$->attr.name = copyString(id);
            $$->kind.exp = IdK; }
;

fun_decla: tipo fun-id LPAR {
              //Atualiza o escopo ANTES de adicionar os parâmetros
              strncpy(currentScope, $2->attr.name, sizeof(currentScope));
          } params RPAR comp_decla {
              $$ = newExpNode(FunctionK);
              $$->kind.exp = FunctionK;
              $$->attr.name = $2->attr.name;
              $$->child[0] = $1;
              $$->type = $1->type;
              $$->child[1] = $5; // Parâmetros agora vêm depois da atualização do escopo
              $$->child[2] = $7; // Corpo da função
              $$->lineno = $2->lineno;

              char funcType[20];
              if ($1->type == VOIDTYPE) {
                  snprintf(funcType, sizeof(funcType), "void (função)");
              } else {
                  snprintf(funcType, sizeof(funcType), "%s (função)", $1->attr.name);
              }

              insertSymbol(st, $2->attr.name, $2->lineno, funcType, "Global", "Função", FUN_ID);
              strcpy(currentScope, "Global");
          }
;


params: VOID {
            $$ = newExpNode(TypeK);
            $$->attr.name = "VOID";
            $$->size = 0;
            $$->child[0] = NULL;
            $$->lineno = lineno;
          } 
        | param_seq { $$ = $1; }
;

param_seq: param_seq VIRG param_seq {
                YYSTYPE t = $1;
                if (t != NULL){
                  while (t->sibling != NULL)
                       t = t->sibling;
                  t->sibling = $3;
                  $$ = $1;
                }
                else $$ = $3;
              } | param { $$ = $1; }
;

param: tipo ID {
          $$ = newExpNode(VarParamK);
          $$->attr.name = copyString(id);
          $$->kind.exp = VarParamK;
          $$->size = 0;
          $$->lineno = lineno;
          $$->type = $1->type;
          $$->child[0] = $1;

          char paramType[20];
          snprintf(paramType, sizeof(paramType), "%s[]", $1->attr.name);

          insertSymbol(st, id, lineno, $1->attr.name, currentScope, "Parâmetro", PARAM_ID);
        }| tipo ID LCO RCO{
         $$ = newExpNode(VetParamK);
          $$->child[0] = $1;
          $$->attr.name = copyString(id);
          $$->kind.exp = VetParamK;
          $$->size = 0;
          $$->lineno = lineno;
          $$->type = $1->type;
          $$->child[0] = $1;

          char paramType[20];
          snprintf(paramType, sizeof(paramType), "%s[]", $1->attr.name);  // 🔹 Agora registra como vetor `int[]`

          insertSymbol(st, id, lineno, paramType, currentScope, "Parâmetro", PARAM_ID);
        }
;

comp_decla: LCHA local_decla stmt_seq RCHA {
                YYSTYPE t = $2;
                  if (t != NULL){
                    while (t->sibling != NULL)
                       t = t->sibling;
                    t->sibling = $3;
                    $$ = $2;
                  }
                  else $$ = $3;
                  strcpy(currentScope, "Global");

              }            
    | LCHA RCHA {strcpy(currentScope, "Global");}
    | LCHA local_decla RCHA { $$ = $2;strcpy(currentScope, "Global");  }
    | LCHA stmt_seq RCHA { $$ = $2;strcpy(currentScope, "Global");  }
;

local_decla: local_decla var_decla {
              YYSTYPE t = $1;
                if (t != NULL){
                  while (t->sibling != NULL)
                     t = t->sibling;
                  t->sibling = $2;
                  $$ = $1;
                }
                else $$ = $2;
            }
    | var_decla { $$ = $1; }
;

stmt_seq: stmt_seq stmt {
              YYSTYPE t = $1;
              if (t != NULL){
                while (t->sibling != NULL)
                t = t->sibling;
                t->sibling = $2;
                $$ = $1;
              }
              else $$ = $2;
            }
    | stmt { $$ = $1; }
;
 
stmt: exp_decla { $$ = $1; }
    | comp_decla { $$ = $1; }
    | sele_decla { $$ = $1; }
    | itera_decla { $$ = $1; }
    | return_decla { $$ = $1; }

exp_decla: exp END {
    $$ = $1;
    // Verifica se a expressão é uma chamada de função
    if ($1->kind.exp == CallK) {
        Symbol *funcSymbol = lookupSymbol(st, $1->attr.name);
        
        // Verifica se a função tem tipo 'void' e se está sendo atribuída
        if (funcSymbol != NULL && funcSymbol->type == "void") {
            // Se for uma atribuição
            if ($2->kind.stmt == AssignK) {
                printf("Erro Semântico: A função '%s' retorna void e não pode ser atribuída (linha %d)\n", $1->attr.name, lineno);
                Error = 1;
            }
        }
    }
}

sele_decla: IF LPAR exp RPAR stmt {
  
            $$ = newStmtNode(IfK);
            $$->attr.name = "IF";
            $$->child[0] = $3;
            $$->child[1] = $5;
            $$->lineno = lineno;
            $$->kind.stmt = IfK;
          }
    | IF LPAR exp RPAR stmt ELSE stmt{
            $$ = newStmtNode(IfK);
            $$->attr.name = "IF";
            $$->child[0] = $3;
            $$->child[1] = $5;
            $$->child[2] = $7;
            $$->scope= $3->scope;
            $$->lineno = lineno;
            $$->kind.stmt = IfK;
          }
;

itera_decla: WHILE LPAR exp RPAR stmt {
          $$ = newStmtNode(WhileK);
          $$->attr.name = "WHILE";
          $$->child[0] = $3;
          $$->child[1] = $5;
          $$->scope = $3->scope;
          $$->lineno = lineno;
          $$->kind.stmt = WhileK;
        }
;

return_decla: RETURN exp END{
                $$ = newStmtNode(ReturnINT);
                $$->child[0] = $2;
                $$->lineno = lineno;
            }| RETURN END { $$ = newStmtNode(ReturnVOID); }
;

exp: var ASSIGN exp {
        $$ = newStmtNode(AssignK);
        $$->kind.stmt = AssignK;
        $$->attr.name = $1->attr.name;
        $$->scope = scope;
        $$->child[0] = $1;
        $$->child[1] = $3;
        $$->lineno = lineno;

        // Busca informações da variável `a`
        Symbol *varSymbol = lookupSymbol(st, $1->attr.name);

        // Só busca a função se `$3` for uma chamada de função (CallK)
        Symbol *funcSymbol = NULL;
        if ($3->kind.exp == CallK && $3->attr.name != NULL) {
            funcSymbol = lookupSymbol(st, $3->attr.name);
        }

        // Verifica se a variável é INT e a função retorna VOID
        if (varSymbol != NULL && funcSymbol != NULL) {
            if (strcmp(varSymbol->type, "INT") == 0 && strstr(funcSymbol->type, "void") != NULL) {
                printf("Erro Semântico: Atribuição inválida, variável '%s' é do tipo INT e a função '%s' retorna void (linha %d)\n",
                       $1->attr.name, $3->attr.name, lineno);
                Error = 1;
            }
        }
      } 
   | simple_exp { $$ = $1; }
;



var: ID {
        $$ = newExpNode(IdK);
        $$->attr.name = copyString(id);
        $$->lineno = lineno;
        $$->child[0] = NULL;

        Symbol *entry = lookupSymbol(st, id);
        if (entry == NULL) {
            printf("Erro Semântico: Identificador '%s' usado, mas não declarado (linha %d, escopo %s)\n",
                   id, lineno+1, currentScope);
            Error = 1;
        }
  } |fun-id LCO exp RCO {
        $$ = newExpNode(IdK);
        $$->attr.name = $1->attr.name;
        $$->child[0] = $3;
        $$->lineno = lineno;
        }
;

simple_exp: sum_exp rel sum_exp {
                  $$ = newStmtNode(AssignK);
                  $$ = $2;
                  $$->child[0] = $1;
                  $$->child[1] = $3;
                  $$->scope = scope;
              } | sum_exp{ $$ = $1; }
;

rel:          MEIQ 
              {
                $$ = newExpNode(OpK);
                $$->attr.op = MEIQ;
                $$->lineno = lineno;
              } 
            | MEQ {
                $$ = newExpNode(OpK);
                $$->attr.op = MEQ;
                $$->lineno = lineno;
              }
            | MAQ {
                $$ = newExpNode(OpK);
                $$->attr.op = MAQ;
                $$->lineno = lineno;
              }
            | MAIQ {
                $$ = newExpNode(OpK);
                $$->attr.op = MAIQ;
                $$->lineno = lineno;
              }
            | EQ {
                $$ = newExpNode(OpK);
                $$->attr.op = EQ;
                $$->lineno = lineno;
              }
            | NEQ {
                $$ = newExpNode(OpK);
                $$->attr.op = NEQ;
                $$->lineno = lineno;
              }
;

sum_exp: sum_exp sum ope {
            $$ = $2;
            $$->child[0] = $1;
            $$->child[1] = $3;
            $$->scope = scope;
            $$->lineno = lineno;
       }| ope { $$ = $1; }
;

sum: ADD {
         $$ = newExpNode(OpK);
         $$->attr.op = ADD;
         $$->lineno = lineno;
   }| SUB {
         $$ = newExpNode(OpK);
         $$->attr.op = SUB;
         $$->lineno = lineno;
       }
;

ope: ope mul fac {
              $$ = $2;
              $$->scope = scope;
              $$->child[0] = $1;
              $$->child[1] = $3;
              $$->lineno = lineno;
    }| fac { $$ = $1; }
;

mul: MUL {
         $$ = newExpNode(OpK);
         $$->attr.op = MUL;
         $$->lineno = lineno;
   }| DIV {
         $$ = newExpNode(OpK);
         $$->attr.op = DIV;
         $$->lineno = lineno;
       }
;

fac: LPAR exp RPAR { $$ = $2; } 
     | var { $$ = $1; }
     | acti { $$ = $1; params = 0; }
     | NUM { $$ = newExpNode(ConstK);
            $$->type = INTTYPE;
            $$->attr.val = atoi(tokenString); }
;

acti: fun-id LPAR arg_seq RPAR {
          $$ = newExpNode(CallK);
          $$->kind.exp = CallK;
          $$->attr.name = $1->attr.name;
          $$->child[0] = $3;
          $$->params = params;
          $$->lineno = lineno;

          if (strcmp($1->attr.name, "input") != 0 && strcmp($1->attr.name, "output") != 0) {
              Symbol *funcSymbol = lookupSymbol(st, $1->attr.name);
              if (funcSymbol == NULL || funcSymbol->idType != FUN_ID) {
                  printf("Erro Semântico: Chamada de função '%s' não declarada (linha %d)\n", 
                         $1->attr.name, lineno+1);
                  Error = 1;
              }
          }
       }| fun-id LPAR RPAR{
           $$ = newExpNode(CallK);
           $$->kind.exp = CallK;
           $$->attr.name = $1->attr.name;
           $$->params = params;
           $$->lineno = lineno;

           //Ignorar funções embutidas (input/output)
           if (strcmp($1->attr.name, "input") != 0 && strcmp($1->attr.name, "output") != 0) {
               Symbol *funcSymbol = lookupSymbol(st, $1->attr.name);
               if (funcSymbol == NULL || funcSymbol->idType != FUN_ID) {
                   printf("Erro Semântico: Chamada de função '%s' não declarada (linha %d)\n", 
                          $1->attr.name, lineno+1);
                   Error = 1;
               }
           }
         }
;


arg_seq: arg_seq VIRG exp {
              YYSTYPE t = $1;
              if (t != NULL){
                while (t->sibling != NULL)
                t = t->sibling;
                t->sibling = $3;
                params ++;
                $$ = $1;
              }
              else $$ = $3;
   }| exp { 
           params ++;
           $$ = $1; }
;

%%

int yyerror(char *message) {
    if (yychar == -2) return 0; 
    Error = TRUE;

    if (yychar == ERR) 
        printf("Erro léxico na linha %d. Lexema: ", lineno);
    else 
        printf("Erro sintático na linha %d. Token: ", lineno);

    switch (yychar) {
        case IF: printf("%s\n", tokenString); break;
        case RETURN: printf("%s\n", tokenString); break;
        case ELSE: printf("%s\n", tokenString); break;
        case INT: printf("%s\n", tokenString); break;
        case WHILE: printf("%s\n", tokenString); break;
        case VOID: printf("%s\n", tokenString); break;
        case EQ: printf("==\n"); break;
        case ASSIGN: printf("=\n"); break;
        case NEQ: printf("!=\n"); break;
        case MEQ: printf("<\n"); break;
        case MAQ: printf(">\n"); break;
        case MEIQ: printf("<=\n"); break;
        case MAIQ: printf(">=\n"); break;
        case LPAR: printf("(\n"); break;
        case RPAR: printf(")\n"); break;
        case LCO: printf("[\n"); break;
        case RCO: printf("]\n"); break;
        case LCHA: printf("{\n"); break;
        case RCHA: printf("}\n"); break;
        case END: printf(";\n"); break;
        case VIRG: printf(",\n"); break;
        case ADD: printf("+\n"); break;
        case SUB: printf("-\n"); break;
        case MUL: printf("*\n"); break;
        case DIV: printf("/\n"); break;
        case FIM: printf("EOF\n"); break;
        case NUM: printf("NUM, valor = %s\n", tokenString); break;
        case ID: printf("ID, lexema = %s\n", tokenString); break;
        case ERR: printf("%s\n", tokenString); break;
        default:
            printf("Token desconhecido: %d\n", yychar);
    }

    return 0;  
}


static int yylex(void){ 
  return getToken(); 
}

TreeNode * parse(void)
{ 
  st = createSymbolTable();  
  yyparse();

  printSymbolTable(st);

  checkUndeclared(st);
  checkTypeErrors(st);
  checkMainDeclared(st);

  return savedTree;
}
