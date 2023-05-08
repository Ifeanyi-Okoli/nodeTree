#include <stdio.h>
#include <stdlib.h>

typedef struct Node //using struct named Node to define the tree data structure
{
    int value;
    int calculated;
    char op;    //operator
    struct Node* left;  //node left pointer
    struct Node* right; // node right pointer
} Node;

//Define an enum to represent the type of operation to be performed
typedef enum TypeTag {
    ADD,
    MUL,
    SUB
} TypeTag;

//Function to create a new node with the specified operation type
Node* makeFunc(TypeTag type) {
    //Allocate memory for a new node
    Node* node = (Node*) malloc(sizeof(Node));
    node->calculated = 0;   // set calculated flag to 0
    node->left = NULL;  //set left pointer to NULL
    node->right = NULL; //set right pointer to Null

    //set the operator based on the specified operation type
    switch(type) {
        case ADD:
            node->op = '+';
            break;
        case MUL:
            node->op = '*';
            break;
        case SUB:
            node->op = '-';
            break;
        default:
            break;
    }
    return node;
}
//Fnction to calculate the value of a node
int calc(Node* node) {
    //if the node has already been calculated, return the value of the node
    if (node->calculated) {
        return node->value;
    }

    //calculate the value of the left and right nodes, if they exist
    int left = 0;
    int right = 0;
    if (node->left != NULL) {
        left = calc(node->left);
    }
    if (node->right != NULL) {
        right = calc(node->right);
    }

    //perform operation based on the operator of the node
    switch (node->op) {
        case '+':
            node->value = left + right;
            break;
        case '-':
            node->value = left - right;
            break;
        case '*':
            node->value = left * right;
            break;
        default:
            break;
    }
    node->calculated = 1;   //set calculated flag to 1
    return node->value;
}

// Function to calculate the nth Fibonacci numberusing a tree structure
int fibonacci(int n) {
    // Create a node representing the addition operation with operands 1 and 0
    Node* add = makeFunc(ADD);
    add->left = makeFunc(1);
    add->right = makeFunc(0);

    Node* fib = add;    //initialize fib node

    //Create a tree structure representing the Fibonacci sequence up to the nth term.
    int i;
    for (i = 2; i <= n; i++) {
        Node* next = makeFunc(ADD);
        next->left = fib;
        next->right = add;
        fib = next;
        calc(fib);
    }

    // Calculate the value of the nth Fibonacci number
    int result = calc(fib);
    // Free memory allocated for nodes
    free(add);
    free(fib);

    return result;
}

int main() {
    //Create nodes representing addition, multiplication, and subtraction operations
    Node* add = makeFunc(ADD);
    add->left = makeFunc(10);
    add->right = makeFunc(6);

    Node* mul = makeFunc(MUL);
    mul->left = makeFunc(5);
    mul->right = makeFunc(4);

    Node* sub = makeFunc(SUB);
    sub->left = mul;
    sub->right = add;

    Node* fibo = makeFunc(SUB);
    fibo->left = sub;
    fibo->right = NULL;

    printf("add : %d\n", calc(add));
    printf("mul : %d\n", calc(mul));
    printf("sub : %d\n", calc(sub));
    printf("fibo : %d\n", fibonacci(calc(fibo)));

    free(add);
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}


