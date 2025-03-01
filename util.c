#define INDENT indentno+=2
#define UNINDENT indentno-=2

#include "globals.h"
#include "util.h"

static int indentno = 0;

void printToken( TokenType token, const char* tokenString )
 { switch (token)
   { case IF:   fprintf(listing,"%s\n",tokenString);break;
     case RETURN:  fprintf(listing,"%s\n",tokenString);break;
     case ELSE: fprintf(listing,"%s\n",tokenString);break;
     case INT:  fprintf(listing,"%s\n",tokenString);break;
     case WHILE:  fprintf(listing,"%s\n",tokenString);break;
     case VOID: fprintf(listing,"%s\n",tokenString);break;
     case EQ: fprintf(listing,"==\n"); break;
     case ASSIGN: fprintf(listing,"=\n"); break;
     case NEQ: fprintf(listing,"!=\n"); break;
     case MEQ: fprintf(listing,"<\n"); break;
     case MAQ: fprintf(listing,">\n"); break;
     case MEIQ: fprintf(listing,"<=\n"); break;
     case MAIQ: fprintf(listing,">=\n"); break;
     case LPAR: fprintf(listing,"(\n"); break;
     case RPAR: fprintf(listing,")\n"); break;
     case LCO: fprintf(listing,"[\n"); break;
     case RCO: fprintf(listing,"]\n"); break;
     case LCHA: fprintf(listing,"{\n"); break;
     case RCHA: fprintf(listing,"}\n"); break;
     case END: fprintf(listing,";\n"); break;
     case VIRG: fprintf(listing,",\n"); break;
     case ADD: fprintf(listing,"+\n"); break;
     case SUB: fprintf(listing,"-\n"); break;
     case MUL: fprintf(listing,"*\n"); break;
     case DIV: fprintf(listing,"/\n"); break;
     case FIM: fprintf(listing,"EOF\n"); break;
     case NUM: fprintf(listing,"NUM, val = %s\n",tokenString);break;
     case ID:  fprintf(listing,"ID, nome = %s\n",tokenString);break;
     case ERR:
       fprintf(listing,
           "%s\n",tokenString);
       break;
     default: /* Nunca deve acontecer */
       fprintf(listing,"Token Desconhecido: %d\n",token);
   }
 }

TreeNode * newStmtNode(StmtKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = StmtK;
    t->kind.stmt = kind;
    t->lineno = lineno;
  }
  return t;
}

TreeNode * newExpNode(ExpKind kind)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = ExpK;
    t->kind.exp = kind;
    t->lineno = lineno;
    t->type = Void;
  }
  return t;
}

char * copyString(char * s)
{ int n;
  char * t;
  if (s==NULL) return NULL;
  n = strlen(s)+1;
  t = malloc(n);
  if (t==NULL)
    fprintf(listing,"Out of memory error at line %d\n",lineno);
  else strcpy(t,s);
  return t;
}

/* printSpaces indents by printing spaces */
static void printSpaces(void)
{ int i;
  for (i=0;i<indentno;i++)
    fprintf(listing," ");
}

void printTree( TreeNode * tree )
{ int i;
  INDENT;
  while (tree != NULL) {
    printSpaces();
    if (tree->nodekind==StmtK)
    { switch (tree->kind.stmt) {
        case IfK:
          fprintf(listing,"If\n");
          break;
        case WhileK:
          fprintf(listing,"While\n");
          break;
        case AssignK:
          fprintf(listing,"Assign: \n");
          break;
        case ReturnINT:
          fprintf(listing,"Return\n");
          break;
        case ReturnVOID:
          fprintf(listing,"Return\n");
          break;
        default:
          fprintf(listing,"Unknown StmtNode kind\n");
          break;
      }
    }
    else if (tree->nodekind==ExpK){
    switch (tree->kind.exp) {
        case OpK:
          fprintf(listing,"Op: ");
          printToken(tree->attr.op,"\0");
          break;
        case ConstK:
          fprintf(listing,"Const: %d\n",tree->attr.val);
          break;
        case IdK:
          fprintf(listing,"Id: %s\n",tree->attr.name);
          break;
        case VarDeclK:
          fprintf(listing,"Var: %s\n",tree->attr.name);
          break;
        case FunctionK:
          fprintf(listing,"Func: %s\n",tree->attr.name);
          break;
        case CallK:
          fprintf(listing,"Chamada da Função: %s\n",tree->attr.name);
          break;
        case TypeK:
          fprintf(listing,"Tipo: %s\n",tree->attr.name);
          break;
        case VarParamK:
          fprintf(listing,"Parametro: %s\n",tree->attr.name);
          break; 
        case VetParamK:
          fprintf(listing,"Parametro: %s\n",tree->attr.name);
          break;
        case VetorK:
          fprintf(listing, "Vetor: %s", tree->attr.name);
	        break;
        default:
          fprintf(listing,"Unknown ExpNode kind: %d\n", tree->nodekind);
          break;
      }
    }
    else fprintf(listing,"Unknown Node kind\n");
    for (i=0;i<MAXCHILDREN;i++)
          printTree(tree->child[i]);
    tree = tree->sibling;
  }
  UNINDENT;
}