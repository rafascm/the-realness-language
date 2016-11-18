DELIM   [\t\n ]
NUMERO  [0-9]
LETRA   [A-Za-z_]
INT     {NUMERO}+   
FLOAT   {NUMERO}+("."{NUMERO}+)?
ID      {LETRA}({LETRA}|{NUMERO})*
CHAR    '.'
STRING   \"[^\n]*\"
BOOL    "true"|"false"

%%

{DELIM}    {}
{INT}      { yylval = yytext; return tk_Nint; }
{FLOAT}    { yylval = yytext; return tk_Nfloat; }
{CHAR}     { yylval = yytext; return tk_Nchar; }
{STRING}   { yylval = yytext; return tk_Nstring; }
{BOOL}     { yylval = yytext; return tk_Nbool; }

"int"      { yylval = yytext; return tk_int; }
"float"    { yylval = yytext; return tk_float; }
"string"   { yylval = yytext; return tk_string; }
"char"     { yylval = yytext; return tk_char; }
"bool"     { yylval = yytext; return tk_bool; }
"void"     { yylval = yytext; return tk_void; }

":"       { yylval = yytext; return tk_inicio; }
"ty"      { yylval = yytext; return tk_final; }

"for"      { yylval = yytext; return tk_for; }
"repeat"   { yylval = yytext; return tk_repeat;}
"until"    { yylval = yytext; return tk_until; }
"while"    { yylval = yytext; return tk_while; }
"do"       { yylval = yytext; return tk_do; }
"if"       { yylval = yytext; return tk_if; }
"then"     { yylval = yytext; return tk_then; }
"else"     { yylval = yytext; return tk_else; }

"return"   { yylval = yytext; return tk_return; }

"set"     { yylval = yytext; return tk_printf; }
"get"     { yylval = yytext; return tk_scanf; }


"and"      { yylval = yytext; return tk_and; }
"not"      { yylval = yytext; return tk_not; }
"or"       { yylval = yytext; return tk_or; }

"in"       { yylval = yytext; return tk_in; }

"<="       { yylval = yytext; return tk_meig; }
">="       { yylval = yytext; return tk_maig; }
"!="       { yylval = yytext; return tk_dif; }
"="        { yylval = yytext; return tk_ig; }
">"       { yylval = yytext; return tk_dif; }
"<"        { yylval = yytext; return tk_ig; }
 
"="       { yylval = yytext; return tk_atrib; } 

"main()"   { yylval = yytext; return tk_main; }

{ID}       { yylval = yytext; return tk_id; }
.          { yylval = yytext; return yytext[0]; }

%%
