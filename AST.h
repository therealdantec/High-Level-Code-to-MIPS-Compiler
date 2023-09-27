#ifndef AST_H
#define AST_H

// Define AST node types
enum ASTNodeType {
    AST_VARIABLE,
    AST_CONSTANT,
    AST_BINARY_OPERATION,
    AST_WRITE_STATEMENT,
};

// AST node structure
struct ASTNode {
    enum ASTNodeType type;
    union {
        char* variable_name; // For variables
        int constant_value;  // For constants
        struct {
            char op;  // Operator (+, -, , etc.)
            struct ASTNode* left;
            struct ASTNode* right;
        } binary_operation;  // For binary operations
    } data;
};

// Function to create different types of AST nodes
struct ASTNode* create_variable_node(const char* variable_name);
struct ASTNode* create_constant_node(int constant_value);
struct ASTNode* create_binary_operation_node(char op, struct ASTNode* left, struct ASTNode* right);
void free_ast(struct ASTNode* root);

#endif