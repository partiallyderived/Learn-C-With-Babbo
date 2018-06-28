// If you have not viewed functions1.c, please do so before viewing this file.

// In this file, we will go over more function examples and explanations.
#include <stdio.h>

// The previous file has one function, sum_times_difference, which had as arguments 2 ints and returned an int.

// The following is a function that accepts no arguments and has no return value:

void hello(void) {
    printf("Hello!\n");
}

// Notice that we use "void" where the return value would be normally.

// Similarly, we must enclosed "void" in the argument parentheses to denote that hello accepts no arguments.

// When we call hello, we will see "Hello!" printed to the shell.

// *** IMPORTANT NOTE FOR PROGRAMMERS IN OTHER LANGUAGES ***
//
// In most languages, a function that takes no arguments is designated by "empty parentheses":
// void hello() {
//     printf("Hello!\n");
// }
// While this way *appear* to have the same effect in C, it is actually not declaring a function that
// takes 0 parameters: see https://stackoverflow.com/questions/5929711/c-function-with-no-parameters-behavior
// To repeat, to define a function that takes no arguments in C, you must enclose void within the parentheses.
//
// *** END OF NOTE FOR PROGRAMMERS IN OTHER LANGUAGES    ***

// Note that functions with no return value may omit a return statement.
// The following function does the same thing as hello:
void hello2(void) {
    // We can just call "hello" from here.
    hello();
    return;
}

// This function will print the concatenation of the given strings:
void concat_and_print(const char* string1, const char* string2) {
    printf("%s%s\n", string1, string2);
}

// This function will always return 0:
int zero(void) {
    return 0;
}

// Note that the above function resembles main: indeed, main is a special function that is called when you
// start your program.
// The return value of main is called an "exit code".
// An exit code of 0 should indicate that your program ran without errors, 
// and a non-zero exit code should indicate that an error occurred or the program ran adnormally.
// Often, different non-zero exit codes correspond to different errors.

// Here is a function that does floating point division with the given ints:
double floating_point_divide(int dividend, int divisor) {
    return ((double) dividend) / divisor;
}

// Here is a function that doubles the given int and then increments (adds one) to it.
// Notice that we can assign function arguments just as they were any other variable.
int double_and_increment(int integer) {
    integer = integer * 2;
    integer = integer + 1;
    return integer;
}

int main(void) {
    // Now let's call our functions.
    // Print "Hello" to the console:
    hello(); // When calling a function with no arguments, we use empty-parentheses instead of (void).
    
    // Concatenate "Grape" and "fruit":
    concat_and_print("Grape", "fruit");
    
    // Do floating point division on two int values:
    printf("floating_point_divide(%d, %d) = %f\n", 1, 3, floating_point_divide(1, 3));
    
    // Double and then increment an int:
    int a = 3;
    printf("double_and_increment(%d) = %d\n", a, double_and_increment(a));
    
    // Note that, even though we double and increment the argument in double_and_increment,
    // a remains unchanged:
    printf("a is still %d\n", a); // Prints "a is still 3"
    
    // When values are passed to a function, they are copied instead of substituted to the argument,
    // which is itself a variable.
    
    // Moreover, variables declared in a function and the function arguments are referred to
    // as "local variables" because they are local to the function: they may not be used
    // outside of the function or inside other functions called in the function body. Note that this permits two
    // different functions to use variables of the same name.
    
    // As main is also a function, all variables defined in main may only be used in main.
    // The counterpart to local variables are "global variables", which are declared 
    // outside of functions in the "global scope", the same space in which functions may
    // be defined. We will discuss global variables more later.
    
    return 0;
}
