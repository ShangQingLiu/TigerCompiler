/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

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

#line 83 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    EQ = 291,
    NEQ = 292,
    LT = 293,
    LE = 294,
    GT = 295,
    GE = 296,
    PLUS = 297,
    MINUS = 298,
    TIMES = 299,
    DIVIDE = 300,
    UMINUS = 301
  };
#endif
/* Tokens.  */
#define ID 258
#define STRING 259
#define INT 260
#define COMMA 261
#define COLON 262
#define LPAREN 263
#define RPAREN 264
#define LBRACK 265
#define RBRACK 266
#define LBRACE 267
#define RBRACE 268
#define DOT 269
#define ARRAY 270
#define IF 271
#define THEN 272
#define ELSE 273
#define WHILE 274
#define FOR 275
#define TO 276
#define LET 277
#define IN 278
#define END 279
#define OF 280
#define BREAK 281
#define NIL 282
#define FUNCTION 283
#define VAR 284
#define TYPE 285
#define SEMICOLON 286
#define DO 287
#define ASSIGN 288
#define OR 289
#define AND 290
#define EQ 291
#define NEQ 292
#define LT 293
#define LE 294
#define GT 295
#define GE 296
#define PLUS 297
#define MINUS 298
#define TIMES 299
#define DIVIDE 300
#define UMINUS 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "parser.y" /* yacc.c:355  */

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

#line 236 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 253 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   341

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
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

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "STRING", "INT", "COMMA", "COLON",
  "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE", "DOT",
  "ARRAY", "IF", "THEN", "ELSE", "WHILE", "FOR", "TO", "LET", "IN", "END",
  "OF", "BREAK", "NIL", "FUNCTION", "VAR", "TYPE", "SEMICOLON", "DO",
  "ASSIGN", "OR", "AND", "EQ", "NEQ", "LT", "LE", "GT", "GE", "PLUS",
  "MINUS", "TIMES", "DIVIDE", "UMINUS", "$accept", "program", "exp",
  "lvalue", "exp_seq", "arg_seq", "efield_seq", "decs", "dec", "tydecs",
  "tydec", "ty", "fields", "field", "vardec", "fundecs", "fundec", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -29

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-29)))

#define YYTABLE_NINF -50

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-50)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     143,   -28,    77,   -29,   -29,    54,   143,   143,     2,    85,
     -29,   -29,   143,    22,   265,     5,   143,    74,   143,    10,
      30,   -29,   239,    44,   184,   199,    27,    85,    61,    66,
      68,    49,    85,   -29,    58,   -29,   -29,    56,   -29,   -29,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,    88,   143,   265,   -29,   137,    89,   -10,
      63,   -29,    91,   -29,   143,   -29,   143,   143,   143,   -29,
      94,     3,    69,   115,   -29,   -29,   -29,   276,   286,   296,
     296,   296,   296,   296,   296,   -24,   -24,   -29,   -29,   172,
     -29,   265,   143,   -29,    81,   143,   -29,   -29,   212,   265,
     224,   104,   107,   143,    -1,   -29,    97,   -29,   -29,   143,
     154,   143,   143,   117,   113,   -29,    92,   265,   -29,   104,
     101,   -29,   -29,   265,   124,   265,   253,   125,     1,   143,
     119,   127,   -29,   143,   132,   146,   143,   265,   -29,   -29,
     265,   104,   114,   265,   -29,   143,   265
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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
       0,     0,     0,     0,    48,    55,    67,    22,    21,    15,
      16,    17,    19,    18,    20,    11,    12,    13,    14,     0,
      39,     4,     0,    24,    41,     0,    27,    43,    28,    30,
       0,    61,     0,     0,     0,    33,     0,    40,    45,     0,
      46,     0,     0,     0,     0,    60,     0,    64,    57,    61,
       0,    56,    34,    25,     0,    29,     0,     0,     0,     0,
       0,     0,    47,     0,    62,     0,     0,    65,    58,    59,
      31,     0,     0,    68,    63,     0,    69
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -29,   -29,     0,   -29,    -8,    48,    28,   -23,   -29,   120,
     -29,   -29,    34,    14,   -29,   129,   -29
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    13,    22,    15,    23,    58,    62,    31,    32,    33,
      34,   121,   114,   115,    35,    36,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    94,   118,    16,    69,    26,    24,    25,   135,    74,
     102,   119,    38,    60,   120,    52,    55,    57,    59,    53,
      50,    51,    39,    61,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,   103,   136,    54,    63,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    65,    91,    20,    97,     2,     3,     4,
      68,    16,     5,    21,    70,   106,    98,    99,   100,    71,
       6,    72,    73,     7,     8,     1,     9,     2,     3,     4,
      10,    11,     5,    56,    28,    17,    27,    18,    30,    19,
       6,    90,    57,     7,     8,   110,     9,    12,    93,    95,
      10,    11,   101,   117,    96,   104,   109,   113,   -49,   123,
     116,   125,   126,    28,    29,    30,     1,    12,     2,     3,
       4,   122,   128,     5,   127,   129,   131,    60,   134,   137,
     139,     6,   138,   140,     7,     8,   143,     9,   141,   105,
     108,    10,    11,    92,     1,   146,     2,     3,     4,   142,
     145,     5,   132,   130,    75,   144,     0,     0,    12,     6,
     124,     0,     7,     8,     0,     9,    76,     0,     0,    10,
      11,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,   107,     0,     0,    12,     0,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
       0,    66,     0,     0,     0,     0,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
     111,    67,     0,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,   112,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      64,     0,     0,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,   133,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,   -50,   -50,   -50,   -50,   -50,   -50,    48,    49,
      50,    51
};

static const yytype_int16 yycheck[] =
{
       0,    11,     3,    31,    27,     3,     6,     7,     7,    32,
       7,    12,    12,     3,    15,    10,    16,    17,    18,    14,
      44,    45,     0,    13,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    33,    36,    33,     9,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     9,    54,     1,    64,     3,     4,     5,
      33,    31,     8,     9,     3,    73,    66,    67,    68,     3,
      16,     3,    23,    19,    20,     1,    22,     3,     4,     5,
      26,    27,     8,     9,    28,     8,     1,    10,    30,    12,
      16,     3,    92,    19,    20,    95,    22,    43,     9,    36,
      26,    27,     8,   103,    13,    36,    25,     3,    23,   109,
       3,   111,   112,    28,    29,    30,     1,    43,     3,     4,
       5,    24,     9,     8,     7,    33,    25,     3,     3,   129,
       3,    16,    13,   133,    19,    20,   136,    22,     6,    24,
      92,    26,    27,     6,     1,   145,     3,     4,     5,     3,
      36,     8,   124,   119,    34,   141,    -1,    -1,    43,    16,
       6,    -1,    19,    20,    -1,    22,    37,    -1,    -1,    26,
      27,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    11,    -1,    -1,    43,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    17,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      18,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    21,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      31,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    32,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     8,    16,    19,    20,    22,
      26,    27,    43,    48,    49,    50,    31,     8,    10,    12,
       1,     9,    49,    51,    49,    49,     3,     1,    28,    29,
      30,    54,    55,    56,    57,    61,    62,    63,    49,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    10,    14,    33,    49,     9,    49,    52,    49,
       3,    13,    53,     9,    31,     9,    17,    32,    33,    54,
       3,     3,     3,    23,    54,    56,    62,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
       3,    49,     6,     9,    11,    36,    13,    51,    49,    49,
      49,     8,     7,    33,    36,    24,    51,    11,    52,    25,
      49,    18,    21,     3,    59,    60,     3,    49,     3,    12,
      15,    58,    24,    49,     6,    49,    49,     7,     9,    33,
      59,    25,    53,    32,     3,     7,    36,    49,    13,     3,
      49,     6,     3,    49,    60,    36,    49
};

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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 78 "parser.y" /* yacc.c:1646  */
    {
        ast_root = (yyvsp[0].exp);
    }
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 85 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = VarExp(EM_tokPos, (yyvsp[0].var));
    }
#line 1473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 89 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = AssignExp(EM_tokPos, (yyvsp[-2].var), (yyvsp[0].exp));
    }
#line 1481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 93 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = IntExp(EM_tokPos, (yyvsp[0].num));
    }
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 97 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = StringExp(EM_tokPos, (yyvsp[0].str));
    }
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 101 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = NilExp(EM_tokPos);
    }
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 106 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = SeqExp(EM_tokPos, NULL);
    }
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 110 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = SeqExp(EM_tokPos, (yyvsp[-1].expList));
    }
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 116 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = OpExp(EM_tokPos, A_minusOp, IntExp(EM_tokPos, 0), (yyvsp[0].exp));
    }
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 120 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = OpExp(EM_tokPos, A_plusOp, (yyvsp[-2].exp), (yyvsp[0].exp));
    }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 124 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = OpExp(EM_tokPos, A_minusOp, (yyvsp[-2].exp), (yyvsp[0].exp));
    }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 128 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = OpExp(EM_tokPos, A_timesOp, (yyvsp[-2].exp), (yyvsp[0].exp));
    }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 132 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = OpExp(EM_tokPos, A_divideOp, (yyvsp[-2].exp), (yyvsp[0].exp));
    }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 136 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = OpExp(EM_tokPos, A_eqOp, (yyvsp[-2].exp), (yyvsp[0].exp));
    }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 140 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = OpExp(EM_tokPos, A_neqOp, (yyvsp[-2].exp), (yyvsp[0].exp));
    }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 144 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = OpExp(EM_tokPos, A_ltOp, (yyvsp[-2].exp), (yyvsp[0].exp));
    }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 148 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = OpExp(EM_tokPos, A_gtOp, (yyvsp[-2].exp), (yyvsp[0].exp));
    }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 152 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = OpExp(EM_tokPos, A_leOp, (yyvsp[-2].exp), (yyvsp[0].exp));
    }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 156 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = OpExp(EM_tokPos, A_geOp, (yyvsp[-2].exp), (yyvsp[0].exp));
    }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 162 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = IfExp(EM_tokPos, (yyvsp[-2].exp), (yyvsp[0].exp), IntExp(EM_tokPos, 0));
    }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 166 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = IfExp(EM_tokPos, (yyvsp[-2].exp), IntExp(EM_tokPos, 1), (yyvsp[0].exp));
    }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 172 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = CallExp(EM_tokPos, Symbol((yyvsp[-2].str)), NULL);
    }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 176 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = CallExp(EM_tokPos, Symbol((yyvsp[-3].str)), (yyvsp[-1].expList));
    }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 182 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = ArrayExp(EM_tokPos, Symbol((yyvsp[-5].str)), (yyvsp[-3].exp), (yyvsp[0].exp));
    }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 187 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = RecordExp(EM_tokPos, Symbol((yyvsp[-2].str)), NULL);
    }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 191 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = RecordExp(EM_tokPos, Symbol((yyvsp[-3].str)), (yyvsp[-1].efieldList));
    }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 197 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = IfExp(EM_tokPos, (yyvsp[-2].exp), (yyvsp[0].exp), NULL);
    }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 201 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = IfExp(EM_tokPos, (yyvsp[-4].exp), (yyvsp[-2].exp), (yyvsp[0].exp));
    }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 206 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = WhileExp(EM_tokPos, (yyvsp[-2].exp), (yyvsp[0].exp));
    }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 210 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = ForExp(EM_tokPos, Symbol((yyvsp[-6].str)), (yyvsp[-4].exp), (yyvsp[-2].exp), (yyvsp[0].exp));
    }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 214 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = BreakExp(EM_tokPos);
    }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 220 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = LetExp(EM_tokPos, (yyvsp[-2].decList), SeqExp(EM_tokPos, NULL));
    }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 224 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exp) = LetExp(EM_tokPos, (yyvsp[-3].decList), SeqExp(EM_tokPos, (yyvsp[-1].expList)));
    }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 230 "parser.y" /* yacc.c:1646  */
    {
		is_success = FALSE;	
        (yyval.exp) = SeqExp(EM_tokPos, NULL);
    }
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 235 "parser.y" /* yacc.c:1646  */
    {
		is_success = FALSE;
        (yyval.exp) = (yyvsp[0].exp);
    }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 240 "parser.y" /* yacc.c:1646  */
    {
		is_success = FALSE;
	}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 247 "parser.y" /* yacc.c:1646  */
    {
        (yyval.var) = SimpleVar(EM_tokPos, Symbol((yyvsp[0].str)));
    }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 251 "parser.y" /* yacc.c:1646  */
    {
        (yyval.var) = FieldVar(EM_tokPos, (yyvsp[-2].var), Symbol((yyvsp[0].str)));
    }
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 255 "parser.y" /* yacc.c:1646  */
    {
        (yyval.var) = SubscriptVar(EM_tokPos, (yyvsp[-3].var), (yyvsp[-1].exp));
    }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 259 "parser.y" /* yacc.c:1646  */
    {
        (yyval.var) = SubscriptVar(EM_tokPos, SimpleVar(EM_tokPos, Symbol((yyvsp[-3].str))), (yyvsp[-1].exp));
    }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 272 "parser.y" /* yacc.c:1646  */
    {
        (yyval.expList) = ExpList((yyvsp[0].exp), NULL);
    }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 276 "parser.y" /* yacc.c:1646  */
    {
        (yyval.expList) = ExpList((yyvsp[-2].exp), (yyvsp[0].expList));
    }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 288 "parser.y" /* yacc.c:1646  */
    {
        (yyval.expList) = ExpList((yyvsp[0].exp), NULL);
    }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 292 "parser.y" /* yacc.c:1646  */
    {
        (yyval.expList) = ExpList((yyvsp[-2].exp), (yyvsp[0].expList));
    }
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 304 "parser.y" /* yacc.c:1646  */
    {
        (yyval.efieldList) = EfieldList(Efield(Symbol((yyvsp[-2].str)), (yyvsp[0].exp)), NULL);
    }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 308 "parser.y" /* yacc.c:1646  */
    {
        (yyval.efieldList) = EfieldList(Efield(Symbol((yyvsp[-4].str)), (yyvsp[-2].exp)), (yyvsp[0].efieldList));
    }
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 320 "parser.y" /* yacc.c:1646  */
    {
        (yyval.decList) = DecList((yyvsp[-1].dec), (yyvsp[0].decList));
    }
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 324 "parser.y" /* yacc.c:1646  */
    {
        (yyval.decList) = NULL;
    }
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 328 "parser.y" /* yacc.c:1646  */
    {
		is_success = FALSE;
	}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 335 "parser.y" /* yacc.c:1646  */
    {
        (yyval.dec) = TypeDec(EM_tokPos, (yyvsp[0].nametyList));
    }
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 340 "parser.y" /* yacc.c:1646  */
    {
        (yyval.dec) = (yyvsp[0].dec);
    }
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 344 "parser.y" /* yacc.c:1646  */
    {
        (yyval.dec) = FunctionDec(EM_tokPos, (yyvsp[0].fundecList));
    }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 356 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nametyList) = NametyList((yyvsp[0].namety), NULL);
    }
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 361 "parser.y" /* yacc.c:1646  */
    {
        (yyval.nametyList) = NametyList((yyvsp[-1].namety), (yyvsp[0].nametyList));
    }
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 373 "parser.y" /* yacc.c:1646  */
    {
        (yyval.namety) = Namety(Symbol((yyvsp[-2].str)), (yyvsp[0].ty));
    }
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 385 "parser.y" /* yacc.c:1646  */
    {
        (yyval.ty) = NameTy(EM_tokPos, Symbol((yyvsp[0].str)));
    }
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 389 "parser.y" /* yacc.c:1646  */
    {
        (yyval.ty) = RecordTy(EM_tokPos, (yyvsp[-1].fieldList));
    }
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 393 "parser.y" /* yacc.c:1646  */
    {
        (yyval.ty) = ArrayTy(EM_tokPos, Symbol((yyvsp[0].str)));
	}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 405 "parser.y" /* yacc.c:1646  */
    {
        (yyval.fieldList) = (yyvsp[0].fieldList);
    }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 409 "parser.y" /* yacc.c:1646  */
    {
        (yyval.fieldList) = NULL;
    }
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 421 "parser.y" /* yacc.c:1646  */
    {
        (yyval.fieldList) = FieldList(Field(EM_tokPos, Symbol((yyvsp[-2].str)), Symbol((yyvsp[0].str))), NULL);
    }
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 425 "parser.y" /* yacc.c:1646  */
    {
        (yyval.fieldList) = FieldList(Field(EM_tokPos, Symbol((yyvsp[-4].str)), Symbol((yyvsp[-2].str))), (yyvsp[0].fieldList));
    }
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 437 "parser.y" /* yacc.c:1646  */
    {
        (yyval.dec) = VarDec(EM_tokPos, Symbol((yyvsp[-2].str)), NULL, (yyvsp[0].exp));
    }
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 441 "parser.y" /* yacc.c:1646  */
    {
        (yyval.dec) = VarDec(EM_tokPos, Symbol((yyvsp[-4].str)), Symbol((yyvsp[-2].str)), (yyvsp[0].exp));
    }
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 448 "parser.y" /* yacc.c:1646  */
    {
        (yyval.fundecList) = FundecList((yyvsp[0].fundec), NULL);
    }
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 452 "parser.y" /* yacc.c:1646  */
    {
        (yyval.fundecList) = FundecList((yyvsp[-1].fundec), (yyvsp[0].fundecList));
    }
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 464 "parser.y" /* yacc.c:1646  */
    {
        (yyval.fundec) = Fundec(EM_tokPos, Symbol((yyvsp[-5].str)), (yyvsp[-3].fieldList), NULL, (yyvsp[0].exp));
    }
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 468 "parser.y" /* yacc.c:1646  */
    {
        (yyval.fundec) = Fundec(EM_tokPos, Symbol((yyvsp[-7].str)), (yyvsp[-5].fieldList), Symbol((yyvsp[-2].str)), (yyvsp[0].exp));
    }
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2007 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 478 "parser.y" /* yacc.c:1906  */


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
