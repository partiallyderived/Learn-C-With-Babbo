// In this file we discuss the concept of scope, which determines when a programmer may reference a variable.

#include <stdio.h>

int main(void) {
    // The scope of a variable is the part of the code that the variable may be referenced.
    // The scope of the variable var, declared below, is the entire body of the main function.
    int var = 3;
    
    // Now let's look at a variable with a more restricted scope.
    if (var == 3) {
        // The scope of the variable "other_var" is the body of this if statement.
        // Attempting to refer to it elsewhere will result in an error.
        int other_var = 5;
    } else {
        // other_var = 7; // error
    }
    // other_var = 10; // error
    
    // Note a crucial similarity between the scope of var and the scope of other_var: they consist of the
    // portion of the code inclosed in the braces {} in which they are declared.
    // This is called "block scope", as portions of code surrounded by braces are called blocks or code blocks.
    // Functions are enclosed in braces: this indeed forms a block scope for local variables.
    // Block scope of course applies to functions other than main as well.
    // You can even create blocks arbitrarily without if statements or function definitions:
    {
        int other_other_var = 7;
    }
    // other_other_var = 8; // error
    // Making blocks arbitrarily is rarely useful, however: I have never seen it done in my programming career.
    
    // Note that it is perfectly valid to declare a variable in an inner scope that has the same name as a variable
    // in an outer scope:
    int my_var = 5;
    {
        int my_var = 7;
        printf("my_var = %d, corresponding to its value in the most inner scope\n", my_var);
        // Note that the outer scope "my_var" cannot be referenced by normal means within the inner scope.
        // Giving an inner scope variable the same name as an outer scope variable is thus discouraged.
    }
    
    // Now for a little conceptual exposition:
    // The scope of a variable is often also referred to as the "lifetime" of that variable.
    // When you enter the block scope of a local (declared inside a function, the only kind we've discussed) variable,
    // that variable is "created", and when you exit the scope, that variable is "destroyed".
    // A variable is "created" by allocating memory for it on what is called the "stack".
    
    // Generally speaking, a stack is a data structure (way of organizing data) in which the most recently added data
    // are also the most efficiently removed.
    // It is perfectly analagous to, say, a stack of pancakes: we can most easily remove the pancake at the top, and
    // we can easily add pancakes to the stack. The pancake which is easiest to remove is the most recently added
    // pancake, namely the one at the top.
    
    // So why do programs use a stack for allocating space for variables?
    // Note that, as a program is being executed, the most recently entered block scope will be the next one
    // executed.
    // In case this isn't clear, look at this example:
    {
        int outer = 5;
        {
            int inner = 6;
        } // <--- A scope is called by a right brace: The right brace will always refer to the most recently entered
          // scope.
    }
    // Thus, stacks are a very efficient way to allocate space for variables with a block scope, because the
    // variables that need to be destroyed (have their space deallocated for other purposes) will be at the top of the
    // stack, and thus easy to remove.
    
    return 0;
}