#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// Set of functions to emit MIPS code
FILE * MIPScode;
int tempCounter1 = 0;
int tempCounter2 = 0;

void  initAssemblyFile(){
    // Creates a MIPS file with a generic header that needs to be in every file

    MIPScode = fopen("MIPScode.asm", "a");
    
    fprintf(MIPScode, ".text\n");
    fprintf(MIPScode, "main:\n");
    fprintf(MIPScode, "# -----------------------\n");

}

// Function to generate a unique temporary register name
char* generateTempReg() {
    char tempRegName[15]; // Adjust the size as needed
    snprintf(tempRegName, sizeof(tempRegName), "$t%d", tempCounter1++);
    return strdup(tempRegName);
}

// Function to generate a unique temporary address name
char* generateTempAddr() {
    char tempAddrName[15]; // Adjust the size as needed
    snprintf(tempAddrName, sizeof(tempAddrName), "$a%d", tempCounter2++);
    return strdup(tempAddrName);
}

void emitMIPSAssignment(char * id1, char * id2){
  // This is the temporary approach, until register management is implemented

  fprintf(MIPScode, "lw %s, %s\n", id1, id2);
  // fprintf(MIPScode, "li %s, %s\n", dante, id2);
  // fprintf(MIPScode, "sw %s, %s\n", dante, id1);

}

void emitMIPSBinaryOp(char* op, char* xyz, char* id4, char* id3){
    fprintf(MIPScode, "%s %s, %s, %s\n", op, xyz, id4, id3);
}

void emitMIPSFunction(char* name){
    fprintf(MIPScode, "Function %s\n", name);
}

void emitMIPSjal(){
    fprintf(MIPScode, "jal\n");
}

void emitMIPSConstantIntAssignment(char id1[50], char id2[50]){
     // This is the temporary approach, until register management is implemented
     // The parameters of this function should inform about registers
     // For now, this is "improvised" to illustrate the idea of what needs to 
     // be emitted in MIPS

     // nextRegister = allocateRegister(id1);  // This is conceptual to inform what needs to be done later

    fprintf(MIPScode, "li $t0, %s\n", id2);
}

void emitMIPSWriteId(char* regi, char * id){
    // This is what needs to be printed, but must manage registers
    // $a0 is the register through which everything is printed in MIPS
    
    fprintf(MIPScode, "lw %s, %s\n", regi, id);
    fprintf(MIPScode, "li $v0, 1\n");
    fprintf(MIPScode, "syscall\n");
}

void emitEndOfAssemblyCode(){
    fprintf(MIPScode, "# -----------------\n");
    fprintf(MIPScode, "#  Done, terminate program.\n\n");
    fprintf(MIPScode, "li $v0,1   # call code for terminate\n");
    fprintf(MIPScode, "syscall      # system call (terminate)\n");
    fprintf(MIPScode, "li $v0,10   # call code for terminate\n");
    fprintf(MIPScode, "syscall      # system call (terminate)\n");
    fprintf(MIPScode, ".end main\n");
}