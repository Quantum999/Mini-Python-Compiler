python.out: y.tab.c lex.yy.c
	gcc lex.yy.c y.tab.c -ll -w -o python.out
lex.yy.c: grammar.l 
	lex grammar.l 
y.tab.c: grammar.y 
	yacc grammar.y -d
clean: 
	rm -rf a.out lex.yy.c y.tab.c y.tab.h python.out
