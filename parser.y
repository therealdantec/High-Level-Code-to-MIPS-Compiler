%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbolTable.h"
#include "AST.h"
#include "IRcode.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;

FILE * IRcode;


void yyerror(const char* s);
char* currentScope = "global"; // "global" or the name of the function
int semanticCheckPassed = 1; // flags to record correctness of semantic checks

// Function to call OpenAI API and get MIPS code
char* generateMIPSFromIR(char* irCode) {
    // Use your OpenAI API key
    const char* apiKey = "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";  // Replace with your actual API key

    // Construct the command to call the Python script (assuming it's a separate script)
    char command[1000];
	printf("LOOK AT THIS SUPER COOL IR CODE: %s\n", irCode);
    snprintf(command, sizeof(command), "python3 OpenAI_API.py \"%s\" \"%s\"", apiKey, irCode);
	printf("%s\n", command);

    // Execute the command and capture the output
    FILE* pipe = popen(command, "r");
    if (!pipe) {
        perror("popen");
        exit(EXIT_FAILURE);
    }

	char buffer[4096];
	char* result = malloc(1); // Start with a small buffer
	result[0] = '\0'; // Null-terminate the empty string
	size_t len = 0;

	while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
		len += strlen(buffer);
		result = realloc(result, len + 1); // Resize the result buffer
		strcat(result, buffer); // Append the new line
	}

    // Close the pipe
    pclose(pipe);

    return result;
}
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
%token <string> LTE GTE NE AND OR EQ TRUTH FALSITY
%token <string> ASS
%token <string> WRITE REEE IF ELSE SWITCH CASE WHILE REPEAT UNTIL
%token <string> PLUS MINUS TIMES DIVIDE
%token <string> LPRN RPRN LCB RCB LSB RSB
%type <string> DeclareFunct

%printer { fprintf(yyoutput, "%s", $$); } ID;
%printer { fprintf(yyoutput, "%s", $$); } NUMBER;

%type <ast_node> Program Code Type VarDecl Expr Stmt Param ParamsList FunctCall CallParamsList StrucAccess SwitchBlock ElseBlock BoolExpr

%start Program

%%

// program, the big kahuna, the whole program in a single node
Program: 

	// function definition
	// FUNCT Type ID LPRN ParamsList RPRN LCB Code RCB SEMICOLON
	DeclareFunct Code RCB SEMICOLON { 
		printf("RULE Program: Function\n");
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
			addItem($2, "Arr", nodeToString($1), atoi(nodeToString($4)), currentScope);

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
		IRstruct($2, nodeToString($4));
	}
;

SwitchBlock:
	SwitchBlock CASE Expr LCB Code RCB {
		printf("\n RECOGNIZED RULE: SwitchBlock: SwitchBlock CASE Expr LCB Code RCB\n");
		$$ = astCreateSwitchBlock($1, $3, $5);
	}
	| {
		printf("\n RECOGNIZED RULE: SwitchBlock: EMPTY\n");
		$$ = NULL;
	}
;

ElseBlock:
	ELSE LCB Code RCB {
		printf("\n RECOGNIZED RULE: ElseBlock: ELSE LCB Code RCB\n");
		$$ = $3;
	}
	| {
		printf("\n RECOGNIZED RULE: ElseBlock: EMPTY\n");
		$$ = NULL;
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
	// if statement
	| IF LPRN BoolExpr RPRN LCB Code RCB ElseBlock {
		printf("\n RECOGNIZED RULE: Stmt: IF LPRN BoolExpr RPRN LCB Code RCB ElseBlock\n");
		$$ = astCreateIfElse($3, $6, $8);
	}
	// switch statment
	| SWITCH LPRN Expr RPRN LCB SwitchBlock Code RCB {
		printf("\n RECOGNIZED RULE: SWITCH STATEMENT\n");
		$$ = astCreateSwitchStmt($3, $6, $7);
	}
	// while loop
	| WHILE LPRN BoolExpr RPRN LCB Code RCB {
		printf("\n RECOGNIZED RULE: WHILE LOOP\n");
		$$ = astCreateLoop($3, $6);
	}
	// repeat until loop
	| REPEAT LCB Code RCB UNTIL LPRN BoolExpr RPRN {
		printf("\n RECOGNIZED RULE: REPEAT STATEMENT\n");
		$$ = astCreateLoop($7, $3);
	}
;


// some math or somethingdd
Expr:	
	// just a variable value for use in a statment
	ID { 
		printf("\n RECOGNIZED RULE: ID, %s\n", $1); 
		$$ = astCreateVar($1);
	}
	// array variable
	| ID LSB NUMBER RSB {
		printf("\n RECOGNIZED RULE: Array Variable\n");
	}
	// function call
	| FunctCall {
		printf("\n RECOGNIZED RULE: Function Call\n");
		$$ = $1;
	}
	// struc access. The period is the access operator
	// but how to nested strucs?
	| StrucAccess {
		printf("\n RECOGNIZED RULE: Struct Access\n");
		$$ = $1;
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
		
		// this is some wizard temp register shit
		if (semanticCheckPassed) {
			$$ = astCreateBinaryOp("+", astCreateVar($1), $3);
			char* result = generateTempVar();  // Generate a temporary variable for the result
			emitBinaryOperation("+", result, $1, nodeToString($3));
			$$ = astCreateVar(result);
			
		}		
	}
	| NUMBER PLUS Expr {
		printf("\n RECOGNIZED RULE: NUMBER PLUS Expr, %s\n", $1);

		if (semanticCheckPassed) {
			char* result = generateTempVar();  // Generate a temporary variable for the result
			char* str = (char*)malloc(15);
			char* str1 = (char*)malloc(15);
			sprintf(str, "%s", $1);
			sprintf(str1, "%s", nodeToString($3));
			emitBinaryOperation("+", result, str, str1);
			// Update the current expression result
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

		// this is some wizard temp register shit
		if (semanticCheckPassed) {
			$$ = astCreateBinaryOp("-", astCreateVar($1), $3);
			char* result = generateTempVar();  // Generate a temporary variable for the result
			emitBinaryOperation("-", result, $1, nodeToString($3));
		}		

	}
	| NUMBER MINUS Expr {
		printf("\n RECOGNIZED RULE: NUMBER PLUS Expr, %s\n", $1);
		
		if (semanticCheckPassed) {
			char* result = generateTempVar();  // Generate a temporary variable for the result
			char* str = (char*)malloc(15);
			char* str1 = (char*)malloc(15);
			sprintf(str, "%s", $1);
			sprintf(str1, "%s", nodeToString($3));
			emitBinaryOperation("-", result, str, str1);
			// Update the current expression result
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


		// this is some wizard temp register shit
		if (semanticCheckPassed) {
			$$ = astCreateBinaryOp("*", astCreateVar($1), $3);
			char* result = generateTempVar();  // Generate a temporary variable for the result
			emitBinaryOperation("*", result, $1, nodeToString($3));
			
		}		
	}
	| NUMBER TIMES Expr {
		printf("\n RECOGNIZED RULE: NUMBER PLUS Expr, %s\n", $1);

		if (semanticCheckPassed) {
			char* result = generateTempVar();  // Generate a temporary variable for the result
			char* str = (char*)malloc(15);
			char* str1 = (char*)malloc(15);
			sprintf(str, "%s", $1);
			sprintf(str1, "%s", nodeToString($3));
			emitBinaryOperation("*", result, str, str1);
			// Update the current expression result
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


		// this is some wizard temp register shit
		if (semanticCheckPassed) {
			$$ = astCreateBinaryOp("/", astCreateVar($1), $3);
			char* result = generateTempVar();  // Generate a temporary variable for the result
			emitBinaryOperation("/", result, $1, nodeToString($3));
		}	

	}
	| NUMBER DIVIDE Expr {
		printf("\n RECOGNIZED RULE: NUMBER PLUS Expr, %s\n", $1);
		
		if (semanticCheckPassed) {
			char* result = generateTempVar();  // Generate a temporary variable for the result
			char* str = (char*)malloc(15);
			char* str1 = (char*)malloc(15);
			sprintf(str, "%s", $1);
			sprintf(str1, "%s", nodeToString($3));
			emitBinaryOperation("/", result, str, str1);
			// Update the current expression result
			$$ = astCreateBinaryOp("/", astCreateInt($1), $3);
		}
	}
;

//LT GT LTE GTE NE AND OR EQ 
BoolExpr:
	Expr LT Expr {
		printf("\n RECOGNIZED RULE: BoolExpr: Expr LT Expr\n");
		$$ = astCreateBinaryOp($2, $1, $3);
	}
	| Expr GT Expr{
		printf("\n RECOGNIZED RULE: BoolExpr: Expr GT Expr\n");
		$$ = astCreateBinaryOp($2, $1, $3);
	}
	| Expr LTE Expr{
		printf("\n RECOGNIZED RULE: BoolExpr: Expr LTE Expr\n");
		$$ = astCreateBinaryOp($2, $1, $3);
	}
	| Expr GTE Expr{
		printf("\n RECOGNIZED RULE: BoolExpr: Expr GTE Expr\n");
		$$ = astCreateBinaryOp($2, $1, $3);
	}
	| Expr NE Expr{
		printf("\n RECOGNIZED RULE: BoolExpr: Expr NE Expr\n");
		$$ = astCreateBinaryOp($2, $1, $3);
	}
	| Expr EQ Expr{
		printf("\n RECOGNIZED RULE: BoolExpr: Expr EQ Expr\n");
		$$ = astCreateBinaryOp($2, $1, $3);
	}
	| BoolExpr AND BoolExpr{
		printf("\n RECOGNIZED RULE: BoolExpr: BoolExpr AND BoolExpr\n");
		$$ = astCreateBinaryOp($2, $1, $3);
	}
	| BoolExpr OR BoolExpr{
		printf("\n RECOGNIZED RULE: BoolExpr: BoolExpr OR BoolExpr\n");
		$$ = astCreateBinaryOp($2, $1, $3);
	}
;

%%
int main(int argc, char**argv)
{

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

	// Start parser
	yyparse();

	closeIRcodeFile();

	// Read the generated IR code from the file
	FILE* irFile = fopen("IRcode.ir", "r");
	char* irCode;
	long irFileSize;

	if (irFile == NULL) {
		perror("IRcode.ir");
		printf("IR file not opened\n");
		exit(EXIT_FAILURE);
	}

	fseek(irFile, 0, SEEK_END);
	irFileSize = ftell(irFile);
	rewind(irFile);

	irCode = malloc(irFileSize + 1);

	if (irCode == NULL) {
		perror("malloc");
		printf("malloc didn't work\n");
		exit(EXIT_FAILURE);
	}

	fread(irCode, sizeof(char), irFileSize, irFile);
	irCode[irFileSize] = '\0';

	fclose(irFile);

	// Print IR code for debugging
	printf("IR Code:\n%s\n", irCode);

	// Call OpenAI API to convert IR to MIPS
	char* mipsCode = generateMIPSFromIR(irCode);

	// Print MIPS code for debugging
	printf("MIPS Code:\n%s\n", mipsCode);

	// Write MIPS code to a file
	FILE* mipsFile = fopen("MIPS_Code.asm", "w");
	if (!mipsFile) {
		perror("MIPS_Code.asm");
		exit(EXIT_FAILURE);
	}

	fprintf(mipsFile, "%s", mipsCode);

	fclose(mipsFile);

	// Cleanup allocated memory
	free(irCode);
	free(mipsCode);

    printf("\n##### COMPILER FINISHED #####\n");

	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
