#include "globals.h"

/* set NO_PARSE to TRUE to get a scanner-only compiler */
#define NO_PARSE FALSE
/* set NO_ANALYZE to TRUE to get a parser-only compiler */
#define NO_ANALYZE FALSE

/* set NO_CODE to TRUE to get a compiler that does not
 * generate code
 */
#define NO_CODE FALSE

#include "util.h"
#if NO_PARSE
#include "scan.h"
#else
#include "parse.h"  // Incluindo o arquivo gerado pelo Bison
#endif

int lineno = 0;
FILE * source;
FILE * listing;
FILE * code;

/* allocate and set tracing flags */
int EchoSource = FALSE;
int TraceScan = FALSE;
int TraceParse = TRUE;
int TraceAnalyze = FALSE;
int TraceCode = FALSE;

int Error = FALSE;


int main(int argc, char *argv[]) {
  TreeNode *syntaxTree;
  char pgm[120]; /* source code file name */
  
  if (argc != 2) {
    fprintf(stderr, "usage: %s <filename>\n", argv[0]);
    exit(1);
  }
  
  strcpy(pgm, argv[1]);
  if (strchr(pgm, '.') == NULL)
    strcat(pgm, ".txt");
  
  source = fopen(pgm, "r");
  if (source == NULL) {
    fprintf(stderr, "File %s not found\n", pgm);
    exit(1);
  }

  listing = stdout; /* send listing to screen */
  fprintf(listing, "\nCOMPILACAO C MENOS: %s\n", pgm);
  
  #if NO_PARSE
    while (getToken() != ENDFILE);
  #else
    syntaxTree = parse();
    if (TraceParse){
      if (syntaxTree == NULL) {
        fprintf(listing, "Erro: Árvore sintática não foi gerada devido a um erro sintático\n");
      } else {
        fprintf(listing, "\nÁrvore Sintática:\n");
        printTree(syntaxTree);
    }
  }
  #endif

  
  fclose(source);
  return 0;
}
