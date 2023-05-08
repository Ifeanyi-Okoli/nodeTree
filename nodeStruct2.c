#include <stdio.h>

typedef struct {
    int (*func)(int, int); // function pointer to arithmetic operation
    int arg1; // first argument to operation
    int arg2; // second argument to operation
} node;

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    if (b == 0) {
        printf("Error: division by zero\n");
        return 0;
    }
    return a / b;
}

int fibo(int n) {
    if (n < 2) {
        return n;
    }
    return fibo(n-1) + fibo(n-2);
}

void calc(node n) {
    int result = n.func(n.arg1, n.arg2);
    printf("Result: %d\n", result);
}

int main() {
    node add_node = {add, 10, 6};
    node mul_node = {mul, 5, 4};
    node sub_node1 = {sub, mul_node.func(mul_node.arg1, mul_node.arg2), add_node.func(add_node.arg1, add_node.arg2)};
    node sub_node2 = {sub, sub_node1.func(sub_node1.arg1, sub_node1.arg2), 0};
    node fibo_node = {fibo, sub};
    
    calc(add_node);
    calc(mul_node);
    calc(sub_node1);
    calc(sub_node2);
    calc(fibo_node);
    
    return 0;
}
