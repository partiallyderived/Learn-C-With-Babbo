// This line starts with two forward slashes /, which can be found next to right-shift on most computers.
// In C and many other programming languages, anything on a line after // is ignored by the compiler.
// Words that appear after // are called "comments".
// Comments are used to give explanations to individuals reading the source code.
// I will use comments throughout our lessons to explain what the code is doing.

// This line tells C to include standard terminal input/output utilities for this program.
// "stdio" stands for "standard input-output".
#include <stdio.h>

// This line is the entry-point for our program.
// Everything between "int main(void) {" and the closing brace "}" is what our program will actually do.
int main(void) {
    // Our program only does one thing: it prints "Hello World!" on its own line onto the terminal.
    // That is what printf("Hello World!\n"); does.
    
    // printf is a programming concept called a "function".
    // Put simply, a function is something that takes zero or more inputs (called "arguments") and does something with
    // them. The arguments appear within a set of parentheses () after the function name.
    // In this case, printf takes only one argument: "Hello World!\n".
    // In programming terminology, we say that printf was "called" with the argument "Hello World!\n".
    // The \n at the end of "Hello World!\n" tells our program to also print a new line.
    // Without \n, the terminal prompt would be printed on the same line as "Hello World!", which looks ugly.
    // This call to printf constitutes what is called a "statement", which is essentially a piece of code that
    // "does something." All statements in C need to be followed by a semi-colon (;).
    printf("Hello World!\n");
    
    // Note that if we did not have the line "#include <stdio.h>" at the beginning of the file, the C compiler would not
    // have been able to find printf, and our program would not have compiled.
}
