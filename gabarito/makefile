all: gabarito

lex.yy.c: gabarito.lex
	lex gabarito.lex

y.tab.c: gabarito.y
	yacc gabarito.y

gabarito: lex.yy.c y.tab.c
	g++ -o gabarito y.tab.c -lfl
