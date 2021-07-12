%{
	#include <string.h>
	#include "y.tab.h"
	#define stack_size 100
	#define DEBUG 1
	
	int yycolumn = 1;
	int startFlag = 1;
	
	#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; 		\
    yylloc.first_column = yycolumn; yylloc.last_column = yycolumn + yyleng - 1; 	\
    yycolumn += yyleng;												
    
 	static int sp=0, stack [stack_size];
 	
 	static void debug(const char *X)
 	{
 		#ifdef DEBUG
 		if(startFlag)
 		{
 			printf("---------------------------------Tokens--------------------------\n1 ");
 			startFlag=0;
 		}
 		
 		if(strcmp(X, "NL")==0)
 		{
 			printf("Tok_%s\n%d ", X, yylineno);
 		}
		else
		{
			printf("Tok_%s ", X);	
		}
 		#endif
 	}

 	static void push (int i) 
 	{
   		if (++sp<stack_size) stack[sp]= i;
   		else {printf ("error: stack overflow\n"); exit(1);}
 	}
 	
 	int pop () 
 	{
   		if (sp>-1) return stack[sp--];
   		else {printf ("error: stack underflow\n"); exit(1);}
 	}
 	
 	int top()
 	{
 		if(sp>-1) return stack[sp];
 		else return 1;
 	}
 	
 	static int indent_depth(const char *K)
	{
		int len = strlen(K), i, tab_count=1;
		for(i=0; i< len ; i++)
		{
			if(K[i]=='\t')
			{
				tab_count++;
			}
			else
			{
				printf("Nope");
				break;
			}	
		}
		return tab_count;
	}	
 	int depth = 1;
 		
%}
%option yylineno
%option noyywrap
whitespace [ ]
Multiline_comment \'\'\'.+\'\'\'
%%

[\t]*		{
			depth = indent_depth(yytext);
//			printf("Depth : %d ",  depth);
			if(depth < top())
			{
				while (depth < top()) pop();
				yylval.depth = depth;
				
				return DD;
			}
			
			if(depth == top())
			{
				
				yylval.depth = depth;
				return ND;				
			}
			if(depth > top())
			{
				push(depth);
				
				yylval.depth = depth;
				return ID;
			}
			
		}

"import" {debug("IMPT"); return Tok_Import;}
"print"  {debug("Print"); return Tok_Print;}
"pass" {debug("Pass"); return Tok_Pass;}
"if" {debug("If"); return Tok_If;}
"in" {debug("In"); return Tok_In;}
"while" {debug("While"); return Tok_While;}
"for" {debug("For"); return Tok_for;}
"break" {debug("Break"); return Tok_Break;}
"and" {debug("And"); return Tok_And;}
"or" {debug("Or"); return Tok_Or;}
"not" {debug("Not"); return Tok_Not;}
"elif" {debug("Elif"); return Tok_Elif;}
"else" {debug("Else"); return Tok_Else;}
":" {debug("Cln"); return Tok_Cln;}
">" {debug("GT"); return Tok_GT;}
"<" {debug("LT"); return Tok_LT;}
">=" {debug("EGT"); return Tok_EGT;}
"<=" {debug("ELT"); return Tok_ELT;}
"==" {debug("EQ"); return Tok_EQ;}
"!=" {debug("NEQ"); return Tok_NEQ;}
"True" {debug("True"); return Tok_True;}
"False" {debug("False"); return Tok_False;}
"+" {debug("PL"); return Tok_PL;}
"-" {debug("MN"); return Tok_MN;}
"*" {debug("ML"); return Tok_ML;}
"/" {debug("DV"); return Tok_DV;}
"(" { debug("OP"); return Tok_OP;}
")" {debug("CP"); return Tok_CP;}
"[" {debug("OB"); return Tok_OB;}
"]" {debug("CB"); return Tok_CB;}
"," {debug("Comma"); return Tok_Comma;}
"=" {debug("EQL"); return Tok_EQL;}
"list" {debug("List"); return Tok_List;}
"range" {debug("Range"); return Tok_range;}
[0-9]+ {yylval.text = strdup(yytext); debug(yylval.text); return Tok_Number;}
[_a-zA-Z][_a-zA-Z0-9]* {yylval.text = strdup(yytext); debug(yylval.text); return Tok_ID;}
\"([^\"\n])*\" {yylval.text = strdup(yytext); debug(yylval.text); return Tok_String;}
\'([^\'\n])*\' {yylval.text = strdup(yytext); debug(yylval.text); return Tok_String;}
"#"([a-z]|[0-9]|[A-Z]|" ")* {}
{whitespace} {} 
"\n" {yycolumn=1; debug("NL"); return Tok_NL;}
<<EOF>> {debug("EOF"); return Tok_EndOfFile;}

%%