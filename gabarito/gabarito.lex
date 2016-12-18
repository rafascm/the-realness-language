DELIM   [\t ]
LINHA   [\n]
NUMERO  [0-9]
LETRA   [A-Za-z_]
INT     {NUMERO}+
DOUBLE  {NUMERO}+("."{NUMERO}+)?
CHAR    ['][^\n'][']
ID      {LETRA}({LETRA}|{NUMERO})*
ID_INC  ("<")({LETRA})*(".h")?(">")
CIN     ("cin"{DELIM}*">>")
COUT    (("cout"|"cerr"){DELIM}*"<<")
INCLUDE ("#include")
STR     (\"[^"]*\")

%%

{LINHA}    { nlinha++; }
{DELIM}    {}
{CIN}      { return TK_CIN; }
{COUT}     { return TK_COUT; }
{INCLUDE}  { return TK_INCLUDE; }
{STR}	   { return TK_STR; }	
"using namespace std" { return TK_NAMESPACE; }
"endl"     { return TK_ENDL; }
"main"     { return TK_MAIN; }
"if"	   { return TK_IF; }
"goto"     { return TK_GOTO; }
"return"   { return TK_RETURN; }
"int"      { return TK_INT; }
"char"     { return TK_CHAR; }
"float"    { return TK_FLOAT; }
"double"   { return TK_DOUBLE; }
"long"     { return TK_LONG; }
"void"     { return TK_VOID; }
"&&"       { return TK_AND; }
"||"       { return TK_OR; }
"=="       { return TK_IGUAL; }
"!="       { return TK_DIF; }
">="       { return TK_MAIGUAL; }
"<="       { return TK_MEIGUAL; }
{ID}       { yylval = yytext; return TK_ID; }
{ID_INC}   { yylval = yytext; return TK_ID_INC; }
{INT}      { yylval = yytext; return TK_CINT; }
{DOUBLE}   { yylval = yytext; return TK_CDOUBLE; }
{CHAR}     { yylval = yytext; return TK_CCHAR; }
.          { return *yytext; }

%%

 


