main: lex.yy.o display.o
	gcc lex.yy.o display.o -o analyse -ll  -lm
lex.yy.o: lex.yy.c lex_example.l
	lex lex_example.l
	gcc -c lex.yy.c
display.o: display.c token.h
	gcc -c display.c
clean:
	rm lex.yy.c
	rm *o
	rm analyse
