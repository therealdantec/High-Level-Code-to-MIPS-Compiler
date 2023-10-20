#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// hi
FILE* IRcode = NULL;
int numIds;
int tempCounter = 0; // To generate temporary variable names

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
    char tempVarName[15]; // Adjust the size as needed
    snprintf(tempVarName, sizeof(tempVarName), "T%d", tempCounter++);
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
    fprintf(IRcode, "output %s\n", id);
}

// Function to emit input
void emitReadId(char* id) {
    fprintf(IRcode, "input %s\n", id);
}

// Function to emit label
void emitLabel(char* label) {
    fprintf(IRcode, "%s:\n", label);
}

