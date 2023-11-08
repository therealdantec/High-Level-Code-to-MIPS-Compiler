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
char* currentScope = "global"; // "global" or the name of the function
int semanticCheckPassed = 1; // flags to record correctness of semantic checks
%}


%union {
	int number;
	char character;
	char* string;
	struct node* ast_node;
}

%token <string> INT CHAR STRING BOOL STRUC FUNCT
%token <string> ID NUMBER
%token <string> SEMICOLON COMMA UNDERSCORE PERIOD
%token <string> LT GT 
%token <string> LTE GTE NE AND OR EQ
%token <string> ASS
%token <string> WRITE REEE
%token <string> PLUS MINUS TIMES DIVIDE
%token <string> LPRN RPRN LCB RCB LSB RSB
%type <string> DeclareFunct

%printer { fprintf(yyoutput, "%s", $$); } ID;
%printer { fprintf(yyoutput, "%s", $$); } NUMBER;

%type <ast_node> Program Code Type VarDecl Expr Stmt Param ParamsList FunctCall CallParamsList StrucAccess

%start Program

%%

// program, the big kahuna, the whole program in a single node
Program: 
	// function definition
	// FUNCT Type ID LPRN ParamsList RPRN LCB Code RCB SEMICOLON
	DeclareFunct Code RCB SEMICOLON { 
		printf("RULE Program: Function\n");
		// $$ = astCreateFunct($3, nodeToString($2), $5, $8);
		// IRfunction(nodeToString($2), $3);
		// emitMIPSFunction($3);
		emitMIPSjal();
	}
	| FunctCall SEMICOLON {
		printf("RULE Program: FunctCall\n");
		$$ = $1;
	}
	| Program Program {
		printf("RULE Program: Program Program\n");
		$$ = $1;
	}
	| {
		printf("RULE Program: EMPTY\n");
		$$ = NULL;
	}
;

DeclareFunct:
	FUNCT Type ID LPRN ParamsList RPRN LCB {
		printf("RULE Function: Function Declaration");
		IRfunction(nodeToString($2), $3);
		emitMIPSFunction($3);
		
	}
;

// the types of pieces of code
Code:
	Code VarDecl {
		printf("RULE Code: VarDecl\n");
		$$ = $1;
	}
	| Code Stmt {
		printf("RULE Code: Stmt\n");
		$$ = $1;
	}
	| {
		printf("RULE Code: EMPTY\n");
		$$ = NULL;
	}
;

// function call
FunctCall:
	ID LPRN CallParamsList RPRN {
		printf("RULE RECOGNIZED: FunctCall\n");
		callIRfunction($1);
		$$ = $3;
	}
;

// Value types
Type: 
	INT {
		printf("RULE Type: INT\n");
		$$ = astCreateType($1);
	}
	| CHAR {
		printf("RULE Type: CHAR\n");
		$$ = astCreateType($1);
	}
	| STRING {
		printf("RULE Type: STRING\n");
		$$ = astCreateType($1);
	}
	| BOOL {
		printf("RULE Type: BOOL\n");
		$$ = astCreateType($1);
	}
;

// parameters
ParamsList:
	ParamsList COMMA Param {
		printf("RULE ParamsList: ParamsList COMMA Param\n");
		$$ = $3;
	}
	| Param {
		printf("RULE ParamsList: Param\n");
		$$ = $1;
	}
	| {
		printf("RULE ParamsList: EMPTY\n");
		$$ = NULL;
	}
;

Param: 
	Type ID {
		printf("RULE Param: ID=%s\n", $2);
		$$ = astCreateFunctParam(nodeToString($1), $2);	

	}
;

CallParamsList:
	CallParamsList COMMA Expr {
		printf("RULE CallParamsList: CallParamsList COMMA Expr\n");
		$$ = $3;
	}
	| Expr {
		printf("RULE CallParamsList: Expr\n");
		$$ = $1;
	}
	| {
		printf("RULE CallParamsList: EMPTY\n");
		$$ = NULL;
	}
;

// // struc access
StrucAccess:
	StrucAccess PERIOD ID {
		printf("RULE StructAccess: StrucAccess PERIOD ID\n");
	}
	| ID PERIOD ID {
		printf("RULE StructAccess: ID PERIOD ID\n");
	}
;



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
	| Type ID LSB Expr RSB SEMICOLON {
		printf("\n RECOGNIZED RULE: Array Declaration\n");

		//Semantic check
		int inSymTab = found($2, currentScope);

		if (inSymTab == 0){
			addItem($2, "Arr", nodeToString($1), $4, currentScope);

			IRarray($2, nodeToString($1), nodeToString($4));

			// Add to AST. Null for now
			$$ = NULL;

		}
		else {
			printf("SEMANTIC ERROR: Arr %s is already declared\n", $2);
		}

		showSymTable();

	}
	//struct decl
	| STRUC ID LCB VarDecl RCB {
		printf("\n RECOGNIZED RULE: Struct Declaration\n");
		IRstruct($2, $4);
	}
;


Stmt:
	ID ASS Expr SEMICOLON {
		printf("\n RULE ID ASS Expr SEMICOLON\n");
		// Semantic check
		// TODO implement type checking
		if (found($1, currentScope)) {
			$$ = astCreateVar($1);  

			char* result = generateTempVar();
			emitAssignment(result, nodeToString($3));

			emitMIPSAssignment(result, nodeToString($3));
		} 
		else {
			printf("SEMANTIC ERROR: Var %s has not been declared\n", $1);
		}
		
	}
	// array assignment
	| ID LSB NUMBER RSB ASS Expr SEMICOLON {
		printf("\n RECOGNIZED RULE: ARRAY ASSIGNMENT\n");
		char* arrayRef;
		sprintf(arrayRef, "%s[%s]", $1, $3);
		$$ = astCreateVar(arrayRef);
	}
	// write x;
	| WRITE ID SEMICOLON {
		printf("\n RECOGNIZED RULE: WRITE statement\n");
		
		// Check if identifiers have been declared
		if(found($2, currentScope)) {
			emitWriteId($2);
			char* write = generateTempAddr();
			emitMIPSWriteId(write, $2);
			$$ = astCreateWrite($2);
		}
		else {
			printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $2, currentScope);
		}
	}
	// return keyword returns node* to expr value
	| REEE Expr SEMICOLON {
		$$ = astCreateReee(nodeToString($2));
	}
;

// some math or something
Expr:	
	// just a variable value for use in a statment
	ID { 
		printf("\n RECOGNIZED RULE: ID, %s\n", $1); 
		$$ = astCreateVar($1);
		// char* result = generateTempVar();
		// emitAssignment(result, $1);
	}
	// array variable
	| ID LSB NUMBER RSB {
		printf("\n RECOGNIZED RULE: Array Variable\n");
	}
	// function call
	| FunctCall {
		printf("\n RECOGNIZED RULE: Function Call\n");
	}
	// struc access. The period is the access operator
	// but how to nested strucs?
	| StrucAccess {
		printf("\n RECOGNIZED RULE: Struct Access\n");
	}
	// a number literal for use in a statement
	| NUMBER { 
		printf("\n RECOGNIZED RULE: NUMBER, %s\n", $1); 
		$$ = astCreateInt($1);
	}
	// x + some math or something
	| ID PLUS Expr {
		printf("\n RECOGNIZED RULE: ID PLUS Expr, ID is %s \n", $1);

		

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


		// this is some wizard temp register shit
		if (semanticCheckPassed) {
			//$$ = astCreateVar($1);
			$$ = astCreateBinaryOp("+", astCreateVar($1), $3);
			char* result = generateTempVar();  // Generate a temporary variable for the result
			emitBinaryOperation("+", result, $1, nodeToString($3));
			emitMIPSBinaryOp("add", result, $1, nodeToString($3));
			$$ = astCreateVar(result);
			
		}		
	}
	| NUMBER PLUS Expr {
		printf("\n RECOGNIZED RULE: NUMBER PLUS Expr, %s\n", $1);
		
		// see if types are compatible, currently causing segfault cuz nodes
		// if (!compareTypes($1, $3, currentScope);) {
		// 	printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
		// 	semanticCheckPassed = 0;
		// }

		if (semanticCheckPassed) {
			char* result = generateTempVar();  // Generate a temporary variable for the result
			char* str = (char*)malloc(15);
			char* str1 = (char*)malloc(15);
			sprintf(str, "%s", $1);
			sprintf(str1, "%s", nodeToString($3));
			emitBinaryOperation("+", result, str, str1);
			emitMIPSBinaryOp("add", result, str, str1);
			// Update the current expression result
			$$ = astCreateVar(result);
			$$ = astCreateBinaryOp("+", astCreateInt($1), $3);
		}
	}
	| ID MINUS Expr {
		printf("\n RECOGNIZED RULE: ID PLUS Expr, ID is %s \n", $1);

		

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


		// this is some wizard temp register shit
		if (semanticCheckPassed) {
			//$$ = astCreateVar($1);
			$$ = astCreateBinaryOp("-", astCreateVar($1), $3);
			char* result = generateTempVar();  // Generate a temporary variable for the result
			emitBinaryOperation("-", result, $1, nodeToString($3));
			emitMIPSBinaryOp("sub", result, $1, nodeToString($3));
			//$$ = astCreateVar(result);
			
		}		
	}
	| NUMBER MINUS Expr {
		printf("\n RECOGNIZED RULE: NUMBER PLUS Expr, %s\n", $1);
		
		// see if types are compatible, currently causing segfault cuz nodes
		// if (!compareTypes($1, $3, currentScope);) {
		// 	printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
		// 	semanticCheckPassed = 0;
		// }

		if (semanticCheckPassed) {
			char* result = generateTempVar();  // Generate a temporary variable for the result
			char* str = (char*)malloc(15);
			char* str1 = (char*)malloc(15);
			sprintf(str, "%s", $1);
			sprintf(str1, "%s", nodeToString($3));
			emitBinaryOperation("-", result, str, str1);
			emitMIPSBinaryOp("sub", result, str, str1);
			// Update the current expression result
			//$$ = astCreateVar(result);
			$$ = astCreateBinaryOp("-", astCreateInt($1), $3);
		}
	}
	| ID TIMES Expr {
		printf("\n RECOGNIZED RULE: ID PLUS Expr, ID is %s \n", $1);

		

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


		// this is some wizard temp register shit
		if (semanticCheckPassed) {
			//$$ = astCreateVar($1);
			$$ = astCreateBinaryOp("*", astCreateVar($1), $3);
			char* result = generateTempVar();  // Generate a temporary variable for the result
			emitBinaryOperation("*", result, $1, nodeToString($3));
			emitMIPSBinaryOp("mult", result, $1, nodeToString($3));
			//$$ = astCreateVar(result);
			
		}		
	}
	| NUMBER TIMES Expr {
		printf("\n RECOGNIZED RULE: NUMBER PLUS Expr, %s\n", $1);
		
		// see if types are compatible, currently causing segfault cuz nodes
		// if (!compareTypes($1, $3, currentScope);) {
		// 	printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
		// 	semanticCheckPassed = 0;
		// }

		if (semanticCheckPassed) {
			char* result = generateTempVar();  // Generate a temporary variable for the result
			char* str = (char*)malloc(15);
			char* str1 = (char*)malloc(15);
			sprintf(str, "%s", $1);
			sprintf(str1, "%s", nodeToString($3));
			emitBinaryOperation("*", result, str, str1);
			emitMIPSBinaryOp("mult", result, str, str1);
			// Update the current expression result
			//$$ = astCreateVar(result);
			$$ = astCreateBinaryOp("*", astCreateInt($1), $3);
		}
	}
	| ID DIVIDE Expr {
		printf("\n RECOGNIZED RULE: ID PLUS Expr, ID is %s \n", $1);

		

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


		// this is some wizard temp register shit
		if (semanticCheckPassed) {
			//$$ = astCreateVar($1);
			$$ = astCreateBinaryOp("/", astCreateVar($1), $3);
			char* result = generateTempVar();  // Generate a temporary variable for the result
			emitBinaryOperation("/", result, $1, nodeToString($3));
			emitMIPSBinaryOp("div", result, $1, nodeToString($3));
			//$$ = astCreateVar(result);
			
		}		
	}
	| NUMBER DIVIDE Expr {
		printf("\n RECOGNIZED RULE: NUMBER PLUS Expr, %s\n", $1);
		
		// see if types are compatible, currently causing segfault cuz nodes
		// if (!compareTypes($1, $3, currentScope);) {
		// 	printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
		// 	semanticCheckPassed = 0;
		// }

		if (semanticCheckPassed) {
			char* result = generateTempVar();  // Generate a temporary variable for the result
			char* str = (char*)malloc(15);
			char* str1 = (char*)malloc(15);
			sprintf(str, "%s", $1);
			sprintf(str1, "%s", nodeToString($3));
			emitBinaryOperation("/", result, str, str1);
			emitMIPSBinaryOp("div", result, str, str1);
			// Update the current expression result
			//$$ = astCreateVar(result);
			$$ = astCreateBinaryOp("/", astCreateInt($1), $3);
		}
	}
;

// VarDeclList:
// 	VarDeclList VarDecl {
// 		printf("RULE VarDeclList: VarDeclList VarDecl\n");
// 		$$ = $2;
// 	}
// 	| VarDecl {
// 		printf("RULE VarDeclList: VarDecl\n");
// 		$$ = $1;
// 	}
// ;

// // statements, anything that involves operators, or isn't a function or vardecl
// StmtList:	
// 	Stmt StmtList {
// 		$$ = $2;
// 	}
// 	| Stmt {
// 		$$ = $1;
// 	}
// ;

%%
int main(int argc, char**argv)
{

	// #ifdef YYDEBUG
	// 	yydebug = 1;
	// #endif

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
