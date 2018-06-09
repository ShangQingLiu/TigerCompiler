
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "past.h"
#include "errormsg.h"
#include "symbol.h"
#include "utils.h"

static exp_t ast_root;
static bool is_success = TRUE;

int yylex(void);
void yyerror(char *msg);
exp_t parse();


/* Line 189 of yacc.c  */
#line 91 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     STRING = 259,
     INT = 260,
     COMMA = 261,
     COLON = 262,
     LPAREN = 263,
     RPAREN = 264,
     LBRACK = 265,
     RBRACK = 266,
     LBRACE = 267,
     RBRACE = 268,
     DOT = 269,
     ARRAY = 270,
     IF = 271,
     THEN = 272,
     ELSE = 273,
     WHILE = 274,
     FOR = 275,
     TO = 276,
     LET = 277,
     IN = 278,
     END = 279,
     OF = 280,
     BREAK = 281,
     NIL = 282,
     FUNCTION = 283,
     VAR = 284,
     TYPE = 285,
     SEMICOLON = 286,
     DO = 287,
     ASSIGN = 288,
     OR = 289,
     AND = 290,
     GE = 291,
     GT = 292,
     LE = 293,
     LT = 294,
     NEQ = 295,
     EQ = 296,
     MINUS = 297,
     PLUS = 298,
     DIVIDE = 299,
     TIMES = 300,
     UMINUS = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 20 "parser.y"

    int pos;
    int num;
    string_t str;
    symbol_t sym;
    var_t var;
    exp_t exp;
    dec_t dec;
    ty_t ty;
    decList_t decList;
    expList_t expList;
    field_t field;
    fieldList_t fieldList;
    fundec_t fundec;
    fundecList_t fundecList;
    namety_t namety;
    nametyList_t nametyList;
    efield_t efield;
    efieldList_t efieldList;



/* Line 214 of yacc.c  */
#line 196 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 208 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   355

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNRULES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    11,    13,    15,    17,    20,
      24,    27,    31,    35,    39,    43,    47,    51,    55,    59,
      63,    67,    71,    75,    79,    84,    91,    95,   100,   105,
     112,   117,   126,   128,   133,   139,   143,   147,   149,   151,
     155,   160,   165,   167,   171,   173,   177,   181,   187,   190,
     191,   194,   196,   198,   200,   202,   205,   210,   212,   216,
     220,   222,   223,   227,   233,   238,   245,   247,   250,   258
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    -1,    50,    -1,    50,    33,    49,
      -1,     5,    -1,     4,    -1,    27,    -1,     8,     9,    -1,
       8,    51,     9,    -1,    42,    49,    -1,    49,    43,    49,
      -1,    49,    42,    49,    -1,    49,    45,    49,    -1,    49,
      44,    49,    -1,    49,    41,    49,    -1,    49,    40,    49,
      -1,    49,    39,    49,    -1,    49,    37,    49,    -1,    49,
      38,    49,    -1,    49,    36,    49,    -1,    49,    35,    49,
      -1,    49,    34,    49,    -1,     3,     8,     9,    -1,     3,
       8,    52,     9,    -1,     3,    10,    49,    11,    25,    49,
      -1,     3,    12,    13,    -1,     3,    12,    53,    13,    -1,
      16,    49,    17,    49,    -1,    16,    49,    17,    49,    18,
      49,    -1,    19,    49,    32,    49,    -1,    20,     3,    33,
      49,    21,    49,    32,    49,    -1,    26,    -1,    22,    54,
      23,    24,    -1,    22,    54,    23,    51,    24,    -1,     8,
       1,     9,    -1,     1,    31,    49,    -1,     1,    -1,     3,
      -1,    50,    14,     3,    -1,    50,    10,    49,    11,    -1,
       3,    10,    49,    11,    -1,    49,    -1,    49,    31,    51,
      -1,    49,    -1,    49,     6,    52,    -1,     3,    41,    49,
      -1,     3,    41,    49,     6,    53,    -1,    55,    54,    -1,
      -1,     1,    54,    -1,    56,    -1,    61,    -1,    62,    -1,
      57,    -1,    57,    56,    -1,    30,     3,    41,    58,    -1,
       3,    -1,    12,    59,    13,    -1,    15,    25,     3,    -1,
      60,    -1,    -1,     3,     7,     3,    -1,     3,     7,     3,
       6,    60,    -1,    29,     3,    33,    49,    -1,    29,     3,
       7,     3,    33,    49,    -1,    63,    -1,    63,    62,    -1,
      28,     3,     8,    59,     9,    41,    49,    -1,    28,     3,
       8,    59,     9,     7,     3,    41,    49,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    84,    88,    92,    96,   100,   105,   109,
     115,   119,   123,   127,   131,   135,   139,   143,   147,   151,
     155,   161,   165,   171,   175,   181,   186,   190,   196,   200,
     205,   209,   213,   219,   223,   229,   234,   239,   246,   250,
     254,   258,   271,   275,   287,   291,   303,   307,   319,   324,
     327,   334,   339,   343,   355,   360,   372,   384,   388,   392,
     404,   409,   420,   424,   436,   440,   447,   451,   463,   467
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "STRING", "INT", "COMMA", "COLON",
  "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE", "DOT",
  "ARRAY", "IF", "THEN", "ELSE", "WHILE", "FOR", "TO", "LET", "IN", "END",
  "OF", "BREAK", "NIL", "FUNCTION", "VAR", "TYPE", "SEMICOLON", "DO",
  "ASSIGN", "OR", "AND", "GE", "GT", "LE", "LT", "NEQ", "EQ", "MINUS",
  "PLUS", "DIVIDE", "TIMES", "UMINUS", "$accept", "program", "exp",
  "lvalue", "exp_seq", "arg_seq", "efield_seq", "decs", "dec", "tydecs",
  "tydec", "ty", "fields", "field", "vardec", "fundecs", "fundec", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    50,    50,
      50,    50,    51,    51,    52,    52,    53,    53,    54,    54,
      54,    55,    55,    55,    56,    56,    57,    58,    58,    58,
      59,    59,    60,    60,    61,    61,    62,    62,    63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     1,     1,     2,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     6,     3,     4,     4,     6,
       4,     8,     1,     4,     5,     3,     3,     1,     1,     3,
       4,     4,     1,     3,     1,     3,     3,     5,     2,     0,
       2,     1,     1,     1,     1,     2,     4,     1,     3,     3,
       1,     0,     3,     5,     4,     6,     1,     2,     7,     9
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    37,    38,     6,     5,     0,     0,     0,     0,     0,
      32,     7,     0,     0,     2,     3,     0,     0,     0,     0,
      37,     8,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,    54,    52,    53,    66,    10,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    23,    44,     0,     0,
       0,    26,     0,    35,     0,     9,     0,     0,     0,    50,
       0,     0,     0,     0,    48,    55,    67,    22,    21,    20,
      18,    19,    17,    16,    15,    12,    11,    14,    13,     0,
      39,     4,     0,    24,    41,     0,    27,    43,    28,    30,
       0,    61,     0,     0,     0,    33,     0,    40,    45,     0,
      46,     0,     0,     0,     0,    60,     0,    64,    57,    61,
       0,    56,    34,    25,     0,    29,     0,     0,     0,     0,
       0,     0,    47,     0,    62,     0,     0,    65,    58,    59,
      31,     0,     0,    68,    63,     0,    69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    13,    22,    15,    23,    58,    62,    31,    32,    33,
      34,   121,   114,   115,    35,    36,    37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -52
static const yytype_int16 yypact[] =
{
     154,   -26,    67,   -52,   -52,    54,   154,   154,    17,    55,
     -52,   -52,   154,    21,   279,     5,   154,    97,   154,     1,
      30,   -52,   253,    14,   198,   213,    20,    55,    61,    62,
      68,    59,    55,   -52,    56,   -52,   -52,    60,   -52,   -52,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,    84,   154,   279,   -52,   150,    80,   -10,
      49,   -52,    78,   -52,   154,   -52,   154,   154,   154,   -52,
      85,     4,    53,   127,   -52,   -52,   -52,   290,   300,   310,
     310,   310,   310,   310,   310,   -35,   -35,   -52,   -52,   186,
     -52,   279,   154,   -52,    72,   154,   -52,   -52,   226,   279,
     238,    96,   101,   154,    57,   -52,    83,   -52,   -52,   154,
     165,   154,   154,   103,    99,   -52,    81,   279,   -52,    96,
      90,   -52,   -52,   279,   115,   279,   267,   117,    -5,   154,
     108,   119,   -52,   154,   120,   122,   154,   279,   -52,   -52,
     279,    96,    86,   279,   -52,   154,   279
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -52,   -52,     0,   -52,   -51,    42,    13,   -24,   -52,   104,
     -52,   -52,    22,    -1,   -52,   105,   -52
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -50
static const yytype_int16 yytable[] =
{
      14,    94,   135,    69,    60,    16,    24,    25,    74,    50,
      51,   102,    38,    97,    61,    52,    55,    57,    59,    53,
      26,    39,   106,    65,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,   136,   103,    54,    63,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    68,    91,    20,    27,     2,     3,     4,
     118,    16,     5,    21,    70,    71,    98,    99,   100,   119,
       6,    72,   120,     7,     8,    17,     9,    18,   -49,    19,
      10,    11,    73,    28,    29,    30,    30,    90,    28,    93,
      95,    96,    57,   101,   104,   110,    12,   109,     1,   113,
       2,     3,     4,   117,   116,     5,    56,   122,   128,   123,
     127,   125,   126,     6,   129,   131,     7,     8,    60,     9,
     134,   138,   139,    10,    11,   142,   141,   145,     1,   137,
       2,     3,     4,   140,   108,     5,   143,   132,    75,    12,
     144,   130,    76,     6,     0,   146,     7,     8,     0,     9,
       0,   105,     0,    10,    11,     1,    92,     2,     3,     4,
       0,     0,     5,     0,     0,     0,     0,     0,     0,    12,
       6,   124,     0,     7,     8,     0,     9,     0,     0,     0,
      10,    11,     0,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    12,   107,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     0,     0,     0,     0,    66,     0,     0,     0,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,   111,    67,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,   112,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    64,     0,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,   133,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,   -50,   -50,   -50,   -50,
     -50,   -50,    48,    49,    50,    51
};

static const yytype_int16 yycheck[] =
{
       0,    11,     7,    27,     3,    31,     6,     7,    32,    44,
      45,     7,    12,    64,    13,    10,    16,    17,    18,    14,
       3,     0,    73,     9,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    41,    33,    33,     9,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    33,    54,     1,     1,     3,     4,     5,
       3,    31,     8,     9,     3,     3,    66,    67,    68,    12,
      16,     3,    15,    19,    20,     8,    22,    10,    23,    12,
      26,    27,    23,    28,    29,    30,    30,     3,    28,     9,
      41,    13,    92,     8,    41,    95,    42,    25,     1,     3,
       3,     4,     5,   103,     3,     8,     9,    24,     9,   109,
       7,   111,   112,    16,    33,    25,    19,    20,     3,    22,
       3,    13,     3,    26,    27,     3,     6,    41,     1,   129,
       3,     4,     5,   133,    92,     8,   136,   124,    34,    42,
     141,   119,    37,    16,    -1,   145,    19,    20,    -1,    22,
      -1,    24,    -1,    26,    27,     1,     6,     3,     4,     5,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      16,     6,    -1,    19,    20,    -1,    22,    -1,    -1,    -1,
      26,    27,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    42,    11,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    18,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    21,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    31,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     8,    16,    19,    20,    22,
      26,    27,    42,    48,    49,    50,    31,     8,    10,    12,
       1,     9,    49,    51,    49,    49,     3,     1,    28,    29,
      30,    54,    55,    56,    57,    61,    62,    63,    49,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    10,    14,    33,    49,     9,    49,    52,    49,
       3,    13,    53,     9,    31,     9,    17,    32,    33,    54,
       3,     3,     3,    23,    54,    56,    62,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
       3,    49,     6,     9,    11,    41,    13,    51,    49,    49,
      49,     8,     7,    33,    41,    24,    51,    11,    52,    25,
      49,    18,    21,     3,    59,    60,     3,    49,     3,    12,
      15,    58,    24,    49,     6,    49,    49,     7,     9,    33,
      59,    25,    53,    32,     3,     7,    41,    49,    13,     3,
      49,     6,     3,    49,    60,    41,    49
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 78 "parser.y"
    {
        ast_root = (yyvsp[(1) - (1)].exp);
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 85 "parser.y"
    {
        (yyval.exp) = VarExp(EM_tokPos, (yyvsp[(1) - (1)].var));
    ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    {
        (yyval.exp) = AssignExp(EM_tokPos, (yyvsp[(1) - (3)].var), (yyvsp[(3) - (3)].exp));
    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 93 "parser.y"
    {
        (yyval.exp) = IntExp(EM_tokPos, (yyvsp[(1) - (1)].num));
    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    {
        (yyval.exp) = StringExp(EM_tokPos, (yyvsp[(1) - (1)].str));
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 101 "parser.y"
    {
        (yyval.exp) = NilExp(EM_tokPos);
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    {
        (yyval.exp) = SeqExp(EM_tokPos, NULL);
    ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 110 "parser.y"
    {
        (yyval.exp) = SeqExp(EM_tokPos, (yyvsp[(2) - (3)].expList));
    ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    {
        (yyval.exp) = OpExp(EM_tokPos, A_minusOp, IntExp(EM_tokPos, 0), (yyvsp[(2) - (2)].exp));
    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    {
        (yyval.exp) = OpExp(EM_tokPos, A_plusOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    {
        (yyval.exp) = OpExp(EM_tokPos, A_minusOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    {
        (yyval.exp) = OpExp(EM_tokPos, A_timesOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 132 "parser.y"
    {
        (yyval.exp) = OpExp(EM_tokPos, A_divideOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    {
        (yyval.exp) = OpExp(EM_tokPos, A_eqOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    {
        (yyval.exp) = OpExp(EM_tokPos, A_neqOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    {
        (yyval.exp) = OpExp(EM_tokPos, A_ltOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 148 "parser.y"
    {
        (yyval.exp) = OpExp(EM_tokPos, A_gtOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    {
        (yyval.exp) = OpExp(EM_tokPos, A_leOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    {
        (yyval.exp) = OpExp(EM_tokPos, A_geOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp));
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    {
        (yyval.exp) = IfExp(EM_tokPos, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), IntExp(EM_tokPos, 0));
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    {
        (yyval.exp) = IfExp(EM_tokPos, (yyvsp[(1) - (3)].exp), IntExp(EM_tokPos, 1), (yyvsp[(3) - (3)].exp));
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 172 "parser.y"
    {
        (yyval.exp) = CallExp(EM_tokPos, Symbol((yyvsp[(1) - (3)].str)), NULL);
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 176 "parser.y"
    {
        (yyval.exp) = CallExp(EM_tokPos, Symbol((yyvsp[(1) - (4)].str)), (yyvsp[(3) - (4)].expList));
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    {
        (yyval.exp) = ArrayExp(EM_tokPos, Symbol((yyvsp[(1) - (6)].str)), (yyvsp[(3) - (6)].exp), (yyvsp[(6) - (6)].exp));
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 187 "parser.y"
    {
        (yyval.exp) = RecordExp(EM_tokPos, Symbol((yyvsp[(1) - (3)].str)), NULL);
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 191 "parser.y"
    {
        (yyval.exp) = RecordExp(EM_tokPos, Symbol((yyvsp[(1) - (4)].str)), (yyvsp[(3) - (4)].efieldList));
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    {
        (yyval.exp) = IfExp(EM_tokPos, (yyvsp[(2) - (4)].exp), (yyvsp[(4) - (4)].exp), NULL);
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    {
        (yyval.exp) = IfExp(EM_tokPos, (yyvsp[(2) - (6)].exp), (yyvsp[(4) - (6)].exp), (yyvsp[(6) - (6)].exp));
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 206 "parser.y"
    {
        (yyval.exp) = WhileExp(EM_tokPos, (yyvsp[(2) - (4)].exp), (yyvsp[(4) - (4)].exp));
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    {
        (yyval.exp) = ForExp(EM_tokPos, Symbol((yyvsp[(2) - (8)].str)), (yyvsp[(4) - (8)].exp), (yyvsp[(6) - (8)].exp), (yyvsp[(8) - (8)].exp));
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    {
        (yyval.exp) = BreakExp(EM_tokPos);
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    {
        (yyval.exp) = LetExp(EM_tokPos, (yyvsp[(2) - (4)].decList), SeqExp(EM_tokPos, NULL));
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    {
        (yyval.exp) = LetExp(EM_tokPos, (yyvsp[(2) - (5)].decList), SeqExp(EM_tokPos, (yyvsp[(4) - (5)].expList)));
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 230 "parser.y"
    {
		is_success = FALSE;	
        (yyval.exp) = SeqExp(EM_tokPos, NULL);
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 235 "parser.y"
    {
		is_success = FALSE;
        (yyval.exp) = (yyvsp[(3) - (3)].exp);
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 240 "parser.y"
    {
		is_success = FALSE;
	;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 247 "parser.y"
    {
        (yyval.var) = SimpleVar(EM_tokPos, Symbol((yyvsp[(1) - (1)].str)));
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 251 "parser.y"
    {
        (yyval.var) = FieldVar(EM_tokPos, (yyvsp[(1) - (3)].var), Symbol((yyvsp[(3) - (3)].str)));
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 255 "parser.y"
    {
        (yyval.var) = SubscriptVar(EM_tokPos, (yyvsp[(1) - (4)].var), (yyvsp[(3) - (4)].exp));
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 259 "parser.y"
    {
        (yyval.var) = SubscriptVar(EM_tokPos, SimpleVar(EM_tokPos, Symbol((yyvsp[(1) - (4)].str))), (yyvsp[(3) - (4)].exp));
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 272 "parser.y"
    {
        (yyval.expList) = ExpList((yyvsp[(1) - (1)].exp), NULL);
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 276 "parser.y"
    {
        (yyval.expList) = ExpList((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].expList));
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 288 "parser.y"
    {
        (yyval.expList) = ExpList((yyvsp[(1) - (1)].exp), NULL);
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 292 "parser.y"
    {
        (yyval.expList) = ExpList((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].expList));
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 304 "parser.y"
    {
        (yyval.efieldList) = EfieldList(Efield(Symbol((yyvsp[(1) - (3)].str)), (yyvsp[(3) - (3)].exp)), NULL);
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 308 "parser.y"
    {
        (yyval.efieldList) = EfieldList(Efield(Symbol((yyvsp[(1) - (5)].str)), (yyvsp[(3) - (5)].exp)), (yyvsp[(5) - (5)].efieldList));
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 320 "parser.y"
    {
        (yyval.decList) = DecList((yyvsp[(1) - (2)].dec), (yyvsp[(2) - (2)].decList));
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 324 "parser.y"
    {
        (yyval.decList) = NULL;
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 328 "parser.y"
    {
		is_success = FALSE;
	;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 335 "parser.y"
    {
        (yyval.dec) = TypeDec(EM_tokPos, (yyvsp[(1) - (1)].nametyList));
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 340 "parser.y"
    {
        (yyval.dec) = (yyvsp[(1) - (1)].dec);
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 344 "parser.y"
    {
        (yyval.dec) = FunctionDec(EM_tokPos, (yyvsp[(1) - (1)].fundecList));
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 356 "parser.y"
    {
        (yyval.nametyList) = NametyList((yyvsp[(1) - (1)].namety), NULL);
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 361 "parser.y"
    {
        (yyval.nametyList) = NametyList((yyvsp[(1) - (2)].namety), (yyvsp[(2) - (2)].nametyList));
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 373 "parser.y"
    {
        (yyval.namety) = Namety(Symbol((yyvsp[(2) - (4)].str)), (yyvsp[(4) - (4)].ty));
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 385 "parser.y"
    {
        (yyval.ty) = NameTy(EM_tokPos, Symbol((yyvsp[(1) - (1)].str)));
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 389 "parser.y"
    {
        (yyval.ty) = RecordTy(EM_tokPos, (yyvsp[(2) - (3)].fieldList));
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 393 "parser.y"
    {
        (yyval.ty) = ArrayTy(EM_tokPos, Symbol((yyvsp[(3) - (3)].str)));
	;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 405 "parser.y"
    {
        (yyval.fieldList) = (yyvsp[(1) - (1)].fieldList);
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 409 "parser.y"
    {
        (yyval.fieldList) = NULL;
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 421 "parser.y"
    {
        (yyval.fieldList) = FieldList(Field(EM_tokPos, Symbol((yyvsp[(1) - (3)].str)), Symbol((yyvsp[(3) - (3)].str))), NULL);
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 425 "parser.y"
    {
        (yyval.fieldList) = FieldList(Field(EM_tokPos, Symbol((yyvsp[(1) - (5)].str)), Symbol((yyvsp[(3) - (5)].str))), (yyvsp[(5) - (5)].fieldList));
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 437 "parser.y"
    {
        (yyval.dec) = VarDec(EM_tokPos, Symbol((yyvsp[(2) - (4)].str)), NULL, (yyvsp[(4) - (4)].exp));
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 441 "parser.y"
    {
        (yyval.dec) = VarDec(EM_tokPos, Symbol((yyvsp[(2) - (6)].str)), Symbol((yyvsp[(4) - (6)].str)), (yyvsp[(6) - (6)].exp));
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 448 "parser.y"
    {
        (yyval.fundecList) = FundecList((yyvsp[(1) - (1)].fundec), NULL);
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 452 "parser.y"
    {
        (yyval.fundecList) = FundecList((yyvsp[(1) - (2)].fundec), (yyvsp[(2) - (2)].fundecList));
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 464 "parser.y"
    {
        (yyval.fundec) = Fundec(EM_tokPos, Symbol((yyvsp[(2) - (7)].str)), (yyvsp[(4) - (7)].fieldList), NULL, (yyvsp[(7) - (7)].exp));
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 468 "parser.y"
    {
        (yyval.fundec) = Fundec(EM_tokPos, Symbol((yyvsp[(2) - (9)].str)), (yyvsp[(4) - (9)].fieldList), Symbol((yyvsp[(7) - (9)].str)), (yyvsp[(9) - (9)].exp));
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2178 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 478 "parser.y"


void yyerror(char *msg) {
    EM_error(EM_tokPos, "%s", msg);
}

exp_t parse(string_t fname) 
{
    EM_reset(fname);
    if (yyparse() == 0) {/* parsing worked */
        fprintf(stderr,"Parsing successful!\n");
		if(is_success)
        	return ast_root;
		else { 
			fprintf(stderr, "There is some errors!\n");
			return NULL;
		}
    }
    else { 
        fprintf(stderr,"Parsing failed\n");
        return NULL;
    }
}

