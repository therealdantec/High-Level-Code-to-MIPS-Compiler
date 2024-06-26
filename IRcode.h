#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMP_VARS 100

// hi
FILE* IRcode = NULL;
int numIds;
int tempCounter = 0; // To generate temporary variable names

struct TempVarAssignment {
    char varName[100];
    int isAssigned;
};

struct TempVarAssignment tempAssignments[MAX_TEMP_VARS];

// Function to initialize IR code file
void initIRcodeFile() {
    IRcode = fopen("IRcode.ir", "w");
    fprintf(IRcode, "\n\n#### IR Code ####\n\n");
}

// Function to close IR code file
void closeIRcodeFile() {
    if (IRcode != NULL) {
        fclose(IRcode);
    }
}

// Function to generate a unique temporary variable name
char* generateTempVar() {
    char tempVarName[100]; // Adjust the size as needed
    snprintf(tempVarName, sizeof(tempVarName), "$t%d", tempCounter++);
    return strdup(tempVarName);
}

// Function to emit binary operation with arbitrary number of IDs
void emitBinaryOperation(char* op, char* reg, char* id1, char* id2) {
    fprintf(IRcode, "%s = %s %s %s\n", reg, id1, op, id2);
}

// Function to emit assignment
void emitAssignment(char* id1, char* value) {
    fprintf(IRcode, "%s = %s\n", id1, value);
}

// Function to emit constant assignment
void emitConstantIntAssignment(char* id, char* value) {
    fprintf(IRcode, "%s = %s\n", id, value);
}

// Function to emit output
void emitWriteId(char* id) {
    fprintf(IRcode, "print %s\n", id);
}

// Function to emit input
void emitReadId(char* id) {
    fprintf(IRcode, "input %s\n", id);
}

// Function to emit label
void emitLabel(char* label) {
    fprintf(IRcode, "%s:\n", label);
}

// Function to create IR code for a function name and type
void IRfunction(char* type, char* name){
    fprintf(IRcode, "\nFunction: %s %s\n", type, name);
}

void callIRfunction(char* name){
    fprintf(IRcode, "\nCalling Function %s\n", name);
}

void IRarray(char* name, char* type, char* size){
    fprintf(IRcode, "DECLARE ARRAY: Name %s, Type %s, Size %s\n", name, type, size);
}

void IRstruct(char* name, char* tings){
    fprintf(IRcode, "STRUCT %s { \n%s\n}\n", name, tings);

}

void IR_Boolean(char* boolexpr, char* expr1, char* expr2){
    fprintf(IRcode, "BOOLEAN EXPRESSION: %s %s %s\n", expr1, boolexpr, expr2);
}

void IR_Loop(char* name, char* expr1, char* expr2, char* op){
    fprintf(IRcode, "LOOP: %s %s %s %s\n", name, expr1, op, expr2);
}