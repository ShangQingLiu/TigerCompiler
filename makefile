a.out: parsetest.o y.tab.o lex.yy.o errormsg.o ast.o past.o symbol.o table.o utils.o types.o env.o semant.o f_translate.o
	gcc -g parsetest.o y.tab.o lex.yy.o errormsg.o ast.o past.o symbol.o table.o utils.o types.o env.o semant.o f_translate.o

parsetest.o: parsetest.c errormsg.h utils.h past.h
	gcc -g -c parsetest.c

y.tab.o: y.tab.c
	gcc -g -c y.tab.c

y.tab.c: parser.y
	yacc -dv parser.y

y.tab.h: y.tab.c
	echo "y.tab.h was created at the same time as y.tab.c"

errormsg.o: errormsg.c errormsg.h utils.h
	gcc -g -c errormsg.c

lex.yy.o: lex.yy.c y.tab.h errormsg.h utils.h ast.h
	gcc -g -c lex.yy.c

# lex.yy.c: ref_tiger.lex
# 	lex ref_tiger.lex

lex.yy.c: tiger.l
	flex tiger.l lex.yy.c

past.o: past.c past.h
	gcc -g -c past.c

#tree.o: tree.c tree.h
#	gcc -g -c tree.c

f_translate.o: f_translate.c f_translate.h ast.h
	gcc -g -c f_translate.c

types.o: types.c types.h
	gcc -g -c types.c

env.o: env.c env.h
	gcc -g -c env.c

semant.o: semant.c semant.h
	gcc -g -c semant.c

ast.o: ast.c ast.h
	gcc -g -c ast.c

symbol.o: symbol.c symbol.h
	gcc -g -c symbol.c

table.o: table.c table.h
	gcc -g -c table.c

utils.o: utils.c utils.h
	gcc -g -c utils.c

clean: 
	rm -f a.out utils.o parsetest.o lex.yy.o errormsg.o y.tab.c y.tab.h y.tab.o
