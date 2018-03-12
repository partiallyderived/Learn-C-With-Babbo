// This lesson will teach you about variables and format specifiers.

// Need this for "printf" again.
#include <stdio.h>


int main(void) {
    // Start of our program.
    
    // The following statement "declares" a variable called "my_int" of type "int" and "initializes" it to the value 3.
    int my_int = 3;
    
    // "int" is something called a "Data Type": it is the type of data that "my_int" will hold.
    // "int" stands for "integer".
    
    // "my_int" is the name of our variable. The technical term for the name of a variable is "identifier."
    
    // An identifier may contains letters, numbers, and the underscore, but must not start with a number.
    // Here are some examples:
    // int 2_int = 5; // BAD: identifier starts with a number.
    // int my_!nt = 6; // BAD: identifier contains "!", which is neither a letter, number, or underscore.
    int my_int2 = 8; // GOOD: identifier contains a number, but it does not start with it.
    
    // In the previous line, 8 is what is called an int "literal."
    // A literal is a single, non-variable token representing a constant value, in this case the integer 8.
    
    // We may view the "value" of variables using the printf function.
    // This will "my_int is 3" on its own line in the terminal:
    printf("my_int is %d\n", my_int);
    
    // Unlike our other usages of printf, this call takes 2 arguments instead of one.
    // This is because we have "%d" in the first argument, which is called a "format specifier."
    // "%d" means "put the decimal (base 10) representation of the given integer value here."
    
    // It is possible to give multiple format specifiers to "printf":
    printf("my_int is %d, and my_int2 is %d\n", my_int, my_int2);
    
    // printf expects as many extra arguments as there are format specifiers, so there should be
    // (number of format specifiers) + 1 total arguments to printf.
    // The first argument goes with the first format specifier, the second to the second format specifier, and so on.
    
    // After they are declares, most variables may be have their value changed:
    my_int = 7;
    printf("Now my_int is %d\n", my_int);
    
    // Changing a variable's value is called "assignment": in that example, the variable my_int was "assigned" to the
    // int literal 7.

    // When you give a value to a variable on the same line it is declared, you "initialize" that variable.
    int my_int3 = -4; // my_int3 is "initialized" to -4.
    
    // You may also declare a variable without initializing it:
    int my_int4;
    
    // Here, we have declared my_int4 but not initialized it to any value. 
    // You might wonder what happens if we try to print it:
    printf("my_int4 is %d\n", my_int4);
    
    // The previous statement may print "my_int4 is 0". It may also print "my_int4 is -2147483648", or any other integer
    // that may be represented in 4 bytes (see pdf). This is an example of something called "undefined behavior".
    // The value of an uninitialized, unassigned variable is undefined in C, and could be anything.
    // However, we may make the value of my_int4 defined by assigning it:
    
    my_int4 = my_int2;
    
    printf("my_int4 is %d\n", my_int4);
    
    // Notice in the previous assignment that we may assign variables to other variables. This causes my_int to be
    // assigned the value of my_int2 at the time of assignment. So if we reassign my_int2, the value of my_int4 which 
    // was the previous value of my_int2 will be unchanged:
    my_int2 = -1;
    printf("my_int2 = %d, my_int4 = %d\n", my_int2, my_int4);
    
    // Sometimes, we may have variables whose values we know will never change.
    // To ensure that we never accidentally assign a new value to them, it may be useful to declare a "constant" 
    // variable:
    
    const int my_const_int = 7;
    
    // This statement initialized my_const_int to 7. The keyword "const" tells C that this variable should never be
    // reassigned. "const" is called a "qualifier", as it qualifies my_const_int to be constant.
    
    // my_const_int = 5; // ERROR: Not allowed, since my_const_int was qualified with "const".
    
    // It is also possible to declare a constant variable without assigning it:
    const int my_other_const;
    
    // This variable is mostly useless however, since its value is undefined and we can't assign to it, even though it
    // was never initialized.
    
    // my_other_const = 8; // ERROR: Not allowed, since my_other_const is const and may not be assigned.
    
    // Thus, all we have is some undefined value that we can't change:
    printf("my_other_const is %d and I can't do anything about it!\n", my_other_const);
    
    // Therefore: always initialize constant variables.
}