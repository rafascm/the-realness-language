%{

char* troca_aspas( char* lexema );

%}

DELIM   [\t ]
LINHA   [\n]
NUMERO  [0-9]
LETRA   [A-Za-z_]
INT     {NUMERO}+
DOUBLE  {NUMERO}+("."{NUMERO}+)?
ID      {LETRA}({LETRA}|{NUMERO})*
CSTRING "'"([^\n']|"''")*"'"

COMMENT "(*"([^*]|"*"[^)])*"*)"

%%

{LINHA}    { nlinha++; }
{DELIM}    {}
{COMMENT}  {}

"CategoryIs"  { yylval = Atributos( yytext ); return TK_PROGRAM; }
"Shantay"       { yylval = Atributos( yytext ); return TK_BEGIN; }
"Sashay"         { yylval = Atributos( yytext ); return TK_END; }
"WroteU"     { yylval = Atributos( yytext ); return TK_WRITELN; }
"If"          { yylval = Atributos( yytext ); return TK_IF; }
"Then"        { yylval = Atributos( yytext ); return TK_THEN; }
"Else"        { yylval = Atributos( yytext ); return TK_ELSE; }
"For"         { yylval = Atributos( yytext ); return TK_FOR; }
"To"          { yylval = Atributos( yytext ); return TK_TO; }
"Do"          { yylval = Atributos( yytext ); return TK_DO; }
"Array"       { yylval = Atributos( yytext ); return TK_ARRAY; }
"Of"          { yylval = Atributos( yytext ); return TK_OF; }
"The Library is Officially Open\nBecause Reading is ? FUNDAMENTAL" { yylval = Atributos( yytext ); return TK_ABRIR1; }
"The Library is Officially Closed" { yylval = Atributos( yytext ); return TK_FECHAR; }
".."       { yylval = Atributos( yytext ); return TK_PTPT; }
"="       { yylval = Atributos( yytext ); return TK_ATRIB; }
"<="       { yylval = Atributos( yytext ); return TK_MEIG; }
">="       { yylval = Atributos( yytext ); return TK_MAIG; }
"<>"       { yylval = Atributos( yytext ); return TK_DIF; }
"And"      { yylval = Atributos( yytext ); return TK_AND; }


{CSTRING}  { yylval = Atributos( troca_aspas( yytext ), Tipo( "string" ) );
             return TK_CSTRING; }
{ID}       { yylval = Atributos( yytext ); return TK_ID; }
{INT}      { yylval = Atributos( yytext, Tipo( "int" ) ); return TK_CINT; }
{DOUBLE}   { yylval = Atributos( yytext, Tipo( "double" ) ); return TK_CDOUBLE; }

.          { yylval = Atributos( yytext ); return *yytext; }

%%

char* troca_aspas( char* lexema ) {
  int n = strlen( lexema );
  lexema[0] = '"';
  lexema[n-1] = '"';

  return lexema;
}
