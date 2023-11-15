#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char* type; // the type of node
    union {
        char* var_id; // for VAR
        char* value; // for LITERALS
        char* data_type; // for DATA_TYPE
        char* id; // for PRINT, might want to change this to a blanket node for all special keywords
        struct { // for VAR_DECL
            char* type; 
            char* id;
        } var_decl;
         struct { // for FUNCT_PARAM
            char* type; 
            char* id;
        } funct_param;
        struct { // for BINARY_OP
            char* op; 
            struct node* left;
            struct node* right;
        } binary_op;
        struct { // for FUNCT
            char* id;
            char* return_type;
            struct node* params; // params
            struct node* funct_block; // block of code
        } funct;
        struct { // for ARRAY. shouldn't need to worry about type
            char* data_type;
            char* id;
            struct node** values;
        } array;
        struct { // for STRUC
            char* id;
            struct node** vars;
        } struc;
        struct { // for BOOL_EXPR
            char* op;
            struct node* left;
            struct node* right;
        } bool_expr;
    } data;  
} node;

node* astCreateType(char* data_type) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = "DATA_TYPE";
    new_node->data.data_type = data_type;
    return new_node;
};

node* astCreateFunct(char* id, char* return_type, node* params, node* functBlock) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = "FUNCT";
    new_node->data.funct.id = id;
    new_node->data.funct.return_type = return_type;
    new_node->data.funct.params = params;
    new_node->data.funct.funct_block = functBlock;
    return new_node;
};

node* astCreateFunctParam(char* type, char* id) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = "FUNCT_PARAM";
    new_node->data.funct_param.type = type;
    new_node->data.funct_param.id = id;
    return new_node;
};


node* astCreateArray() {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = "ARRAY";
    return new_node;
};

node* astCreateStruc() {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = "STRUC";
    return new_node;
};

node* astCreateVar(char* id) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = "VAR";
    new_node->data.var_id = id; 
    return new_node;
};

// for var declaration, takes type and id
node* astCreateVarDecl(char* type, char* id) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = "VAR_DECL";
    new_node->data.var_decl.type = type; 
    new_node->data.var_decl.id = id;
    return new_node;
};

// binary operations
node* astCreateBinaryOp(char* op, node* left, node* right) { 
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = "BINARY_OP";
    new_node->data.binary_op.op = op;  
    new_node->data.binary_op.left = left;  
    new_node->data.binary_op.right = right;   
    return new_node;
};

// int literal
node* astCreateInt(char* value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = "INT_LITERAL";
    new_node->data.value = value; 
    return new_node;
};

// char literal
node* astCreateChar(char* value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = "CHAR_LITERAL";
    new_node->data.value = value; 
    return new_node;
};

// string literal
node* astCreateString(char* value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = "STRING_LITERAL";
    new_node->data.value = value; 
    return new_node;
};

// bool literal
node* astCreateBool(char* value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = "BOOL_LITERAL";
    new_node->data.value = value; 
    return new_node;
};

// write keyword
node* astCreateWrite(char* id) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = "WRITE";
    new_node->data.id = id;
    return new_node;
};

// Function to create a return statement AST node
node* astCreateReee(char* value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = "REEE";
    new_node->data.value = value;
    return new_node;
}

node* astCreateBoolExpr(char* op, node* left, node* right) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = "BOOL_EXPR";
    new_node->data.bool_expr.op = op;
    new_node->data.bool_expr.left = left;
    new_node->data.bool_expr.right = right;
    return new_node;
}

// make a string out of the node
char* nodeToString(node* n) {
    if (strcmp(n->type, "INT_LITERAL") == 0)    return n->data.value;
    if (strcmp(n->type, "BOOL_LITERAL") == 0)    return n->data.value;
    if (strcmp(n->type, "CHAR_LITERAL") == 0)    return n->data.value;
    if (strcmp(n->type, "STRING_LITERAL") == 0)    return n->data.value;
    if (strcmp(n->type, "BINARY_OP") == 0)  return nodeToString(n->data.binary_op.left);
    if (strcmp(n->type, "WRITE") == 0)      return n->data.id;
    if (strcmp(n->type, "VAR_DECL") == 0)   return n->type;
    if (strcmp(n->type, "VAR") == 0)        return n->data.var_id;
    if (strcmp(n->type, "DATA_TYPE") == 0)        return n->data.data_type;
    if (strcmp(n->type, "FUNCT") == 0)        return n->data.funct.id;
    if (strcmp(n->type, "FUNCT_PARAM") == 0)        return n->data.funct_param.id;
    if (strcmp(n->type, "ARRAY") == 0)        return "ARRAY";
    if (strcmp(n->type, "STRUC") == 0)        return "STRUC";
};

// freeing da tree
void free_ast(node* root) {
    if (root == NULL) return;

    if (strcmp(root->type, "BINARY_OP") == 0) {
        free_ast(root->data.binary_op.left);  
        free_ast(root->data.binary_op.right);  
    }
    free(root);
};


// void print_ast(node* root) {
//     if (root == NULL) return;

//     if (root->type == NUM) {
//         printf("%d", root->data.value);  
//     } else if (root->type == BINARY_OP) {
//         printf("(");
//         print_ast(root->data.binary_op.left);  
//         printf(" %c ", root->data.binary_op.op);  
//         print_ast(root->data.binary_op.right);  
//         printf(")");
//     }
// };