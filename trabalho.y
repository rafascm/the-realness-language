%{
#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

int yylex();
void yyerror( const char* st );

// Faz o mapeamento dos tipos dos operadores
map< string, string > tipo_opr;

// Pilha de variáveis temporárias para cada bloco
vector< string > var_temp;

#define MAX_DIM 2

struct Tipo {
  string tipo_base;
  int ndim;
  int inicio[MAX_DIM];
  int fim[MAX_DIM];

  Tipo() {} // Construtor Vazio

  Tipo( string tipo ) {
    tipo_base = tipo;
    ndim = 0;
  }

  Tipo( string base, int inicio, int fim  ) {
    tipo_base = base;
    ndim = 1;
    this->inicio[0] = inicio;
    this->fim[0] = fim;
  }
};

struct Atributos {
  string v, c; // Valor, tipo e código gerado.
  Tipo t;
  vector<string> lista; // Uma lista auxiliar.

  Atributos() {} // Constutor vazio
  Atributos( string valor ) {
    v = valor;
  }

  Atributos( string valor, Tipo tipo ) {
    v = valor;
    t = tipo;
  }
};

// Declarar todas as funções que serão usadas.
void insere_ts( string nome_var, Tipo tipo );
Tipo consulta_ts( string nome_var );
string gera_nome_var_temp( string tipo );
string gera_label( string tipo );
void debug( string producao, Atributos atr );
int toInt( string valor );
string toString( int n );

Atributos gera_codigo_operador( Atributos s1, string opr, Atributos s3 );
Atributos gera_codigo_if( Atributos expr, string cmd_then, string cmd_else );

string traduz_nome_tipo_pascal( string tipo_pascal );
string traduz_nome_tipo_interno( string tipo_interno );

string includes =
"#include <iostream>\n"
"#include <stdio.h>\n"
"#include <stdlib.h>\n"
"\n"
"using namespace std;\n";


#define YYSTYPE Atributos

%}

%token TK_ID TK_CINT TK_CDOUBLE TK_VAR TK_PROGRAM TK_BEGIN TK_END TK_ATRIB
%token TK_WRITELN TK_CSTRING
%token TK_MAIG TK_MEIG TK_DIF TK_IF TK_THEN TK_ELSE TK_AND
%token TK_FOR TK_TO TK_DO TK_ARRAY TK_OF TK_PTPT
%token TK_ABRIR1 TK_FECHAR

%left TK_AND
%nonassoc '<' '>' TK_MAIG TK_MEIG '=' TK_DIF
%left '+' '-'
%left '*' '/'

%%

S :  ABRIR1 PROGRAM DECLS MAIN FECHAR
    {
      cout << includes << endl;
      cout << $3.c << endl;
      cout << $4.c << endl;
    }
  ;

ABRIR1 : TK_ABRIR1 ';'
        {$$.c = "";}
      ;

FECHAR : TK_FECHAR ';'
          {$$.c = "";}
        ;

PROGRAM : TK_PROGRAM TK_ID ';'
          { $$.c = ""; }
        ;

DECLS : DECL DECLS
        { $$.c = $1.c + $2.c; }
      |
        { $$.c = ""; }
      ;

DECL : VARS
       { $$.c = $1.c; }
     ;

VARS : VAR ';' VARS
       { $$.c = $1.c + $3.c; }
     |
       { $$.c = ""; }
     ;

VAR : TK_ID IDS
      {
        Tipo tipo = Tipo( traduz_nome_tipo_pascal( $1.v ) );
        string tipo_em_c = traduz_nome_tipo_interno( tipo.tipo_base );

        $$ = Atributos();

        for( int i = 0; i < $2.lista.size(); i ++ ) {
          $$.c += tipo_em_c + " " + $2.lista[i] + ";\n";
          insere_ts( $2.lista[i], tipo );
        }
      }
    | IDS ':' TK_ARRAY '[' TK_CINT TK_PTPT TK_CINT ']' TK_OF TK_ID
      {
        Tipo tipo = Tipo( traduz_nome_tipo_pascal( $10.v ),
                          toInt( $5.v ), toInt( $7.v ) );
        string tipo_em_c = traduz_nome_tipo_interno( tipo.tipo_base );

        $$ = Atributos();

        for( int i = 0; i < $1.lista.size(); i ++ ) {
          $$.c += tipo_em_c + " " + $1.lista[i] + "[" +
                  toString( toInt( $7.v ) - toInt( $5.v ) + 1 ) + "];\n";
          insere_ts( $1.lista[i], tipo );
        }
      }
    ;

IDS : IDS ',' TK_ID
      { $$  = $1;
        $$.lista.push_back( $3.v ); }
    | TK_ID
      { $$ = Atributos();
        $$.lista.push_back( $1.v ); }
    ;

MAIN : BLOCO '.'
       { $$.c = "int main()\n" + $1.c; }
     ;

BLOCO : TK_BEGIN { var_temp.push_back( "" );} CMDS TK_END
        { string vars = var_temp[var_temp.size()-1];
          var_temp.pop_back();
          $$.c = "{\n" + vars + $3.c + "}\n"; }
      ;

CMDS : CMD ';' CMDS
       { $$.c = $1.c + $3.c; }
     | { $$.c = ""; }
     ;

CMD : WRITELN
    | ATRIB
    | CMD_IF
    | BLOCO
    | CMD_FOR
    ;

CMD_FOR : TK_FOR NOME_VAR TK_ATRIB E TK_TO E TK_DO CMD
          {
            string var_fim = gera_nome_var_temp( $2.t.tipo_base );
            string label_teste = gera_label( "teste_for" );
            string label_fim = gera_label( "fim_for" );
            string condicao = gera_nome_var_temp( "b" );

            // Falta verificar os tipos... perde ponto se não o fizer.
            $$.c =  $4.c + $6.c +
                    "  " + $2.v + " = " + $4.v + ";\n" +
                    "  " + var_fim + " = " + $6.v + ";\n" +
                    label_teste + ":;\n" +
                    "  " +condicao+" = "+$2.v + " > " + var_fim + ";\n" +
                    "  " + "if( " + condicao + " ) goto " + label_fim +
                    ";\n" +
                    $8.c +
                    "  " + $2.v + " = " + $2.v + " + 1;\n" +
                    "  goto " + label_teste + ";\n" +
                    label_fim + ":;\n";
          }
        ;

CMD_IF : TK_IF E TK_THEN CMD
         { $$ = gera_codigo_if( $2, $4.c, "" ); }
       | TK_IF E TK_THEN CMD TK_ELSE CMD
         { $$ = gera_codigo_if( $2, $4.c, $6.c ); }
       ;


WRITELN : TK_WRITELN '(' E ')'
          { $$.c = $3.c +
                   "  cout << " + $3.v + ";\n"
                   "  cout << endl;\n";
          }
        ;

ATRIB : TK_ID TK_ATRIB E
        { // Falta verificar se pode atribuir.
          $$.c = $3.c + "  " + $1.v + " = " + $3.v + ";\n";
          debug( "ATRIB : TK_ID TK_ATRIB E ';'", $$ );
        }
      | TK_ID '[' E ']' TK_ATRIB E
        { // Falta testar: tipo, limite do array, e se a variável existe
          $$.c = $3.c + $6.c +
                 "  " + $1.v + "[" + $3.v + "] = " + $6.v + ";\n";
        }
      ;

E : E '+' E
    { $$ = gera_codigo_operador( $1, "+", $3 ); }
  | E '-' E
    { $$ = gera_codigo_operador( $1, "-", $3 ); }
  | E '*' E
    { $$ = gera_codigo_operador( $1, "*", $3 ); }
  | E '/' E
    { $$ = gera_codigo_operador( $1, "/", $3 ); }
  | E '<' E
    { $$ = gera_codigo_operador( $1, "<", $3 ); }
  | E '>' E
    { $$ = gera_codigo_operador( $1, ">", $3 ); }
  | E TK_MEIG E
    { $$ = gera_codigo_operador( $1, "<=", $3 ); }
  | E TK_MAIG E
    { $$ = gera_codigo_operador( $1, ">=", $3 ); }
  | E '=' E
    { $$ = gera_codigo_operador( $1, "==", $3 ); }
  | E TK_DIF E
    { $$ = gera_codigo_operador( $1, "!=", $3 ); }
  | E TK_AND E
    { $$ = gera_codigo_operador( $1, "&&", $3 ); }
  | '(' E ')'
    { $$ = $2; }
  | F
  ;

F : NOME_VAR
  | TK_CINT
    { $$.v = $1.v; $$.t = Tipo( "i" ); $$.c = $1.c; }
  | TK_CDOUBLE
    { $$.v = $1.v; $$.t = Tipo( "d" ); $$.c = $1.c; }
  | TK_CSTRING
    { $$.v = $1.v; $$.t = Tipo( "s" ); $$.c = $1.c; }
  | TK_ID '[' E ']'
    { // Falta testar se é array E diminuir uma dimensão.
      $$.t = Tipo( consulta_ts( $1.v ).tipo_base );
      $$.v = gera_nome_var_temp( $$.t.tipo_base );
      $$.c = $3.c +
             "  " + $$.v + " = " + $1.v + "[" + $3.v + "];\n";
    }
  ;

NOME_VAR : TK_ID
             { $$.v = $1.v; $$.t = consulta_ts( $1.v ); $$.c = $1.c; }
           ;

%%
int nlinha = 1;

#include "lex.yy.c"

int yyparse();

void debug( string producao, Atributos atr ) {
/*
  cerr << "Debug: " << producao << endl;
  cerr << "  t: " << atr.t << endl;
  cerr << "  v: " << atr.v << endl;
  cerr << "  c: " << atr.c << endl;
*/
}

void yyerror( const char* st )
{
  printf( "%s", st );
  printf( "Linha: %d, \"%s\"\n", nlinha, yytext );
}

void erro( string msg ) {
  cerr << "Erro: " << msg << endl;
  fprintf( stderr, "Linha: %d, [%s]\n", nlinha, yytext );
  exit(1);
}

void inicializa_operadores() {
  // Resultados para o operador "+"
  tipo_opr["i+i"] = "i";
  tipo_opr["i+d"] = "d";
  tipo_opr["d+i"] = "d";
  tipo_opr["d+d"] = "d";
  tipo_opr["s+s"] = "s";
  tipo_opr["c+s"] = "s";
  tipo_opr["s+c"] = "s";
  tipo_opr["c+c"] = "s";

  // Resultados para o operador "-"
  tipo_opr["i-i"] = "i";
  tipo_opr["i-d"] = "d";
  tipo_opr["d-i"] = "d";
  tipo_opr["d-d"] = "d";

  // Resultados para o operador "*"
  tipo_opr["i*i"] = "i";
  tipo_opr["i*d"] = "d";
  tipo_opr["d*i"] = "d";
  tipo_opr["d*d"] = "d";

  // Resultados para o operador "/"
  tipo_opr["i/i"] = "d";
  tipo_opr["i/d"] = "d";
  tipo_opr["d/i"] = "d";
  tipo_opr["d/d"] = "d";

  // Resultados para o operador "<"
  tipo_opr["i<i"] = "b";
  tipo_opr["i<d"] = "b";
  tipo_opr["d<i"] = "b";
  tipo_opr["d<d"] = "b";
  tipo_opr["c<c"] = "b";
  tipo_opr["i<c"] = "b";
  tipo_opr["c<i"] = "b";
//  tipo_opr["c<s"] = "b";
//  tipo_opr["s<c"] = "b";
//  tipo_opr["s<s"] = "b";

  // Resultados para o operador "And"
  tipo_opr["b&&b"] = "b";
}

map< string, Tipo > ts;

Tipo consulta_ts( string nome_var ) {
  if( ts.find( nome_var ) == ts.end() )
    erro( "Variável não declarada: " + nome_var );

  return ts[ nome_var ];
}

void insere_ts( string nome_var, Tipo tipo ) {
  if( ts.find( nome_var ) != ts.end() )
    erro( "Variável já declarada: " + nome_var +
          " (" + ts[ nome_var ].tipo_base + ")" );

  ts[ nome_var ] = tipo;
}

string toString( int n ) {
  char buff[100];

  sprintf( buff, "%d", n );

  return buff;
}

int toInt( string valor ) {
  int aux = -1;

  if( sscanf( valor.c_str(), "%d", &aux ) != 1 )
    erro( "Numero inválido: " + valor );

  return aux;
}
string gera_nome_var_temp( string tipo ) {
  static int n = 0;
  string nome = "t" + tipo + "_" + toString( ++n );

  var_temp[var_temp.size()-1] += traduz_nome_tipo_interno( tipo ) + " " + nome + ";\n";

  return nome;
}

string gera_label( string tipo ) {
  static int n = 0;
  string nome = "l_" + tipo + "_" + toString( ++n );

  return nome;
}

Tipo tipo_resultado( Tipo t1, string opr, Tipo t3 ) {
  if( t1.ndim == 0 && t3.ndim == 0 ) {
    string aux = tipo_opr[ t1.tipo_base + opr + t3.tipo_base ];

    if( aux == "" )
      erro( "O operador " + opr + " não está definido para os tipos '" +
            t1.tipo_base + "' e '" + t3.tipo_base + "'.");

    return Tipo( aux );
  }
  else { // Testes para os operadores de comparacao de array
    return Tipo();
  }
}

Atributos gera_codigo_operador( Atributos s1, string opr, Atributos s3 ) {
  Atributos ss;

  ss.t = tipo_resultado( s1.t, opr, s3.t );
  ss.v = gera_nome_var_temp( ss.t.tipo_base );
  ss.c = s1.c + s3.c + // Codigo das expressões dos filhos da arvore.
          "  " + ss.v + " = " + s1.v + " " + opr + " " + s3.v + ";\n";

  debug( "E: E " + opr + " E", ss );
  return ss;
}

Atributos gera_codigo_if( Atributos expr, string cmd_then, string cmd_else ) {
  Atributos ss;
  string label_else = gera_label( "else" );
  string label_end = gera_label( "end" );

  ss.c = expr.c +
         "  " + expr.v + " = !" + expr.v + ";\n\n" +
         "  if( " + expr.v + " ) goto " + label_else + ";\n" +
         cmd_then +
         "  goto " + label_end + ";\n" +
         label_else + ":;\n" +
         cmd_else +
         label_end + ":;\n";

  return ss;
}


string traduz_nome_tipo_pascal( string tipo_pascal ) {
  // No caso do Pascal, a comparacao deveria ser case-insensitive

  if( tipo_pascal == "Integer" )
    return "i";
  else if( tipo_pascal == "Boolean" )
    return "b";
  else if( tipo_pascal == "Double" )
    return "d";
  else if( tipo_pascal == "Char" )
    return "c";
  else if( tipo_pascal == "String" )
    return "s";
  else
    erro( "Tipo inválido: " + tipo_pascal );
}

string traduz_nome_tipo_interno( string tipo_interno ) {
  if( tipo_interno == "i" )
    return "int";
  else if( tipo_interno == "b" )
    return "int";
  else if( tipo_interno == "d" )
    return "double";
  else if( tipo_interno == "c" )
    return "char";
  else if( tipo_interno == "s" )
    return "string";
  else
    erro( "Tipo inválido: " + tipo_interno );
}


int main( int argc, char* argv[] )
{
  inicializa_operadores();
  yyparse();
}
