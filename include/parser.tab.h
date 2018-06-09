
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 121 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


