// In this file we discuss compount conditionals, which may be used to make conditional statements from other
// conditional statements.

#include <stdio.h>

int main(void) {
    // Let's say you want to determine whether a number a user enters is between 0 and 1.
    // We can do this with if statements and scanf.
    printf("Enter a number: ");
    double num;
    scanf("%lf", &num);
    
    if (num > 0) {
        if (num < 1) {
            printf("0 < %f < 1\n", num);
        } else {
            printf("You entered %f, which is not between 0 and 1\n", num);
        }
    } else {
        printf("You entered %f, which is not between 0 and 1\n", num);
    }
    
    // This works, but is a bit verbose.
    // We can make it much more succinct using the "&&" operator, which "ands" the results of two conditional 
    // expressions.
    // That is, it is 1 (true) if both operands are non-zero (true), and 0 (false) if both operands are 0 (false).
    // So let's try it again:
    
    double other_num;
    printf("Enter another number: ");
    scanf("%lf", &other_num);
    
    if (other_num > 0 && other_num < 1) {
        printf("0 < %f < 1\n", other_num);
    } else {
        printf("You entered %f, which is not between 0 and 1\n", other_num);
    }
    
    // As you can see, the code is a bit nicer this way.
    
    // Another way to form compound conditionals is by using the "||" operator, which "ors" the results of two
    // conditional expressions.
    // (The symbol "|" is called a pipe, and on most keyboards it is typed by holding shift and pressing the 
    // backslash (\) key)
    // That is, it is true if either operand or both operands are true, and false otherwise.
    // For example, suppose we wanted to determine whether at least one of the numbers the user entered
    // was between 0 and 1.
    // Then we could do something like this:
    if ((num > 0 && num < 1) || (other_num > 0 && other_num < 1)) {
        printf("At least one number you entered was between 0 and 1\n");
    } else {
        printf("Neither number you entered was between 0 and 1\n");
    }
    
    // Note that this "or" is different from the meaning of or in casual usage, which usually excludes both options
    // from being true.
    // For example, if I say I am either going to the supermarket *or* stopping by the convenience store, that usually
    // means I will do one or the other, but not both.
    // In programming, the casual usage of or is called "exclusive or" or "xor", and there is no operator which 
    // represents it, though it may be easily replicated using the "not" operator !, which is true when operating
    // on false statements, and false when operating on true statements.
    // Let's use it to determine whether the user has entered only 1 number between 0 and 1.
    
    // To make it less cluttered, let's store the results of the conditional statements saying whether
    // num and other_num are between 0 and 1, respectively.
    int statement1 = num > 0 && num < 1;
    int statement2 = other_num > 0 && other_num < 1;
    
    if ((statement1 && !statement2) || (!statement1 && statement2)) {
        printf("Exactly one number you entered was between 0 and 1\n");
    } else {
        printf("Either both numbers you entered were between 0 and 1 or neither were\n");
    }
    
    return 0;
}