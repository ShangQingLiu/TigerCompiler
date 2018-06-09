/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 20 "parser.y" /* yacc.c:1909  */

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

#line 167 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
