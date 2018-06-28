// This file introduces conditionals, a programming concept without which virtually no interesting programs could be
// written.

#include <stdio.h>

int main(void) {
    // Say we wanted to write the following simple program:
    // The user inputs an int and we read it into a variable.
    // Then, if the int is positive, we say that it is positive, and the same for if it is negative, or zero.
    
    // To do this, we will need to use conditionals, which allow us to "branch off" and execute different sections of
    // our code based on the result of some expression.
    
    // To demonstrate, let's start writing the program.
    
    // Get the user input:
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    
    // A conditional starts with the keyword "if":
    if (num > 0) {
        // Inside the parentheses is a "condition", which, if true, executes the code within the following set of
        // braces.
        // The condition here is "num > 0", which, predictably, checks to see if a numeric type is greater than 0.
        printf("You entered a positive number!\n");
    } 
    else if (num < 0) {
        // "else if" allows you to specify another condition that may execute if the first condition is false.
        // In this case, the user has entered a negative number.
        printf("You entered a negative number!\n");
        
        // You can have as many (including 0) "else if" statements as you wish.
        // Note that the body of an "else if" statement will not execute if the previous "if" or "else if" statement
        // is true.
    }
    else {
        // You may optionally put "else" following an "if" or "else if" statement.
        // The body of an "else" statement is executed if all "if" and "else if" statements are false.
        // In this case, we have an integer which is neither positive nor negative: it must be 0.
        printf("You entered zero!\n");
    }
    
    // I use the words "true" or "false" to denote the "truth value" of a conditional statement such as num > 0.
    // Unlike most other languages, in C truth values are represented not by "boolean" values "true" and "false", but
    // by int values. In particular, all non-zero values are considered true, while 0 and only 0 is considered false.
    // The following example illustrates this:
    if (1) {
        printf("1 is true!\n");
    }
    if (-2) {
        printf("-2 is true!\n");
    }
    if (0) {
        printf("This statement won't be printed because 0 is false!\n");
    }
    
    // Since int values represent truth in C, an expression such as "4 > 3" must result in an int value.
    // Indeed, conditional expressions are either 0 (false) or 1 (true).
    printf("4 > 3 = %d\n", 4 > 3); // prints "4 > 3 = 1"
    
    printf("4 < 3 = %d\n", 4 < 3); // prints "4 < 3 = 1"
    
    // You can even interweave conditional expressions and arithmetic expressions in C.
    printf("5 * (4 > 3) = %d\n", 5 * (4 > 3)); // prints 5. Do you see why?
    
    // ">" and "<" are called "comparison operators" or "relational operators", since they compare two values.
    // Here are some other comparison operators.
    
    // Greater than or equal to is represented by ">=".
    double a = 3.14;
    if (a >= 2.72) {
        printf("a is at least 2.72\n");
    }
    
    // Less than or equal is represented by "<=".
    int b = 3 + 5;
    if (b <= 8) {
        printf("b is at most 8\n");
    }
    
    // Equality is represented by TWO equal signs, not one.
    // This is because assignment is represented by a single equals sign.
    // This is a common source of error for programmers.
    if (0 == (3 - 3)) {
        printf("0 is equal to 3 - 3\n");
    }
    
    // Inequality is represented by an exclamation point followed by an equals sign:
    if (1 != 0) {
        printf("1 is not 0\n");
    }
    
    return 0;
}
