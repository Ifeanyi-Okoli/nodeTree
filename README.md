# Node Structure

DEVELOPMENT ENVIRONMENT AND HOW TO COMPILE AND RUN THE SOURCE CODE
The development environment is Visual Studio 2017. The source code is written in C.
The development environmen refers to the tools and software used to write, compile and debug the source code. It can be set up using IDE and a compiler.

For this project, I followed the following steps to set up the development environment:

1. I installed Visual Studio Code
2. I installed C/C++ extension for Visual Studio Code
3. I installed MinGW-w64 - for 32 and 64 bit Windows
4. I created a new folder named Fibonacci
5. I created a new file named README.md
6. I created a new file named recursivefxn.c inside the directory.
7. In the created file, I wrote the codes for recursive, memoization and iterative methods.
8. I ran the code.
9. The program returns the corresponding value of the sequence.

In summary, the development environment for C programming on Windows requires an IDE or a text editor for writing the code, a C compiler for compiling the code, and a debugger for debugging the code. Once the source code is written, you can compile and run it using the command prompt or the IDE, and debug it using a debugger tool.


nodeStruct1: This is a C program that defines a tree data structure and uses it to perform calculations for arithmetic operations and calculate the nth Fibonacci number.

The source code defines a tree data structure and uses it to perform calculations for arithmetic operations and calculate the nth Fibonacci number.

The tree data structure is defined using a struct named "Node" which has the following fields:

"value": an integer value that represents the calculated value of the node
"calculated": a flag that indicates whether the value of the node has been calculated
"op": a character that represents the operation to be performed by the node
"left" and "right": pointers to the left and right children of the node respectively.
The code also defines an enum named "TypeTag" which represents the type of operation to be performed. The three types of operations defined in the enum are "ADD", "MUL", and "SUB", which correspond to addition, multiplication, and subtraction respectively.

The code then defines a function "makeFunc" which takes an argument of type "TypeTag" and returns a new node with the specified operation type. This function allocates memory for the new node, initializes its fields, and sets the operator based on the specified operation type.

The code also defines a function "calc" which takes a node as input and calculates its value by performing the operation specified by its operator. If the node has already been calculated, it returns its value directly. Otherwise, it recursively calculates the values of its left and right children, performs the operation specified by its operator, and sets the calculated flag to 1.

The function "fibonacci" uses the "makeFunc" and "calc" functions to calculate the nth Fibonacci number using a tree structure. It initializes a node "add" representing the addition operation with operands 1 and 0. It then creates a tree structure representing the Fibonacci sequence up to the nth term, where each node represents the addition of its left and right children. The value of the nth Fibonacci number is then calculated by calling the "calc" function on the root node of the tree.

The "main" function of the code creates nodes representing addition, multiplication, and subtraction operations, and a node representing the calculation of the nth Fibonacci number. It sets the children of each node appropriately and calls the "calc" function on each node to perform the corresponding calculation. Finally, it frees the memory allocated for the nodes.

Overall, the code demonstrates the use of a tree data structure to perform calculations and illustrates how the recursive nature of the tree can be leveraged to solve problems such as computing the nth Fibonacci number.




nodeStruct2: This is a C program that defines a tree data structure and uses it to perform calculations for arithmetic operations and calculate the nth Fibonacci number.