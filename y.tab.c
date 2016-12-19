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
#define YYLAST   499

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

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
      51,    52,    44,    42,    50,    43,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    47,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
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
       0,   138,   138,   146,   147,   150,   156,   159,   162,   169,
     175,   183,   191,   199,   205,   214,   219,   222,   227,   232,
     244,   245,   246,   247,   248,   251,   251,   260,   267,   271,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   286,
     294,   301,   305,   311,   315,   321,   327,   336,   344,   352,
     358,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   384,
     390,   396,   402,   408,   414,   430,   449,   453,   459
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
  "TK_MOD", "';'", "'['", "']'", "','", "'('", "')'", "':'", "$accept",
  "S", "MAIN", "DECLS", "DECL", "G_VAR", "VAR", "VAR_DEFS", "ATRIB",
  "TIPO", "BLOCO", "$@1", "SUB_BLOCO", "CMDS", "CMD", "CMD_WROTEU",
  "CMD_READU", "CMD_RETURN", "CMD_IF", "CMD_FOR", "BEGIN_FOR", "CONT_FOR",
  "CMD_WHILE", "CMD_DOWHILE", "E", "F", "BOOL", YY_NULLPTR
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
     295,   296,    43,    45,    42,    47,   297,    59,    91,    93,
      44,    40,    41,    58
};
# endif

#define YYPACT_NINF -106

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-106)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -33,   -38,    11,  -106,  -106,   489,  -106,  -106,  -106,  -106,
    -106,     3,   -22,  -106,   -16,    12,  -106,  -106,   -15,  -106,
     -18,    72,  -106,    19,   -10,   -19,    -9,    -7,    -6,    -5,
      -3,    25,    20,    21,    28,    58,    72,    33,    34,    39,
    -106,  -106,  -106,    40,    41,     7,     7,     7,     7,    75,
       7,    99,     7,    72,    54,  -106,  -106,   -13,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,    46,  -106,  -106,    47,  -106,
    -106,  -106,  -106,     7,     7,   358,  -106,  -106,   220,   358,
      95,    44,   120,    82,    94,    64,   145,   101,    63,     7,
     102,   114,   117,     7,   -17,   170,     7,     7,     7,     7,
       7,     7,     7,     7,   472,     7,     7,     7,     7,     7,
       7,    -8,  -106,  -106,    72,     7,   110,     7,    25,  -106,
       7,   358,    83,    84,  -106,    86,   248,  -106,   408,   408,
     408,   408,   408,   408,   433,   383,  -106,   358,    38,    38,
     -17,   -17,   -17,     7,     7,   105,   358,     7,   332,  -106,
     195,    88,  -106,   100,   358,   276,    72,   358,   139,  -106,
     142,     7,   135,  -106,   140,   107,   108,   304,     7,     7,
      25,  -106,  -106,   358,   358,  -106
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     6,     1,     4,    20,    21,    22,    23,
      24,     0,     0,     5,     0,     0,    25,     3,     0,     7,
       8,    29,     2,     0,     0,    41,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,     0,     0,
      33,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,    38,    37,    16,    11,    26,
      28,    30,    31,    32,    36,     9,    77,    78,    69,    70,
      71,    73,    72,     0,     0,    17,    68,    76,     0,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    40,     0,     0,     0,     0,     0,    27,
       0,    12,     0,    16,    15,     0,     0,    65,    55,    56,
      57,    58,    59,    60,    61,    62,    67,    66,    51,    52,
      53,    54,    63,     0,     0,    43,    47,     0,     0,    49,
       0,    13,    10,    74,    18,     0,     0,    46,     0,    50,
       0,     0,     0,    44,     0,     0,     0,     0,     0,     0,
       0,    14,    75,    19,    48,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -106,  -106,  -106,  -106,  -106,  -106,  -106,    69,  -106,    -2,
    -106,  -106,  -105,   -24,   -90,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,   -46,    57,  -106
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    12,     5,    13,    14,    32,    58,    33,    34,
      17,    21,    54,    35,    36,    37,    38,    39,    40,    41,
      85,   165,    42,    43,    75,    76,    77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,    79,    80,    15,    82,    89,    86,     1,    45,     3,
     143,     4,    60,   149,    16,    66,    67,   104,   105,    18,
      68,    69,    70,    71,   145,    20,    72,    94,    95,    87,
      23,    19,    22,    44,    47,    90,    53,    91,    46,    73,
     144,    57,    48,   121,    49,    50,    51,   126,    52,    84,
     128,   129,   130,   131,   132,   133,   134,   135,    74,   137,
     138,   139,   140,   141,   142,   175,   163,    55,    56,   146,
      59,   148,   104,   105,   150,     6,     7,     8,     9,    10,
      61,    62,   108,   109,   110,    24,    63,    64,    81,    25,
      65,    88,    26,    27,    92,    93,   113,   154,   155,    28,
     115,   157,     6,     7,     8,     9,    10,   116,    29,    30,
      31,   117,    83,   119,   120,   167,   122,    96,    97,    98,
      99,   100,   173,   174,   101,   102,   103,   123,   147,   104,
     105,   125,   151,   156,    91,   152,   160,   106,   107,   108,
     109,   110,    96,    97,    98,    99,   100,   112,   161,   101,
     102,   103,   164,   168,   104,   105,   166,   171,   169,   170,
     124,   136,   106,   107,   108,   109,   110,    96,    97,    98,
      99,   100,   114,     0,   101,   102,   103,     0,     0,   104,
     105,     0,     0,     0,     0,     0,     0,   106,   107,   108,
     109,   110,    96,    97,    98,    99,   100,   118,     0,   101,
     102,   103,     0,     0,   104,   105,     0,     0,     0,     0,
       0,     0,   106,   107,   108,   109,   110,    96,    97,    98,
      99,   100,   127,     0,   101,   102,   103,     0,     0,   104,
     105,     0,     0,     0,     0,     0,     0,   106,   107,   108,
     109,   110,    96,    97,    98,    99,   100,   159,     0,   101,
     102,   103,     0,     0,   104,   105,     0,     0,     0,     0,
       0,     0,   106,   107,   108,   109,   110,     0,     0,   111,
      96,    97,    98,    99,   100,     0,     0,   101,   102,   103,
       0,     0,   104,   105,     0,     0,     0,     0,     0,     0,
     106,   107,   108,   109,   110,     0,     0,   153,    96,    97,
      98,    99,   100,     0,     0,   101,   102,   103,     0,     0,
     104,   105,     0,     0,     0,     0,     0,     0,   106,   107,
     108,   109,   110,     0,     0,   162,    96,    97,    98,    99,
     100,     0,     0,   101,   102,   103,     0,     0,   104,   105,
       0,     0,     0,     0,     0,     0,   106,   107,   108,   109,
     110,     0,     0,   172,    96,    97,    98,    99,   100,     0,
       0,   101,   102,   103,     0,     0,   104,   105,     0,     0,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   158,
      96,    97,    98,    99,   100,     0,     0,   101,   102,   103,
       0,     0,   104,   105,     0,     0,     0,     0,     0,     0,
     106,   107,   108,   109,   110,    96,    97,    98,    99,   100,
       0,     0,   101,   102,     0,     0,     0,   104,   105,     0,
       0,     0,     0,     0,     0,   106,   107,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,     0,     0,    -1,     0,     0,
       0,     0,   104,   105,     0,     0,     0,     0,     0,     0,
     106,   107,   108,   109,   110,    96,    97,    98,    99,   100,
       0,     0,   101,     0,     0,     0,     0,   104,   105,     0,
       0,     0,     0,     0,     0,   106,   107,   108,   109,   110,
      66,    67,     0,     0,     0,    68,    69,    70,    71,     0,
       0,    72,     6,     7,     8,     9,    10,     0,     0,    11
};

static const yytype_int16 yycheck[] =
{
      46,    47,    48,     5,    50,    18,    52,    40,    18,    47,
      18,     0,    36,   118,    11,     8,     9,    34,    35,    41,
      13,    14,    15,    16,   114,    13,    19,    73,    74,    53,
      48,    47,    47,    14,    53,    48,    11,    50,    48,    32,
      48,    13,    51,    89,    51,    51,    51,    93,    51,    51,
      96,    97,    98,    99,   100,   101,   102,   103,    51,   105,
     106,   107,   108,   109,   110,   170,   156,    47,    47,   115,
      12,   117,    34,    35,   120,     3,     4,     5,     6,     7,
      47,    47,    44,    45,    46,    13,    47,    47,    13,    17,
      49,    37,    20,    21,    48,    48,    52,   143,   144,    27,
      18,   147,     3,     4,     5,     6,     7,    13,    36,    37,
      38,    47,    13,    12,    51,   161,    14,    22,    23,    24,
      25,    26,   168,   169,    29,    30,    31,    13,    18,    34,
      35,    14,    49,    28,    50,    49,    48,    42,    43,    44,
      45,    46,    22,    23,    24,    25,    26,    52,    48,    29,
      30,    31,    13,    18,    34,    35,    14,    49,    18,    52,
      91,   104,    42,    43,    44,    45,    46,    22,    23,    24,
      25,    26,    52,    -1,    29,    30,    31,    -1,    -1,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    22,    23,    24,    25,    26,    52,    -1,    29,
      30,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    22,    23,    24,
      25,    26,    52,    -1,    29,    30,    31,    -1,    -1,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    22,    23,    24,    25,    26,    52,    -1,    29,
      30,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    -1,    -1,    49,
      22,    23,    24,    25,    26,    -1,    -1,    29,    30,    31,
      -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    -1,    -1,    49,    22,    23,
      24,    25,    26,    -1,    -1,    29,    30,    31,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    -1,    -1,    49,    22,    23,    24,    25,
      26,    -1,    -1,    29,    30,    31,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    -1,    -1,    49,    22,    23,    24,    25,    26,    -1,
      -1,    29,    30,    31,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      22,    23,    24,    25,    26,    -1,    -1,    29,    30,    31,
      -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    22,    23,    24,    25,    26,
      -1,    -1,    29,    30,    -1,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      22,    23,    24,    25,    26,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    22,    23,    24,    25,    26,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
       8,     9,    -1,    -1,    -1,    13,    14,    15,    16,    -1,
      -1,    19,     3,     4,     5,     6,     7,    -1,    -1,    10
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    55,    47,     0,    57,     3,     4,     5,     6,
       7,    10,    56,    58,    59,    63,    11,    64,    41,    47,
      13,    65,    47,    48,    13,    17,    20,    21,    27,    36,
      37,    38,    60,    62,    63,    67,    68,    69,    70,    71,
      72,    73,    76,    77,    14,    18,    48,    53,    51,    51,
      51,    51,    51,    11,    66,    47,    47,    13,    61,    12,
      67,    47,    47,    47,    47,    49,     8,     9,    13,    14,
      15,    16,    19,    32,    51,    78,    79,    80,    78,    78,
      78,    13,    78,    13,    63,    74,    78,    67,    37,    18,
      48,    50,    48,    48,    78,    78,    22,    23,    24,    25,
      26,    29,    30,    31,    34,    35,    42,    43,    44,    45,
      46,    49,    52,    52,    52,    18,    13,    47,    52,    12,
      51,    78,    14,    13,    61,    14,    78,    52,    78,    78,
      78,    78,    78,    78,    78,    78,    79,    78,    78,    78,
      78,    78,    78,    18,    48,    68,    78,    18,    78,    66,
      78,    49,    49,    49,    78,    78,    28,    78,    47,    52,
      48,    48,    49,    68,    13,    75,    14,    78,    18,    18,
      52,    49,    49,    78,    78,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    58,    59,    59,
      59,    60,    60,    60,    60,    61,    61,    62,    62,    62,
      63,    63,    63,    63,    63,    65,    64,    66,    67,    67,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    69,
      70,    71,    71,    72,    72,    73,    74,    74,    75,    76,
      77,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    79,
      79,    79,    79,    79,    79,    79,    79,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     2,     0,     2,     0,     2,     2,     5,
       8,     2,     4,     5,     8,     3,     1,     3,     6,     9,
       1,     1,     1,     1,     1,     0,     4,     3,     2,     0,
       2,     2,     2,     1,     1,     1,     2,     2,     2,     4,
       4,     1,     3,     5,     7,     9,     4,     3,     3,     5,
       6,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     4,     7,     1,     1,     1
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
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 146 "trabalho.y" /* yacc.c:1646  */
    { (yyval).codigo += "int main()" + (yyvsp[0]).codigo; }
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 151 "trabalho.y" /* yacc.c:1646  */
    { (yyval).codigo += global_vars[global_vars.size()-1];
          global_vars.pop_back();
          (yyval).codigo += (yyvsp[0]).codigo;
         }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 156 "trabalho.y" /* yacc.c:1646  */
    { global_vars.push_back(""); }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 163 "trabalho.y" /* yacc.c:1646  */
    {
          (yyval) = Atributos((yyvsp[0]).valor, (yyvsp[-1]).type);
          global_vars.push_back("");
          global_vars[global_vars.size()-1]+= decl_var((yyvsp[0]).valor, (yyvsp[-1]).type) + ";\n";
          insert_var_ts((yyvsp[0]).valor, (yyvsp[-1]).type);
        }
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 170 "trabalho.y" /* yacc.c:1646  */
    {
          (yyval) = Atributos((yyvsp[-3]).valor, Type((yyvsp[-4]).type.base_type, toInt((yyvsp[-1]).valor)));
          global_vars[global_vars.size()-1] += decl_var((yyval).valor, (yyval).type) + ";\n";
          insert_var_ts((yyval).valor, (yyval).type);
        }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 176 "trabalho.y" /* yacc.c:1646  */
    {
          (yyval) = Atributos((yyvsp[-6]).valor, Type((yyvsp[-7]).type.base_type, toInt((yyvsp[-4]).valor), toInt((yyvsp[-1]).valor)));
          global_vars[global_vars.size()-1] += "  " + decl_var((yyval).valor, (yyval).type) + ";\n";
          insert_var_ts((yyval).valor, (yyval).type);
        }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 184 "trabalho.y" /* yacc.c:1646  */
    {
        (yyval).codigo = "";
        for(vector<string>::iterator it = (yyvsp[0]).lista_str.begin(); it != (yyvsp[0]).lista_str.end(); it++){
          block_vars[block_vars.size()-1] += "  " + (decl_var(*it, (yyvsp[-1]).type)) + ";\n";
          insert_var_ts(*it, (yyvsp[-1]).type);
        }
      }
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 192 "trabalho.y" /* yacc.c:1646  */
    {
        (yyval) = Atributos((yyvsp[-2]).valor, (yyvsp[-3]).type);
        block_vars[block_vars.size()-1] += "  " + decl_var((yyvsp[-2]).valor, (yyvsp[-3]).type) + ";\n";
        insert_var_ts((yyvsp[-2]).valor, (yyvsp[-3]).type);
        (yyvsp[-2]).type = (yyvsp[-3]).type;
        (yyval).codigo = atribui_var((yyvsp[-2]), (yyvsp[0]));
      }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 200 "trabalho.y" /* yacc.c:1646  */
    {
        (yyval) = Atributos((yyvsp[-3]).valor, Type((yyvsp[-4]).type.base_type, toInt((yyvsp[-1]).valor)));
        block_vars[block_vars.size()-1] += "  " + decl_var((yyval).valor, (yyval).type) + ";\n";
        insert_var_ts((yyval).valor, (yyval).type);
      }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 206 "trabalho.y" /* yacc.c:1646  */
    {
        (yyval) = Atributos((yyvsp[-6]).valor, Type((yyvsp[-7]).type.base_type, toInt((yyvsp[-4]).valor), toInt((yyvsp[-1]).valor)));
        block_vars[block_vars.size()-1] += "  " + decl_var((yyval).valor, (yyval).type) + ";\n";
        insert_var_ts((yyval).valor, (yyval).type);
      }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 215 "trabalho.y" /* yacc.c:1646  */
    {
              (yyval).lista_str.push_back((yyvsp[-2]).valor);
              (yyval).lista_str.insert((yyval).lista_str.end(), (yyvsp[0]).lista_str.begin(), (yyvsp[0]).lista_str.end());
            }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 219 "trabalho.y" /* yacc.c:1646  */
    { (yyvsp[0]).lista_str.push_back((yyvsp[0]).valor); }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 223 "trabalho.y" /* yacc.c:1646  */
    {
          (yyvsp[-2]).type = check_ts((yyvsp[-2]).valor);
          (yyval).codigo = atribui_var((yyvsp[-2]), (yyvsp[0]));
        }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 228 "trabalho.y" /* yacc.c:1646  */
    {
          (yyvsp[-5]).type = check_ts((yyvsp[-5]).valor);
          (yyval).codigo = atribuicao_array((yyvsp[-5]),(yyvsp[-3]),(yyvsp[0]));
        }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 233 "trabalho.y" /* yacc.c:1646  */
    {
          string limites_matriz = matrix_limit_test_generator((yyvsp[-8]), (yyvsp[-6]), (yyvsp[-3]));
          string id_temp = vartmp_name_generator("i");

          Type t_matriz = check_ts((yyvsp[-8]).valor);
          (yyval).codigo = (yyvsp[-6]).codigo + (yyvsp[-3]).codigo + (yyvsp[0]).codigo + "  " + id_temp + " = " + (yyvsp[-6]).valor + "*"
                    + toString(t_matriz.tam[1]) + ";\n" + "  " + id_temp + " = " + id_temp + " + " + (yyvsp[-3]).valor + ";\n"
                    + limites_matriz + "  " + (yyvsp[-8]).valor + "[" + id_temp + "] = " + (yyvsp[0]).valor + ";\n";
        }
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 244 "trabalho.y" /* yacc.c:1646  */
    { Type t("i"); (yyval) = Atributos("int", t);    }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 245 "trabalho.y" /* yacc.c:1646  */
    { Type t("c"); (yyval) = Atributos("char", t);   }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 246 "trabalho.y" /* yacc.c:1646  */
    { Type t("d"); (yyval) = Atributos("double", t); }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 247 "trabalho.y" /* yacc.c:1646  */
    { Type t("s"); (yyval) = Atributos("char[]", t); }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 248 "trabalho.y" /* yacc.c:1646  */
    { Type t("b"); (yyval) = Atributos("int", t);    }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 251 "trabalho.y" /* yacc.c:1646  */
    { block_vars.push_back(""); }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 252 "trabalho.y" /* yacc.c:1646  */
    {
          (yyval).codigo = "{\n";
          (yyval).codigo += block_vars[block_vars.size()-1];
          block_vars.pop_back();
          (yyval).codigo += (yyvsp[-1]).codigo + "}\n";
        }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 261 "trabalho.y" /* yacc.c:1646  */
    {
              (yyval).codigo = "{\n";
              (yyval).codigo += (yyvsp[-1]).codigo + "}\n";
            }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 268 "trabalho.y" /* yacc.c:1646  */
    {
          (yyval).codigo = (yyvsp[-1]).codigo + (yyvsp[0]).codigo;
        }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 271 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = Atributos(); }
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 282 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 287 "trabalho.y" /* yacc.c:1646  */
    {
               (yyval).codigo = (yyvsp[-1]).codigo +
                     "  cout << " + (yyvsp[-1]).valor + ";\n"
                     "  cout << endl;\n";
             }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 295 "trabalho.y" /* yacc.c:1646  */
    {
                 (yyvsp[-1]).type = check_ts((yyvsp[-1]).valor);
                 (yyval).codigo = std_reading((yyvsp[-1]));
               }
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 302 "trabalho.y" /* yacc.c:1646  */
    {
               (yyval).codigo = (yyvsp[0]).codigo + "  return 0;\n";
             }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 306 "trabalho.y" /* yacc.c:1646  */
    {
               (yyval).codigo = (yyvsp[-2]).codigo + (yyvsp[0]).codigo + "  return "+ (yyvsp[0]).valor +";\n";
             }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 312 "trabalho.y" /* yacc.c:1646  */
    {
           (yyval) = if_code_generator((yyvsp[-2]), (yyvsp[0]).codigo, "");
         }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 316 "trabalho.y" /* yacc.c:1646  */
    {
           (yyval) = if_code_generator((yyvsp[-4]), (yyvsp[-2]).codigo, (yyvsp[0]).codigo);
         }
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 322 "trabalho.y" /* yacc.c:1646  */
    {
            (yyval) = for_code_generator((yyvsp[-6]), (yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]));
          }
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 328 "trabalho.y" /* yacc.c:1646  */
    {
               (yyval) = Atributos((yyvsp[-2]).valor, (yyvsp[-3]).type);
               block_vars[block_vars.size()-1] += "  " + decl_var((yyvsp[-2]).valor, (yyvsp[-3]).type) + ";\n";
               insert_var_ts((yyvsp[-2]).valor, (yyvsp[-3]).type);
               (yyvsp[-2]).type = (yyvsp[-3]).type;
               (yyval).codigo = atribui_var((yyvsp[-2]), (yyvsp[0]));
             }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 337 "trabalho.y" /* yacc.c:1646  */
    {
                (yyval) = Atributos((yyvsp[-2]).valor, check_ts((yyvsp[-2]).valor));
                (yyval).codigo = atribui_var((yyvsp[-2]), (yyvsp[0]));
              }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 345 "trabalho.y" /* yacc.c:1646  */
    {
              (yyval).codigo = (yyvsp[0]).codigo + "\n" + "  "
                        + (yyvsp[-2]).valor + " = " + (yyvsp[0]).valor + ";\n";
            }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 353 "trabalho.y" /* yacc.c:1646  */
    {
              (yyval) = while_code_generator((yyvsp[-2]), (yyvsp[0]));
            }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 359 "trabalho.y" /* yacc.c:1646  */
    {
                (yyval) = do_while_code_generator((yyvsp[-4]), (yyvsp[-1]));
              }
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 364 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "+", (yyvsp[0]));    }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 365 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "-", (yyvsp[0]));    }
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 366 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "*", (yyvsp[0]));    }
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 367 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "/", (yyvsp[0]));    }
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 368 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), ">", (yyvsp[0]));    }
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 369 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "<", (yyvsp[0]));    }
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 370 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), ">=", (yyvsp[0]));   }
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 371 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "<=", (yyvsp[0]));   }
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 372 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "!=", (yyvsp[0]));   }
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 373 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "==", (yyvsp[0]));   }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 374 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "&&", (yyvsp[0]));   }
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 375 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "||", (yyvsp[0]));   }
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 376 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]), "%", (yyvsp[0]));    }
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 377 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = un_opr_code_generator("!", (yyvsp[0])); }
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 378 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]);                                   }
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 379 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = opr_code_generator((yyvsp[-2]),"@",(yyvsp[0]));  }
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 380 "trabalho.y" /* yacc.c:1646  */
    { (yyval) = in_opr_code_generator((yyvsp[-2]), "in", (yyvsp[0]));}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 385 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval).valor = (yyvsp[0]).valor;
      (yyval).type = check_ts((yyvsp[0]).valor);
      (yyval).codigo = (yyvsp[0]).codigo;
    }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 391 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval).valor = (yyvsp[0]).valor;
      (yyval).type = Type("i");
      (yyval).codigo = (yyvsp[0]).codigo;
    }
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 397 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval).valor = (yyvsp[0]).valor;
      (yyval).type = Type("d");
      (yyval).codigo = (yyvsp[0]).codigo;
    }
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 403 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval).valor = (yyvsp[0]).valor;
      (yyval).type = Type("c");
      (yyval).codigo = (yyvsp[0]).codigo;
    }
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 409 "trabalho.y" /* yacc.c:1646  */
    {
      (yyval).valor = (yyvsp[0]).valor;
      (yyval).type = Type("s");
      (yyval).codigo = (yyvsp[0]).codigo;
    }
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 415 "trabalho.y" /* yacc.c:1646  */
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
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 431 "trabalho.y" /* yacc.c:1646  */
    {
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
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 454 "trabalho.y" /* yacc.c:1646  */
    {
        (yyval).valor = "1";
        (yyval).type = Type("b");
        (yyval).codigo = (yyvsp[0]).codigo;
      }
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 460 "trabalho.y" /* yacc.c:1646  */
    {
        (yyval).valor = "0";
        (yyval).type = Type("b");
        (yyval).codigo = (yyvsp[0]).codigo;
      }
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2123 "y.tab.c" /* yacc.c:1646  */
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
#line 467 "trabalho.y" /* yacc.c:1906  */


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

  // Type basico
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
