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

struct Type;
struct Atributos;

int yylex();

void yyerror(const char* st);
void erro(string msg);
void initializing_oprs();
void insert_var_ts(string nome, Type type);

Type check_ts(string nome);


string toString(int n);
string decl_var(string nome, Type type);
string translate_intern_C(string interno);
string translate_realness_intern(string realness);
string translate_intern_realness(string interno);
string rename_user_var(string nome);
string vartmp_name_generator(string tipo_interno);
string atribui_var(Atributos s1, Atributos s3);
string std_reading(Atributos s3);
string label_generator(string type);
string desbloquifica(string lexema);

string atribuicao_array(Atributos s1, Atributos pos, Atributos s3);
string atribuicao_matriz(Atributos s1, Atributos pos_linha, Atributos pos_coluna, Atributos s3);

int is_atribuivel(Atributos s1, Atributos s3);
int toInt(string valor);
double toDouble(string valor);
char toChar(string valor);

Atributos opr_code_generator(Atributos s1, string opr, Atributos s3);
Atributos un_opr_code_generator(string opr, Atributos s2);
Atributos in_opr_code_generator(Atributos var,string opr, Atributos array);
Atributos if_code_generator(Atributos expr, string cmd_then, string cmd_else);
Atributos while_code_generator(Atributos expr, Atributos bloco);
Atributos do_while_code_generator(Atributos bloco, Atributos expr);
Atributos for_code_generator(Atributos atrib, Atributos condicao, Atributos pulo, Atributos bloco);

string array_limit_test_generator( string indice_1, Type tipoArray );
string matrix_limit_test_generator( Atributos id, Atributos indice_1, Atributos indice_2);


map<string, Type> ts;
vector<string> global_vars;
vector<string> block_vars;
map<string, string> type_opr;

struct Type {
  string base_type;
  int ndim;
  int tam[MAX_DIM];

  Type(){}


  Type (string type){
    base_type = type;
    ndim = 0;
  }

  Type (string type, int i){
    base_type = type;
    ndim = 1;
    this->tam[0] = i;
  }

  Type (string type, int i, int j){
    base_type = type;
    ndim = 2;
    this->tam[0] = i;
    this->tam[1] = j;
  }

};

struct Atributos {
  string valor, codigo;
  Type type;
  vector<string> lista_str;

  Atributos(){}

  Atributos( string v ){
    this->valor = v;
  }

  Atributos( string v, Type t ){
    this->valor = v;
    this->type = t;
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

%token TK_INT TK_CHAR TK_DOUBLE TK_STRING TK_BOOL TK_TRUE TK_FALSE
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

MAIN  : TK_MAIN BLOCO { $$.codigo += "int main()" + $2.codigo; }
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
     ;

G_VAR : TIPO TK_ID
        {
          $$ = Atributos($2.valor, $1.type);
          global_vars.push_back("");
          global_vars[global_vars.size()-1]+= decl_var($2.valor, $1.type) + ";\n";
          insert_var_ts($2.valor, $1.type);
        }
      | TIPO TK_ID '[' TK_CINT ']'
        {
          $$ = Atributos($2.valor, Type($1.type.base_type, toInt($4.valor)));
          global_vars[global_vars.size()-1] += decl_var($$.valor, $$.type) + ";\n";
          insert_var_ts($$.valor, $$.type);
        }
      | TIPO TK_ID '[' TK_CINT ']' '[' TK_CINT ']'
        {
          $$ = Atributos($2.valor, Type($1.type.base_type, toInt($4.valor), toInt($7.valor)));
          global_vars[global_vars.size()-1] += "  " + decl_var($$.valor, $$.type) + ";\n";
          insert_var_ts($$.valor, $$.type);
        }
      ;

VAR : TIPO VAR_DEFS
      {
        $$.codigo = "";
        for(vector<string>::iterator it = $2.lista_str.begin(); it != $2.lista_str.end(); it++){
          block_vars[block_vars.size()-1] += "  " + (decl_var(*it, $1.type)) + ";\n";
          insert_var_ts(*it, $1.type);
        }
      }
    | TIPO TK_ID TK_ATRIB E
      {
        $$ = Atributos($2.valor, $1.type);
        block_vars[block_vars.size()-1] += "  " + decl_var($2.valor, $1.type) + ";\n";
        insert_var_ts($2.valor, $1.type);
        $2.type = $1.type;
        $$.codigo = atribui_var($2, $4);
      }
    | TIPO TK_ID '[' TK_CINT ']'
      {
        $$ = Atributos($2.valor, Type($1.type.base_type, toInt($4.valor)));
        block_vars[block_vars.size()-1] += "  " + decl_var($$.valor, $$.type) + ";\n";
        insert_var_ts($$.valor, $$.type);
      }
    | TIPO TK_ID '[' TK_CINT ']' '[' TK_CINT ']'
      {
        $$ = Atributos($2.valor, Type($1.type.base_type, toInt($4.valor), toInt($7.valor)));
        block_vars[block_vars.size()-1] += "  " + decl_var($$.valor, $$.type) + ";\n";
        insert_var_ts($$.valor, $$.type);
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
          $1.type = check_ts($1.valor);
          $$.codigo = atribui_var($1, $3);
        }
      | TK_ID '[' E ']' TK_ATRIB E
        {
          $1.type = check_ts($1.valor);
          $$.codigo = atribuicao_array($1,$3,$6);
        }
      | TK_ID '[' E ']' '[' E ']' TK_ATRIB E
        {
          string limites_matriz = matrix_limit_test_generator($1, $3, $6);
          string id_temp = vartmp_name_generator("i");

          Type t_matriz = check_ts($1.valor);
          $$.codigo = $3.codigo + $6.codigo + $9.codigo + "  " + id_temp + " = " + $3.valor + "*"
                    + toString(t_matriz.tam[1]) + ";\n" + "  " + id_temp + " = " + id_temp + " + " + $6.valor + ";\n"
                    + limites_matriz + "  " + $1.valor + "[" + id_temp + "] = " + $9.valor + ";\n";
        }
      ;

TIPO  : TK_INT             { Type t("i"); $$ = Atributos("int", t);    }
      | TK_CHAR            { Type t("c"); $$ = Atributos("char", t);   }
      | TK_DOUBLE          { Type t("d"); $$ = Atributos("double", t); }
      | TK_STRING          { Type t("s"); $$ = Atributos("char[]", t); }
      | TK_BOOL            { Type t("b"); $$ = Atributos("int", t);    }
      ;

BLOCO : TK_BEGIN { block_vars.push_back(""); } CMDS TK_END
        {
          $$.codigo = "{\n";
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
    | CMD_IF
    | CMD_FOR
    | CMD_WHILE
    | CMD_DOWHILE ';'
    | ATRIB ';'
    | VAR ';'  { $$ = $1; }
    ;


CMD_WROTEU : TK_WRITE '(' E ')'
             {
               $$.codigo = $3.codigo +
                     "  cout << " + $3.valor + ";\n"
                     "  cout << endl;\n";
             }
           ;

CMD_READU : TK_READ '(' TK_ID ')'
               {
                 $3.type = check_ts($3.valor);
                 $$.codigo = std_reading($3);
               }
             ;

CMD_RETURN : TK_RETURN
             {
               $$.codigo = $1.codigo + "  return 0;\n";
             }
           | TK_RETURN ':' E
             {
               $$.codigo = $1.codigo + $3.codigo + "  return "+ $3.valor +";\n";
             }
           ;

CMD_IF : TK_IF '(' E ')' CMD
         {
           $$ = if_code_generator($3, $5.codigo, "");
         }
       | TK_IF '(' E ')' CMD TK_ELSE CMD
         {
           $$ = if_code_generator($3, $5.codigo, $7.codigo);
         }
       ;

CMD_FOR : TK_FOR '(' BEGIN_FOR ';' E ';' CONT_FOR ')' SUB_BLOCO
          {
            $$ = for_code_generator($3, $5, $7, $9);
          }
       ;

 BEGIN_FOR : TIPO TK_ID TK_ATRIB E
             {
               $$ = Atributos($2.valor, $1.type);
               block_vars[block_vars.size()-1] += "  " + decl_var($2.valor, $1.type) + ";\n";
               insert_var_ts($2.valor, $1.type);
               $2.type = $1.type;
               $$.codigo = atribui_var($2, $4);
             }

            | TK_ID TK_ATRIB E
              {
                $$ = Atributos($1.valor, check_ts($1.valor));
                $$.codigo = atribui_var($1, $3);
              }
           ;

  CONT_FOR : TK_ID TK_ATRIB E
            {
              $$.codigo = $3.codigo + "\n" + "  "
                        + $1.valor + " = " + $3.valor + ";\n";
            }
          ;


CMD_WHILE : TK_WHILE '(' E ')' SUB_BLOCO
            {
              $$ = while_code_generator($3, $5);
            }
          ;

CMD_DOWHILE : TK_DO SUB_BLOCO TK_WHILE '(' E ')'
              {
                $$ = do_while_code_generator($2, $5);
              }
             ;

E : E '+' E     { $$ = opr_code_generator($1, "+", $3);    }
  | E '-' E     { $$ = opr_code_generator($1, "-", $3);    }
  | E '*' E     { $$ = opr_code_generator($1, "*", $3);    }
  | E '/' E     { $$ = opr_code_generator($1, "/", $3);    }
  | E TK_G E    { $$ = opr_code_generator($1, ">", $3);    }
  | E TK_L E    { $$ = opr_code_generator($1, "<", $3);    }
  | E TK_GE E   { $$ = opr_code_generator($1, ">=", $3);   }
  | E TK_LE E   { $$ = opr_code_generator($1, "<=", $3);   }
  | E TK_DIFF E { $$ = opr_code_generator($1, "!=", $3);   }
  | E TK_E E    { $$ = opr_code_generator($1, "==", $3);   }
  | E TK_AND E  { $$ = opr_code_generator($1, "&&", $3);   }
  | E TK_OR E   { $$ = opr_code_generator($1, "||", $3);   }
  | E TK_MOD E  { $$ = opr_code_generator($1, "%", $3);    }
  | TK_NOT E    { $$ = un_opr_code_generator("!", $2); }
  | '(' E ')'   { $$ = $2;                                   }
  | E TK_CMPARRAY E { $$ = opr_code_generator($1,"@",$3);  }
  | E TK_IN F   { $$ = in_opr_code_generator($1, "in", $3);}
  | F
  ;

F : TK_ID
    {
      $$.valor = $1.valor;
      $$.type = check_ts($1.valor);
      $$.codigo = $1.codigo;
    }
  | TK_CINT
    {
      $$.valor = $1.valor;
      $$.type = Type("i");
      $$.codigo = $1.codigo;
    }
  | TK_CDOUBLE
    {
      $$.valor = $1.valor;
      $$.type = Type("d");
      $$.codigo = $1.codigo;
    }
  | TK_CCHAR
    {
      $$.valor = $1.valor;
      $$.type = Type("c");
      $$.codigo = $1.codigo;
    }
  | TK_CSTRING
    {
      $$.valor = $1.valor;
      $$.type = Type("s");
      $$.codigo = $1.codigo;
    }
  | TK_ID '[' E ']'
    {
      Type tipoArray = check_ts( $1.valor );
      $$.type = Type( tipoArray.base_type );
      if( tipoArray.ndim != 1 )
        erro( "Variável " + $1.valor + " não é array de uma dimensão" );

      if( $3.type.ndim != 0 || $3.type.base_type != "i" )
        erro( "Indice de array deve ser integer de zero dimensão: " +
              $3.type.base_type + "/" + toString( $3.type.ndim ) );

      $$.valor = vartmp_name_generator( $$.type.base_type );
      $$.codigo = $3.codigo +
             array_limit_test_generator( $3.valor, tipoArray ) +
             "  " + $$.valor + " = " + $1.valor + "[" + $3.valor + "];\n";
    }
  | TK_ID '[' E ']' '[' E ']'
    {
      string limites_matriz = matrix_limit_test_generator($1, $3, $6);
      string id_temp = vartmp_name_generator("i");

      Type t_matriz = check_ts($1.valor);

      $$.type = Type(t_matriz.base_type);
      $$.valor = vartmp_name_generator($$.type.base_type);


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
        $$.type = Type("b");
        $$.codigo = $1.codigo;
      }
     | TK_FALSE
      {
        $$.valor = "0";
        $$.type = Type("b");
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

void initializing_oprs() {

  // +
  type_opr["i+i"] = "i";
  type_opr["i+d"] = "d";
  type_opr["d+i"] = "d";
  type_opr["d+d"] = "d";
  type_opr["s+s"] = "s";

  // -
  type_opr["i-i"] = "i";
  type_opr["i-d"] = "d";
  type_opr["d-i"] = "d";
  type_opr["d-d"] = "d";

  // *
  type_opr["i*i"] = "i";
  type_opr["i*d"] = "d";
  type_opr["d*i"] = "d";
  type_opr["d*d"] = "d";

  // /
  type_opr["i/d"] = "d";
  type_opr["i/i"] = "i";
  type_opr["d/i"] = "d";
  type_opr["d/d"] = "d";

  //  >
  type_opr["i>i"] = "b";
  type_opr["i>d"] = "b";
  type_opr["d>i"] = "b";
  type_opr["d>d"] = "b";
  type_opr["c>c"] = "b";
  type_opr["i>c"] = "b";
  type_opr["c>i"] = "b";
  type_opr["s>s"] = "b";

  //  <
  type_opr["i<i"] = "b";
  type_opr["i<d"] = "b";
  type_opr["d<i"] = "b";
  type_opr["d<d"] = "b";
  type_opr["c<c"] = "b";
  type_opr["i<c"] = "b";
  type_opr["c<i"] = "b";
  type_opr["s<s"] = "b";

  //  >=
  type_opr["i>=i"] = "b";
  type_opr["i>=d"] = "b";
  type_opr["d>=i"] = "b";
  type_opr["d>=d"] = "b";
  type_opr["c>=c"] = "b";
  type_opr["i>=c"] = "b";
  type_opr["c>=i"] = "b";

  //  <=
  type_opr["i<=i"] = "b";
  type_opr["i<=d"] = "b";
  type_opr["d<=i"] = "b";
  type_opr["d<=d"] = "b";
  type_opr["c<=c"] = "b";
  type_opr["i<=c"] = "b";
  type_opr["c<=i"] = "b";

  //  ==
  type_opr["i==i"] = "b";
  type_opr["i==d"] = "b";
  type_opr["d==i"] = "b";
  type_opr["d==d"] = "b";
  type_opr["c==c"] = "b";
  type_opr["i==c"] = "b";
  type_opr["c==i"] = "b";
  type_opr["s==s"] = "b";

  // !=
  type_opr["i!=i"] = "b";
  type_opr["i!=d"] = "b";
  type_opr["d!=i"] = "b";
  type_opr["d!=d"] = "b";
  type_opr["c!=c"] = "b";
  type_opr["i!=c"] = "b";
  type_opr["c!=i"] = "b";
  type_opr["s!=s"] = "i";

  // =
  type_opr["i=i"] = "i";
  type_opr["b=b"] = "b";
  type_opr["b=i"] = "b";
  type_opr["d=d"] = "d";
  type_opr["d=i"] = "d";
  type_opr["c=c"] = "c";
  type_opr["s=s"] = "s";
  type_opr["s=c"] = "s";

  // and
  type_opr["b&&b"] = "b";
  type_opr["i&&i"] = "b";
  type_opr["i&&d"] = "b";
  type_opr["d&&i"] = "b";
  type_opr["d&&d"] = "b";

  // or
  type_opr["b||b"] = "b";
  type_opr["i||i"] = "b";
  type_opr["i||d"] = "b";
  type_opr["d||i"] = "b";
  type_opr["d||d"] = "b";

  // not
  type_opr["!i"] = "i";
  type_opr["!b"] = "b";
  type_opr["!c"] = "c";
  type_opr["!d"] = "d";

  // mod
  type_opr["i%i"] = "i";

  // in
  type_opr["iini"] = "b";
  type_opr["dind"] = "b";
  type_opr["cinc"] = "b";
  type_opr["sins"] = "b";
  type_opr["iins"] = "b";
  type_opr["dins"] = "b";
  type_opr["iinc"] = "b";
  type_opr["cins"] = "b";

  // @
  type_opr["i@i"] = "i";
  type_opr["d@d"] = "i";
  type_opr["c@c"] = "i";
}

void insert_var_ts(string nome, Type type){
  if(ts.find(nome) != ts.end()){
    erro("Variavel ja declarada: " + nome);
  }
  ts[nome] = type;
}

Type check_ts(string nome) {
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

string decl_var(string nome, Type type){
  if(type.base_type == "s"){
    int tam = MAX_STRING_SIZE;
    if(type.ndim == 1)
      return translate_intern_C(type.base_type)
                + " " + nome + "[" + toString(type.tam[0]*tam) + "]";
    if(type.ndim == 2)
      return translate_intern_C(type.base_type)
              + " " + nome + "[" + toString(tam*type.tam[1]) + "]";
    return translate_intern_C(type.base_type) + " " + nome + "[" + toString(tam) + "]";
  }
  if(type.ndim == 1)
    return translate_intern_C(type.base_type)
              + " " + nome + "[" + toString(type.tam[0]) + "]";
  if(type.ndim == 2)
    return translate_intern_C(type.base_type)
            + " " + nome + "[" + toString(type.tam[0]*type.tam[1]) + "]";

  return translate_intern_C(type.base_type) + " " + nome;
}


string translate_intern_C(string interno){
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
  erro("Type interno inexistente: " + interno);
  return "";
}

string translate_realness_intern(string realness){
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
  erro("Type " + realness + " em The Realness inexistente");
  return "";
}

string translate_intern_realness(string interno){
  if(interno == "i")
    return "integer";
  if(interno == "c")
    return "char";
  if(interno == "b")
    return "boolean";
  if(interno == "d")
    return "double";
  if(interno == "s")
    return "string";
  erro("Type interno " + interno + " inexistente");
  return "";
}

string rename_user_var(string nome){
  return "_" + nome;
}

string vartmp_name_generator(string tipo_interno){
  static int n = 1;
  string nome = "t" + tipo_interno + "_" + toString(n++);

  block_vars[block_vars.size()-1] += "  "
                                  + decl_var(nome, Type(tipo_interno))
                                  + ";\n";

  return nome;
}

string array_limit_test_generator( string indice_1, Type tipoArray ) {
  string var_teste_tam = vartmp_name_generator( "b" );
  string var_teste = vartmp_name_generator( "b" );
  string label_end = label_generator( "limite_array_ok" );

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

string matrix_limit_test_generator(Atributos id, Atributos indice1, Atributos indice2){
  Type t_matriz = check_ts(id.valor);

  if(indice1.type.base_type != "i" || indice2.type.base_type != "i" ||
     indice1.type.ndim != 0 || indice2.type.ndim != 0)
    erro("indice tem que ser inteiro");

  if(t_matriz.ndim != 2)
    erro(id.valor + " nao é matriz.");

  return "";
}

string atribui_var(Atributos s1, Atributos s3){
  if (is_atribuivel(s1, s3) == 1){
    if (s1.type.base_type == "s"){
       return s3.codigo + "  strncpy("+ s1.valor + ", " + s3.valor +", "
                        + toString(MAX_STRING_SIZE) + ");\n";
    } else if (s1.type.base_type == "b" && s3.type.base_type == "i") {
      string val = (s3.valor == "0" ? "0" : "1");
      return s3.codigo + "  " + s1.valor + " = " + val + ";\n";
    } else {
      return s3.codigo + "  " + s1.valor + " = " + s3.valor + ";\n";
    }
  } else{
    erro("Atribuicao nao permitida! "
          + translate_intern_realness(s1.type.base_type) + " = "
          + translate_intern_realness(s3.type.base_type));
  }
}

string atribuicao_array(Atributos s1, Atributos pos, Atributos s3){
  if (is_atribuivel(s1,s3) == 1) {
      return pos.codigo + s3.codigo + "  " + s1.valor + "[" + pos.valor + "] = " + s3.valor + ";\n";
  }
  else{
    erro("Atribuicao nao permitida!");
  }
}



string std_reading(Atributos s3){
  string codigo;
  string indice_pula_linha = vartmp_name_generator("i");
  if (s3.type.base_type == "s"){
    codigo = s3.codigo + "  fgets(" + s3.valor + ", " + toString(MAX_STRING_SIZE) + ", stdin);\n"
                       + "  " + indice_pula_linha + " = strcspn(" + s3.valor + ", \"\\n\");\n"
                       + "  " + s3.valor + "[" + indice_pula_linha + "] = 0;\n";
  } else{
    codigo = s3.codigo + "  cin >> " + s3.valor +  ";\n";
  }
  return codigo;
}

string label_generator(string type){
  static int n = 0;
  string nome = "l_" + type + "_" + toString(++n);
  return nome;
}

string desbloquifica(string lexema){
  lexema[0] = ' ';
  lexema[lexema.size()-2] = ' ';
  return lexema;
}

int is_atribuivel(Atributos s1, Atributos s3){
  string key = s1.type.base_type + "=" + s3.type.base_type;
  if (type_opr.find(key) != type_opr.end()){
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

Atributos opr_code_generator(Atributos s1, string opr, Atributos s3){
  Atributos ss;

  string tipo1 = s1.type.base_type;
  string tipo3 = s3.type.base_type;
  string tipo_resultado = type_opr[tipo1 + opr + tipo3];

  if(tipo_resultado == "")
    erro("Operacao nao permitida. " + translate_intern_realness(tipo1) + " " + opr + " " + translate_intern_realness(tipo3));

  ss.valor = vartmp_name_generator(tipo_resultado);
  ss.type = Type(tipo_resultado);

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
  else if(s1.type.ndim == 1 && s3.type.ndim == 1 && opr == "@"){
    int tam, aux;
    string atr1, atr2;
    string type = tipo1;

    if(type == "c") aux = sizeof(toChar(type));
    else if (type == "d") aux = sizeof(toDouble(type));
    else if (type == "i" || type == "b") aux = sizeof(toInt(type));

    if (s1.type.tam[0]>s3.type.tam[0]){
      tam = s1.type.tam[0]*aux;
      atr1 = s1.valor;
      atr2 = s3.valor;
    }
    else {
      tam = s3.type.tam[0]*aux;
      atr1 = s3.valor;
      atr2 = s1.valor;
    }
    ss.codigo += "  " + ss.valor + " = memcmp(" + atr1 + ", " + atr2 + ", " + toString(tam) + ") ; \n";
    ss.codigo += "  " + ss.valor + " = !" + ss.valor + ";\n";
  }

  else {
    ss.codigo += "  " + ss.valor + " = " + s1.valor + " " + opr + " " + s3.valor + ";\n";
  }
  return ss;
}

Atributos in_opr_code_generator(Atributos var, string opr, Atributos array){
  Atributos ss;

  string tipo1 = var.type.base_type;
  string tipo3 = array.type.base_type;
  string tipo_resultado = type_opr[tipo1 + opr + tipo3];

  if(tipo_resultado == "")
    erro("Operacao nao permitida. " + translate_intern_realness(tipo1) + " " + opr + " " + translate_intern_realness(tipo3));

  if(array.type.ndim > 0){
    string res = vartmp_name_generator(tipo_resultado);
    string array_temp = vartmp_name_generator(tipo3);
    ss.type = Type(tipo_resultado);
    int tam_array;

    if(array.type.ndim == 1)
      tam_array = array.type.tam[0];
    else
      tam_array = array.type.tam[0]*array.type.tam[1];

    string label_in = label_generator("in");
    int indice = 0;
    ss.codigo = "\n\n  " + res + " = 0;\n";

    for(int i=0;i<tam_array;i++){
      string array_valor = array.valor + "["+ toString(i) + "]";
      string label_not_in = label_generator("not_in");
      string var_temp = vartmp_name_generator(tipo1);

      ss.codigo += var.codigo + array.codigo + "  " + array_temp + " = " + array_valor + ";\n"
                    + "  " + var_temp + " = " + var.valor + " == " + array_temp + ";\n"
                    + "  " + var_temp + " = !" + var_temp + ";\n" + "  if ("+ var_temp +") goto " + label_not_in + ";\n"
                    + "    " + res + " = 1;\n" + "  goto " + label_in + ";\n" + label_not_in + ":;\n\n";
      }
      ss.codigo += label_in + ":;\n";
      ss.valor = res;
    }
    else{
      erro(array.valor + " não é um array");
    }
    return ss;
}

Atributos un_opr_code_generator(string opr, Atributos s2){
  Atributos ss;

  string tipo2 = s2.type.base_type;
  string tipo_resultado = type_opr[opr + tipo2];

  if(tipo_resultado == "")
    erro("Operacao nao permitida. " + opr + translate_intern_realness(tipo2));

  ss.valor = vartmp_name_generator(tipo_resultado);
  ss.type = Type(tipo_resultado);

  ss.codigo = s2.codigo + "  " + ss.valor + " = " + opr + s2.valor + ";\n";

  return ss;
}

Atributos if_code_generator(Atributos expr, string cmd_then, string cmd_else){

  Atributos ss;
  string label_else = label_generator( "else" );
  string label_end = label_generator( "end" );

  ss.codigo = expr.codigo + "  " + expr.valor + " = !" + expr.valor + ";\n\n" + "  if( " + expr.valor + " ) goto " + label_else + ";\n" +
         cmd_then + "  goto " + label_end + ";\n" + "  " + label_else + ":;\n" + cmd_else + "  " + label_end + ":;\n";
  return ss;
}

Atributos while_code_generator(Atributos expr, Atributos bloco){
  Atributos ss;
  string label_teste = label_generator( "teste_while" );
  string label_end = label_generator( "fim_while" );

  string condicao_var = vartmp_name_generator(expr.type.base_type);

  ss.codigo = label_teste + ":;\n" + expr.codigo + "  " + condicao_var + " = !" + expr.valor + ";\n\n"
            + "if ("+ condicao_var +") goto " + label_end + ";\n" + desbloquifica(bloco.codigo)
            + "goto " + label_teste + ";\n" + label_end + ":;\n";
  return ss;
}

Atributos do_while_code_generator(Atributos bloco, Atributos expr){
  Atributos ss;
  string label_teste = label_generator( "teste_dowhile" );
  string label_end = label_generator( "fim_dowhile" );

  string condicao_var = vartmp_name_generator(expr.type.base_type);
  ss.codigo = label_teste + ":;\n" + desbloquifica(bloco.codigo) + expr.codigo + "  " + condicao_var + " = !" + expr.valor + ";\n\n"
            + "if ("+ condicao_var +") goto " + label_end + ";\n" + "goto " + label_teste + ";\n" + label_end + ":;\n";
  return ss;
}

Atributos for_code_generator(Atributos atrib, Atributos condicao, Atributos pulo, Atributos bloco){
  Atributos ss;
  string var_fim = vartmp_name_generator( atrib.type.base_type );
  string label_teste = label_generator( "teste_for" );
  string label_end = label_generator( "fim_for" );
  string condicao_var = vartmp_name_generator(condicao.type.base_type);

  ss.codigo = atrib.codigo + label_teste + ":;\n" + condicao.codigo + "  " + condicao_var + " = !" + condicao.valor + ";\n\n"
            + "if ("+ condicao_var +") goto " + label_end + ";\n" + desbloquifica(bloco.codigo)
            + pulo.codigo + "  goto " + label_teste + ";\n" + label_end + ":;\n";
  return ss;
}

int main(int argc, char* argv[]){
  initializing_oprs();
  yyparse();
}
