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

  // Cria variavel basica
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


#line 186 "y.tab.c" /* yacc.c:339  */

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
    TK_TRUE = 263,
    TK_FALSE = 264,
    TK_MAIN = 265,
    TK_BEGIN = 266,
    TK_END = 267,
    TK_ID = 268,
    TK_CINT = 269,
    TK_CDOUBLE = 270,
    TK_CSTRING = 271,
    TK_RETURN = 272,
    TK_ATRIB = 273,
    TK_CCHAR = 274,
    TK_WRITE = 275,
    TK_READ = 276,
    TK_G = 277,
    TK_L = 278,
    TK_GE = 279,
    TK_LE = 280,
    TK_DIFF = 281,
    TK_IF = 282,
    TK_ELSE = 283,
    TK_E = 284,
    TK_AND = 285,
    TK_OR = 286,
    TK_NOT = 287,
    TK_BREAK = 288,
    TK_IN = 289,
    TK_CMPARRAY = 290,
    TK_FOR = 291,
    TK_WHILE = 292,
    TK_DO = 293,
    TK_SWITCH = 294,
    TK_START = 295,
    TK_STOP = 296,
    TK_MOD = 297
  };
#endif
/* Tokens.  */
#define TK_INT 258
#define TK_CHAR 259
#define TK_DOUBLE 260
#define TK_STRING 261
#define TK_BOOL 262
#define TK_TRUE 263
#define TK_FALSE 264
#define TK_MAIN 265
#define TK_BEGIN 266
#define TK_END 267
#define TK_ID 268
#define TK_CINT 269
#define TK_CDOUBLE 270
#define TK_CSTRING 271
#define TK_RETURN 272
#define TK_ATRIB 273
#define TK_CCHAR 274
#define TK_WRITE 275
#define TK_READ 276
#define TK_G 277
#define TK_L 278
#define TK_GE 279
#define TK_LE 280
#define TK_DIFF 281
#define TK_IF 282
#define TK_ELSE 283
#define TK_E 284
#define TK_AND 285
#define TK_OR 286
#define TK_NOT 287
#define TK_BREAK 288
#define TK_IN 289
#define TK_CMPARRAY 290
#define TK_FOR 291
#define TK_WHILE 292
#define TK_DO 293
#define TK_SWITCH 294
#define TK_START 295
#define TK_STOP 296
#define TK_MOD 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 318 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   578

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  206

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
      48,    49,    44,    42,    50,    43,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    47,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   138,   138,   146,   150,   153,   159,   162,   163,   166,
     169,   172,   173,   176,   177,   178,   179,   182,   189,   195,
     203,   211,   219,   225,   234,   239,   242,   247,   252,   265,
     266,   267,   268,   269,   272,   272,   283,   290,   294,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   312,
     320,   329,   333,   340,   344,   345,   348,   349,   352,   353,
     356,   360,   366,   372,   381,   389,   397,   403,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   429,   435,   441,   447,
     453,   459,   475,   495,   499,   505
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_INT", "TK_CHAR", "TK_DOUBLE",
  "TK_STRING", "TK_BOOL", "TK_TRUE", "TK_FALSE", "TK_MAIN", "TK_BEGIN",
  "TK_END", "TK_ID", "TK_CINT", "TK_CDOUBLE", "TK_CSTRING", "TK_RETURN",
  "TK_ATRIB", "TK_CCHAR", "TK_WRITE", "TK_READ", "TK_G", "TK_L", "TK_GE",
  "TK_LE", "TK_DIFF", "TK_IF", "TK_ELSE", "TK_E", "TK_AND", "TK_OR",
  "TK_NOT", "TK_BREAK", "TK_IN", "TK_CMPARRAY", "TK_FOR", "TK_WHILE",
  "TK_DO", "TK_SWITCH", "TK_START", "TK_STOP", "'+'", "'-'", "'*'", "'/'",
  "TK_MOD", "';'", "'('", "')'", "','", "'['", "']'", "':'", "$accept",
  "S", "MAIN", "DECLS", "DECL", "FUNCTION", "F_PARAMS", "PARAMS", "PARAM",
  "G_VAR", "VAR", "VAR_DEFS", "ATRIB", "TIPO", "BLOCO", "$@1", "SUB_BLOCO",
  "CMDS", "CMD", "CMD_WROTEU", "CMD_READU", "CMD_RETURN", "CMD_CALL",
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
     295,   296,    43,    45,    42,    47,   297,    59,    40,    41,
      44,    91,    93,    58
};
# endif

#define YYPACT_NINF -134

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-134)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -23,   -25,    30,  -134,  -134,    97,  -134,  -134,  -134,  -134,
    -134,    22,    -5,  -134,  -134,    -4,    36,  -134,  -134,     8,
    -134,   -39,    92,  -134,    75,    38,   -13,     4,    11,    12,
      39,    42,    43,    73,    45,    47,    76,    74,    92,    59,
      61,    63,    64,  -134,  -134,  -134,    78,    71,  -134,    81,
     113,    80,     5,   120,     5,     5,     5,   123,     5,    41,
       5,    92,   100,  -134,  -134,   -11,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,    22,    75,    98,   101,  -134,  -134,
     102,  -134,  -134,  -134,  -134,     5,     5,   457,  -134,  -134,
     103,    99,   105,  -134,   116,   457,   291,   107,   319,   139,
     156,   126,   347,   162,   129,     5,   165,   167,  -134,  -134,
       5,   168,     5,    -6,   375,     5,     5,     5,     5,     5,
       5,     5,     5,   108,     5,     5,     5,     5,     5,     5,
       5,  -134,   120,   -10,  -134,  -134,    92,     5,   161,     5,
      73,  -134,     5,   457,   130,  -134,   142,   141,   146,   166,
    -134,   507,   507,   507,   507,   507,   507,   532,   482,  -134,
     457,   -19,   -19,    -6,    -6,    -6,   191,  -134,     5,     5,
     171,   457,     5,   431,  -134,   403,   151,   152,  -134,   153,
    -134,   457,   216,    92,   457,   192,  -134,   193,     5,     5,
     188,  -134,   201,   174,   172,   241,   266,     5,     5,    73,
    -134,  -134,  -134,   457,   457,  -134
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     6,     1,     4,    29,    30,    31,    32,
      33,     0,     0,     5,     8,     0,     0,    34,     3,     0,
       7,    17,    38,     2,    16,     0,     0,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,    43,    44,    45,     0,     0,    10,    12,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,    38,     0,    48,    47,    25,    20,    35,    37,    39,
      40,    41,    42,    46,     0,    16,    13,    18,    94,    95,
      86,    87,    88,    90,    89,     0,     0,    26,    85,    93,
      58,     0,    54,    57,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     9,    11,
       0,     0,     0,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,     0,    49,    50,     0,     0,     0,     0,
       0,    36,     0,    21,    25,    24,     0,     0,     0,     0,
      82,    72,    73,    74,    75,    76,    77,    78,    79,    84,
      83,    68,    69,    70,    71,    80,     0,    56,     0,     0,
      60,    64,     0,     0,    66,     0,    22,    14,    19,    91,
      59,    27,     0,     0,    63,     0,    67,     0,     0,     0,
       0,    61,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    15,    92,    28,    65,    62
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,  -134,  -134,  -134,  -134,  -134,   154,  -134,  -134,
    -134,   121,  -134,    18,   157,  -134,  -130,   -27,  -133,  -134,
    -134,  -134,  -134,  -134,  -134,    96,  -134,  -134,  -134,  -134,
    -134,  -134,   -54,   109,  -134
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    12,     5,    13,    14,    47,    48,    49,    15,
      34,    66,    35,    36,    18,    22,    62,    37,    38,    39,
      40,    41,    42,    91,    92,    93,    43,    44,   101,   193,
      45,    46,    87,    88,    89
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      94,    95,    96,   170,    98,    52,   102,   105,   168,    24,
     174,    68,    25,    78,    79,   123,   124,     1,    80,    81,
      82,    83,     3,    16,    84,   127,   128,   129,   123,   124,
       4,   113,   114,    17,   103,    53,    19,    85,    54,   106,
     107,   169,    50,    20,     6,     7,     8,     9,    10,    21,
     191,   143,    51,    86,    99,    23,   147,    55,   149,    56,
      57,   151,   152,   153,   154,   155,   156,   157,   158,   205,
     160,   161,   162,   163,   164,   165,   166,   100,     6,     7,
       8,     9,    10,   171,    61,   173,    67,    58,   175,    65,
      59,    60,    63,    50,    64,     6,     7,     8,     9,    10,
       6,     7,     8,     9,    10,    26,    69,    11,    70,    27,
      71,    72,    28,    29,   181,   182,    78,    79,   184,    30,
      74,    80,    81,    82,    83,    73,    76,    84,    31,    32,
      33,    75,    77,    90,   195,   196,    97,   104,   115,   116,
     117,   118,   119,   203,   204,   120,   121,   122,   131,   110,
     123,   124,   111,   112,   130,   132,   135,   137,   125,   126,
     127,   128,   129,   115,   116,   117,   118,   119,   133,   138,
     120,   121,   122,   139,   141,   123,   124,   142,   144,   172,
     106,   146,   148,   125,   126,   127,   128,   129,   115,   116,
     117,   118,   119,   177,   176,   120,   121,   122,   178,   183,
     123,   124,   187,   188,   189,   192,   197,   194,   125,   126,
     127,   128,   129,   115,   116,   117,   118,   119,   179,   198,
     120,   121,   122,   199,   200,   123,   124,   145,   167,   109,
       0,   108,   159,   125,   126,   127,   128,   129,   115,   116,
     117,   118,   119,   180,     0,   120,   121,   122,     0,     0,
     123,   124,     0,     0,     0,     0,     0,     0,   125,   126,
     127,   128,   129,   115,   116,   117,   118,   119,   190,     0,
     120,   121,   122,     0,     0,   123,   124,     0,     0,     0,
       0,     0,     0,   125,   126,   127,   128,   129,   115,   116,
     117,   118,   119,   201,     0,   120,   121,   122,     0,     0,
     123,   124,     0,     0,     0,     0,     0,     0,   125,   126,
     127,   128,   129,   115,   116,   117,   118,   119,   202,     0,
     120,   121,   122,     0,     0,   123,   124,     0,     0,     0,
       0,     0,     0,   125,   126,   127,   128,   129,     0,     0,
     134,   115,   116,   117,   118,   119,     0,     0,   120,   121,
     122,     0,     0,   123,   124,     0,     0,     0,     0,     0,
       0,   125,   126,   127,   128,   129,     0,     0,   136,   115,
     116,   117,   118,   119,     0,     0,   120,   121,   122,     0,
       0,   123,   124,     0,     0,     0,     0,     0,     0,   125,
     126,   127,   128,   129,     0,     0,   140,   115,   116,   117,
     118,   119,     0,     0,   120,   121,   122,     0,     0,   123,
     124,     0,     0,     0,     0,     0,     0,   125,   126,   127,
     128,   129,     0,     0,   150,   115,   116,   117,   118,   119,
       0,     0,   120,   121,   122,     0,     0,   123,   124,     0,
       0,     0,     0,     0,     0,   125,   126,   127,   128,   129,
       0,     0,   186,   115,   116,   117,   118,   119,     0,     0,
     120,   121,   122,     0,     0,   123,   124,     0,     0,     0,
       0,     0,     0,   125,   126,   127,   128,   129,   185,   115,
     116,   117,   118,   119,     0,     0,   120,   121,   122,     0,
       0,   123,   124,     0,     0,     0,     0,     0,     0,   125,
     126,   127,   128,   129,   115,   116,   117,   118,   119,     0,
       0,   120,   121,     0,     0,     0,   123,   124,     0,     0,
       0,     0,     0,     0,   125,   126,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,     0,     0,    -1,     0,     0,     0,
       0,   123,   124,     0,     0,     0,     0,     0,     0,   125,
     126,   127,   128,   129,   115,   116,   117,   118,   119,     0,
       0,   120,     0,     0,     0,     0,   123,   124,     0,     0,
       0,     0,     0,     0,   125,   126,   127,   128,   129
};

static const yytype_int16 yycheck[] =
{
      54,    55,    56,   136,    58,    18,    60,    18,    18,    48,
     140,    38,    51,     8,     9,    34,    35,    40,    13,    14,
      15,    16,    47,     5,    19,    44,    45,    46,    34,    35,
       0,    85,    86,    11,    61,    48,    41,    32,    51,    50,
      51,    51,    24,    47,     3,     4,     5,     6,     7,    13,
     183,   105,    14,    48,    13,    47,   110,    53,   112,    48,
      48,   115,   116,   117,   118,   119,   120,   121,   122,   199,
     124,   125,   126,   127,   128,   129,   130,    59,     3,     4,
       5,     6,     7,   137,    11,   139,    12,    48,   142,    13,
      48,    48,    47,    75,    47,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7,    13,    47,    10,    47,    17,
      47,    47,    20,    21,   168,   169,     8,     9,   172,    27,
      49,    13,    14,    15,    16,    47,    13,    19,    36,    37,
      38,    50,    52,    13,   188,   189,    13,    37,    22,    23,
      24,    25,    26,   197,   198,    29,    30,    31,    49,    51,
      34,    35,    51,    51,    51,    50,    49,    18,    42,    43,
      44,    45,    46,    22,    23,    24,    25,    26,    52,    13,
      29,    30,    31,    47,    12,    34,    35,    48,    13,    18,
      50,    14,    14,    42,    43,    44,    45,    46,    22,    23,
      24,    25,    26,    52,    52,    29,    30,    31,    52,    28,
      34,    35,    51,    51,    51,    13,    18,    14,    42,    43,
      44,    45,    46,    22,    23,    24,    25,    26,    52,    18,
      29,    30,    31,    49,    52,    34,    35,   106,   132,    75,
      -1,    74,   123,    42,    43,    44,    45,    46,    22,    23,
      24,    25,    26,    52,    -1,    29,    30,    31,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    22,    23,    24,    25,    26,    52,    -1,
      29,    30,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    22,    23,
      24,    25,    26,    52,    -1,    29,    30,    31,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    22,    23,    24,    25,    26,    52,    -1,
      29,    30,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    -1,    -1,
      49,    22,    23,    24,    25,    26,    -1,    -1,    29,    30,
      31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    -1,    -1,    49,    22,
      23,    24,    25,    26,    -1,    -1,    29,    30,    31,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    -1,    -1,    49,    22,    23,    24,
      25,    26,    -1,    -1,    29,    30,    31,    -1,    -1,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    -1,    -1,    49,    22,    23,    24,    25,    26,
      -1,    -1,    29,    30,    31,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      -1,    -1,    49,    22,    23,    24,    25,    26,    -1,    -1,
      29,    30,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    22,
      23,    24,    25,    26,    -1,    -1,    29,    30,    31,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    22,    23,    24,    25,    26,    -1,
      -1,    29,    30,    -1,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    22,
      23,    24,    25,    26,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    22,    23,    24,    25,    26,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    55,    47,     0,    57,     3,     4,     5,     6,
       7,    10,    56,    58,    59,    63,    67,    11,    68,    41,
      47,    13,    69,    47,    48,    51,    13,    17,    20,    21,
      27,    36,    37,    38,    64,    66,    67,    71,    72,    73,
      74,    75,    76,    80,    81,    84,    85,    60,    61,    62,
      67,    14,    18,    48,    51,    53,    48,    48,    48,    48,
      48,    11,    70,    47,    47,    13,    65,    12,    71,    47,
      47,    47,    47,    47,    49,    50,    13,    52,     8,     9,
      13,    14,    15,    16,    19,    32,    48,    86,    87,    88,
      13,    77,    78,    79,    86,    86,    86,    13,    86,    13,
      67,    82,    86,    71,    37,    18,    50,    51,    68,    61,
      51,    51,    51,    86,    86,    22,    23,    24,    25,    26,
      29,    30,    31,    34,    35,    42,    43,    44,    45,    46,
      51,    49,    50,    52,    49,    49,    49,    18,    13,    47,
      49,    12,    48,    86,    13,    65,    14,    86,    14,    86,
      49,    86,    86,    86,    86,    86,    86,    86,    86,    87,
      86,    86,    86,    86,    86,    86,    86,    79,    18,    51,
      72,    86,    18,    86,    70,    86,    52,    52,    52,    52,
      52,    86,    86,    28,    86,    47,    49,    51,    51,    51,
      52,    72,    13,    83,    14,    86,    86,    18,    18,    49,
      52,    52,    52,    86,    86,    70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    58,    58,    59,
      60,    61,    61,    62,    62,    62,    62,    63,    63,    63,
      64,    64,    64,    64,    65,    65,    66,    66,    66,    67,
      67,    67,    67,    67,    69,    68,    70,    71,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      74,    75,    75,    76,    77,    77,    78,    78,    79,    79,
      80,    80,    81,    82,    82,    83,    84,    85,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     2,     0,     2,     0,     2,     1,     6,
       1,     3,     1,     2,     5,     8,     0,     2,     5,     8,
       2,     4,     5,     8,     3,     1,     3,     6,     9,     1,
       1,     1,     1,     1,     0,     4,     3,     2,     0,     2,
       2,     2,     2,     1,     1,     1,     2,     2,     2,     4,
       4,     1,     3,     4,     1,     0,     3,     1,     1,     4,
       5,     7,     9,     4,     3,     3,     5,     6,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     4,     7,     1,     1,     1
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
#line 139 "trabalho.y" /* yacc.c:1646  */
    {
      cout << includes << endl;
      cout << (yyvsp[-3]).codigo << endl;
      cout << (yyvsp[-2]).codigo << endl;
    }
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 147 "trabalho.y" /* yacc.c:1646  */
    {
          (yyval).codigo += "int main()" + (yyvsp[0]).codigo;
        }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 154 "trabalho.y" /* yacc.c:1646  */
    { (yyval).codigo += global_vars[global_vars.size()-1];
          global_vars.pop_back();
          (yyval).codigo += (yyvsp[0]).codigo;
         }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 159 "trabalho.y" /* yacc.c:1646  */
    { global_vars.push_back(""); }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 183 "trabalho.y" /* yacc.c:1646  */
    {
          (yyval) = Atributos((yyvsp[0]).valor, (yyvsp[-1]).type);
          global_vars.push_back("");
          global_vars[global_vars.size()-1]+= decl_var((yyvsp[0]).valor, (yyvsp[-1]).type) + ";\n";
          insert_var_ts((yyvsp[0]).valor, (yyvsp[-1]).type);
        }
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 190 "trabalho.y" /* yacc.c:1646  */
    {
          (yyval) = Atributos((yyvsp[-3]).valor, Type((yyvsp[-4]).type.base_type, toInt((yyvsp[-1]).valor)));
          global_vars[global_vars.size()-1] += decl_var((yyval).valor, (yyval).type) + ";\n";
          insert_var_ts((yyval).valor, (yyval).type);
        }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 196 "trabalho.y" /* yacc.c:1646  */
    {
          (yyval) = Atributos((yyvsp[-6]).valor, Type((yyvsp[-7]).type.base_type, toInt((yyvsp[-4]).valor), toInt((yyvsp[-1]).valor)));
          global_vars[global_vars.size()-1] += "  " + decl_var((yyval).valor, (yyval).type) + ";\n";
          insert_var_ts((yyval).valor, (yyval).type);
        }
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 204 "trabalho.y" /* yacc.c:1646  */
    {
        (yyval).codigo = "";
        for(vector<string>::iterator it = (yyvsp[0]).lista_str.begin(); it != (yyvsp[0]).lista_str.end(); it++){
          block_vars[block_vars.size()-1] += "  " + (decl_var(*it, (yyvsp[-1]).type)) + ";\n";
          insert_var_ts(*it, (yyvsp[-1]).type);
        }
      }
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 212 "trabalho.y" /* yacc.c:1646  */
    {
        (yyval) = Atributos((yyvsp[-2]).valor, (yyvsp[-3]).type);
        block_vars[block_vars.size()-1] += "  " + decl_var((yyvsp[-2]).valor, (yyvsp[-3]).type) + ";\n";
        insert_var_ts((yyvsp[-2]).valor, (yyvsp[-3]).type);
        (yyvsp[-2]).type = (yyvsp[-3]).type;
        (yyval).codigo = atribui_var((yyvsp[-2]), (yyvsp[0]));
      }
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 220 "trabalho.y" /* yacc.c:1646  */
    {
        (yyval) = Atributos((yyvsp[-3]).valor, Type((yyvsp[-4]).type.base_type, toInt((yyvsp[-1]).valor)));
        block_vars[block_vars.size()-1] += "  " + decl_var((yyval).valor, (yyval).type) + ";\n";
        insert_var_ts((yyval).valor, (yyval).type);
      }
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 226 "trabalho.y" /* yacc.c:1646  */
    {
        (yyval) = Atributos((yyvsp[-6]).valor, Type((yyvsp[-7]).type.base_type, toInt((yyvsp[-4]).valor), toInt((yyvsp[-1]).valor)));
        block_vars[block_vars.size()-1] += "  " + decl_var((yyval).valor, (yyval).type) + ";\n";
        insert_var_ts((yyval).valor, (yyval).type);
      }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 235 "trabalho.y" /* yacc.c:1646  */
    {
              (yyval).lista_str.push_back((yyvsp[-2]).valor);
              (yyval).lista_str.insert((yyval).lista_str.end(), (yyvsp[0]).lista_str.begin(), (yyvsp[0]).lista_str.end());
            }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 239 "trabalho.y" /* yacc.c:1646  */
    { (yyvsp[0]).lista_str.push_back((yyvsp[0]).valor); }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 243 "trabalho.y" /* yacc.c:1646  */
    {
          (yyvsp[-2]).type = check_ts((yyvsp[-2]).valor);
          (yyval).codigo = atribui_var((yyvsp[-2]), (yyvsp[0]));
        }
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 248 "trabalho.y" /* yacc.c:1646  */
    {
          (yyvsp[-5]).type = check_ts((yyvsp[-5]).valor);
          (yyval).codigo = atribuicao_array((yyvsp[-5]),(yyvsp[-3]),(yyvsp[0]));
        }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 253 "trabalho.y" /* yacc.c:1646  */
    {
          // Chama o teste de limites antes de mais nada.
          string limites_matriz = matrix_limit_test_generator((yyvsp[-8]), (yyvsp[-6]), (yyvsp[-3]));
          string id_temp = vartmp_name_generator("i");

          Type t_matriz = check_ts((yyvsp[-8]).valor);
          (yyval).codigo = (yyvsp[-6]).codigo + (yyvsp[-3]).codigo + (yyvsp[0]).codigo + "  " + id_temp + " = " + (yyvsp[-6]).valor + "*"
                    + toString(t_matriz.tam[1]) + ";\n" + "  " + id_temp + " = " + id_temp + " + " + (yyvsp[-3]).valor + ";\n"
                    + limites_matriz + "  " + (yyvsp[-8]).valor + "[" + id_temp + "] = " + (yyvsp[0]).valor + ";\n";
        }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 265 "trabalho.y" /* yacc.c:1646  */
    { Type t("i"); (yyval) = Atributos("int", t);    }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 266 "trabalho.y" /* yacc.c:1646  */
    { Type t("c"); (yyval) = Atributos("char", t);   }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 267 "trabalho.y" /* yacc.c:1646  */
    { Type t("d"); (yyval) = Atributos("double", t); }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 268 "trabalho.y" /* yacc.c:1646  */
    { Type t("s"); (yyval) = Atributos("char[]", t); }
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 269 "trabalho.y" /* yacc.c:1646  */
    { Type t("b"); (yyval) = Atributos("int", t);    }
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 272 "trabalho.y" /* yacc.c:1646  */
    { block_vars.push_back(""); }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 273 "trabalho.y" /* yacc.c:1646  */
    {
          (yyval).codigo = "{\n";
          // Adiciona as variaveis desse bloco ao inicio do mesmo e
          // desempilha a lista de variaveis desse bloco.
          (yyval).codigo += block_vars[block_vars.size()-1];
          block_vars.pop_back();
          (yyval).codigo += (yyvsp[-1]).codigo + "}\n";
        }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 284 "trabalho.y" /* yacc.c:1646  */
    {
              (yyval).codigo = "{\n";
              (yyval).codigo += (yyvsp[-1]).codigo + "}\n";
            }
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 291 "trabalho.y" /* yacc.c:1646  */
    {
          (yyval).codigo = (yyvsp[-1]).codigo + (yyvsp[0]).codigo;
        }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 294 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributos(); }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 306 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 313 "trabalho.y" /* yacc.c:1646  */
    {
               (yyval).codigo = (yyvsp[-1]).codigo +
                     "  cout << " + (yyvsp[-1]).valor + ";\n"
                     "  cout << endl;\n";
             }
#line 1848 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 321 "trabalho.y" /* yacc.c:1646  */
    {
                 (yyvsp[-1]).type = check_ts((yyvsp[-1]).valor);
                 (yyval).codigo = std_reading((yyvsp[-1]));
               }
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 330 "trabalho.y" /* yacc.c:1646  */
    {
               (yyval).codigo = (yyvsp[0]).codigo + "  return 0;\n";
             }
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 334 "trabalho.y" /* yacc.c:1646  */
    {
               (yyval).codigo = (yyvsp[-2]).codigo + (yyvsp[0]).codigo + "  return "+ (yyvsp[0]).valor +";\n";
             }
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 357 "trabalho.y" /* yacc.c:1646  */
    {
           (yyval) = if_code_generator((yyvsp[-2]), (yyvsp[0]).codigo, "");
         }
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 361 "trabalho.y" /* yacc.c:1646  */
    {
           (yyval) = if_code_generator((yyvsp[-4]), (yyvsp[-2]).codigo, (yyvsp[0]).codigo);
         }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 367 "trabalho.y" /* yacc.c:1646  */
    {
            (yyval) = for_code_generator((yyvsp[-6]), (yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]));
          }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 373 "trabalho.y" /* yacc.c:1646  */
    {
               (yyval) = Atributos((yyvsp[-2]).valor, (yyvsp[-3]).type);
               block_vars[block_vars.size()-1] += "  " + decl_var((yyvsp[-2]).valor, (yyvsp[-3]).type) + ";\n";
               insert_var_ts((yyvsp[-2]).valor, (yyvsp[-3]).type);
               (yyvsp[-2]).type = (yyvsp[-3]).type;
               (yyval).codigo = atribui_var((yyvsp[-2]), (yyvsp[0]));
             }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 382 "trabalho.y" /* yacc.c:1646  */
    {
                (yyval) = Atributos((yyvsp[-2]).valor, check_ts((yyvsp[-2]).valor));
                (yyval).codigo = atribui_var((yyvsp[-2]), (yyvsp[0]));
              }
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 390 "trabalho.y" /* yacc.c:1646  */
    {
              (yyval).codigo = (yyvsp[0]).codigo + "\n" + "  "
                        + (yyvsp[-2]).valor + " = " + (yyvsp[0]).valor + ";\n";
            }
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 398 "trabalho.y" /* yacc.c:1646  */
    {
              (yyval) = while_code_generator((yyvsp[-2]), (yyvsp[0]));
            }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 404 "trabalho.y" /* yacc.c:1646  */
    {
                (yyval) = do_while_code_generator((yyvsp[-4]), (yyvsp[-1]));
              }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 409 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "+", (yyvsp[0]));    }
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 410 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "-", (yyvsp[0]));    }
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 411 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "*", (yyvsp[0]));    }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 412 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "/", (yyvsp[0]));    }
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 413 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), ">", (yyvsp[0]));    }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 414 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "<", (yyvsp[0]));    }
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 415 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), ">=", (yyvsp[0]));   }
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 416 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "<=", (yyvsp[0]));   }
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 417 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "!=", (yyvsp[0]));   }
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 418 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "==", (yyvsp[0]));   }
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 419 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "&&", (yyvsp[0]));   }
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 420 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "||", (yyvsp[0]));   }
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 421 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "%", (yyvsp[0]));    }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 422 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = un_opr_code_generator("!", (yyvsp[0])); }
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 423 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]);                                   }
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 424 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]),"@",(yyvsp[0]));  }
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 425 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = in_opr_code_generator((yyvsp[-2]), "in", (yyvsp[0]));}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 430 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval).valor = (yyvsp[0]).valor;
      (yyval).type = check_ts((yyvsp[0]).valor);
      (yyval).codigo = (yyvsp[0]).codigo;
    }
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 436 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval).valor = (yyvsp[0]).valor;
      (yyval).type = Type("i");
      (yyval).codigo = (yyvsp[0]).codigo;
    }
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 442 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval).valor = (yyvsp[0]).valor;
      (yyval).type = Type("d");
      (yyval).codigo = (yyvsp[0]).codigo;
    }
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 448 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval).valor = (yyvsp[0]).valor;
      (yyval).type = Type("c");
      (yyval).codigo = (yyvsp[0]).codigo;
    }
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 454 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval).valor = (yyvsp[0]).valor;
      (yyval).type = Type("s");
      (yyval).codigo = (yyvsp[0]).codigo;
    }
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 460 "trabalho.y" /* yacc.c:1646  */
    {
      Type tipoArray = check_ts( (yyvsp[-3]).valor );
      (yyval).type = Type( tipoArray.base_type );
      if( tipoArray.ndim != 1 )
        erro( "Variável " + (yyvsp[-3]).valor + " não é array de uma dimensão" );

      if( (yyvsp[-1]).type.ndim != 0 || (yyvsp[-1]).type.base_type != "i" )
        erro( "Indice de array deve ser integer de zero dimensão: " +
              (yyvsp[-1]).type.base_type + "/" + toString( (yyvsp[-1]).type.ndim ) );

      (yyval).valor = vartmp_name_generator( (yyval).type.base_type );
      (yyval).codigo = (yyvsp[-1]).codigo +
             array_limit_test_generator( (yyvsp[-1]).valor, tipoArray ) +
             "  " + (yyval).valor + " = " + (yyvsp[-3]).valor + "[" + (yyvsp[-1]).valor + "];\n";
    }
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 476 "trabalho.y" /* yacc.c:1646  */
    {
      // Chama o teste de limites antes de mais nada.
      string limites_matriz = matrix_limit_test_generator((yyvsp[-6]), (yyvsp[-4]), (yyvsp[-1]));
      string id_temp = vartmp_name_generator("i");

      Type t_matriz = check_ts((yyvsp[-6]).valor);

      (yyval).type = Type(t_matriz.base_type);
      (yyval).valor = vartmp_name_generator((yyval).type.base_type);


      (yyval).codigo = (yyvsp[-4]).codigo + (yyvsp[-1]).codigo + limites_matriz
                + "  " + id_temp + " = " + (yyvsp[-4]).valor + "*"
                + toString(t_matriz.tam[1]) + ";\n"
                + "  " + id_temp + " = "
                + id_temp + " + " + (yyvsp[-1]).valor + ";\n"
                + "  " + (yyval).valor + " = " + (yyvsp[-6]).valor
                + "[" + id_temp + "];\n";
    }
#line 2139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 500 "trabalho.y" /* yacc.c:1646  */
    {
        (yyval).valor = "1";
        (yyval).type = Type("b");
        (yyval).codigo = (yyvsp[0]).codigo;
      }
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 506 "trabalho.y" /* yacc.c:1646  */
    {
        (yyval).valor = "0";
        (yyval).type = Type("b");
        (yyval).codigo = (yyvsp[0]).codigo;
      }
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2163 "y.tab.c" /* yacc.c:1646  */
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
#line 513 "trabalho.y" /* yacc.c:1906  */


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
  erro("Bug no compilador! Type interno inexistente: " + interno);
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
  if(interno == "v")
    return "void";
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

  // Verifica o type dos indices
  if(indice1.type.base_type != "i" || indice2.type.base_type != "i" ||
     indice1.type.ndim != 0 || indice2.type.ndim != 0)
    erro("Indice de arrei deve ser intero.");

  // Verifica se a variavel e' mesmo um array de dimensao 2
  if(t_matriz.ndim != 2)
    erro("Variavel " + id.valor + " nao e' arrei de dimensao dois.");

  return "";
}

string atribui_var(Atributos s1, Atributos s3){
  if (is_atribuivel(s1, s3) == 1){
    if (s1.type.base_type == "s"){
       return s3.codigo + "  strncpy("+ s1.valor + ", " + s3.valor +", "
                        + toString(MAX_STRING_SIZE) + ");\n";
    } else if (s1.type.base_type == "b" && s3.type.base_type == "i") {
      string val = (s3.valor == "0" ? "0" : "1"); //lida com b=i
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
      return pos.codigo + s3.codigo +
             "  " + s1.valor + "[" + pos.valor + "] = " + s3.valor + ";\n";
  }
  else{
    erro("Atribuicao nao permitida!");
  }
}



string std_reading(Atributos s3){
  string codigo;
  string indice_pula_linha = vartmp_name_generator("i");
  if (s3.type.base_type == "s"){
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
    erro("Operacao nao permitida. "
       + translate_intern_realness(tipo1)
       + " " + opr + " "
       + translate_intern_realness(tipo3));

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

  // Type basico
  else {
    ss.codigo += "  " + ss.valor + " = "
              + s1.valor + " " + opr + " " + s3.valor
              + ";\n";
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

      ss.codigo += var.codigo + array.codigo
                    + "  " + array_temp + " = " + array_valor + ";\n"
                    + "  " + var_temp + " = " + var.valor
                    + " == " + array_temp + ";\n"
                    + "  " + var_temp + " = !" + var_temp + ";\n"
                    + "  if ("+ var_temp +") goto " + label_not_in + ";\n"
                    + "    " + res + " = 1;\n"
                    + "  goto " + label_in + ";\n"
                    + label_not_in + ":;\n\n"
                    ;
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
    erro("Operacao nao permitida. "
       + opr + translate_intern_realness(tipo2));

  ss.valor = vartmp_name_generator(tipo_resultado);
  ss.type = Type(tipo_resultado);

  ss.codigo = s2.codigo + "  "
            + ss.valor + " = "
            + opr + s2.valor
            + ";\n";

  return ss;
}

Atributos if_code_generator(Atributos expr, string cmd_then, string cmd_else){

  Atributos ss;
  string label_else = label_generator( "else" );
  string label_end = label_generator( "end" );
//string condicao_var = vartmp_name_generator(expr.type.base_type);

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

Atributos while_code_generator(Atributos expr, Atributos bloco){
  Atributos ss;
  string label_teste = label_generator( "teste_while" );
  string label_end = label_generator( "fim_while" );
  // o zizi coloca "b" ao inves de base_type, mas acho base_type melhor pra verificar erros
  string condicao_var = vartmp_name_generator(expr.type.base_type);

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

Atributos do_while_code_generator(Atributos bloco, Atributos expr){
  Atributos ss;
  string label_teste = label_generator( "teste_dowhile" );
  string label_end = label_generator( "fim_dowhile" );
  // o zizi coloca "b" ao inves de base_type, mas acho base_type melhor pra verificar erros
  string condicao_var = vartmp_name_generator(expr.type.base_type);
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

Atributos for_code_generator(Atributos atrib, Atributos condicao, Atributos pulo, Atributos bloco){
  Atributos ss;
  string var_fim = vartmp_name_generator( atrib.type.base_type );
  string label_teste = label_generator( "teste_for" );
  string label_end = label_generator( "fim_for" );
  string condicao_var = vartmp_name_generator(condicao.type.base_type);

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
  initializing_oprs();
  yyparse();
}
