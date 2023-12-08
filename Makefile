all: parser

parser.tab.c parser.tab.h:	parser.y
	bison -t -v -d parser.y

lex.yy.c: lexer.l parser.tab.h
	flex lexer.l

parser: lex.yy.c parser.tab.c parser.tab.h
	gcc -o parser -g parser.tab.c lex.yy.c
	./parser test.txt

clean:
	rm -f parser lexer parser.tab.c lex.yy.c parser.tab.h parser.output IRcode.ir MIPS_Code.asm
	ls -l

