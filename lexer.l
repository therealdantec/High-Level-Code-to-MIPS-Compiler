%option noyywrap

%{
#include <stdio.h>
#include <string.h>

#define YY_DECL int yylex()
#include "parser.tab.h"

int words = 0;
int chars = 0;
int lines = 0;

%}

letter      [a-zA-Z]
digit       [0-9]
ID          {letter}({letter}|{digit})*
delim       [ \t\n]
NUMBER         {digit}+(\.{digit}+)?(E[+\-]?(digit)+)?
ws          {delim}+

%%
"/*"    				{
							int c;
							while((c = input()) != 0) {
								if(c == '*') {
									if((c = input()) == '/')
										break;
									else
										unput(c);
								}
							}
						}
						
"int"	{words++; chars += strlen(yytext);
		 printf("%s : TYPE\n", yytext);
                 yylval.string = strdup(yytext); 
		 return TYPE;
		}

"char"	{words++; chars += strlen(yytext);
		 printf("%s : TYPE\n", yytext);
                 yylval.string = strdup(yytext); 
		 return WRITE;
		}
		
"write"	{words++; chars += strlen(yytext);
			printf("%s : KEYWORD\n", yytext);
			yylval.string = strdup(yytext); 
			return WRITE;
		}
		
{ID}	{words++; chars += strlen(yytext);
			  printf("%s : IDENTIFIER\n",yytext);
			  yylval.string = strdup(yytext); 
			  return ID;
			}
			
{NUMBER}		{words++; chars += strlen(yytext);
			  printf("%s : NUMBER\n",yytext);
			  yylval.number = atoi(strdup(yytext)); 
			  return NUMBER;
			}
			
";"		{chars++;
		  printf("%s : SEMICOLON\n", yytext);
		  yylval.string = strdup(yytext); 
		  return SEMICOLON;
		}
		
"="		{chars++;
		  printf("%s : EQ\n", yytext);
		  yylval.string = strdup(yytext); 
		  return EQ;
		}
		
"+"     {chars++;
         printf("%s : ADD_OP\n", yytext);
         yylval.string = strdup(yytext); 
	 return PLUS;
        }

"-"     {chars++;
         printf("%s : SUBTRACT_OP\n", yytext);
         yylval.string = strdup(yytext); 
	 return MINUS;
        }

"*"     {chars++;
         printf("%s : MULTIPLY_OP\n", yytext);
         yylval.string = strdup(yytext); 
	 return TIMES;
        }

"/"     {chars++;
         printf("%s : DIVISION_OP\n", yytext);
         yylval.string = strdup(yytext); 
	 return DIVIDE;
        }

"_"     {chars++;
         printf("%s : UNDERSCORE\n", yytext);
         yylval.string = strdup(yytext); 
	 return KEY;
        }

"("     {chars++;
         printf("%s : OPEN_PAREN\n", yytext);
         yylval.string = strdup(yytext); 
	 return KEY;
        }

")"     {chars++;
         printf("%s : CLOSED_PAREN\n", yytext);
         yylval.string = strdup(yytext); 
	 return KEY;
        }

"{"     {chars++;
         printf("%s : OPEN_BRACE\n", yytext);
         yylval.string = strdup(yytext); 
	 return KEY;
        }

"}"     {chars++;
         printf("%s : CLOSED_BRACE\n", yytext);
         yylval.string = strdup(yytext); 
	 return KEY;
        }

"["     {chars++;
         printf("%s : OPEN_BRACKET\n", yytext);
         yylval.string = strdup(yytext); 
	 return KEY;
        }

"]"     {chars++;
         printf("%s : CLOSED_BRACKET\n", yytext);
         yylval.string = strdup(yytext); 
	 return KEY;
        }

"<"     {chars++;
         printf("%s : LESS_THAN\n", yytext);
         yylval.string = strdup(yytext); 
	 return KEY;
        }

">"     {chars++;
         printf("%s : GREATER_THAN\n", yytext);
         yylval.string = strdup(yytext); 
	 return KEY;
        }

"<="     {chars++;
         printf("%s : LESS_OR_EQUAL\n", yytext);
         yylval.string = strdup(yytext); 
	 return KEY;
        }

">="     {chars++;
         printf("%s : GREATER_OR_EQUAL\n", yytext);
         yylval.string = strdup(yytext); 
	 return KEY;
        }

","     {chars++;
         printf("%s : PUNCTUATION\n", yytext);
         yylval.string = strdup(yytext); 
	 return KEY;
        }

"!="     {chars++;
         printf("%s : NOT_EQUAL\n", yytext);
         yylval.string = strdup(yytext); 
	 return KEY;
        }

"."     {chars++;
         printf("%s : PUNCTUATION\n", yytext);
         yylval.string = strdup(yytext); 
	 return KEY;
        }

"&&"     {chars++;
         printf("%s : AND_OP\n", yytext);
         yylval.string = strdup(yytext); 
	 return KEY;
        }

"=="     {chars++;
         printf("%s : EQUALS\n", yytext);
         yylval.string = strdup(yytext); 
	 return KEY;
        }

"|"     {chars++;
         printf("%s : PIPE\n", yytext);
         yylval.string = strdup(yytext); 
	 return KEY;
        }

\n		{lines++; chars=0;}
[ \t]	{chars++;}
.		{chars++;
         printf("%s : Unrecognized symbol at line %d char %d\n", yytext,lines,chars);
		}
		


%%