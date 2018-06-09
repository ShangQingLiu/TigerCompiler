IDIR =./include
SDIR =./src
TESTDIR=./test
ODIR =./obj
BDIR =./bin

COMPILER=gcc
CFLAGS=-I$(IDIR) -g -c -o
OPTIONS=-o

PARSE_OBJECTS = parsetest.o y.tab.o lex.yy.o errormsg.o ast.o past.o \
symbol.o table.o utils.o

SEM_OBJECTS = semantest.o y.tab.o lex.yy.o errormsg.o ast.o past.o\
symbol.o table.o utils.o types.o env.o semant.o translate.o tree.o \
frame.o temp.o escape.o

CG_OBJECTS = codegentest.o y.tab.o lex.yy.o errormsg.o ast.o past.o \
symbol.o table.o utils.o types.o env.o semant.o translate.o tree.o \
frame.o temp.o assem.o flowgraph.o liveness.o color.o graph.o \
escape.o canonical.o codegen.o printtree.o regalloc.o

TREE_OBJECTS = treetest.o y.tab.o lex.yy.o errormsg.o ast.o past.o \
symbol.o table.o utils.o types.o env.o semant.o translate.o tree.o \
frame.o temp.o assem.o flowgraph.o liveness.o color.o graph.o \
escape.o canonical.o codegen.o printtree.o

# LEXER_OBJS = $(patsubst %,$(ODIR)/%,$(LEXER_OBJECTS))
PARSER_OBJS = $(patsubst %,$(ODIR)/%,$(PARSER_OBJECTS))
PARSE_OBJS = $(patsubst %,$(ODIR)/%,$(PARSE_OBJECTS))
# SEM_OBJS = $(patsubst %,$(ODIR)/%,$(SEM_OBJECTS))
# STR_OBJS  = $(patsubst %, $(ODIR)/%, $(STR_OBJECTS))
TREE_OBJS = $(patsubst %, $(ODIR)/%, $(TREE_OBJECTS))
CG_OBJS = $(patsubst %, $(ODIR)/%, $(CG_OBJECTS))

LEXER_PROG_NAME=$(BDIR)/lextest
PARSER_PROG_NAME=$(BDIR)/parsertest
PARSE_PROG_NAME=$(BDIR)/parsetest
SEM_PROG_NAME=$(BDIR)/semantest
STR_PROG_NAME=$(BDIR)/stringtest
TREE_PROG_NAME=$(BDIR)/treetest
PROG_NAME=$(BDIR)/codegentest

all: $(CG_OBJS)
	$(COMPILER) $^ $(OPTIONS) $(PROG_NAME)

treetest: $(TREE_OBJS)
	$(COMPILER) $^ $(OPTIONS) $(TREE_PROG_NAME)
	
parsetest: $(PARSE_OBJS)
	$(COMPILER) $^ $(OPTIONS) $(PARSE_PROG_NAME)
	
stringtest: $(STR_OBJS)
	$(COMPILER) $^ $(OPTIONS) $(STR_PROG_NAME)
	
semantest: $(SEM_OBJS)
	$(COMPILER) $^ $(OPTIONS) $(SEM_PROG_NAME)

parsertest: $(PARSER_OBJS)
	$(COMPILER) $^ $(OPTIONS) $(PARSER_PROG_NAME)
	
lextest: $(LEXER_OBJS)
	$(COMPILER) $^ $(OPTIONS) $(LEXER_PROG_NAME)

$(ODIR)/%.o: $(SDIR)/%.c
	$(COMPILER) $(CFLAGS) $@ $<
	
$(ODIR)/%.o: $(TESTDIR)/%.c
	$(COMPILER) $(CFLAGS) $@ $<

$(ODIR)/frame.o: $(SDIR)/x86frame.c
	$(COMPILER) $(CFLAGS) $@ $<
	
$(ODIR)/codegen.o: $(SDIR)/x86codegen.c
	$(COMPILER) $(CFLAGS) $@ $<


$(ODIR)/lex.yy.o: $(SDIR)/lex.yy.c
	$(COMPILER) $(CFLAGS) $@ $<

#$(SDIR)/lex.yy.c: $(SDIR)/tiger.l
	# flex -o $(SDIR)/lex.yy.c $<

$(ODIR)/y.tab.o: $(SDIR)/y.tab.c
	$(COMPILER) $(CFLAGS) $@ $<

#$(SDIR)/y.tab.c: $(SDIR)/parser.y
	# bison -ydvo $@ $<

clean: 
	rm -f $(ODIR)/*.o $(LEXER_PROG_NAME) $(PARSER_PROG_NAME) $(PARSE_PROG_NAME) \
		$(SEM_PROG_NAME) $(STR_PROG_NAME) $(TREE_PROG_NAME) $(PROG_NAME)
