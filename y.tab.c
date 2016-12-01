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


#line 151 "y.tab.c" /* yacc.c:339  */

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
    TK_ID = 258,
    TK_CINT = 259,
    TK_CDOUBLE = 260,
    TK_VAR = 261,
    TK_PROGRAM = 262,
    TK_BEGIN = 263,
    TK_END = 264,
    TK_ATRIB = 265,
    TK_WRITELN = 266,
    TK_CSTRING = 267,
    TK_MAIG = 268,
    TK_MEIG = 269,
    TK_DIF = 270,
    TK_IF = 271,
    TK_THEN = 272,
    TK_ELSE = 273,
    TK_AND = 274,
    TK_FOR = 275,
    TK_TO = 276,
    TK_DO = 277,
    TK_ARRAY = 278,
    TK_OF = 279,
    TK_PTPT = 280,
    TK_ABRIR1 = 281,
    TK_FECHAR = 282
  };
#endif
/* Tokens.  */
#define TK_ID 258
#define TK_CINT 259
#define TK_CDOUBLE 260
#define TK_VAR 261
#define TK_PROGRAM 262
#define TK_BEGIN 263
#define TK_END 264
#define TK_ATRIB 265
#define TK_WRITELN 266
#define TK_CSTRING 267
#define TK_MAIG 268
#define TK_MEIG 269
#define TK_DIF 270
#define TK_IF 271
#define TK_THEN 272
#define TK_ELSE 273
#define TK_AND 274
#define TK_FOR 275
#define TK_TO 276
#define TK_DO 277
#define TK_ARRAY 278
#define TK_OF 279
#define TK_PTPT 280
#define TK_ABRIR1 281
#define TK_FECHAR 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 253 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   252

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  111

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

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
      41,    42,    33,    31,    39,    32,    40,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,    35,
      28,    30,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,   107,   111,   115,   119,   122,   125,   129,
     132,   135,   147,   163,   166,   171,   175,   175,   181,   183,
     186,   187,   188,   189,   190,   193,   215,   217,   222,   229,
     234,   241,   243,   245,   247,   249,   251,   253,   255,   257,
     259,   261,   263,   265,   268,   269,   271,   273,   275,   284
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_ID", "TK_CINT", "TK_CDOUBLE",
  "TK_VAR", "TK_PROGRAM", "TK_BEGIN", "TK_END", "TK_ATRIB", "TK_WRITELN",
  "TK_CSTRING", "TK_MAIG", "TK_MEIG", "TK_DIF", "TK_IF", "TK_THEN",
  "TK_ELSE", "TK_AND", "TK_FOR", "TK_TO", "TK_DO", "TK_ARRAY", "TK_OF",
  "TK_PTPT", "TK_ABRIR1", "TK_FECHAR", "'<'", "'>'", "'='", "'+'", "'-'",
  "'*'", "'/'", "';'", "':'", "'['", "']'", "','", "'.'", "'('", "')'",
  "$accept", "S", "ABRIR1", "FECHAR", "PROGRAM", "DECLS", "DECL", "VARS",
  "VAR", "IDS", "MAIN", "BLOCO", "$@1", "CMDS", "CMD", "CMD_FOR", "CMD_IF",
  "WRITELN", "ATRIB", "E", "F", "NOME_VAR", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    60,    62,
      61,    43,    45,    42,    47,    59,    58,    91,    93,    44,
      46,    40,    41
};
# endif

#define YYPACT_NINF -67

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-67)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -20,   -22,    14,     9,   -67,   -67,    15,    17,   -11,    31,
      28,    17,   -67,     2,   -24,   -67,   -67,     0,   -67,    13,
       7,   -67,    17,    18,    45,   232,    20,   -67,   -67,   -67,
      16,   -67,     1,    32,     5,    74,   -67,    69,    46,   -67,
     -67,   -67,   -67,   -67,    78,     5,     5,     5,    47,   -67,
     -67,   -67,     5,   105,   -67,   -67,   -67,    73,   -67,   232,
      60,   171,    61,    30,     5,    37,     5,     5,     5,   232,
       5,     5,     5,     5,     5,     5,     5,     5,     5,   -67,
      82,    77,   -67,    83,   -67,   178,   178,   178,    70,   200,
     178,   178,   178,   -29,   -29,   -67,   -67,   127,    62,     5,
     -67,   232,     5,    79,   171,   -67,   149,    98,   232,   -67,
     -67
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     1,     0,     7,     0,    14,
       0,     7,     8,     0,     0,     5,    14,    11,    16,     0,
       0,     6,    10,     0,     0,    19,     0,     2,    15,     9,
       0,    13,     0,     0,     0,     0,    23,     0,     0,    24,
      22,    20,    21,     4,     0,     0,     0,     0,    49,    45,
      46,    47,     0,     0,    43,    44,    49,     0,    17,    19,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,    28,     0,    42,    38,    37,    40,    26,    41,
      35,    36,    39,    31,    32,    33,    34,     0,     0,     0,
      48,     0,     0,     0,    30,    27,     0,     0,     0,    12,
      25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,   -67,   -67,   -67,    93,   -67,    84,   -67,    96,
     -67,    97,   -67,    49,   -66,   -67,   -67,   -67,   -67,   -45,
     -67,    75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    27,     7,    10,    11,    12,    13,    14,
      19,    36,    25,    37,    38,    39,    40,    41,    42,    53,
      54,    55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      61,    62,    63,    88,    76,    77,     1,    65,    48,    49,
      50,    45,    23,     4,     5,    24,     6,    51,     8,    83,
       9,    85,    86,    87,    15,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    16,   105,    18,    22,    46,    24,
      26,    30,   110,    66,    67,    68,    52,    28,    31,    70,
      66,    67,    68,    44,   104,    43,    70,   106,    71,    72,
      73,    74,    75,    76,    77,    71,    72,    73,    74,    75,
      76,    77,    82,    47,    66,    67,    68,    56,    58,    84,
      70,    59,    60,    78,    64,    80,    98,    99,   101,    71,
      72,    73,    74,    75,    76,    77,    66,    67,    68,    81,
     103,   109,    70,   107,    21,    17,    29,    20,    79,     0,
      57,    71,    72,    73,    74,    75,    76,    77,    66,    67,
      68,   100,    69,     0,    70,     0,     0,     0,     0,     0,
       0,     0,     0,    71,    72,    73,    74,    75,    76,    77,
      66,    67,    68,     0,     0,     0,    70,     0,   102,     0,
       0,     0,     0,     0,     0,    71,    72,    73,    74,    75,
      76,    77,    66,    67,    68,     0,     0,     0,    70,     0,
       0,   108,     0,     0,     0,     0,     0,    71,    72,    73,
      74,    75,    76,    77,    66,    67,    68,     0,     0,     0,
      70,    -1,    -1,    -1,     0,     0,     0,     0,     0,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    74,
      75,    76,    77,    66,    67,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    71,    72,
      73,    74,    75,    76,    77,    32,     0,     0,     0,     0,
      18,     0,     0,    33,     0,     0,     0,     0,    34,     0,
       0,     0,    35
};

static const yytype_int8 yycheck[] =
{
      45,    46,    47,    69,    33,    34,    26,    52,     3,     4,
       5,    10,    36,    35,     0,    39,     7,    12,     3,    64,
       3,    66,    67,    68,    35,    70,    71,    72,    73,    74,
      75,    76,    77,    78,     3,   101,     8,    35,    37,    39,
      27,    23,   108,    13,    14,    15,    41,    40,     3,    19,
      13,    14,    15,    37,    99,    35,    19,   102,    28,    29,
      30,    31,    32,    33,    34,    28,    29,    30,    31,    32,
      33,    34,    42,    41,    13,    14,    15,     3,     9,    42,
      19,    35,     4,    10,    37,    25,     4,    10,    18,    28,
      29,    30,    31,    32,    33,    34,    13,    14,    15,    38,
      38,     3,    19,    24,    11,     9,    22,    10,    59,    -1,
      35,    28,    29,    30,    31,    32,    33,    34,    13,    14,
      15,    38,    17,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      13,    14,    15,    -1,    -1,    -1,    19,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    13,    14,    15,    -1,    -1,    -1,    19,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    13,    14,    15,    -1,    -1,    -1,
      19,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    28,    29,    30,    31,
      32,    33,    34,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    34,     3,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    11,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    44,    45,    35,     0,     7,    47,     3,     3,
      48,    49,    50,    51,    52,    35,     3,    52,     8,    53,
      54,    48,    35,    36,    39,    55,    27,    46,    40,    50,
      23,     3,     3,    11,    16,    20,    54,    56,    57,    58,
      59,    60,    61,    35,    37,    10,    37,    41,     3,     4,
       5,    12,    41,    62,    63,    64,     3,    64,     9,    35,
       4,    62,    62,    62,    37,    62,    13,    14,    15,    17,
      19,    28,    29,    30,    31,    32,    33,    34,    10,    56,
      25,    38,    42,    62,    42,    62,    62,    62,    57,    62,
      62,    62,    62,    62,    62,    62,    62,    62,     4,    10,
      38,    18,    21,    38,    62,    57,    62,    24,    22,     3,
      57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    46,    47,    48,    48,    49,    50,
      50,    51,    51,    52,    52,    53,    55,    54,    56,    56,
      57,    57,    57,    57,    57,    58,    59,    59,    60,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    63,    63,    63,    63,    63,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     2,     3,     2,     0,     1,     3,
       0,     2,    10,     3,     1,     2,     0,     4,     3,     0,
       1,     1,     1,     1,     1,     8,     4,     6,     4,     3,
       6,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     4,     1
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
#line 100 "trabalho.y" /* yacc.c:1646  */
    {
      cout << includes << endl;
      cout << (yyvsp[-2]).c << endl;
      cout << (yyvsp[-1]).c << endl;
    }
#line 1435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 108 "trabalho.y" /* yacc.c:1646  */
    {(yyval).c = "";}
#line 1441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 112 "trabalho.y" /* yacc.c:1646  */
    {(yyval).c = "";}
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 116 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = ""; }
#line 1453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 120 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c + (yyvsp[0]).c; }
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 122 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = ""; }
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 126 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[0]).c; }
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 130 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c; }
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 132 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = ""; }
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 136 "trabalho.y" /* yacc.c:1646  */
    {
        Tipo tipo = Tipo( traduz_nome_tipo_pascal( (yyvsp[-1]).v ) );
        string tipo_em_c = traduz_nome_tipo_interno( tipo.tipo_base );

        (yyval) = Atributos();

        for( int i = 0; i < (yyvsp[0]).lista.size(); i ++ ) {
          (yyval).c += tipo_em_c + " " + (yyvsp[0]).lista[i] + ";\n";
          insere_ts( (yyvsp[0]).lista[i], tipo );
        }
      }
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 148 "trabalho.y" /* yacc.c:1646  */
    {
        Tipo tipo = Tipo( traduz_nome_tipo_pascal( (yyvsp[0]).v ),
                          toInt( (yyvsp[-5]).v ), toInt( (yyvsp[-3]).v ) );
        string tipo_em_c = traduz_nome_tipo_interno( tipo.tipo_base );

        (yyval) = Atributos();

        for( int i = 0; i < (yyvsp[-9]).lista.size(); i ++ ) {
          (yyval).c += tipo_em_c + " " + (yyvsp[-9]).lista[i] + "[" +
                  toString( toInt( (yyvsp[-3]).v ) - toInt( (yyvsp[-5]).v ) + 1 ) + "];\n";
          insere_ts( (yyvsp[-9]).lista[i], tipo );
        }
      }
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 164 "trabalho.y" /* yacc.c:1646  */
    { (yyval)  = (yyvsp[-2]);
        (yyval).lista.push_back( (yyvsp[0]).v ); }
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 167 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributos();
        (yyval).lista.push_back( (yyvsp[0]).v ); }
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 172 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = "int main()\n" + (yyvsp[-1]).c; }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 175 "trabalho.y" /* yacc.c:1646  */
    { var_temp.push_back( "" );}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 176 "trabalho.y" /* yacc.c:1646  */
    { string vars = var_temp[var_temp.size()-1];
          var_temp.pop_back();
          (yyval).c = "{\n" + vars + (yyvsp[-1]).c + "}\n"; }
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 182 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-2]).c + (yyvsp[0]).c; }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 183 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = ""; }
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 194 "trabalho.y" /* yacc.c:1646  */
    {
            string var_fim = gera_nome_var_temp( (yyvsp[-6]).t.tipo_base );
            string label_teste = gera_label( "teste_for" );
            string label_fim = gera_label( "fim_for" );
            string condicao = gera_nome_var_temp( "b" );

            // Falta verificar os tipos... perde ponto se não o fizer.
            (yyval).c =  (yyvsp[-4]).c + (yyvsp[-2]).c +
                    "  " + (yyvsp[-6]).v + " = " + (yyvsp[-4]).v + ";\n" +
                    "  " + var_fim + " = " + (yyvsp[-2]).v + ";\n" +
                    label_teste + ":;\n" +
                    "  " +condicao+" = "+(yyvsp[-6]).v + " > " + var_fim + ";\n" +
                    "  " + "if( " + condicao + " ) goto " + label_fim +
                    ";\n" +
                    (yyvsp[0]).c +
                    "  " + (yyvsp[-6]).v + " = " + (yyvsp[-6]).v + " + 1;\n" +
                    "  goto " + label_teste + ";\n" +
                    label_fim + ":;\n";
          }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 216 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_if( (yyvsp[-2]), (yyvsp[0]).c, "" ); }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 218 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_if( (yyvsp[-4]), (yyvsp[-2]).c, (yyvsp[0]).c ); }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 223 "trabalho.y" /* yacc.c:1646  */
    { (yyval).c = (yyvsp[-1]).c +
                   "  cout << " + (yyvsp[-1]).v + ";\n"
                   "  cout << endl;\n";
          }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 230 "trabalho.y" /* yacc.c:1646  */
    { // Falta verificar se pode atribuir.
          (yyval).c = (yyvsp[0]).c + "  " + (yyvsp[-2]).v + " = " + (yyvsp[0]).v + ";\n";
          debug( "ATRIB : TK_ID TK_ATRIB E ';'", (yyval) );
        }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 235 "trabalho.y" /* yacc.c:1646  */
    { // Falta testar: tipo, limite do array, e se a variável existe
          (yyval).c = (yyvsp[-3]).c + (yyvsp[0]).c +
                 "  " + (yyvsp[-5]).v + "[" + (yyvsp[-3]).v + "] = " + (yyvsp[0]).v + ";\n";
        }
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 242 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "+", (yyvsp[0]) ); }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 244 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "-", (yyvsp[0]) ); }
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 246 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "*", (yyvsp[0]) ); }
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 248 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "/", (yyvsp[0]) ); }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 250 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "<", (yyvsp[0]) ); }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 252 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), ">", (yyvsp[0]) ); }
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 254 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "<=", (yyvsp[0]) ); }
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 256 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), ">=", (yyvsp[0]) ); }
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 258 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "==", (yyvsp[0]) ); }
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 260 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "!=", (yyvsp[0]) ); }
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 262 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = gera_codigo_operador( (yyvsp[-2]), "&&", (yyvsp[0]) ); }
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 264 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 270 "trabalho.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v; (yyval).t = Tipo( "i" ); (yyval).c = (yyvsp[0]).c; }
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 272 "trabalho.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v; (yyval).t = Tipo( "d" ); (yyval).c = (yyvsp[0]).c; }
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 274 "trabalho.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v; (yyval).t = Tipo( "s" ); (yyval).c = (yyvsp[0]).c; }
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 276 "trabalho.y" /* yacc.c:1646  */
    { // Falta testar se é array E diminuir uma dimensão.
      (yyval).t = Tipo( consulta_ts( (yyvsp[-3]).v ).tipo_base );
      (yyval).v = gera_nome_var_temp( (yyval).t.tipo_base );
      (yyval).c = (yyvsp[-1]).c +
             "  " + (yyval).v + " = " + (yyvsp[-3]).v + "[" + (yyvsp[-1]).v + "];\n";
    }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 285 "trabalho.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v; (yyval).t = consulta_ts( (yyvsp[0]).v ); (yyval).c = (yyvsp[0]).c; }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1737 "y.tab.c" /* yacc.c:1646  */
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
#line 288 "trabalho.y" /* yacc.c:1906  */

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
