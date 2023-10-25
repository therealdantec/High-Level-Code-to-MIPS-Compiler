#include <string.h>
#include <stdio.h>
#include <stdlib.h>


//typedef enum { INT, BINARY_OP, PRINT, VAR_DECL, VAR, FUNCT } nodeType;

typedef struct node {
    char* type; // the type of node
    union {
        char* var_id; // for VAR
        char* value; // for
        char* id; // for PRINT, might want to change this to a blanket node for all special keywords
        struct { // for VAR_DECL, using a blanket node for all value types
            char* type; 
            char* id;
        } var_decl;
        struct { // for BINARY_OP
            char* op; 
            struct node* left;
            struct node* right;
        } binary_op;
        struct { // for FUNCT
            char* id;
            char* return_type;
            struct node* left; // params
            struct node* right; // block of code
        } funct;
    } data;  
} node;

node* astCreateVar(char* id) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = "VAR";
    new_node->data.var_id = id; 
    return new_node;
}

// for var declaration, takes type and id
node* astCreateVarDecl(char* type, char* id) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = "VAR_DECL";
    new_node->data.var_decl.type = type; 
    new_node->data.var_decl.id = id;
    return new_node;
}

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
}

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