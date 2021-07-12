/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    Tok_EndOfFile = 258,
    Tok_Number = 259,
    Tok_True = 260,
    Tok_False = 261,
    Tok_ID = 262,
    Tok_Print = 263,
    Tok_Cln = 264,
    Tok_NL = 265,
    Tok_EQL = 266,
    Tok_NEQ = 267,
    Tok_EQ = 268,
    Tok_GT = 269,
    Tok_LT = 270,
    Tok_EGT = 271,
    Tok_ELT = 272,
    Tok_Or = 273,
    Tok_And = 274,
    Tok_Not = 275,
    Tok_In = 276,
    ID = 277,
    ND = 278,
    DD = 279,
    Tok_String = 280,
    Tok_If = 281,
    Tok_Elif = 282,
    Tok_While = 283,
    Tok_for = 284,
    Tok_Else = 285,
    Tok_Import = 286,
    Tok_Break = 287,
    Tok_Pass = 288,
    Tok_MN = 289,
    Tok_PL = 290,
    Tok_DV = 291,
    Tok_ML = 292,
    Tok_OP = 293,
    Tok_CP = 294,
    Tok_OB = 295,
    Tok_CB = 296,
    Tok_Comma = 297,
    Tok_List = 298,
    Tok_range = 299
  };
#endif
/* Tokens.  */
#define Tok_EndOfFile 258
#define Tok_Number 259
#define Tok_True 260
#define Tok_False 261
#define Tok_ID 262
#define Tok_Print 263
#define Tok_Cln 264
#define Tok_NL 265
#define Tok_EQL 266
#define Tok_NEQ 267
#define Tok_EQ 268
#define Tok_GT 269
#define Tok_LT 270
#define Tok_EGT 271
#define Tok_ELT 272
#define Tok_Or 273
#define Tok_And 274
#define Tok_Not 275
#define Tok_In 276
#define ID 277
#define ND 278
#define DD 279
#define Tok_String 280
#define Tok_If 281
#define Tok_Elif 282
#define Tok_While 283
#define Tok_for 284
#define Tok_Else 285
#define Tok_Import 286
#define Tok_Break 287
#define Tok_Pass 288
#define Tok_MN 289
#define Tok_PL 290
#define Tok_DV 291
#define Tok_ML 292
#define Tok_OP 293
#define Tok_CP 294
#define Tok_OB 295
#define Tok_CB 296
#define Tok_Comma 297
#define Tok_List 298
#define Tok_range 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 440 "grammar.y"
 char *text; int depth; struct ASTNode* node;

#line 148 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
