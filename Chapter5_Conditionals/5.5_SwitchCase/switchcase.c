// In this file we discuss switch statements, which allow you to execute one or more statements based on the 
// value of some integer.

#include <stdio.h>

int main(void) {
    // Let's write a program in which we take 2 double inputs, and either add, subtract, multiply, or divide them
    // based on a prompt.
    
    // First, let's get the numbers:
    double first;
    printf("Enter the first operand: ");
    scanf("%lf", &first);
    
    double second;
    printf("Enter the second operand: ");
    scanf("%lf", &second);
    
    // Now, we will ask the user to use a number to signify what operation to perform.
    int operation;
    printf("Which operation would you like to perform?\n");
    printf("1) Addition\n");
    printf("2) Subtraction\n");
    printf("3) Multiplication\n");
    printf("4) Division\n");
    printf("> ");
    
    // So the user should enter 1, 2, 3, or 4, which will decide the operation.
    scanf("%d", &operation);
    
    // We could decide which operation to use using a series of if statements, but it is more elegant to use
    // a switch statement.
    
    // To use a switch statement, we write "switch(x)" where x is some integer.
    switch(operation) {
        // Then, we write a series of "cases" that each decide a different code block to execute.
        // The syntax of a case is "case x:" where x is an integer constant. Variables, even constant variables, are
        // not allowed.
        case 1:
            // This will be executed if the user enters "1" for the operation, corresponding to addition.
            // We say that the value of operation "matches" this case.
            printf("%f + %f = %f\n", first, second, first + second);
            break; // In this switch statement, we will end each case with break (more details below).
        case 2:
            printf("%f - %f = %f\n", first, second, first - second);
            break;
        case 3:
            printf("%f * %f = %f\n", first, second, first * second);
            break;
        case 4:
            printf("%f / %f = %f\n", first, second, first / second);
            break;
        default:
            // You can optionally put a "default" case in a switch statement.
            // This will be executed if no case is matched.
            // No break statement should be put in a default case.
            printf("You didn't specify a valid operation :(\n");
    }
    
    // At the end of each case above, we put "break;".
    // In general, "break" is used to "break out of" different constructs, but "switch" is the only thing we've seen
    // so far where break may be used.
    // In this case, break will exit the switch statement: without it, your program will continue to execute all the
    // cases *below* the matched case, including the default if there is one, until every case is executed or a break
    // is encountered.
    // This is casually referred to as "falling through" cases.
    
    // For example, the following switch statements results in B, C, and D being printed.
    
    switch(2) {
        case 1:
            printf("A");
        case 2:
            printf("B");
        case 3:
            printf("C");
        case 4:
            printf("D");
        default:
            printf("\n");
    }
    
    // The omission of a break statement is an often unintentional error made by the programmer, so you should be
    // careful to include it unless you intend to omit it.
    
    // Sometimes it can be elegant to fall through several cases.
    // Consider the task of informing the user whether an integer they entered from 1 to 10 is prime:
    int num;
    printf("Enter an integer from 1 to 10: ");
    scanf("%d", &num);
    
    switch(num) {
        case 2:
        case 3:
        case 5:
        case 7:
            printf("%d is prime\n", num);
            break;
        case 4:
        case 6:
        case 8:
        case 9:
        case 10:
            printf("%d is composite\n", num);
            break;
        case 1:
            printf("1 is neither prime nor composite\n");
            break;
        default:
            printf("%d is not between 1 and 10 :(\n", num);
    }
    
    // Some programmers insist you should never have cases without break statements, while others will occasionally
    // find them useful. You'll have to decide what style of programming you prefer.
    
    return 0;
}