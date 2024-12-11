%{
#include <stdio.h>
#include <string.h>

char tokenString[1024]; // Buffer para armazenar tokens de uma linha
char lineContent[1024]; // Buffer para armazenar o texto original de uma linha
int lineno = 0;         // Contador de linhas
%}

digit      [0-9]
letter     [a-zA-Z]
novalinha  (\r\n|\n|\r)
outro      [^0-9a-zA-Z;/=\-+*(){[}><!,\t\]]
whitespace [\t]
%%

{novalinha} {
    lineno++;
    if (strlen(tokenString) > 0) { 
        printf("%s\t\t%s\n", tokenString, lineContent);
        tokenString[0] = '\0'; 
        lineContent[0] = '\0'; 
    } 
}


"/*"([^*]|\*+[^*/])*\*+"/"    { /* Ignorar comentários de bloco */ }
"//".*                         { /* Ignorar comentários de linha */ }

"else"                  { strcat(tokenString, " ELSE"); strcat(lineContent, yytext); }
"if"                    { strcat(tokenString, " IF"); strcat(lineContent, yytext); }
"int"                   { strcat(tokenString, " INT"); strcat(lineContent, yytext); }
"return"                { strcat(tokenString, " RETURN"); strcat(lineContent, yytext); }
"void"                  { strcat(tokenString, " VOID"); strcat(lineContent, yytext); }
"while"                 { strcat(tokenString, " WHILE"); strcat(lineContent, yytext); }
"+"                     { strcat(tokenString, " ADD"); strcat(lineContent, yytext); }
"-"                     { strcat(tokenString, " SUB"); strcat(lineContent, yytext); }
"*"                     { strcat(tokenString, " MUL"); strcat(lineContent, yytext); }
"/"                     { strcat(tokenString, " DIV"); strcat(lineContent, yytext); }
">="                    { strcat(tokenString, " MAIQ"); strcat(lineContent, yytext); }
"<="                    { strcat(tokenString, " MEIQ"); strcat(lineContent, yytext); }
"=="                    { strcat(tokenString, " EQ"); strcat(lineContent, yytext); }
"="                     { strcat(tokenString, " ASSIGN"); strcat(lineContent, yytext); }
">"                     { strcat(tokenString, " MAQ"); strcat(lineContent, yytext); }
"<"                     { strcat(tokenString, " MEQ"); strcat(lineContent, yytext); }
"!="                    { strcat(tokenString, " NEQ"); strcat(lineContent, yytext); }
","                     { strcat(tokenString, " VIRG"); strcat(lineContent, yytext); }
";"                     { strcat(tokenString, " PEV"); strcat(lineContent, yytext); }
"("                     { strcat(tokenString, " LPAR"); strcat(lineContent, yytext); }
")"                     { strcat(tokenString, " RPAR"); strcat(lineContent, yytext); }
"["                     { strcat(tokenString, " LCO"); strcat(lineContent, yytext); }
"]"                     { strcat(tokenString, " RCO"); strcat(lineContent, yytext); }
"{"                     { strcat(tokenString, " LCHA"); strcat(lineContent, yytext); }
"}"                     { strcat(tokenString, " RCHA"); strcat(lineContent, yytext); }
{letter}+               { strcat(tokenString, " ID"); strcat(lineContent, yytext); }
{digit}+                { strcat(tokenString, " NUM"); strcat(lineContent, yytext); }
({letter}|{digit})+     { strcat(tokenString, " ERRO!"); strcat(lineContent, yytext); }
[ ]*                    { strcat(lineContent, yytext); } 
{outro} {
    printf("ERRO LÉXICO NA LINHA %d: Caractere inválido %s\n", lineno, yytext);
    strcat(lineContent, yytext); 
}

%%

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Erro ao abrir o arquivo: %s\n", argv[1]);
            return 1;
        }
        yyin = file;
    }

    yylex();

    if (strlen(tokenString) > 0) {
        printf("%s\t\t%s\n", tokenString, lineContent);
    }

    return 0;
}
