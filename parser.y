%{
#include <stdio.h>
#include <AST.h>
#include <symbolTable.h>
#include <IRcode.h>
int x, y, z; // Global variable declarations
%}

%token INTEGER
%token WRITE
%token ID
%token IDENTIFIER

%%

program: declarations statement
       {
           // Perform semantic checks here
           if ($1 != INTEGER) {
               fprintf(stderr, "Error: Variable 'x' must have integer type.\n");
               YYERROR;
           }
           if ($2 != INTEGER) {
               fprintf(stderr, "Error: Variable 'y' must have integer type.\n");
               YYERROR;
           }
           if ($3 != INTEGER) {
               fprintf(stderr, "Error: Variable 'z' must have integer type.\n");
               YYERROR;
           }
           printf("Semantic checks passed. Code is valid.\n");
       }

declarations: declarations declaration
           |
           ;

declaration: INTEGER ID ';'
           ;

statement: WRITE ID ';'
         {
             // Perform semantic checks here
             if (lookup_variable($2) != INTEGER) {
                 fprintf(stderr, "Error: Variable '%s' must have integer type.\n", $2);
                 YYERROR;
             }
             printf("Write statement for variable '%s'.\n", $2);
         }
   ;

%%

int lookup_variable(const char* var) {
    if (strcmp(var, "x") == 0) return INTEGER;
    if (strcmp(var, "y") == 0) return INTEGER;
    if (strcmp(var, "z") == 0) return INTEGER;
    fprintf(stderr, "Error: Unknown variable '%s'.\n", var);
    YYERROR;
}

int main() {
    yyparse();
    return 0;
}