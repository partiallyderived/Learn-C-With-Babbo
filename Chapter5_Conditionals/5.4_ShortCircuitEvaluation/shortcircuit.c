// In this file, we will go over an interesting programming feature for evaluating conditional expressions called
// "short-circuit evaluation".

#include <stdio.h>

// This function will be useful later.
int print_and_return(int num) {
    printf("%d\n", num);
    return num;
}

int main(void) {
    // To introduce short-circuit, let's approach a simple problem:
    // we want to take in two floating point numbers from the user, divide the first by the second, and print
    // something only if the quotient is at least 3.14.
    
    double dividend;
    double divisor;
    
    printf("Enter the dividend: ");
    scanf("%lf", &dividend);
    
    printf("Enter the divisor: ");
    scanf("%lf", &divisor);
    
    // But wait! What if the user enters 0 for the divisor?
    // Then our program will crash due to a divide-by-zero error!
    // So we better check if divisor is non-zero first:
    if (divisor != 0) {
        if (dividend / divisor >= 3.14) {
            printf("The quotient is at least pi\n");
        }
    }
    
    // This is a fine solution, but we could make it more elegant by exploiting short-circuit evaluation.
    // Let's set it up again to demonstrate.
    
    printf("Enter another dividend: ");
    scanf("%lf", &dividend);
    
    printf("Enter another divisor: ");
    scanf("%lf", &divisor);
    
    // Now for the trick:
    if (divisor != 0 && dividend / divisor >= 3.14) {
        printf("The quotient is at least pi\n");
    }
    
    // In the previous statement, we check to see if the divisor is non-zero and then do the division in the same
    // conditional statement.
    // Your first extinct may be to think that this is unsafe, because doing the division in the same expression for
    // which we check for a non-zero divisor may suggest that we carry out the division even if the divisor is zero.
    // However, thanks to short-circuit evaluation, this is not the case.
    // When we use the && operator, short-circuit evaluation means that if the first expression (where we check for
    // a non-zero divisor) is *false*, then the second expression (where we perform the division) will not be performed.
    // This is because for && to result in true, both the expressions it is operating on must be true.
    // Thus, if one of the expressions is false, the entire compound conditional is false.
    // Therefore if the first expression is false, there is no need to evaluate the second expression, since we already
    // know the compound conditional evaluates to false.
    
    // For a more straightforward example, look at the "print_and_return" function defined at the beginning of the
    // lesson, and then think about what this line should do:
    
    if (print_and_return(0) && print_and_return(1)) {
        printf("If body\n");
    }
    
    // Due to short-circuit evaluation, 0 will be printed, but not 1, since 0 is false!
    
    // Short-circuit evaluation also applies to the || operator, but in the opposite way.
    // That is, if the first expression evaluates to true, the entire compound expression evaluates to true.
    // I will it as an exercise to explain why this is the case.
    // Try to predict what the output of the following conditional statement is:
    if (print_and_return(2) || print_and_return(1)) {
        print_and_return(3);
    }
    
    // Short-circuit evaluation is a technique used surprisingly often by programmers comfortable with the
    // concept, as it allows the programmer to succinctly check for valid input and perform some test on the data
    // in a single if statement.
    
    return 0;
}