%{
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int yylex();
void yyerror( const char* st );

#define YYSTYPE string
%}

%token TK_MAIN TK_ID TK_VALOR TK_IF TK_GOTO TK_RETURN TK_INT TK_CHAR 
%token TK_FLOAT TK_DOUBLE TK_LONG TK_AND TK_OR TK_IGUAL TK_DIF TK_MAIGUAL TK_MEIGUAL
%token TK_CINT TK_CCHAR TK_CDOUBLE TK_VOID TK_CIN TK_COUT TK_ENDL
%token TK_INCLUDE TK_ID_INC TK_STR TK_NAMESPACE

%%

S : INCLUDE VARIAVEIS LISTAF { cout << "Aceito" << endl; } 
  ;

INCLUDE : TK_INCLUDE TK_ID_INC INCLUDE
	    | NAMESPACE	INCLUDE
	    |
        ;
        
NAMESPACE : TK_NAMESPACE ';'
          ;        

LISTAF : FUN LISTAF 
       | MAIN 
       ;

FUN : TIPO TK_ID '(' ARGUMENTOS ')' CORPO 
    | TK_VOID TK_ID '(' ARGUMENTOS ')' CORPO 
    ;

MAIN : TK_INT TK_MAIN '(' ')' BLOCO 
     ; 

CORPO : BLOCO 
      | ';' 
      ;

BLOCO : '{' VARIAVEIS COMANDOS '}' 
      ; 

ARGUMENTOS : ARGUMENTO
           | 
           ;

ARGUMENTO : TIPO NOMEARG ARRAY ',' ARGUMENTO 
          | TIPO NOMEARG ARRAY 
          ;

NOMEARG : TK_ID
        |
        ;

VARIAVEIS : VARIAVEIS TIPO VAR ';' 
          | 
          ;

TIPO : TK_INT
     | TK_CHAR
     | TK_FLOAT
     | TK_DOUBLE
     | TK_LONG
     ;

VAR : TK_ID ARRAY
    | TK_ID ARRAY ',' VAR
    ;

ARRAY : '[' TK_CINT ']' 
      | '[' ']'
      | 
      ;

COMANDOS : COMANDO ';' COMANDOS
	   |
	   ;

COMANDO : CMD_IF
        | CMD_GOTO
        | CMD_LABEL
        | CMD_ATRIB
        | CMD_PROC
        | CMD_RETURN
        | CMD_CIN
        | CMD_COUT
	|
        ;

CMD_CIN : TK_CIN TK_ID
        ;

CMD_COUT : TK_COUT F
         | TK_COUT TK_ENDL
         ; 

CMD_IF : TK_IF '(' F ')' CMD_GOTO
       ;

CMD_GOTO : TK_GOTO TK_ID
         ;

CMD_LABEL : TK_ID ':' COMANDO
	  ;

CMD_ATRIB : TK_ID '=' OP
          | TK_ID '[' INDICE ']' '=' F
	  ;

CMD_RETURN : TK_RETURN F
           | TK_RETURN
           ;

CMD_PROC : TK_ID '(' ')'
         | TK_ID '(' PARAMS ')'
         ;

OP : F '+' F
   | F '-' F
   | F '*' F
   | F '/' F
   | F '%' F
   | F TK_AND F
   | F TK_OR F
   | F TK_IGUAL F
   | F '>' F
   | F '<' F
   | F TK_MEIGUAL F
   | F TK_MAIGUAL F
   | F TK_DIF F
   | F 
   | '-' F 
   | '!' F
   | TK_ID '[' INDICE ']'
   | TK_ID '(' PARAMS ')'
   | TK_ID '(' ')'
   ;

F : TK_CINT
  | TK_CCHAR
  | TK_CDOUBLE 
  | TK_ID
  | TK_STR
  ;

PARAMS : F ',' PARAMS
       | F

INDICE : TK_CINT
       | TK_ID
       ;


%%
int nlinha = 1;

#include "lex.yy.c"

int yyparse();

void yyerror( const char* st )
{
  puts( st );
  printf( "Linha: %d\n", nlinha );
}

int main( int argc, char* argv[] )
{
  yyparse();
}
