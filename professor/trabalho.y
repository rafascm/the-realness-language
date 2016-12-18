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
void erro( string msg );

// Faz o mapeamento dos tipos dos operadores
map< string, string > tipo_opr;

// Pilha de variáveis temporárias para cada bloco
vector< string > var_temp;

#define MAX_DIM 2

enum TIPO { FUNCAO = -1, BASICO = 0, VETOR = 1, MATRIZ = 2 };

struct Tipo {
  string tipo_base;
  TIPO ndim;
  int inicio[MAX_DIM];
  int fim[MAX_DIM];
  vector<Tipo> retorno; // usando vector por dois motivos:
  // 1) Para não usar ponteiros
  // 2) Para ser genérico. Algumas linguagens permitem mais de um valor
  //    de retorno.
  vector<Tipo> params;

  Tipo() {} // Construtor Vazio

  Tipo( string tipo ) {
    tipo_base = tipo;
    ndim = BASICO;
  }

  Tipo( string base, int inicio, int fim  ) {
    tipo_base = base;
    ndim = VETOR;
    this->inicio[0] = inicio;
    this->fim[0] = fim;
  }

  Tipo( string base, int inicio_1, int fim_1, int inicio_2, int fim_2  ) {
    tipo_base = base;
    ndim = MATRIZ;
    this->inicio[0] = inicio_1;
    this->fim[0] = fim_1;
    this->inicio[1] = inicio_2;
    this->fim[1] = fim_2;
  }

  Tipo( Tipo retorno, vector<Tipo> params ) {
    ndim = FUNCAO;
    this->retorno.push_back( retorno );
    this->params = params;
  }
};

struct Atributos {
  string v, c; // Valor, tipo e código gerado.
  Tipo t;
  vector<string> lista_str; // Uma lista auxiliar de strings.
  vector<Tipo> lista_tipo; // Uma lista auxiliar de tipos.

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
void insere_var_ts( string nome_var, Tipo tipo );
void insere_funcao_ts( string nome_func, Tipo retorno, vector<Tipo> params );
Tipo consulta_ts( string nome_var );
string declara_variavel( string nome, Tipo tipo );
string declara_funcao( string nome, Tipo retorno,
                       vector<string> nomes, vector<Tipo> tipos );

void empilha_ts();
void desempilha_ts();

string gera_nome_var_temp( string tipo );
string gera_label( string tipo );
string gera_teste_limite_array( string indice_1, Tipo tipoArray );
string gera_teste_limite_array( string indice_1, string indice_2,
                                Tipo tipoArray );

void debug( string producao, Atributos atr );
int toInt( string valor );
string toString( int n );

Atributos gera_codigo_operador( Atributos s1, string opr, Atributos s3 );
Atributos gera_codigo_if( Atributos expr, string cmd_then, string cmd_else );

string traduz_nome_tipo_pascal( string tipo_pascal );

string includes =
"#include <iostream>\n"
"#include <stdio.h>\n"
"#include <stdlib.h>\n"
"#include <string.h>\n"
"\n"
"using namespace std;\n";


#define YYSTYPE Atributos

%}

%token TK_ID TK_CINT TK_CDOUBLE TK_VAR TK_PROGRAM TK_BEGIN TK_END TK_ATRIB
%token TK_WRITELN TK_CSTRING TK_FUNCTION TK_MOD
%token TK_MAIG TK_MEIG TK_DIF TK_IF TK_THEN TK_ELSE TK_AND
%token TK_FOR TK_TO TK_DO TK_ARRAY TK_OF TK_PTPT

%left TK_AND
%nonassoc '<' '>' TK_MAIG TK_MEIG '=' TK_DIF
%left '+' '-'
%left '*' '/' TK_MOD

%%

S : PROGRAM DECLS MAIN
    {
      cout << includes << endl;
      cout << $2.c << endl;
      cout << $3.c << endl;
    }
  ;

PROGRAM : TK_PROGRAM TK_ID ';'
          { $$.c = "";
            empilha_ts(); }
        ;

DECLS : DECL DECLS
        { $$.c = $1.c + $2.c; }
      |
        { $$.c = ""; }
      ;

DECL : TK_VAR VARS
       { $$.c = $2.c; }
     | FUNCTION
     ;

FUNCTION : { empilha_ts(); }  CABECALHO ';' CORPO { desempilha_ts(); } ';'
           { $$.c = $2.c + " {\n" + $4.c +
                    " return Result;\n}\n"; }
         ;

CABECALHO : TK_FUNCTION TK_ID OPC_PARAM ':' TK_ID
            {
              Tipo tipo( traduz_nome_tipo_pascal( $5.v ) );

              $$.c = declara_funcao( $2.v, tipo, $3.lista_str, $3.lista_tipo );
            }
          ;

OPC_PARAM : '(' PARAMS ')'
            { $$ = $2; }
          |
            { $$ = Atributos(); }
          ;

PARAMS : PARAM ';' PARAMS
         { $$.c = $1.c + $3.c;
           // Concatenar as listas.
           $$.lista_tipo = $1.lista_tipo;
           $$.lista_tipo.insert( $$.lista_tipo.end(),
                                 $3.lista_tipo.begin(),
                                 $3.lista_tipo.end() );
           $$.lista_str = $1.lista_str;
           $$.lista_str.insert( $$.lista_str.end(),
                                $3.lista_str.begin(),
                                $3.lista_str.end() );
         }
       | PARAM
       ;

PARAM : IDS ':' TK_ID
      {
        Tipo tipo = Tipo( traduz_nome_tipo_pascal( $3.v ) );

        $$ = Atributos();
        $$.lista_str = $1.lista_str;

        for( int i = 0; i < $1.lista_str.size(); i ++ )
          $$.lista_tipo.push_back( tipo );
      }
    | IDS ':' TK_ARRAY '[' TK_CINT TK_PTPT TK_CINT ']' TK_OF TK_ID
      {
        Tipo tipo = Tipo( traduz_nome_tipo_pascal( $10.v ),
                          toInt( $5.v ), toInt( $7.v ) );

        $$ = Atributos();
        $$.lista_str = $1.lista_str;

        for( int i = 0; i < $1.lista_str.size(); i ++ )
          $$.lista_tipo.push_back( tipo );
      }
    ;

CORPO : TK_VAR VARS BLOCO
        { $$.c = declara_variavel( "Result", consulta_ts( "Result" ) ) + ";\n" +
                 $2.c + $3.c; }
      | BLOCO
        { $$.c = declara_variavel( "Result", consulta_ts( "Result" ) ) + ";\n" +
                 $1.c; }
      ;

VARS : VAR ';' VARS
       { $$.c = $1.c + $3.c; }
     |
       { $$ = Atributos(); }
     ;

VAR : IDS ':' TK_ID
      {
        Tipo tipo = Tipo( traduz_nome_tipo_pascal( $3.v ) );

        $$ = Atributos();

        for( int i = 0; i < $1.lista_str.size(); i ++ ) {
          $$.c += declara_variavel( $1.lista_str[i], tipo ) + ";\n";
          insere_var_ts( $1.lista_str[i], tipo );
        }
      }
    | IDS ':' TK_ARRAY '[' TK_CINT TK_PTPT TK_CINT ']' TK_OF TK_ID
      {
        Tipo tipo = Tipo( traduz_nome_tipo_pascal( $10.v ),
                          toInt( $5.v ), toInt( $7.v ) );

        $$ = Atributos();

        for( int i = 0; i < $1.lista_str.size(); i ++ ) {
          $$.c += declara_variavel( $1.lista_str[i], tipo ) + ";\n";
          insere_var_ts( $1.lista_str[i], tipo );
        }
      }
    ;

IDS : IDS ',' TK_ID
      { $$  = $1;
        $$.lista_str.push_back( $3.v ); }
    | TK_ID
      { $$ = Atributos();
        $$.lista_str.push_back( $1.v ); }
    ;

MAIN : BLOCO '.'
       { $$.c = "int main() { \n" + $1.c + "}\n"; }
     ;

BLOCO : TK_BEGIN { var_temp.push_back( "" );} CMDS TK_END
        { string vars = var_temp[var_temp.size()-1];
          var_temp.pop_back();
          $$.c = vars + $3.c; }
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
        { // Falta verificar se pode atribuir (perde ponto se não fizer).
          $1.t = consulta_ts( $1.v ) ;

          if( $1.t.tipo_base == "s" )
            $$.c = $3.c + "  strncpy( " + $1.v + ", " + $3.v + ", 256 );\n";
          else
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
  | E TK_MOD E
    { $$ = gera_codigo_operador( $1, "%", $3 ); }
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

F : TK_CINT
    { $$.v = $1.v; $$.t = Tipo( "i" ); $$.c = $1.c; }
  | TK_CDOUBLE
    { $$.v = $1.v; $$.t = Tipo( "d" ); $$.c = $1.c; }
  | TK_CSTRING
    { $$.v = $1.v; $$.t = Tipo( "s" ); $$.c = $1.c; }
  | TK_ID '[' E ']'
    {
      Tipo tipoArray = consulta_ts( $1.v );
      $$.t = Tipo( tipoArray.tipo_base );
      if( tipoArray.ndim != 1 )
        erro( "Variável " + $1.v + " não é array de uma dimensão" );

      if( $3.t.ndim != 0 || $3.t.tipo_base != "i" )
        erro( "Indice de array deve ser integer de zero dimensão: " +
              $3.t.tipo_base + "/" + toString( $3.t.ndim ) );

      $$.v = gera_nome_var_temp( $$.t.tipo_base );
      $$.c = $3.c +
             gera_teste_limite_array( $3.v, tipoArray ) +
             "  " + $$.v + " = " + $1.v + "[" + $3.v + "];\n";
    }
  | TK_ID '[' E ']' '[' E ']'
    {
      // Implementar: vai criar uma temporaria int para o índice e
      // outra do tipoBase do array para o valor recuperado.
    }
  | TK_ID
    { $$.v = $1.v; $$.t = consulta_ts( $1.v ); $$.c = $1.c; }
  | TK_ID '(' EXPRS ')'
    { $$.t = Tipo( "i" ); // consulta_ts( $1.v );
    // Falta verficar o tipo da função e os parametros.
      $$.v = gera_nome_var_temp( $$.t.tipo_base );
      $$.c = $3.c + "  " + $$.v + " = " + $1.v + "( ";

      for( int i = 0; i < $3.lista_str.size() - 1; i++ )
        $$.c += $3.lista_str[i] + ", ";

      $$.c += $3.lista_str[$3.lista_str.size()-1] + " );\n";
    }
  ;


EXPRS : EXPRS ',' E
        { $$ = Atributos();
          $$.c = $1.c + $3.c;
          $$.lista_str = $1.lista_str;
          $$.lista_str.push_back( $3.v ); }
      | E
        { $$ = Atributos();
          $$.c = $1.c;
          $$.lista_str.push_back( $1.v ); }
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

  // Resultados para o operador "%"
  tipo_opr["i%i"] = "i";

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

  // Resultados para o operador "="
  tipo_opr["i==i"] = "b";
  tipo_opr["i==d"] = "b";
  tipo_opr["d==i"] = "b";
  tipo_opr["d==d"] = "b";
}

// Uma tabela de símbolos para cada escopo
vector< map< string, Tipo > > ts;

void empilha_ts() {
  map< string, Tipo > novo;
  ts.push_back( novo );
}

void desempilha_ts() {
  ts.pop_back();
}

Tipo consulta_ts( string nome_var ) {
  for( int i = ts.size()-1; i >= 0; i-- )
    if( ts[i].find( nome_var ) != ts[i].end() )
      return ts[i][ nome_var ];

  erro( "Variável não declarada: " + nome_var );

  return Tipo();
}

void insere_var_ts( string nome_var, Tipo tipo ) {
  if( ts[ts.size()-1].find( nome_var ) != ts[ts.size()-1].end() )
    erro( "Variável já declarada: " + nome_var +
          " (" + ts[ts.size()-1][ nome_var ].tipo_base + ")" );

  ts[ts.size()-1][ nome_var ] = tipo;
}

void insere_funcao_ts( string nome_func,
                       Tipo retorno, vector<Tipo> params ) {
  if( ts[ts.size()-2].find( nome_func ) != ts[ts.size()-2].end() )
    erro( "Função já declarada: " + nome_func );

  ts[ts.size()-2][ nome_func ] = Tipo( retorno, params );
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

  var_temp[var_temp.size()-1] += declara_variavel( nome, Tipo( tipo ) ) + ";\n";

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

  if( s1.t.tipo_base == "s" && s3.t.tipo_base == "s" )
    // falta testar se é o operador "+"
    ss.c = s1.c + s3.c + // Codigo das expressões dos filhos da arvore.
           "  strncpy( " + ss.v + ", " + s1.v + ", 256 );\n" +
           "  strncat( " + ss.v + ", " + s3.v + ", 256 );\n";
  else if( s1.t.tipo_base == "s" && s3.t.tipo_base == "c" )
    ;
  else if( s1.t.tipo_base == "c" && s3.t.tipo_base == "s" )
    ;
  else
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
  else if( tipo_pascal == "Real" )
    return "d";
  else if( tipo_pascal == "Char" )
    return "c";
  else if( tipo_pascal == "String" )
    return "s";
  else
    erro( "Tipo inválido: " + tipo_pascal );
}

map<string, string> inicializaMapEmC() {
  map<string, string> aux;
  aux["i"] = "int ";
  aux["b"] = "int ";
  aux["d"] = "double ";
  aux["c"] = "char ";
  aux["s"] = "char ";
  return aux;
}

string declara_funcao( string nome, Tipo tipo,
                       vector<string> nomes, vector<Tipo> tipos ) {
  static map<string, string> em_C = inicializaMapEmC();

  if( em_C[ tipo.tipo_base ] == "" )
    erro( "Tipo inválido: " + tipo.tipo_base );

  insere_var_ts( "Result", tipo );

  if( nomes.size() != tipos.size() )
    erro( "Bug no compilador! Nomes e tipos de parametros diferentes." );

  string aux = "";

  for( int i = 0; i < nomes.size(); i++ ) {
    aux += declara_variavel( nomes[i], tipos[i] ) +
           (i == nomes.size()-1 ? " " : ", ");
    insere_var_ts( nomes[i], tipos[i] );
  }

  return em_C[ tipo.tipo_base ] + " " + nome + "(" + aux + ")";
}

string declara_variavel( string nome, Tipo tipo ) {
  static map<string, string> em_C = inicializaMapEmC();

  if( em_C[ tipo.tipo_base ] == "" )
    erro( "Tipo inválido: " + tipo.tipo_base );

  string indice;

  switch( tipo.ndim ) {
    case 0: indice = (tipo.tipo_base == "s" ? "[256]" : "");
            break;

    case 1: indice = "[" + toString(
                  (tipo.fim[0]-tipo.inicio[0]+1) *
                  (tipo.tipo_base == "s" ? 256 : 1)
                ) + "]";
            break;

    case 2:
            break;

    default:
       erro( "Bug muito sério..." );
  }

  return em_C[ tipo.tipo_base ] + nome + indice;
}

string gera_teste_limite_array( string indice_1, Tipo tipoArray ) {
  string var_teste_inicio = gera_nome_var_temp( "b" );
  string var_teste_fim = gera_nome_var_temp( "b" );
  string var_teste = gera_nome_var_temp( "b" );
  string label_end = gera_label( "limite_array_ok" );

  string codigo = "  " + var_teste_inicio + " = " + indice_1 + " >= " +
                  toString( tipoArray.inicio[0] ) + ";\n" +
                  "  " + var_teste_fim + " = " + indice_1 + " <= " +
                  toString( tipoArray.fim[0] ) + ";\n" +
                  "  " + var_teste + " = " + var_teste_inicio + " && " +
                                             var_teste_fim + ";\n";

  codigo += "  if( " + var_teste + " ) goto " + label_end + ";\n" +
          "    printf( \"Limite de array ultrapassado: %d <= %d <= %d\", "+
               toString( tipoArray.inicio[0] ) + " ," + indice_1 + ", " +
               toString( tipoArray.fim[0] ) + " );\n" +
               "  cout << endl;\n" +
               "  exit( 1 );\n" +
            "  " + label_end + ":;\n";

  return codigo;
}

int main( int argc, char* argv[] )
{
  inicializa_operadores();
  yyparse();
}
