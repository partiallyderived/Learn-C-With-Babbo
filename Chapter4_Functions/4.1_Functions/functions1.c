// In this lesson, we will finally discuss functions, a common language feature that has been unexplained since 
// chapter 1.
#include <stdio.h>

// The following piece of code constitutes the definition of a function in C:
int sum_times_difference(int number1, int number2) {
    int sum = number1 + number2;
    int difference = number1 - number2;
    int product = sum * difference;
    return product;
}

// A function is a sequence of statements that depend on zero or more inputs that may optionally produce an output.
// The "sequence of statements" is often referred to as the function body.
// The "inputs" are usually called "arguments" or "parameters." The types of the inputs are called the 
// "argument types." In this case, the function "sum_times_difference" accepts two arguments, both of type int. 
// The "output" of a function is called a "return value", or "the value that the function returns."
// The type of the return value is called the "return type", which is int in this case.

// So to summarize, "sum_times_difference" is a function that accepts two int arguments called "number1" and 
// "number2" and returns an int which is the product of the sum of the given numbers 
// with the difference of the given numbers

// In general, a function definition looks like this:
// <return type> <function name>(<arg1 type> <arg1 name>, <arg2 type> <arg2 name>, ..., <argn type> <argn name>) {
//     <function body>   
// }

// Note that functions may not be defined in other functions in standard C, though some compilers support it.


// So now that we have defined a function, how do we make use of it?
// Let's take a look inside main.

int main(void) {
    // To use a function, we need to give values for each of its parameters.
    // This is called "calling" a function, and it has the following syntax:
    // <function name>(<arg1 value>, <arg2 value>, ..., <argn value>)
    // The following line calls sum_times_difference with arguments 5 and 3:
    sum_times_difference(5, 3);
    
    // 5 and 3 become "number1" and "number2" in sum_times_difference, and the function call results in the function
    // body of sum_times_difference being executed with those arguments.
    
    // The result of the above statement is (5 + 3) * (5 - 3) = 8 * 2 = 16
    // But wait, how can we even use that result?
    // One way is directly, such as for an argument to the printf function:
    printf("sum_times_difference(5, 3) = %d\n", sum_times_difference(5, 3)); 
    
    // Note that sum_times_difference can accept only exactly 2 arguments. 
    // The following lines will cause the program to fail to compile:
    
    // 0 arguments (too few):
    // sum_times_difference();
    
    // 1 argument (too few):
    // sum_times_difference(5);
    
    // 3 arguments (too many):
    // sum_times_difference(5, 3, 2);
    
    // Note as well that printf is also a function.
    // You may wonder then, why calls to printf will compile for difference numbers of (or arbitrarily many) arguments:
    printf("This compiles\n");
    printf("So does %s\n", "this");
    printf("%s %s\n", "And", "this");
    printf("%s %s %s %s %s %s\n", "Even", "this", "will", "compile", "without", "error");
    
    // printf is a special function called a "variable arguments" (usually abbreviated to "var args") function.
    // You can make your own var args functions, though this topic will not be covered in this course.
    
    // We can also assign variables to function calls: in fact, functions calls can be used wherever a literal with the
    // same type as the return type may be used:
    int number1 = 5;
    int number2 = 3;
    int result = sum_times_difference(number1, number2);
    printf("result = %d\n", result);
    
    // This file covered basic usage of functions
    // Please proceed to functions2.c to see more examples and explanations.
    
    return 0;
}