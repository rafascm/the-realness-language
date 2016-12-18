/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "trabalho.y" /* yacc.c:339  */

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
void insere_ts(string nome, Tipo tipo);

Tipo consulta_ts(string nome);

string toString(int n);
string declara_variavel(string nome, Tipo tipo);
string traduz_interno_para_C(string interno);
string traduz_realness_para_interno(string realness);
string traduz_interno_para_realness(string interno);
string renomeia_variavel_usuario(string nome);
string gera_nome_var_temp(string tipo_interno);
string atribuicao_var(Atributos s1, Atributos s3);
string leitura_padrao(Atributos s3);
string gera_label(string tipo);
string desbloquifica(string lexema);

string atribuicao_array(Atributos s1, Atributos pos, Atributos s3);
string atribuicao_matriz(Atributos s1, Atributos pos_linha, Atributos pos_coluna, Atributos s3);

int is_atribuivel(Atributos s1, Atributos s3);
int toInt(string valor);

Atributos gera_codigo_operador(Atributos s1, string opr, Atributos s3);
Atributos gera_codigo_operador_unario(string opr, Atributos s2);
Atributos gera_codigo_if(Atributos expr, string cmd_then, string cmd_else);
Atributos gera_codigo_while(Atributos expr, Atributos bloco);
Atributos gera_codigo_do_while(Atributos bloco, Atributos expr);
Atributos gera_codigo_for(Atributos atrib, Atributos condicao, Atributos pulo, Atributos bloco);

string gera_teste_limite_array( string indice_1, Tipo tipoArray );
string gera_teste_limite_matriz( Atributos id, Atributos indice_1, Atributos indice_2);

map<string, Tipo> ts;
// Pilha de variaveis (temporarias ou definidas pelo usuario)
// que vao ser declaradas no inicio de cada bloco.
vector<string> vars_bloco;
// Faz o mapeamento dos tipos dos operadores
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


#line 184 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_INT = 258,
    TK_CHAR = 259,
    TK_DOUBLE = 260,
    TK_STRING = 261,
    TK_BOOL = 262,
    TK_VOID = 263,
    TK_TRUE = 264,
    TK_FALSE = 265,
    TK_MAIN = 266,
    TK_BEGIN = 267,
    TK_END = 268,
    TK_ID = 269,
    TK_CINT = 270,
    TK_CDOUBLE = 271,
    TK_CSTRING = 272,
    TK_RETURN = 273,
    TK_ATRIB = 274,
    TK_CCHAR = 275,
    TK_WRITE = 276,
    TK_READ = 277,
    TK_G = 278,
    TK_L = 279,
    TK_GE = 280,
    TK_LE = 281,
    TK_DIFF = 282,
    TK_IF = 283,
    TK_ELSE = 284,
    TK_E = 285,
    TK_AND = 286,
    TK_OR = 287,
    TK_NOT = 288,
    TK_BREAK = 289,
    TK_FOR = 290,
    TK_WHILE = 291,
    TK_DO = 292,
    TK_SWITCH = 293,
    TK_START = 294,
    TK_STOP = 295,
    TK_MOD = 296
  };
#endif
/* Tokens.  */
#define TK_INT 258
#define TK_CHAR 259
#define TK_DOUBLE 260
#define TK_STRING 261
#define TK_BOOL 262
#define TK_VOID 263
#define TK_TRUE 264
#define TK_FALSE 265
#define TK_MAIN 266
#define TK_BEGIN 267
#define TK_END 268
#define TK_ID 269
#define TK_CINT 270
#define TK_CDOUBLE 271
#define TK_CSTRING 272
#define TK_RETURN 273
#define TK_ATRIB 274
#define TK_CCHAR 275
#define TK_WRITE 276
#define TK_READ 277
#define TK_G 278
#define TK_L 279
#define TK_GE 280
#define TK_LE 281
#define TK_DIFF 282
#define TK_IF 283
#define TK_ELSE 284
#define TK_E 285
#define TK_AND 286
#define TK_OR 287
#define TK_NOT 288
#define TK_BREAK 289
#define TK_FOR 290
#define TK_WHILE 291
#define TK_DO 292
#define TK_SWITCH 293
#define TK_START 294
#define TK_STOP 295
#define TK_MOD 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 314 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   549

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  197

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      50,    51,    43,    41,    49,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    46,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   136,   136,   144,   148,   151,   154,   157,   159,   164,
     180,   190,   198,   210,   217,   223,   228,   233,   253,   258,
     263,   268,   273,   278,   288,   291,   292,   295,   296,   299,
     300,   301,   302,   306,   306,   317,   324,   328,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   346,   354,
     363,   367,   374,   378,   379,   382,   383,   386,   387,   390,
     394,   400,   406,   417,   425,   433,   439,   445,   449,   453,
     457,   461,   465,   469,   473,   477,   481,   485,   489,   493,
     497,   501,   505,   508,   514,   520,   526,   532,   538,   554,
     575,   579,   585
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_INT", "TK_CHAR", "TK_DOUBLE",
  "TK_STRING", "TK_BOOL", "TK_VOID", "TK_TRUE", "TK_FALSE", "TK_MAIN",
  "TK_BEGIN", "TK_END", "TK_ID", "TK_CINT", "TK_CDOUBLE", "TK_CSTRING",
  "TK_RETURN", "TK_ATRIB", "TK_CCHAR", "TK_WRITE", "TK_READ", "TK_G",
  "TK_L", "TK_GE", "TK_LE", "TK_DIFF", "TK_IF", "TK_ELSE", "TK_E",
  "TK_AND", "TK_OR", "TK_NOT", "TK_BREAK", "TK_FOR", "TK_WHILE", "TK_DO",
  "TK_SWITCH", "TK_START", "TK_STOP", "'+'", "'-'", "'*'", "'/'", "TK_MOD",
  "';'", "'['", "']'", "','", "'('", "')'", "':'", "$accept", "S", "MAIN",
  "DECLS", "DECL", "VAR", "VAR_DEFS", "ATRIB", "TIPO", "FUNCTION",
  "F_PARAMS", "PARAMS", "PARAM", "BLOCO", "$@1", "SUB_BLOCO", "CMDS",
  "CMD", "CMD_WROTEU", "CMD_READU", "CMD_RETURN", "CMD_CALL",
  "CALL_PARAMS", "C_PARAMS", "C_PARAM", "CMD_IF", "CMD_FOR", "BEGIN_FOR",
  "CONT_FOR", "CMD_WHILE", "CMD_DOWHILE", "E", "F", "BOOL", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    43,    45,    42,    47,   296,    59,    91,    93,    44,
      40,    41,    58
};
# endif

#define YYPACT_NINF -143

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-143)))

#define YYTABLE_NINF -33

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-33)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -20,   -24,    21,  -143,  -143,   532,  -143,  -143,  -143,  -143,
    -143,  -143,    11,   -16,  -143,   -21,    14,  -143,  -143,  -143,
     -17,  -143,    16,  -143,   113,  -143,    42,    15,    17,     0,
      34,   -18,    23,    26,    27,    29,    30,    20,    18,    36,
      69,    73,   113,    45,    47,    48,    50,  -143,  -143,  -143,
      52,  -143,  -143,    54,  -143,  -143,  -143,  -143,    42,    42,
     449,  -143,  -143,    51,    53,  -143,    89,    55,    59,  -143,
      42,    42,    95,    42,    42,    97,    42,    64,    42,   113,
      76,  -143,  -143,    41,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,    42,  -143,   128,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    66,    68,    11,
     139,   449,   243,    75,    72,    77,  -143,   449,   151,    78,
     174,   105,   114,    84,   197,   123,    87,   269,  -143,   481,
     481,   481,   481,   481,   481,   504,   472,   -34,   -34,  -143,
    -143,  -143,   124,    42,  -143,  -143,     8,    42,  -143,    95,
    -143,  -143,   113,    42,   119,    42,    20,  -143,    42,    93,
     108,   295,    42,    42,   321,  -143,   132,   449,    42,   425,
    -143,   220,    42,  -143,   110,   449,   347,  -143,   113,   449,
     148,  -143,   373,    42,   144,  -143,   145,   115,  -143,   399,
      42,    42,    20,  -143,   449,   449,  -143
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     6,     1,     4,    18,    19,    20,    21,
      22,    23,     0,     0,     5,     0,     0,     8,    33,     3,
       0,     7,    14,     9,    37,     2,     0,     0,     0,    26,
       0,    50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,    42,    43,    44,
       0,    91,    92,    83,    84,    85,    87,    86,     0,     0,
      10,    82,    90,     0,    14,    13,     0,     0,    25,    28,
       0,     0,    54,     0,     0,     0,     0,     0,     0,    37,
       0,    47,    46,    14,    34,    36,    38,    39,    40,    41,
      45,     0,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    29,     0,
      32,    15,     0,    57,     0,    53,    56,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    81,    71,
      72,    73,    74,    75,    76,    77,    78,    67,    68,    69,
      70,    79,     0,     0,    24,    27,     0,     0,    52,     0,
      48,    49,     0,     0,     0,     0,     0,    35,     0,    88,
       0,     0,     0,     0,     0,    55,    59,    63,     0,     0,
      65,     0,     0,    12,    30,    16,     0,    58,     0,    62,
       0,    66,     0,     0,     0,    60,     0,     0,    89,     0,
       0,     0,     0,    31,    17,    64,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,  -143,  -143,  -143,   160,   140,  -143,    -3,  -143,
    -143,  -143,    57,    71,  -143,  -142,   -25,   -91,  -143,  -143,
    -143,  -143,  -143,  -143,    35,  -143,  -143,  -143,  -143,  -143,
    -143,   -58,  -143,  -143
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    13,     5,    14,    38,    23,    39,    40,    17,
      67,    68,    69,    19,    24,    80,    41,    42,    43,    44,
      45,    46,   114,   115,   116,    47,    48,   123,   187,    49,
      50,    60,    61,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      92,    93,    16,     6,     7,     8,     9,    10,    11,   104,
     105,   106,   111,   112,   170,   117,   118,    85,   120,     1,
     124,     4,     3,    18,    20,    21,    66,   162,    22,    25,
      63,    64,    79,   127,    73,    26,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   -32,
     196,    51,    52,    70,   125,   163,    53,    54,    55,    56,
      26,   166,    57,    27,    81,    28,    29,     6,     7,     8,
       9,    10,    11,    74,   122,    58,    75,    76,   121,    77,
      78,    71,    82,    83,    72,   161,    84,   185,    27,   164,
      28,    86,    59,    87,    88,   167,    89,   169,    90,   107,
     171,    91,    28,   108,   175,   176,   109,    66,   110,   113,
     179,   119,   126,   142,   182,   143,     6,     7,     8,     9,
      10,    11,   147,   148,   153,   189,   149,    30,   154,   151,
     155,    31,   194,   195,    32,    33,   157,   158,   168,   160,
     172,    34,     6,     7,     8,     9,    10,    11,    35,    36,
      37,    94,    95,    96,    97,    98,   173,   183,    99,   100,
     101,   178,   186,   190,   191,    15,   192,   145,    65,   102,
     103,   104,   105,   106,    94,    95,    96,    97,    98,   128,
     144,    99,   100,   101,   165,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   104,   105,   106,    94,    95,    96,
      97,    98,   150,     0,    99,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   103,   104,   105,   106,
      94,    95,    96,    97,    98,   152,     0,    99,   100,   101,
       0,     0,     0,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,    94,    95,    96,    97,    98,   156,     0,
      99,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,    94,    95,    96,    97,
      98,   181,     0,    99,   100,   101,     0,     0,     0,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,     0,
       0,   146,    94,    95,    96,    97,    98,     0,     0,    99,
     100,   101,     0,     0,     0,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,     0,     0,   159,    94,    95,
      96,    97,    98,     0,     0,    99,   100,   101,     0,     0,
       0,     0,     0,     0,     0,     0,   102,   103,   104,   105,
     106,     0,     0,   174,    94,    95,    96,    97,    98,     0,
       0,    99,   100,   101,     0,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   104,   105,   106,     0,     0,   177,
      94,    95,    96,    97,    98,     0,     0,    99,   100,   101,
       0,     0,     0,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,     0,     0,   184,    94,    95,    96,    97,
      98,     0,     0,    99,   100,   101,     0,     0,     0,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,     0,
       0,   188,    94,    95,    96,    97,    98,     0,     0,    99,
     100,   101,     0,     0,     0,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,     0,     0,   193,    94,    95,
      96,    97,    98,     0,     0,    99,   100,   101,     0,     0,
       0,     0,     0,     0,     0,     0,   102,   103,   104,   105,
     106,   180,    94,    95,    96,    97,    98,     0,     0,    99,
     100,   101,     0,     0,     0,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,    94,    95,    96,    97,    98,
       0,     0,    99,   100,   -33,   -33,   -33,   -33,   -33,     0,
       0,   -33,     0,   102,   103,   104,   105,   106,     0,     0,
       0,     0,   102,   103,   104,   105,   106,    94,    95,    96,
      97,    98,     0,     0,    99,     6,     7,     8,     9,    10,
      11,     0,     0,    12,     0,   102,   103,   104,   105,   106
};

static const yytype_int16 yycheck[] =
{
      58,    59,     5,     3,     4,     5,     6,     7,     8,    43,
      44,    45,    70,    71,   156,    73,    74,    42,    76,    39,
      78,     0,    46,    12,    40,    46,    29,    19,    14,    46,
      15,    14,    12,    91,    52,    19,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,    49,
     192,     9,    10,    19,    79,    47,    14,    15,    16,    17,
      19,   152,    20,    47,    46,    49,    50,     3,     4,     5,
       6,     7,     8,    50,    77,    33,    50,    50,    14,    50,
      50,    47,    46,    14,    50,   143,    13,   178,    47,   147,
      49,    46,    50,    46,    46,   153,    46,   155,    46,    48,
     158,    47,    49,    14,   162,   163,    51,   110,    49,    14,
     168,    14,    36,    47,   172,    47,     3,     4,     5,     6,
       7,     8,    47,    51,    19,   183,    49,    14,    14,    51,
      46,    18,   190,   191,    21,    22,    13,    50,    19,    15,
      47,    28,     3,     4,     5,     6,     7,     8,    35,    36,
      37,    23,    24,    25,    26,    27,    48,    47,    30,    31,
      32,    29,    14,    19,    19,     5,    51,   110,    28,    41,
      42,    43,    44,    45,    23,    24,    25,    26,    27,    51,
     109,    30,    31,    32,   149,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    23,    24,    25,
      26,    27,    51,    -1,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      23,    24,    25,    26,    27,    51,    -1,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    23,    24,    25,    26,    27,    51,    -1,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    23,    24,    25,    26,
      27,    51,    -1,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,    -1,
      -1,    48,    23,    24,    25,    26,    27,    -1,    -1,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    42,    43,    44,    45,    -1,    -1,    48,    23,    24,
      25,    26,    27,    -1,    -1,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      45,    -1,    -1,    48,    23,    24,    25,    26,    27,    -1,
      -1,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    -1,    -1,    48,
      23,    24,    25,    26,    27,    -1,    -1,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    -1,    -1,    48,    23,    24,    25,    26,
      27,    -1,    -1,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,    -1,
      -1,    48,    23,    24,    25,    26,    27,    -1,    -1,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    42,    43,    44,    45,    -1,    -1,    48,    23,    24,
      25,    26,    27,    -1,    -1,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      45,    46,    23,    24,    25,    26,    27,    -1,    -1,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    42,    43,    44,    45,    23,    24,    25,    26,    27,
      -1,    -1,    30,    31,    23,    24,    25,    26,    27,    -1,
      -1,    30,    -1,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    23,    24,    25,
      26,    27,    -1,    -1,    30,     3,     4,     5,     6,     7,
       8,    -1,    -1,    11,    -1,    41,    42,    43,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    54,    46,     0,    56,     3,     4,     5,     6,
       7,     8,    11,    55,    57,    58,    61,    62,    12,    66,
      40,    46,    14,    59,    67,    46,    19,    47,    49,    50,
      14,    18,    21,    22,    28,    35,    36,    37,    58,    60,
      61,    69,    70,    71,    72,    73,    74,    78,    79,    82,
      83,     9,    10,    14,    15,    16,    17,    20,    33,    50,
      84,    85,    86,    15,    14,    59,    61,    63,    64,    65,
      19,    47,    50,    52,    50,    50,    50,    50,    50,    12,
      68,    46,    46,    14,    13,    69,    46,    46,    46,    46,
      46,    47,    84,    84,    23,    24,    25,    26,    27,    30,
      31,    32,    41,    42,    43,    44,    45,    48,    14,    51,
      49,    84,    84,    14,    75,    76,    77,    84,    84,    14,
      84,    14,    61,    80,    84,    69,    36,    84,    51,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    47,    47,    66,    65,    48,    47,    51,    49,
      51,    51,    51,    19,    14,    46,    51,    13,    50,    48,
      15,    84,    19,    47,    84,    77,    70,    84,    19,    84,
      68,    84,    47,    48,    48,    84,    84,    48,    29,    84,
      46,    51,    84,    47,    48,    70,    14,    81,    48,    84,
      19,    19,    51,    48,    84,    84,    68
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    58,    58,    59,    59,    60,    60,    60,    61,    61,
      61,    61,    61,    61,    62,    63,    63,    64,    64,    65,
      65,    65,    65,    67,    66,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    71,    72,
      73,    73,    74,    75,    75,    76,    76,    77,    77,    78,
      78,    79,    80,    80,    81,    82,    83,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    85,    85,    85,    85,    85,    85,    85,
      85,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     2,     0,     2,     0,     2,     1,     2,
       4,     5,     8,     3,     1,     3,     6,     9,     1,     1,
       1,     1,     1,     1,     6,     1,     0,     3,     1,     2,
       5,     8,     0,     0,     4,     3,     2,     0,     2,     2,
       2,     2,     1,     1,     1,     2,     2,     2,     4,     4,
       1,     3,     4,     1,     0,     3,     1,     1,     4,     5,
       7,     9,     4,     3,     3,     5,     6,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     1,     1,     1,     1,     1,     1,     4,     7,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 137 "trabalho.y" /* yacc.c:1646  */
    {
      cout << includes << endl;
      cout << (yyvsp[-3]).codigo << endl;
      cout << (yyvsp[-2]).codigo << endl;
    }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 145 "trabalho.y" /* yacc.c:1646  */
    {
          (yyval).codigo = "int main()" + (yyvsp[0]).codigo;
        }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 152 "trabalho.y" /* yacc.c:1646  */
    { (yyval).codigo = (yyvsp[-1]).codigo + (yyvsp[0]).codigo; }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 154 "trabalho.y" /* yacc.c:1646  */
    { (yyval).codigo = ""; }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 158 "trabalho.y" /* yacc.c:1646  */
    { (yyval).codigo = (yyvsp[-1]).codigo; }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 165 "trabalho.y" /* yacc.c:1646  */
    {
        (yyval).codigo = "";
        // Os nomes das variaveis estao na lista_str de $2.
        // Cada variavel e' inserida na tabela de simbolos e
        // sua declaracao e' adicionada a lista de declaracao
        // do bloco atual, que so sera impressa no inicio do bloco.
        for(vector<string>::iterator it = (yyvsp[0]).lista_str.begin();
                                     it != (yyvsp[0]).lista_str.end();
                                     it++){
          vars_bloco[vars_bloco.size()-1] += "  "
                                          + (declara_variavel(*it, (yyvsp[-1]).tipo))
                                          + ";\n";
          insere_ts(*it, (yyvsp[-1]).tipo);
        }
      }
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 181 "trabalho.y" /* yacc.c:1646  */
    {
        (yyval) = Atributos((yyvsp[-2]).valor, (yyvsp[-3]).tipo);
        vars_bloco[vars_bloco.size()-1] += "  "
                                        + declara_variavel((yyvsp[-2]).valor, (yyvsp[-3]).tipo)
                                        + ";\n";
        insere_ts((yyvsp[-2]).valor, (yyvsp[-3]).tipo);
        (yyvsp[-2]).tipo = (yyvsp[-3]).tipo;
        (yyval).codigo = atribuicao_var((yyvsp[-2]), (yyvsp[0]));
      }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 191 "trabalho.y" /* yacc.c:1646  */
    {
        (yyval) = Atributos((yyvsp[-3]).valor, Tipo((yyvsp[-4]).tipo.tipo_base, toInt((yyvsp[-1]).valor)));
        vars_bloco[vars_bloco.size()-1] += "  "
                                        + declara_variavel((yyval).valor, (yyval).tipo)
                                        + ";\n";
        insere_ts((yyval).valor, (yyval).tipo);
      }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 199 "trabalho.y" /* yacc.c:1646  */
    {
        (yyval) = Atributos((yyvsp[-6]).valor, Tipo((yyvsp[-7]).tipo.tipo_base, toInt((yyvsp[-4]).valor), toInt((yyvsp[-1]).valor)));
        vars_bloco[vars_bloco.size()-1] += "  "
                                        + declara_variavel((yyval).valor, (yyval).tipo)
                                        + ";\n";
        insere_ts((yyval).valor, (yyval).tipo);
      }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 211 "trabalho.y" /* yacc.c:1646  */
    {
              (yyval).lista_str.push_back((yyvsp[-2]).valor);
              (yyval).lista_str.insert((yyval).lista_str.end(),
                                  (yyvsp[0]).lista_str.begin(),
                                  (yyvsp[0]).lista_str.end());
            }
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 218 "trabalho.y" /* yacc.c:1646  */
    {
              (yyval).lista_str.push_back((yyvsp[0]).valor);
            }
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 224 "trabalho.y" /* yacc.c:1646  */
    {
          (yyvsp[-2]).tipo = consulta_ts((yyvsp[-2]).valor);
          (yyval).codigo = atribuicao_var((yyvsp[-2]), (yyvsp[0]));
        }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 229 "trabalho.y" /* yacc.c:1646  */
    {
          (yyvsp[-5]).tipo = consulta_ts((yyvsp[-5]).valor);
          (yyval).codigo = atribuicao_array((yyvsp[-5]),(yyvsp[-3]),(yyvsp[0]));
        }
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 234 "trabalho.y" /* yacc.c:1646  */
    {
          // Chama o teste de limites antes de mais nada.
          string teste_limites = gera_teste_limite_matriz((yyvsp[-8]), (yyvsp[-6]), (yyvsp[-3]));
          string indice_temp = gera_nome_var_temp("i");
          string multi_temp = gera_nome_var_temp("i");


          Tipo t_matriz = consulta_ts((yyvsp[-8]).valor);
          (yyval).codigo = (yyvsp[-6]).codigo + (yyvsp[-3]).codigo + (yyvsp[0]).codigo
                    + "  " + multi_temp + " = " + (yyvsp[-6]).valor + "*"
                    + toString(t_matriz.tam[1]) + ";\n"
                    + "  " + indice_temp + " = "
                    + multi_temp + " + " + (yyvsp[-3]).valor + ";\n"
                    + teste_limites
                    + "  " + (yyvsp[-8]).valor + "[" + indice_temp
                    + "] = " + (yyvsp[0]).valor + ";\n";
        }
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 254 "trabalho.y" /* yacc.c:1646  */
    {
          Tipo t("i");
          (yyval) = Atributos("int", t);
        }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 259 "trabalho.y" /* yacc.c:1646  */
    {
          Tipo t("c");
          (yyval) = Atributos("char", t);
        }
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 264 "trabalho.y" /* yacc.c:1646  */
    {
          Tipo t("d");
          (yyval) = Atributos("double", t);
        }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 269 "trabalho.y" /* yacc.c:1646  */
    {
          Tipo t("s");
          (yyval) = Atributos("char[]", t);
        }
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 274 "trabalho.y" /* yacc.c:1646  */
    {
          Tipo t("b");
          (yyval) = Atributos("int", t);
        }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 279 "trabalho.y" /* yacc.c:1646  */
    {
          Tipo t("v");
          (yyval) = Atributos("void", t);
        }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 306 "trabalho.y" /* yacc.c:1646  */
    { vars_bloco.push_back(""); }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 307 "trabalho.y" /* yacc.c:1646  */
    {
          (yyval).codigo = "{\n";
          // Adiciona as variaveis desse bloco ao inicio do mesmo e
          // desempilha a lista de variaveis desse bloco.
          (yyval).codigo += vars_bloco[vars_bloco.size()-1];
          vars_bloco.pop_back();
          (yyval).codigo += (yyvsp[-1]).codigo + "}\n";
        }
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 318 "trabalho.y" /* yacc.c:1646  */
    {
              (yyval).codigo = "{\n";
              (yyval).codigo += (yyvsp[-1]).codigo + "}\n";
            }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 325 "trabalho.y" /* yacc.c:1646  */
    {
          (yyval).codigo = (yyvsp[-1]).codigo + (yyvsp[0]).codigo;
        }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 328 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributos(); }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 340 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 347 "trabalho.y" /* yacc.c:1646  */
    {
               (yyval).codigo = (yyvsp[-1]).codigo +
                     "  cout << " + (yyvsp[-1]).valor + ";\n"
                     "  cout << endl;\n";
             }
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 355 "trabalho.y" /* yacc.c:1646  */
    {
                 (yyvsp[-1]).tipo = consulta_ts((yyvsp[-1]).valor);
                 (yyval).codigo = leitura_padrao((yyvsp[-1]));
               }
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 364 "trabalho.y" /* yacc.c:1646  */
    {
               (yyval).codigo = (yyvsp[0]).codigo + "  return 0;\n";
             }
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 368 "trabalho.y" /* yacc.c:1646  */
    {
               (yyval).codigo = (yyvsp[-2]).codigo + (yyvsp[0]).codigo + "  return "+ (yyvsp[0]).valor +";\n";
             }
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 391 "trabalho.y" /* yacc.c:1646  */
    {
           (yyval) = gera_codigo_if((yyvsp[-2]), (yyvsp[0]).codigo, "");
         }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 395 "trabalho.y" /* yacc.c:1646  */
    {
           (yyval) = gera_codigo_if((yyvsp[-4]), (yyvsp[-2]).codigo, (yyvsp[0]).codigo);
         }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 401 "trabalho.y" /* yacc.c:1646  */
    {
            (yyval) = gera_codigo_for((yyvsp[-6]), (yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]));
          }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 407 "trabalho.y" /* yacc.c:1646  */
    {
               (yyval) = Atributos((yyvsp[-2]).valor, (yyvsp[-3]).tipo);
               vars_bloco[vars_bloco.size()-1] += "  "
                                               + declara_variavel((yyvsp[-2]).valor, (yyvsp[-3]).tipo)
                                               + ";\n";
               insere_ts((yyvsp[-2]).valor, (yyvsp[-3]).tipo);
               (yyvsp[-2]).tipo = (yyvsp[-3]).tipo;
               (yyval).codigo = atribuicao_var((yyvsp[-2]), (yyvsp[0]));
             }
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 418 "trabalho.y" /* yacc.c:1646  */
    {
                (yyval) = Atributos((yyvsp[-2]).valor, consulta_ts((yyvsp[-2]).valor));
                (yyval).codigo = atribuicao_var((yyvsp[-2]), (yyvsp[0]));
              }
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 426 "trabalho.y" /* yacc.c:1646  */
    {
              (yyval).codigo = (yyvsp[0]).codigo + "\n" + "  "
                        + (yyvsp[-2]).valor + " = " + (yyvsp[0]).valor + ";\n";
            }
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 434 "trabalho.y" /* yacc.c:1646  */
    {
              (yyval) = gera_codigo_while((yyvsp[-2]), (yyvsp[0]));
            }
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 440 "trabalho.y" /* yacc.c:1646  */
    {
                (yyval) = gera_codigo_do_while((yyvsp[-4]), (yyvsp[-1]));
              }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 446 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval) = gera_codigo_operador((yyvsp[-2]), "+", (yyvsp[0]));
    }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 450 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval) = gera_codigo_operador((yyvsp[-2]), "-", (yyvsp[0]));
    }
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 454 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval) = gera_codigo_operador((yyvsp[-2]), "*", (yyvsp[0]));
    }
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 458 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval) = gera_codigo_operador((yyvsp[-2]), "/", (yyvsp[0]));
    }
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 462 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval) = gera_codigo_operador((yyvsp[-2]), ">", (yyvsp[0]));
    }
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 466 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval) = gera_codigo_operador((yyvsp[-2]), "<", (yyvsp[0]));
    }
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 470 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval) = gera_codigo_operador((yyvsp[-2]), ">=", (yyvsp[0]));
    }
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 474 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval) = gera_codigo_operador((yyvsp[-2]), "<=", (yyvsp[0]));
    }
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 478 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval) = gera_codigo_operador((yyvsp[-2]), "!=", (yyvsp[0]));
    }
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 482 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval) = gera_codigo_operador((yyvsp[-2]), "==", (yyvsp[0]));
    }
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 486 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval) = gera_codigo_operador((yyvsp[-2]), "&&", (yyvsp[0]));
    }
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 490 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval) = gera_codigo_operador((yyvsp[-2]), "||", (yyvsp[0]));
    }
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 494 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval) = gera_codigo_operador((yyvsp[-2]), "%", (yyvsp[0]));
    }
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 498 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval) = gera_codigo_operador_unario("!", (yyvsp[0]));
    }
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 502 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval) = (yyvsp[-1]);
    }
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 509 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval).valor = (yyvsp[0]).valor;
      (yyval).tipo = consulta_ts((yyvsp[0]).valor);
      (yyval).codigo = (yyvsp[0]).codigo;
    }
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 515 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval).valor = (yyvsp[0]).valor;
      (yyval).tipo = Tipo("i");
      (yyval).codigo = (yyvsp[0]).codigo;
    }
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 521 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval).valor = (yyvsp[0]).valor;
      (yyval).tipo = Tipo("d");
      (yyval).codigo = (yyvsp[0]).codigo;
    }
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 527 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval).valor = (yyvsp[0]).valor;
      (yyval).tipo = Tipo("c");
      (yyval).codigo = (yyvsp[0]).codigo;
    }
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 533 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval).valor = (yyvsp[0]).valor;
      (yyval).tipo = Tipo("s");
      (yyval).codigo = (yyvsp[0]).codigo;
    }
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 539 "trabalho.y" /* yacc.c:1646  */
    {
      Tipo tipoArray = consulta_ts( (yyvsp[-3]).valor );
      (yyval).tipo = Tipo( tipoArray.tipo_base );
      if( tipoArray.ndim != 1 )
        erro( "Variável " + (yyvsp[-3]).valor + " não é array de uma dimensão" );

      if( (yyvsp[-1]).tipo.ndim != 0 || (yyvsp[-1]).tipo.tipo_base != "i" )
        erro( "Indice de array deve ser integer de zero dimensão: " +
              (yyvsp[-1]).tipo.tipo_base + "/" + toString( (yyvsp[-1]).tipo.ndim ) );

      (yyval).valor = gera_nome_var_temp( (yyval).tipo.tipo_base );
      (yyval).codigo = (yyvsp[-1]).codigo +
             gera_teste_limite_array( (yyvsp[-1]).valor, tipoArray ) +
             "  " + (yyval).valor + " = " + (yyvsp[-3]).valor + "[" + (yyvsp[-1]).valor + "];\n";
    }
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 555 "trabalho.y" /* yacc.c:1646  */
    {
      // Chama o teste de limites antes de mais nada.
      string teste_limites = gera_teste_limite_matriz((yyvsp[-6]), (yyvsp[-4]), (yyvsp[-1]));
      string indice_temp = gera_nome_var_temp("i");
      string multi_temp = gera_nome_var_temp("i");

      Tipo t_matriz = consulta_ts((yyvsp[-6]).valor);

      (yyval).tipo = Tipo(t_matriz.tipo_base);
      (yyval).valor = gera_nome_var_temp((yyval).tipo.tipo_base);


      (yyval).codigo = (yyvsp[-4]).codigo + (yyvsp[-1]).codigo + teste_limites
                + "  " + multi_temp + " = " + (yyvsp[-4]).valor + "*"
                + toString(t_matriz.tam[1]) + ";\n"
                + "  " + indice_temp + " = "
                + multi_temp + " + " + (yyvsp[-1]).valor + ";\n"
                + "  " + (yyval).valor + " = " + (yyvsp[-6]).valor
                + "[" + indice_temp + "];\n";
    }
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 580 "trabalho.y" /* yacc.c:1646  */
    {
        (yyval).valor = "1";
        (yyval).tipo = Tipo("b");
        (yyval).codigo = (yyvsp[0]).codigo;
      }
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 586 "trabalho.y" /* yacc.c:1646  */
    {
        (yyval).valor = "0";
        (yyval).tipo = Tipo("b");
        (yyval).codigo = (yyvsp[0]).codigo;
      }
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2192 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 593 "trabalho.y" /* yacc.c:1906  */


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
  // TODO(jullytta): operacoes com char,
  // concatenar int/double/char com string

  // Operador +
  tipo_opr["i+i"] = "i";
  tipo_opr["i+d"] = "d";
  tipo_opr["d+i"] = "d";
  tipo_opr["d+d"] = "d";
  tipo_opr["s+s"] = "s";

  // Operador -
  tipo_opr["i-i"] = "i";
  tipo_opr["i-d"] = "d";
  tipo_opr["d-i"] = "d";
  tipo_opr["d-d"] = "d";

  // Operador *
  tipo_opr["i*i"] = "i";
  tipo_opr["i*d"] = "d";
  tipo_opr["d*i"] = "d";
  tipo_opr["d*d"] = "d";

  // Operador /
  // TODO(jullytta): lidar com a polemica desse operador
  tipo_opr["i/d"] = "d";
  tipo_opr["i/i"] = "i";
  tipo_opr["d/i"] = "d";
  tipo_opr["d/d"] = "d";

  // TODO(jullytta): comparacao de strings
  // Operadores: <>, ==, >, <, <=, >=
  // Operador >
  tipo_opr["i>i"] = "b";
  tipo_opr["i>d"] = "b";
  tipo_opr["d>i"] = "b";
  tipo_opr["d>d"] = "b";
  tipo_opr["c>c"] = "b";
  tipo_opr["i>c"] = "b";
  tipo_opr["c>i"] = "b";

  // Operador <
  tipo_opr["i<i"] = "b";
  tipo_opr["i<d"] = "b";
  tipo_opr["d<i"] = "b";
  tipo_opr["d<d"] = "b";
  tipo_opr["c<c"] = "b";
  tipo_opr["i<c"] = "b";
  tipo_opr["c<i"] = "b";

  // Operador >=
  tipo_opr["i>=i"] = "b";
  tipo_opr["i>=d"] = "b";
  tipo_opr["d>=i"] = "b";
  tipo_opr["d>=d"] = "b";
  tipo_opr["c>=c"] = "b";
  tipo_opr["i>=c"] = "b";
  tipo_opr["c>=i"] = "b";

  // Operador <=
  tipo_opr["i<=i"] = "b";
  tipo_opr["i<=d"] = "b";
  tipo_opr["d<=i"] = "b";
  tipo_opr["d<=d"] = "b";
  tipo_opr["c<=c"] = "b";
  tipo_opr["i<=c"] = "b";
  tipo_opr["c<=i"] = "b";

  // Operador ==
  tipo_opr["i==i"] = "b";
  tipo_opr["i==d"] = "b";
  tipo_opr["d==i"] = "b";
  tipo_opr["d==d"] = "b";
  tipo_opr["c==c"] = "b";
  tipo_opr["i==c"] = "b";
  tipo_opr["c==i"] = "b";

  // Operador <>
  tipo_opr["i!=i"] = "b";
  tipo_opr["i!=d"] = "b";
  tipo_opr["d!=i"] = "b";
  tipo_opr["d!=d"] = "b";
  tipo_opr["c!=c"] = "b";
  tipo_opr["i!=c"] = "b";
  tipo_opr["c!=i"] = "b";

  // Operador =
  tipo_opr["i=i"] = "i";
  tipo_opr["b=b"] = "b";
  tipo_opr["b=i"] = "b";
  tipo_opr["d=d"] = "d";
  tipo_opr["d=i"] = "d";
  tipo_opr["c=c"] = "c";
  tipo_opr["s=s"] = "s";
  tipo_opr["s=c"] = "s";

  // Operador e
  tipo_opr["b&&b"] = "b";
  tipo_opr["i&&i"] = "b";
  tipo_opr["i&&d"] = "b";
  tipo_opr["d&&i"] = "b";
  tipo_opr["d&&d"] = "b";

  // Operador ou
  tipo_opr["b||b"] = "b";
  tipo_opr["i||i"] = "b";
  tipo_opr["i||d"] = "b";
  tipo_opr["d||i"] = "b";
  tipo_opr["d||d"] = "b";

  // Operador naum
  tipo_opr["!i"] = "i";
  tipo_opr["!b"] = "b";
  tipo_opr["!c"] = "c";
  tipo_opr["!d"] = "d";

  // Operador modis
  tipo_opr["i%i"] = "i";

}

void insere_ts(string nome, Tipo tipo){
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
              + " " + nome + "[" + toString(tipo.tam[1]*tam) + "]";

    return "char " + nome + "[" + toString(tam) + "]";
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
  if(interno == "v")
    return "void";
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
  if(realness == "void")
    return "v";
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

  vars_bloco[vars_bloco.size()-1] += "  "
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

  // TODO(jullytta): codigo do teste dinamico retornado
  return "";
}

string atribuicao_var(Atributos s1, Atributos s3){
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
     // Falta testar: tipo, limite do array, e se a variável existe
      return pos.codigo + s3.codigo +
             "  " + s1.valor + "[" + pos.valor + "] = " + s3.valor + ";\n";
  }
  else{
    erro("Atribuicao nao permitida!");
  }
}



string leitura_padrao(Atributos s3){
  string codigo;
  // Usado para encontrar o pula linha que vem com fgets
  // e devidamente se livrar do mesmo.
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
  lexema[0] = ' '; //remove {
  lexema[lexema.size()-2] = ' '; // remove }
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

Atributos gera_codigo_operador(Atributos s1, string opr, Atributos s3){
  Atributos ss;

  string tipo1 = s1.tipo.tipo_base;
  string tipo3 = s3.tipo.tipo_base;
  string tipo_resultado = tipo_opr[tipo1 + opr + tipo3];

  // TODO(jullytta): conferir se tratamos de vetores aqui,
  // ou de strings.
  // TODO(jullytta): mensagem de erro imprime o operador em C,
  // nao em realness. Logo, eh uma mensagem de erro ruim -
  // o usuario teria de saber C para entende-la.
  if(tipo_resultado == "")
    erro("Operacao nao permitida. "
       + traduz_interno_para_realness(tipo1)
       + " " + opr + " "
       + traduz_interno_para_realness(tipo3));

  ss.valor = gera_nome_var_temp(tipo_resultado);
  ss.tipo = Tipo(tipo_resultado);

  ss.codigo = s1.codigo + s3.codigo;

  // Strings
  // TODO(jullytta): comparacao de strings, concatenar string
  // com int, char e double.
  if(tipo_resultado == "s" && opr == "+"){
    ss.codigo += "  strncpy(" + ss.valor + ", " + s1.valor + ", "
              + toString(MAX_STRING_SIZE) + ");\n"
              + "  strncat(" + ss.valor + ", " + s3.valor + ", "
              + toString(MAX_STRING_SIZE) + ");\n";
  }
  // Tipo basico
  else {
    ss.codigo += "  " + ss.valor + " = "
              + s1.valor + " " + opr + " " + s3.valor
              + ";\n";
  }
  return ss;
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
         "  goto " + label_end + ";\n" +
         label_else + ":;\n" +
         cmd_else +
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
