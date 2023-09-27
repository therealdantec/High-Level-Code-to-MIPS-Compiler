#ifndef IRCODE_H
#define IRCODE_H

// Define IR code structure
struct IRCode {
    char* operation;  // IR operation (e.g., "LOAD", "ADD", "WRITE")
    char* operand1;   // Operand 1
    char* operand2;   // Operand 2
    char* result;     // Result (temporary variable)
};

// Function to generate IR code
struct IRCode* generate_ir_code(struct ASTNode* ast, int* temp_var_counter);
void free_ir_code(struct IRCode* ir_code);

#endif