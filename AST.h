#include <string.h>
#include <stdio.h>
#include <stdlib.h>


typedef enum { NUM, BINARY_OP, PRINT, VAR_DECL, VAR } nodeType;

typedef struct node {
    nodeType type;
    union {
        char* var_id; // for VAR type, which is just a symbol.
        //char* var_connor;
        int value; // for NUM
        char* id; // for PRINT, might want to change this to a blanket node for all special keywords
        //char* connor;
        struct { // for VAR_DECL, using a blanket node for all value types for now
            char* type; 
            char* id;
            //char* connor;
        } var;
        struct { // for BINARY_OP
            char* IRCode;
            char* op; 
            struct node* left;
            struct node* right;
        } binary_op;
    } data;  
} node;

node* astCreateVar(char* id) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = VAR;
    new_node->data.var_id = id; 
    return new_node;
}


// node* astCreateConnor(char* connor) {
//     node* new_node = (node*)malloc(sizeof(node));
//     new_node->type = VAR;
//     new_node->data.var_connor = connor; 
//     return new_node;
// }

// for var declaration, takes type and id
node* astCreateVarDecl(char* type, char* id) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = VAR_DECL;
    new_node->data.var.type = type; 
    new_node->data.var.id = id;
    return new_node;
}

// binary operations
node* astCreateBinaryOp(char* op, node* left, node* right) { 
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = BINARY_OP;
    new_node->data.binary_op.op = op;  
    new_node->data.binary_op.left = left;  
    new_node->data.binary_op.right = right;  
    // construct IRcode here
    

    return new_node;
};

//

// numbers/ints
node* astCreateNumber(int value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = NUM;
    new_node->data.value = value; 
    return new_node;
};

// write keyword
node* astCreateWrite(char* id) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->type = PRINT;
    new_node->data.id = id; 
    return new_node;
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

char* nodeToString(node* n) {
    switch(n->type) {
        case NUM:
            {
                char* r = (char*)malloc(15); // overkill but eh
                if (!r) { // it's a good practice to check the result of malloc
                    return NULL;
                }
                sprintf(r, "%d", n->data.value);
                return r;
            }
        case BINARY_OP:
            return nodeToString(n->data.binary_op.left);
        case PRINT:
            return n->data.id;
        case VAR_DECL:
            return "VAR_DECL";
        case VAR:
            return n->data.var_id;
    }
    return NULL; // You should add a default return value for safety
}


void free_ast(node* root) {
    if (root == NULL) return;

    if (root->type == BINARY_OP) {
        free_ast(root->data.binary_op.left);  
        free_ast(root->data.binary_op.right);  
    }
    free(root);
};
