

DELIM   [\t ]
LINHA   [\n]
NUMERO  [0-9]
LETRA   [a-zA-Z_]
INT     {NUMERO}+
DOUBLE  {NUMERO}+("."{NUMERO}+)?
ID      {LETRA}({LETRA}|{NUMERO})*
CSTRING \"(\\.|[^\\"])*\"
CCHAR   ['][^\n'][']
COMMENT "/*"([^*]|\*+[^*/])*\*+"/"

%%

{LINHA}    { nlinha++; }
{DELIM}    {}
{COMMENT}  {}

"allTallShade"         {                               return TK_TRUE;    }
"noTnoShade"           {                               return TK_FALSE;   }

"int"                  {                               return TK_INT;     }
"char"                 {                               return TK_CHAR;    }
"double"               {                               return TK_DOUBLE;  }
"string"               {                               return TK_STRING;  }
"boolean"              {                               return TK_BOOL;    }
"void"                 {                               return TK_VOID;    }



"The Realness"         { yylval = Atributos( yytext ); return TK_MAIN;    }
"<shantay u stay>"     { yylval = Atributos( yytext ); return TK_BEGIN;   }
"</sashay away>"       { yylval = Atributos( yytext ); return TK_END;     }
"ret"                  { yylval = Atributos( yytext ); return TK_RETURN;  }

"wroteU"               { yylval = Atributos( yytext ); return TK_WRITE;   }
"readU"                { yylval = Atributos(yytext);   return TK_READ;    }

"if"                   { yylval = Atributos( yytext ); return TK_IF;      }
"else"                 { yylval = Atributos( yytext ); return TK_ELSE;    }
"for"                  { yylval = Atributos( yytext ); return TK_FOR;     }
"while"                { yylval = Atributos( yytext ); return TK_WHILE;   }
"do"                   { yylval = Atributos( yytext ); return TK_DO;      }
"choices"              { yylval = Atributos( yytext ); return TK_SWITCH;  }
"thankyou"             { yylval = Atributos( yytext ); return TK_BREAK;   }


"in"                   { yylval = Atributos( yytext ); return TK_IN;   }
"="                    { yylval = Atributos( yytext ); return TK_ATRIB;   }
"<="                   { yylval = Atributos( yytext ); return TK_LE;      }
">="                   { yylval = Atributos( yytext ); return TK_GE;      }
"=="                   { yylval = Atributos( yytext ); return TK_E;       }
"<"                    { yylval = Atributos( yytext ); return TK_L;       }
">"                    { yylval = Atributos( yytext ); return TK_G;       }
"!="                   { yylval = Atributos( yytext ); return TK_DIFF;    }
"@"                    { yylval = Atributos( yytext ); return TK_CMPARRAY;}
"and"                  { yylval = Atributos( yytext ); return TK_AND;     }
"or"                   { yylval = Atributos( yytext ); return TK_OR;      }
"not"                  { yylval = Atributos( yytext ); return TK_NOT;     }
"mod"                  { yylval = Atributos( yytext ); return TK_MOD;     }

"The library is officially open\nbecause reading is? FUNDAMENTAL" {
                         yylval = Atributos( yytext ); return TK_START;   }
"The library is officially closed" {
                         yylval = Atributos( yytext ); return TK_STOP;    }

{CSTRING}  { yylval = Atributos(yytext, Tipo("string"));    return TK_CSTRING; }
{CCHAR}    { yylval = Atributos(yytext, Tipo("char"));      return TK_CCHAR;   }
{ID}       { yylval = Atributos(renomeia_variavel_usuario(yytext));
                                                            return TK_ID;      }
{INT}      { yylval = Atributos(yytext, Tipo("int"));       return TK_CINT;    }
{DOUBLE}   { yylval = Atributos(yytext, Tipo("double"));    return TK_CDOUBLE; }

.          { yylval = Atributos( yytext );                  return *yytext;    }

%%
