%{
#include "globals.h"
#include "scan.h"
#include "util.h"

char tokenString[MAXTOKENLEN+1];
char id[MAXTOKENLEN+1];
char func[MAXTOKENLEN+1];
extern int yylex(void);
void novalinha();

int num_linhas = 0;
%}

digit      [0-9]
letter     [a-zA-Z]
novalinha  (\r\n|\n|\r)
outro      [^0-9a-zA-Z;/=\-+*(){[}><!,\t\]]
whitespace [\t]
%%


"/*"([^*]|\*+[^*/])*\*+"/"    { /* Ignorar comentários de bloco */ }
"//".*                         { /* Ignorar comentários de linha */ }

"else"                  {return ELSE;}
"if"                    {return IF;}
"int"                   {return INT;}
"return"                {return RETURN;}
"void"                  {return VOID;} 
"while"                 {return WHILE;}
"+"                     {return ADD;}
"-"                     {return SUB;}
"*"                     {return MUL;}
"/"                     {return DIV;}
">="                    {return MAIQ;}
"<="                    {return MEIQ;}
"=="                    {return EQ;}
"="                     {return ASSIGN;}
">"                     {return MAQ;}
"<"                     {return MEQ;}
"!="                    {return NEQ;}
","                     {return VIRG;}
";"                     {return END;}
"("                     {return LPAR;}
")"                     {return RPAR;}
"["                     {return LCO;}
"]"                     {return RCO;}
"{"                     {return LCHA;}
"}"                     {return RCHA;}
{letter}+               {return ID;}
{digit}+                {return NUM;}
({letter}|{digit})+     {return ERR;}
{novalinha}             {lineno ++;}
[ ]*                    { } 
{outro} {return ERR;}

%%

TokenType getToken(void)
{ static int firstTime = TRUE;
  TokenType currentToken;
  if (firstTime)
  { firstTime = FALSE;
    yyin = source;
    yyout = listing;
  }
  currentToken = yylex();
  if(currentToken == ID) strncpy(id,yytext,MAXTOKENLEN);
  strncpy(tokenString,yytext,MAXTOKENLEN);
  if (TraceScan) {
    fprintf(listing,"\t%d: ",lineno);
    printToken(currentToken,tokenString);
  }
  return currentToken;
}