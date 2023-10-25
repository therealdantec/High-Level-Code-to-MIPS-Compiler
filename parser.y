%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbolTable.h"
#include "AST.h"
#include "IRcode.h"
#include "Assembly.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;

FILE * IRcode;
//FILE * MIPScode;


void yyerror(const char* s);
	char currentScope[50] = "global"; // "global" or the name of the function
	int semanticCheckPassed = 1; // flags to record correctness of semantic checks
%}


%union {
	int number;
	char character;
	char* string;
	struct node* ast_node;
}

%token <string> INT CHAR STRING BOOL STRUC
%token <string> ID NUMBER
%token <string> SEMICOLON COMMA UNDERSCORE PERIOD
%token <string> LT GT 
%token <string> LTE GTE NE AND OR EQ
%token <string> ASS
%token <string> WRITE REEE
%token <string> PLUS MINUS TIMES DIVIDE
%token <string> LPRN RPRN LCB RCB LSB RSB

%printer { fprintf(yyoutput, "%s", $$); } ID;
%printer { fprintf(yyoutput, "%s", $$); } NUMBER;

%type <ast_node> Program Code PieceOfCode Type VarDecl VarDeclList Stmt StmtList Expr FunctList Funct Param ParamsList FunctBlock FunctCall CallParamsList StrucAccess

%start Program

%%

// program, the big kahuna, the whole program in a single node
Program: 
	Code { 
		$$ = $1;
		printf("\nEnd Program\n\n");
	}
;

// code is made up of pieces of code
Code:	
	PieceOfCode Code { 
		$1->data.binary_op.left = $2;
		$$ = $1;
	}
	// a piece of code
	| PieceOfCode {
		$$ = $1; 
	}
;

// the types of pieces of code
PieceOfCode:
	VarDeclList {
		$$ = $1;
	}
	| StmtList {
		$$ = $1;
	}
	| FunctList {
		$$ = $1
	}
;

// Value types
Type: 
	INT {
		$$ = astCreateType($1);
	}
	| CHAR {
		$$ = astCreateType($1);
	}
	| STRING {
		$$ = astCreateType($1);
	}
	| BOOL {
		$$ = astCreateType($1);
	}
;

// the function piece of code
FunctList:	
	// what the hell is a functt?
	FunctList Funct {
		$$ = $2;
	}
;

// a function
Funct:
	Type ID LPRN ParamsList RPRN FunctBlock {
		$$ = astCreateFunct($2, nodeToString($1), $4, $6);
	}
;

// parameters
ParamsList:
	ParamsList COMMA Param {
		$$ = $3;
	}
	| Param {
		$$ = $1
	}
	| "" {

	}
;

Param: 
	Type ID {
		$$ = astCreateFunctParam(nodeToString($1), $2);	
	}
;
	
FunctBlock:
	LCB PieceOfCode RCB SEMICOLON {
		$$ = $2;
		printf("\n RECOGNIZED RULE: Function Block %s\n", $2);
	}
;

FunctCall:
	ID LPRN CallParamsList RPRN {
		printf("\n RECOGNIZED RULE: Function Call\n", $1);
		// Check if function exists and generate the respective IR Code
		if(!found($1, currentScope)){
			printf("SEMANTIC ERROR: Function %s has not been declared\n", $1);
			semanticCheckPassed = 0;
		} else {
			printf("HELLO MR ANDERSON");
		}
		
	}

CallParamsList:
	CallParamsList COMMA Expr {
		$$ = $3;
	}
	| Expr {
		$$ = $1;
	}
	| "" {

	}

// struc access
StrucAccess:
	StrucAccess PERIOD ID {
		
	}
	| ID PERIOD ID {

	}

VarDeclList:
	VarDeclList VarDecl {
		
	}
	| VarDecl {
		
	}
// variable declaration piece of code
VarDecl:	
	Type ID SEMICOLON { 
		printf("\n RECOGNIZED RULE: Variable declaration %s\n", $2);
		// Symbol Table operations
		int inSymTab = found($2, currentScope);
		// semantic checks
		if (inSymTab == 0) {
			addItem($2, "Var", nodeToString($1), 0, currentScope);
			// AST operations
			$$ = astCreateVarDecl(nodeToString($1), $2);
		}
		else {
			printf("SEMANTIC ERROR: Var %s is already declared\n", $2);
		}
		showSymTable();
	}
	// ARRAY decvlaration. Automatically initialize all values to zero or null or whatever. So some type checking required.
	| Type ID LSB NUMBER RSB {
		printf("\n RECOGNIZED RULE: Array Declaration\n");
		
	}
	//struct decl
	| STRUC ID LCB VarDeclList RCB {
		printf("\n RECOGNIZED RULE: Struct Declaration\n");
		
	}
;

// statements, anything that involves operators, or isn't a function or vardecl
StmtList:	
	Stmt StmtList {
		
	}
;

Stmt:	
	// Literally just a semicolon
	SEMICOLON	
	// x = some math or something ;
	| ID ASS Expr SEMICOLON {
		printf("\n RECOGNIZED RULE: x = some math or something\n")
		// Semantic check
		// TODO implement type checking
		if (found($1, currentScope)) {
			$$ = astCreateVar($1);  

			char* result = generateTempVar()
			emitAssignment(result, nodeToString($3));

			// char* dante = generateTempReg();
			emitMIPSAssignment(result, nodeToString($3));
		} 
		else {
			printf("SEMANTIC ERROR: Var %s has not been declared\n", $1);
		}
		
	}
	// array assignment
	| ID LSB NUMBER RSB ASS Expr SEMICOLON {
		printf("\n RECOGNIZED RULE: ARRAY ASSIGNMENT\n")
	}
	// write x;
	| WRITE ID SEMICOLON {
		printf("\n RECOGNIZED RULE: WRITE statement\n");
		
		// Check if identifiers have been declared
		if(found($2, currentScope)) {
			emitWriteId($2);
			char* write = generateTempAddr();
			emitMIPSWriteId(write, $2);
		}
		else {
			printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $2, currentScope);
		}
	}
	| REEE Expr SEMICOLON {
		
	}
;

// some math or something
Expr:	
	// just a variable value for use in a statment
	ID { 
		printf("\n RECOGNIZED RULE: ID, %s\n", $1); 
		$$ = astCreateVar($1);
		char* result = generateTempVar();
		emitAssignment(result, $1);
	}
	// array variable
	| ID LSB NUMBER RSB {
		printf("\n RECOGNIZED RULE: Array Variable\n")
	}
	// function call
	| FunctCall {
		printf("\n RECOGNIZED RULE: Function Call\n")
	}
	// struc access. The period is the access operator
	// but how to nested strucs?
	| StrucAccess {
		printf("\n RECOGNIZED RULE: Struct Access\n")
	}
	// a number literal for use in a statement
	| NUMBER { 
		$$ = astCreateInt($1);
		printf("\n RECOGNIZED RULE: NUMBER, %s\n", $1); 
	}
	// x + some math or something
	| ID PLUS Expr {
		printf("\n RECOGNIZED RULE: ID PLUS Expr, ID is %s \n", $1);

		$$ = astCreateBinaryOp("+", astCreateVar($1), $3);

		// Check if identifiers have been declared
		if (!found($1, currentScope)) {
			printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
			semanticCheckPassed = 0;
		}
		
		// see if types are compatible, currently causing segfault cuz nodes
		// if (!compareTypes($1, $3, currentScope);) {
		// 	printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
		// 	semanticCheckPassed = 0;
		// }

		if (semanticCheckPassed) {
			//$$ = astCreateVar($1);

			char* result = generateTempVar();  // Generate a temporary variable for the result
			emitBinaryOperation("+", result, $1, nodeToString($3));
			emitMIPSBinaryOp(result, $1, nodeToString($3));
			$$ = astCreateVar(result);
			
		}		
	}
	| NUMBER PLUS Expr {
		printf("\n RECOGNIZED RULE: NUMBER PLUS Expr, %d \n", $1);
		
		$$ = astCreateBinaryOp("+", astCreateNumber($1), $3);
		
		// see if types are compatible, currently causing segfault cuz nodes
		// if (!compareTypes($1, $3, currentScope);) {
		// 	printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
		// 	semanticCheckPassed = 0;
		// }

		if (semanticCheckPassed) {
			char* result = generateTempVar();  // Generate a temporary variable for the result
			char* str = (char*)malloc(15);
			char* str1 = (char*)malloc(15);
			sprintf(str, "%d", $1);
			sprintf(str1, "%s", nodeToString($3));
			emitBinaryOperation("+", result, str, str1);
			emitMIPSBinaryOp(result, str, str1)
			// Update the current expression result
			$$ = astCreateVar(result);


		}
	}
;

%%
int main(int argc, char**argv)
{
/*
	#ifdef YYDEBUG
		yydebug = 1;
	#endif
*/
	printf("\n\n##### COMPILER STARTED #####\n\n");
	
	if (argc > 1){
	  if(!(yyin = fopen(argv[1], "r")))
          {
		perror(argv[1]);
		return(1);
	  }
	}

	// Initialize IR and MIPS files
	initIRcodeFile();
	initAssemblyFile();

	// Start parser
	yyparse();


	// initAssemblyFile();
	// Add the closing part required for any MIPS file
	emitEndOfAssemblyCode();

}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
