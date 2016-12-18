%{
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>

using namespace std;

#define MAX_DIM 2
#define MAX_STRING_SIZE 256

struct Tipo;
struct Atributos;

int yylex();

void yyerror(const char* st);
void erro(string msg);
void inicializa_operadores();
void insere_var_ts(string nome, Tipo tipo);

Tipo consulta_ts(string nome);


string toString(int n);
string declara_variavel(string nome, Tipo tipo);
string traduz_interno_para_C(string interno);
string traduz_realness_para_interno(string realness);
string traduz_interno_para_realness(string interno);
string renomeia_variavel_usuario(string nome);
string gera_nome_var_temp(string tipo_interno);
string atribui_var(Atributos s1, Atributos s3);
string leitura_padrao(Atributos s3);
string gera_label(string tipo);
string desbloquifica(string lexema);

string atribuicao_array(Atributos s1, Atributos pos, Atributos s3);
string atribuicao_matriz(Atributos s1, Atributos pos_linha, Atributos pos_coluna, Atributos s3);

int is_atribuivel(Atributos s1, Atributos s3);
int toInt(string valor);
double toDouble(string valor);
char toChar(string valor);

Atributos gera_codigo_operador(Atributos s1, string opr, Atributos s3);
Atributos gera_codigo_operador_unario(string opr, Atributos s2);
Atributos gera_codigo_operador_in(Atributos var, Atributos array)
Atributos gera_codigo_if(Atributos expr, string cmd_then, string cmd_else);
Atributos gera_codigo_while(Atributos expr, Atributos bloco);
Atributos gera_codigo_do_while(Atributos bloco, Atributos expr);
Atributos gera_codigo_for(Atributos atrib, Atributos condicao, Atributos pulo, Atributos bloco);

string gera_teste_limite_array( string indice_1, Tipo tipoArray );
string gera_teste_limite_matriz( Atributos id, Atributos indice_1, Atributos indice_2);


map<string, Tipo> ts;
vector<string> global_vars;
vector<string> block_vars;
map<string, string> tipo_opr;

struct Tipo {
  string tipo_base;
  int ndim;
  int tam[MAX_DIM];

  Tipo(){}

  // Cria variavel basica
  Tipo (string tipo){
    tipo_base = tipo;
    ndim = 0;
  }

  Tipo (string tipo, int i){
    tipo_base = tipo;
    ndim = 1;
    this->tam[0] = i;
  }

  Tipo (string tipo, int i, int j){
    tipo_base = tipo;
    ndim = 2;
    this->tam[0] = i;
    this->tam[1] = j;
  }

};

struct Atributos {
  string valor, codigo;
  Tipo tipo;
  vector<string> lista_str;

  Atributos(){}

  Atributos( string v ){
    this->valor = v;
  }

  Atributos( string v, Tipo t ){
    this->valor = v;
    this->tipo = t;
  }
};



string includes =
    "#include <iostream>\n"
    "#include <stdio.h>\n"
    "#include <stdlib.h>\n"
    "#include <string.h>\n"
    "\n"
    "using namespace std;\n";

#define YYSTYPE Atributos

%}

%token TK_INT TK_CHAR TK_DOUBLE TK_STRING TK_BOOL TK_VOID TK_TRUE TK_FALSE
%token TK_MAIN TK_BEGIN TK_END TK_ID TK_CINT TK_CDOUBLE
%token TK_CSTRING TK_RETURN TK_ATRIB TK_CCHAR
%token TK_WRITE TK_READ
%token TK_G TK_L TK_GE TK_LE TK_DIFF TK_IF TK_ELSE
%token TK_E TK_AND TK_OR TK_NOT TK_BREAK TK_IN TK_CMPARRAY
%token TK_FOR TK_WHILE TK_DO TK_SWITCH TK_START TK_STOP

%left TK_OR
%left TK_AND
%nonassoc TK_G TK_L TK_GE TK_LE TK_ATRIB TK_DIFF TK_E
%left '+' '-'
%left '*' '/' TK_MOD
%nonassoc TK_NOT

%%

S : TK_START ';' DECLS MAIN TK_STOP ';'
    {
      cout << includes << endl;
      cout << $3.codigo << endl;
      cout << $4.codigo << endl;
    }
  ;

MAIN  : TK_MAIN BLOCO
        {
          $$.codigo += "int main()" + $2.codigo;
        }
      |
      ;

DECLS : DECLS DECL
        { $$.codigo += global_vars[global_vars.size()-1];
          global_vars.pop_back();
          $$.codigo += $2.codigo;
         }
      |
        { global_vars.push_back(""); }
      ;

DECL : G_VAR ';'
     | FUNCTION
     ;

FUNCTION : TIPO TK_ID '(' F_PARAMS ')' BLOCO
      ;

F_PARAMS : PARAMS
        ;

PARAMS : PARAM ',' PARAMS
      | PARAM
      ;

PARAM : TIPO TK_ID
     | TIPO TK_ID '[' E ']'
     | TIPO TK_ID '[' E ']' '[' E ']'
     |
     ;

G_VAR : TIPO TK_ID
        {
          $$ = Atributos($2.valor, $1.tipo);
          global_vars.push_back("");
          global_vars[global_vars.size()-1]+= declara_variavel($2.valor, $1.tipo) + ";\n";
          insere_var_ts($2.valor, $1.tipo);
        }
      | TIPO TK_ID '[' TK_CINT ']'
        {
          $$ = Atributos($2.valor, Tipo($1.tipo.tipo_base, toInt($4.valor)));
          global_vars[global_vars.size()-1] += declara_variavel($$.valor, $$.tipo) + ";\n";
          insere_var_ts($$.valor, $$.tipo);
        }
      | TIPO TK_ID '[' TK_CINT ']' '[' TK_CINT ']'
        {
          $$ = Atributos($2.valor, Tipo($1.tipo.tipo_base, toInt($4.valor), toInt($7.valor)));
          global_vars[global_vars.size()-1] += "  " + declara_variavel($$.valor, $$.tipo) + ";\n";
          insere_var_ts($$.valor, $$.tipo);
        }
      ;

VAR : TIPO VAR_DEFS
      {
        $$.codigo = "";
        for(vector<string>::iterator it = $2.lista_str.begin(); it != $2.lista_str.end(); it++){
          block_vars[block_vars.size()-1] += "  " + (declara_variavel(*it, $1.tipo)) + ";\n";
          insere_var_ts(*it, $1.tipo);
        }
      }
    | TIPO TK_ID TK_ATRIB E
      {
        $$ = Atributos($2.valor, $1.tipo);
        block_vars[block_vars.size()-1] += "  " + declara_variavel($2.valor, $1.tipo) + ";\n";
        insere_var_ts($2.valor, $1.tipo);
        $2.tipo = $1.tipo;
        $$.codigo = atribui_var($2, $4);
      }
    | TIPO TK_ID '[' TK_CINT ']'
      {
        $$ = Atributos($2.valor, Tipo($1.tipo.tipo_base, toInt($4.valor)));
        block_vars[block_vars.size()-1] += "  " + declara_variavel($$.valor, $$.tipo) + ";\n";
        insere_var_ts($$.valor, $$.tipo);
      }
    | TIPO TK_ID '[' TK_CINT ']' '[' TK_CINT ']'
      {
        $$ = Atributos($2.valor, Tipo($1.tipo.tipo_base, toInt($4.valor), toInt($7.valor)));
        block_vars[block_vars.size()-1] += "  " + declara_variavel($$.valor, $$.tipo) + ";\n";
        insere_var_ts($$.valor, $$.tipo);
      }
    ;


VAR_DEFS  : TK_ID ',' VAR_DEFS
            {
              $$.lista_str.push_back($1.valor);
              $$.lista_str.insert($$.lista_str.end(), $3.lista_str.begin(), $3.lista_str.end());
            }
          | TK_ID { $1.lista_str.push_back($1.valor); }
          ;

ATRIB : TK_ID TK_ATRIB E
        {
          $1.tipo = consulta_ts($1.valor);
          $$.codigo = atribui_var($1, $3);
        }
      | TK_ID '[' E ']' TK_ATRIB E
        {
          $1.tipo = consulta_ts($1.valor);
          $$.codigo = atribuicao_array($1,$3,$6);
        }
      | TK_ID '[' E ']' '[' E ']' TK_ATRIB E
        {
          // Chama o teste de limites antes de mais nada.
          string limites_matriz = gera_teste_limite_matriz($1, $3, $6);
          string id_temp = gera_nome_var_temp("i");

          Tipo t_matriz = consulta_ts($1.valor);
          $$.codigo = $3.codigo + $6.codigo + $9.codigo
                    + "  " + id_temp + " = " + $3.valor + "*"
                    + toString(t_matriz.tam[1]) + ";\n"
                    + "  " + id_temp + " = "
                    + id_temp + " + " + $6.valor + ";\n"
                    + limites_matriz
                    + "  " + $1.valor + "[" + id_temp
                    + "] = " + $9.valor + ";\n";
        }
      ;

TIPO  : TK_INT
        {
          Tipo t("i");
          $$ = Atributos("int", t);
        }
      | TK_CHAR
        {
          Tipo t("c");
          $$ = Atributos("char", t);
        }
      | TK_DOUBLE
        {
          Tipo t("d");
          $$ = Atributos("double", t);
        }
      | TK_STRING
        {
          Tipo t("s");
          $$ = Atributos("char[]", t);
        }
      | TK_BOOL
        {
          Tipo t("b");
          $$ = Atributos("int", t);
        }
      | TK_VOID
        {
          Tipo t("v");
          $$ = Atributos("void", t);
        }
      //| TK_ID
      // Necessario se formos implementar tipos nao basicos
      // e.g., Vector, Struct
      ;

BLOCO : TK_BEGIN { block_vars.push_back(""); } CMDS TK_END
        {
          $$.codigo = "{\n";
          // Adiciona as variaveis desse bloco ao inicio do mesmo e
          // desempilha a lista de variaveis desse bloco.
          $$.codigo += block_vars[block_vars.size()-1];
          block_vars.pop_back();
          $$.codigo += $3.codigo + "}\n";
        }
      ;

SUB_BLOCO : TK_BEGIN CMDS TK_END
            {
              $$.codigo = "{\n";
              $$.codigo += $2.codigo + "}\n";
            }
          ;

CMDS  : CMD CMDS
        {
          $$.codigo = $1.codigo + $2.codigo;
        }
      | { $$ = Atributos(); }
      ;

CMD : CMD_WROTEU ';'
    | CMD_READU ';'
    | CMD_RETURN ';'
    | CMD_CALL ';'
    | CMD_IF       // nao tem ponto e virgula
    | CMD_FOR
    | CMD_WHILE
    | CMD_DOWHILE ';'
    | ATRIB ';'   // Atribuicoes locais
    | VAR ';'  { $$ = $1; }    // Variaveis locais
    ;

// Precisa adicionar IF, WHILE, DO, FOR aqui
// Porem nao pode ser CMD pq nao tem ;

CMD_WROTEU : TK_WRITE '(' E ')'
             {
               $$.codigo = $3.codigo +
                     "  cout << " + $3.valor + ";\n"
                     "  cout << endl;\n";
             }
           ;

CMD_READU : TK_READ '(' TK_ID ')'
               {
                 $3.tipo = consulta_ts($3.valor);
                 $$.codigo = leitura_padrao($3);
               }
             ;

// tipo da pra dar flwvlw em qualquer parte do codigo
// porem o gabarito do zimbrao aceita return em qualquer parte do codigo
CMD_RETURN : TK_RETURN
             {
               $$.codigo = $1.codigo + "  return 0;\n";
             }
           | TK_RETURN ':' E
             {
               $$.codigo = $1.codigo + $3.codigo + "  return "+ $3.valor +";\n";
             }
           ;

// Definindo a call de uma funcao
CMD_CALL : TK_ID '(' CALL_PARAMS ')'
// Chama uma funcao, precisa verificar se foi definida!
         ;

CALL_PARAMS : C_PARAMS
            |
            ;

C_PARAMS : C_PARAMS ',' C_PARAM
         | C_PARAM
         ;

C_PARAM : TK_ID
        | TK_ID '[' E ']'
        ;

CMD_IF : TK_IF '(' E ')' CMD
         {
           $$ = gera_codigo_if($3, $5.codigo, "");
         }
       | TK_IF '(' E ')' CMD TK_ELSE CMD
         {
           $$ = gera_codigo_if($3, $5.codigo, $7.codigo);
         }
       ;

CMD_FOR : TK_FOR '(' BEGIN_FOR ';' E ';' CONT_FOR ')' SUB_BLOCO
          {
            $$ = gera_codigo_for($3, $5, $7, $9);
          }
       ;

 BEGIN_FOR : TIPO TK_ID TK_ATRIB E
             {
               $$ = Atributos($2.valor, $1.tipo);
               block_vars[block_vars.size()-1] += "  " + declara_variavel($2.valor, $1.tipo) + ";\n";
               insere_var_ts($2.valor, $1.tipo);
               $2.tipo = $1.tipo;
               $$.codigo = atribui_var($2, $4);
             }
             //fazer pra nao precisar colocar o tipo no inicio
            | TK_ID TK_ATRIB E
              {
                $$ = Atributos($1.valor, consulta_ts($1.valor));
                $$.codigo = atribui_var($1, $3);
              }
           ;

 // acho que pra verificar tipos isso fica melhor separado!
 CONT_FOR : TK_ID TK_ATRIB E
            {
              $$.codigo = $3.codigo + "\n" + "  "
                        + $1.valor + " = " + $3.valor + ";\n";
            }
          ;


CMD_WHILE : TK_WHILE '(' E ')' SUB_BLOCO
            {
              $$ = gera_codigo_while($3, $5);
            }
          ;

CMD_DOWHILE : TK_DO SUB_BLOCO TK_WHILE '(' E ')'
              {
                $$ = gera_codigo_do_while($2, $5);
              }
             ;

E : E '+' E     { $$ = gera_codigo_operador($1, "+", $3);    }
  | E '-' E     { $$ = gera_codigo_operador($1, "-", $3);    }
  | E '*' E     { $$ = gera_codigo_operador($1, "*", $3);    }
  | E '/' E     { $$ = gera_codigo_operador($1, "/", $3);    }
  | E TK_G E    { $$ = gera_codigo_operador($1, ">", $3);    }
  | E TK_L E    { $$ = gera_codigo_operador($1, "<", $3);    }
  | E TK_GE E   { $$ = gera_codigo_operador($1, ">=", $3);   }
  | E TK_LE E   { $$ = gera_codigo_operador($1, "<=", $3);   }
  | E TK_DIFF E { $$ = gera_codigo_operador($1, "!=", $3);   }
  | E TK_E E    { $$ = gera_codigo_operador($1, "==", $3);   }
  | E TK_AND E  { $$ = gera_codigo_operador($1, "&&", $3);   }
  | E TK_OR E   { $$ = gera_codigo_operador($1, "||", $3);   }
  | E TK_MOD E  { $$ = gera_codigo_operador($1, "%", $3);    }
  | TK_NOT E    { $$ = gera_codigo_operador_unario("!", $2); }
  | '(' E ')'   { $$ = $2;                                   }
  | E TK_CMPARRAY E { $$ = gera_codigo_operador($1,"@",$3);  }
  | E TK_IN F   { $$ = gera_codigo_operador($1, "in", $3);   }
  | F
  ;

F : TK_ID
    {
      $$.valor = $1.valor;
      $$.tipo = consulta_ts($1.valor);
      $$.codigo = $1.codigo;
    }
  | TK_CINT
    {
      $$.valor = $1.valor;
      $$.tipo = Tipo("i");
      $$.codigo = $1.codigo;
    }
  | TK_CDOUBLE
    {
      $$.valor = $1.valor;
      $$.tipo = Tipo("d");
      $$.codigo = $1.codigo;
    }
  | TK_CCHAR
    {
      $$.valor = $1.valor;
      $$.tipo = Tipo("c");
      $$.codigo = $1.codigo;
    }
  | TK_CSTRING
    {
      $$.valor = $1.valor;
      $$.tipo = Tipo("s");
      $$.codigo = $1.codigo;
    }
  | TK_ID '[' E ']'
    {
      Tipo tipoArray = consulta_ts( $1.valor );
      $$.tipo = Tipo( tipoArray.tipo_base );
      if( tipoArray.ndim != 1 )
        erro( "Variável " + $1.valor + " não é array de uma dimensão" );

      if( $3.tipo.ndim != 0 || $3.tipo.tipo_base != "i" )
        erro( "Indice de array deve ser integer de zero dimensão: " +
              $3.tipo.tipo_base + "/" + toString( $3.tipo.ndim ) );

      $$.valor = gera_nome_var_temp( $$.tipo.tipo_base );
      $$.codigo = $3.codigo +
             gera_teste_limite_array( $3.valor, tipoArray ) +
             "  " + $$.valor + " = " + $1.valor + "[" + $3.valor + "];\n";
    }
  | TK_ID '[' E ']' '[' E ']'
    {
      // Chama o teste de limites antes de mais nada.
      string limites_matriz = gera_teste_limite_matriz($1, $3, $6);
      string id_temp = gera_nome_var_temp("i");

      Tipo t_matriz = consulta_ts($1.valor);

      $$.tipo = Tipo(t_matriz.tipo_base);
      $$.valor = gera_nome_var_temp($$.tipo.tipo_base);


      $$.codigo = $3.codigo + $6.codigo + limites_matriz
                + "  " + id_temp + " = " + $3.valor + "*"
                + toString(t_matriz.tam[1]) + ";\n"
                + "  " + id_temp + " = "
                + id_temp + " + " + $6.valor + ";\n"
                + "  " + $$.valor + " = " + $1.valor
                + "[" + id_temp + "];\n";
    }
  | BOOL

  ;

BOOL : TK_TRUE
      {
        $$.valor = "1";
        $$.tipo = Tipo("b");
        $$.codigo = $1.codigo;
      }
     | TK_FALSE
      {
        $$.valor = "0";
        $$.tipo = Tipo("b");
        $$.codigo = $1.codigo;
      }
     ;

%%

int nlinha = 1;

#include "lex.yy.c"

int yyparse();

void yyerror(const char* st){
  puts( st );
  printf( "Linha: %d, [%s]\n", nlinha, yytext );
}

void erro(string msg){
  cerr << "Erro: " << msg << endl;
  fprintf(stderr, "Linha: %d, [%s]\n", nlinha, yytext );
  exit(1);
}

void inicializa_operadores() {

  // +
  tipo_opr["i+i"] = "i";
  tipo_opr["i+d"] = "d";
  tipo_opr["d+i"] = "d";
  tipo_opr["d+d"] = "d";
  tipo_opr["s+s"] = "s";

  // -
  tipo_opr["i-i"] = "i";
  tipo_opr["i-d"] = "d";
  tipo_opr["d-i"] = "d";
  tipo_opr["d-d"] = "d";

  // *
  tipo_opr["i*i"] = "i";
  tipo_opr["i*d"] = "d";
  tipo_opr["d*i"] = "d";
  tipo_opr["d*d"] = "d";

  // /
  tipo_opr["i/d"] = "d";
  tipo_opr["i/i"] = "i";
  tipo_opr["d/i"] = "d";
  tipo_opr["d/d"] = "d";

  //  >
  tipo_opr["i>i"] = "b";
  tipo_opr["i>d"] = "b";
  tipo_opr["d>i"] = "b";
  tipo_opr["d>d"] = "b";
  tipo_opr["c>c"] = "b";
  tipo_opr["i>c"] = "b";
  tipo_opr["c>i"] = "b";
  tipo_opr["s>s"] = "b";

  //  <
  tipo_opr["i<i"] = "b";
  tipo_opr["i<d"] = "b";
  tipo_opr["d<i"] = "b";
  tipo_opr["d<d"] = "b";
  tipo_opr["c<c"] = "b";
  tipo_opr["i<c"] = "b";
  tipo_opr["c<i"] = "b";
  tipo_opr["s<s"] = "b";

  //  >=
  tipo_opr["i>=i"] = "b";
  tipo_opr["i>=d"] = "b";
  tipo_opr["d>=i"] = "b";
  tipo_opr["d>=d"] = "b";
  tipo_opr["c>=c"] = "b";
  tipo_opr["i>=c"] = "b";
  tipo_opr["c>=i"] = "b";

  //  <=
  tipo_opr["i<=i"] = "b";
  tipo_opr["i<=d"] = "b";
  tipo_opr["d<=i"] = "b";
  tipo_opr["d<=d"] = "b";
  tipo_opr["c<=c"] = "b";
  tipo_opr["i<=c"] = "b";
  tipo_opr["c<=i"] = "b";

  //  ==
  tipo_opr["i==i"] = "b";
  tipo_opr["i==d"] = "b";
  tipo_opr["d==i"] = "b";
  tipo_opr["d==d"] = "b";
  tipo_opr["c==c"] = "b";
  tipo_opr["i==c"] = "b";
  tipo_opr["c==i"] = "b";
  tipo_opr["s==s"] = "b";

  // !=
  tipo_opr["i!=i"] = "b";
  tipo_opr["i!=d"] = "b";
  tipo_opr["d!=i"] = "b";
  tipo_opr["d!=d"] = "b";
  tipo_opr["c!=c"] = "b";
  tipo_opr["i!=c"] = "b";
  tipo_opr["c!=i"] = "b";
  tipo_opr["s!=s"] = "i";

  // =
  tipo_opr["i=i"] = "i";
  tipo_opr["b=b"] = "b";
  tipo_opr["b=i"] = "b";
  tipo_opr["d=d"] = "d";
  tipo_opr["d=i"] = "d";
  tipo_opr["c=c"] = "c";
  tipo_opr["s=s"] = "s";
  tipo_opr["s=c"] = "s";

  // and
  tipo_opr["b&&b"] = "b";
  tipo_opr["i&&i"] = "b";
  tipo_opr["i&&d"] = "b";
  tipo_opr["d&&i"] = "b";
  tipo_opr["d&&d"] = "b";

  // or
  tipo_opr["b||b"] = "b";
  tipo_opr["i||i"] = "b";
  tipo_opr["i||d"] = "b";
  tipo_opr["d||i"] = "b";
  tipo_opr["d||d"] = "b";

  // not
  tipo_opr["!i"] = "i";
  tipo_opr["!b"] = "b";
  tipo_opr["!c"] = "c";
  tipo_opr["!d"] = "d";

  // mod
  tipo_opr["i%i"] = "i";

  // in
  tipo_opr["iini"] = "b";
  tipo_opr["dind"] = "b";
  tipo_opr["cinc"] = "b";
  tipo_opr["sins"] = "b";
  tipo_opr["iins"] = "b";
  tipo_opr["dins"] = "b";
  tipo_opr["iinc"] = "b";
  tipo_opr["cins"] = "b";

  // @
  tipo_opr["i@i"] = "i";
  tipo_opr["d@d"] = "i";
  tipo_opr["c@c"] = "i";
}

void insere_var_ts(string nome, Tipo tipo){
  if(ts.find(nome) != ts.end()){
    erro("Variavel ja declarada: " + nome);
  }
  ts[nome] = tipo;
}

Tipo consulta_ts(string nome) {
  if(ts.find(nome) == ts.end()){
    erro("Variavel nao declarada: " + nome);
  }
  return ts[nome];
}

string toString(int n){
  char buff[100];

  sprintf(buff, "%d", n);

  return buff;
}

string declara_variavel(string nome, Tipo tipo){
  if(tipo.tipo_base == "s"){
    int tam = MAX_STRING_SIZE;
    if(tipo.ndim == 1)
      return traduz_interno_para_C(tipo.tipo_base)
                + " " + nome + "[" + toString(tipo.tam[0]*tam) + "]";
    if(tipo.ndim == 2)
      return traduz_interno_para_C(tipo.tipo_base)
              + " " + nome + "[" + toString(tam*tipo.tam[1]) + "]";
    return traduz_interno_para_C(tipo.tipo_base) + " " + nome + "[" + toString(tam) + "]";
  }
  if(tipo.ndim == 1)
    return traduz_interno_para_C(tipo.tipo_base)
              + " " + nome + "[" + toString(tipo.tam[0]) + "]";
  if(tipo.ndim == 2)
    return traduz_interno_para_C(tipo.tipo_base)
            + " " + nome + "[" + toString(tipo.tam[0]*tipo.tam[1]) + "]";

  return traduz_interno_para_C(tipo.tipo_base) + " " + nome;
}


string traduz_interno_para_C(string interno){
  if(interno == "i")
    return "int";
  if(interno == "c")
    return "char";
  if(interno == "b")
    return "int";
  if(interno == "d")
    return "double";
  if(interno == "s")
    return "char";
  erro("Bug no compilador! Tipo interno inexistente: " + interno);
  return "";
}

string traduz_realness_para_interno(string realness){
  if(realness == "char")
    return "c";
  if(realness == "integer")
    return "i";
  if(realness == "double")
    return "d";
  if(realness == "string")
    return "s";
  if(realness == "boolean")
    return "b";
  erro("Tipo " + realness + " em The Realness inexistente");
  return "";
}

string traduz_interno_para_realness(string interno){
  if(interno == "i")
    return "integer";
  if(interno == "c")
    return "char";
  if(interno == "b")
    return "boolean";
  if(interno == "d")
    return "double";
  if(interno == "v")
    return "void";
  if(interno == "s")
    return "string";
  erro("Tipo interno " + interno + " inexistente");
  return "";
}

string renomeia_variavel_usuario(string nome){
  return "_" + nome;
}

string gera_nome_var_temp(string tipo_interno){
  static int n = 1;
  string nome = "t" + tipo_interno + "_" + toString(n++);

  block_vars[block_vars.size()-1] += "  "
                                  + declara_variavel(nome, Tipo(tipo_interno))
                                  + ";\n";

  return nome;
}

string gera_teste_limite_array( string indice_1, Tipo tipoArray ) {
  string var_teste_tam = gera_nome_var_temp( "b" );
  string var_teste = gera_nome_var_temp( "b" );
  string label_end = gera_label( "limite_array_ok" );

  string codigo = "  " + var_teste_tam + " = " + indice_1 + " < " +
                  toString( tipoArray.tam[0] ) + ";\n" +
                  "  " + var_teste + " = " + var_teste_tam + ";\n";

  codigo += "  if( " + var_teste + " ) goto " + label_end + ";\n" +
          "    printf( \"Limite de array ultrapassado\");\n" +
               "  cout << endl;\n" +
               "  exit( 1 );\n" +
            "  " + label_end + ":;\n";

  return codigo;
}

string gera_teste_limite_matriz(Atributos id, Atributos indice1, Atributos indice2){
  Tipo t_matriz = consulta_ts(id.valor);

  // Verifica o tipo dos indices
  if(indice1.tipo.tipo_base != "i" || indice2.tipo.tipo_base != "i" ||
     indice1.tipo.ndim != 0 || indice2.tipo.ndim != 0)
    erro("Indice de arrei deve ser intero.");

  // Verifica se a variavel e' mesmo um array de dimensao 2
  if(t_matriz.ndim != 2)
    erro("Variavel " + id.valor + " nao e' arrei de dimensao dois.");

  return "";
}

string atribui_var(Atributos s1, Atributos s3){
  if (is_atribuivel(s1, s3) == 1){
    if (s1.tipo.tipo_base == "s"){
       return s3.codigo + "  strncpy("+ s1.valor + ", " + s3.valor +", "
                        + toString(MAX_STRING_SIZE) + ");\n";
    } else if (s1.tipo.tipo_base == "b" && s3.tipo.tipo_base == "i") {
      string val = (s3.valor == "0" ? "0" : "1"); //lida com b=i
      return s3.codigo + "  " + s1.valor + " = " + val + ";\n";
    } else {
      return s3.codigo + "  " + s1.valor + " = " + s3.valor + ";\n";
    }
  } else{
    erro("Atribuicao nao permitida! "
          + traduz_interno_para_realness(s1.tipo.tipo_base) + " = "
          + traduz_interno_para_realness(s3.tipo.tipo_base));
  }
}

string atribuicao_array(Atributos s1, Atributos pos, Atributos s3){
  if (is_atribuivel(s1,s3) == 1) {
      return pos.codigo + s3.codigo +
             "  " + s1.valor + "[" + pos.valor + "] = " + s3.valor + ";\n";
  }
  else{
    erro("Atribuicao nao permitida!");
  }
}



string leitura_padrao(Atributos s3){
  string codigo;
  string indice_pula_linha = gera_nome_var_temp("i");
  if (s3.tipo.tipo_base == "s"){
    codigo = s3.codigo + "  fgets(" + s3.valor
                       + ", " + toString(MAX_STRING_SIZE) + ", stdin);\n"
                       + "  " + indice_pula_linha + " = strcspn(" + s3.valor
                       + ", \"\\n\");\n"
                       + "  " + s3.valor + "[" + indice_pula_linha
                       + "] = 0;\n";
  } else{
    codigo = s3.codigo + "  cin >> " + s3.valor +  ";\n";
  }
  return codigo;
}

string gera_label(string tipo){
  static int n = 0;
  string nome = "l_" + tipo + "_" + toString(++n);
  return nome;
}

string desbloquifica(string lexema){
  lexema[0] = ' ';
  lexema[lexema.size()-2] = ' ';
  return lexema;
}

int is_atribuivel(Atributos s1, Atributos s3){
  string key = s1.tipo.tipo_base + "=" + s3.tipo.tipo_base;
  if (tipo_opr.find(key) != tipo_opr.end()){
    return 1;
  }
  return 0;
}

int toInt(string valor) {
  int aux = -1;
  if( sscanf( valor.c_str(), "%d", &aux ) != 1 )
    erro( "Numero invalido: " + valor );
  return aux;
}

double toDouble(string valor) {
  int aux = -1;
  if( sscanf( valor.c_str(), "%d", &aux ) != 1 )
    erro( "Numero invalido: " + valor );
  return aux;
}

char toChar(string valor) {
  int aux = -1;
  if( sscanf( valor.c_str(), "%d", &aux ) != 1 )
    erro( "Numero invalido: " + valor );
  return aux;
}

Atributos gera_codigo_operador(Atributos s1, string opr, Atributos s3){
  Atributos ss;

  string tipo1 = s1.tipo.tipo_base;
  string tipo3 = s3.tipo.tipo_base;
  string tipo_resultado = tipo_opr[tipo1 + opr + tipo3];

  if(tipo_resultado == "")
    erro("Operacao nao permitida. "
       + traduz_interno_para_realness(tipo1)
       + " " + opr + " "
       + traduz_interno_para_realness(tipo3));

  ss.valor = gera_nome_var_temp(tipo_resultado);
  ss.tipo = Tipo(tipo_resultado);

  ss.codigo = s1.codigo + s3.codigo;

  if(tipo_resultado == "s" && opr == "+"){
    ss.codigo += "  strncpy(" + ss.valor + ", " + s1.valor + ", "
              + toString(MAX_STRING_SIZE) + ");\n"
              + "  strncat(" + ss.valor + ", " + s3.valor + ", "
              + toString(MAX_STRING_SIZE) + ");\n";
  }
  else if(tipo1 == "s" && tipo3 == "s" && opr == "!="){
    ss.codigo += "  "+ ss.valor + " =  strcmp(" + s1.valor + ", " + s3.valor + ");\n";
  }
  else if(tipo1 == "s" && tipo3 == "s" && tipo_resultado == "b" && opr == ">"){
    ss.codigo += "  " + ss.valor + " = strcmp(" + s1.valor + ", " + s3.valor + ") ;\n";
    ss.codigo += "  " + ss.valor + " = " + ss.valor +  " > 0;\n";
  }
  else if(tipo1 == "s" && tipo3 == "s" && tipo_resultado == "b" && opr == "<"){
    ss.codigo += "  " + ss.valor + " = strcmp(" + s1.valor + ", " + s3.valor + ") ;\n";
    ss.codigo += "  " + ss.valor + " = " + ss.valor +  " < 0;\n";
  }
  else if(tipo1 == "s" && tipo3 == "s" && tipo_resultado == "b" && opr == "=="){
    ss.codigo += "  " + ss.valor + " = strcmp(" + s1.valor + ", " + s3.valor + ") ;\n";
    ss.codigo += "  " + ss.valor + " = " + ss.valor +  " == 0;\n";
  }
  else if(s1.tipo.ndim == 1 && s3.tipo.ndim == 1 && opr == "@"){
    int tam, aux;
    string atr1, atr2;
    string tipo = tipo1;

    if(tipo == "c") aux = sizeof(toChar(tipo));
    else if (tipo == "d") aux = sizeof(toDouble(tipo));
    else if (tipo == "i" || tipo == "b") aux = sizeof(toInt(tipo));

    if (s1.tipo.tam[0]>s3.tipo.tam[0]){
      tam = s1.tipo.tam[0]*aux;
      atr1 = s1.valor;
      atr2 = s3.valor;
    }
    else {
      tam = s3.tipo.tam[0]*aux;
      atr1 = s3.valor;
      atr2 = s1.valor;
    }
    ss.codigo += "  " + ss.valor + " = memcmp(" + atr1 + ", " + atr2 + ", " + toString(tam) + ") ; \n";
    ss.codigo += "  " + ss.valor + " = !" + ss.valor + ";\n";
  }

  // Tipo basico
  else {
    ss.codigo += "  " + ss.valor + " = "
              + s1.valor + " " + opr + " " + s3.valor
              + ";\n";
  }
  return ss;
}

Atributos gera_codigo_operador_in(Atributos var, Atributos array){

}

Atributos gera_codigo_operador_unario(string opr, Atributos s2){
  Atributos ss;

  string tipo2 = s2.tipo.tipo_base;
  string tipo_resultado = tipo_opr[opr + tipo2];

  if(tipo_resultado == "")
    erro("Operacao nao permitida. "
       + opr + traduz_interno_para_realness(tipo2));

  ss.valor = gera_nome_var_temp(tipo_resultado);
  ss.tipo = Tipo(tipo_resultado);

  ss.codigo = s2.codigo + "  "
            + ss.valor + " = "
            + opr + s2.valor
            + ";\n";

  return ss;
}

Atributos gera_codigo_if(Atributos expr, string cmd_then, string cmd_else){

  Atributos ss;
  string label_else = gera_label( "else" );
  string label_end = gera_label( "end" );
//string condicao_var = gera_nome_var_temp(expr.tipo.tipo_base);

  ss.codigo = expr.codigo +
         "  " + expr.valor + " = !" + expr.valor + ";\n\n" +
         "  if( " + expr.valor + " ) goto " + label_else + ";\n" +
         cmd_then +
         "  goto " + label_end + ";\n" + "  " +
         label_else + ":;\n" +
         cmd_else + "  " +
         label_end + ":;\n";
  return ss;
}

Atributos gera_codigo_while(Atributos expr, Atributos bloco){
  Atributos ss;
  string label_teste = gera_label( "teste_while" );
  string label_end = gera_label( "fim_while" );
  // o zizi coloca "b" ao inves de tipo_base, mas acho tipo_base melhor pra verificar erros
  string condicao_var = gera_nome_var_temp(expr.tipo.tipo_base);

  ss.codigo = label_teste + ":;\n"
            + expr.codigo + "  "
            + condicao_var + " = !" + expr.valor + ";\n\n"
            + "if ("+ condicao_var +") goto " + label_end
            + ";\n" + desbloquifica(bloco.codigo)
            + "goto " + label_teste + ";\n"
            + label_end + ":;\n"
            ;
  return ss;
}

Atributos gera_codigo_do_while(Atributos bloco, Atributos expr){
  Atributos ss;
  string label_teste = gera_label( "teste_dowhile" );
  string label_end = gera_label( "fim_dowhile" );
  // o zizi coloca "b" ao inves de tipo_base, mas acho tipo_base melhor pra verificar erros
  string condicao_var = gera_nome_var_temp(expr.tipo.tipo_base);
  ss.codigo = label_teste + ":;\n"
            + desbloquifica(bloco.codigo)
            + expr.codigo + "  "
            + condicao_var + " = !" + expr.valor + ";\n\n"
            + "if ("+ condicao_var +") goto " + label_end + ";\n"
            + "goto " + label_teste + ";\n"
            + label_end + ":;\n"
            ;
  return ss;
}

Atributos gera_codigo_for(Atributos atrib, Atributos condicao, Atributos pulo, Atributos bloco){
  Atributos ss;
  string var_fim = gera_nome_var_temp( atrib.tipo.tipo_base );
  string label_teste = gera_label( "teste_for" );
  string label_end = gera_label( "fim_for" );
  string condicao_var = gera_nome_var_temp(condicao.tipo.tipo_base);

  ss.codigo = atrib.codigo
            + label_teste + ":;\n"
            + condicao.codigo + "  "
            + condicao_var + " = !" + condicao.valor + ";\n\n"
            + "if ("+ condicao_var +") goto " + label_end
            + ";\n" + desbloquifica(bloco.codigo)
            + pulo.codigo
            + "  goto " + label_teste + ";\n"
            + label_end + ":;\n"
            ;
  return ss;
}

int main(int argc, char* argv[]){
  inicializa_operadores();
  yyparse();
}
