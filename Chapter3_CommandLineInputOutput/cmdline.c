// In this lesson we will build a simple command line program which takes input from the user.

#include <stdio.h>

int main(void) {
    // So far, our programs have been pretty boring: all we've been doing is printing things onto to console.
    // This will be the first lesson where we actually make a program the user interacts with.
    
    // You have probably seen some form of command line "prompt" 
    // (not to be confused with the Windows shell "Command Prompt") which asks the user for some kind of input, such
    // as "Press any key" or "Enter user name."
    // In this lesson, we will display a few simple prompts to the user, and you will make a somewhat more
    // challenging and interesting program as an exercise.
    
    // First, let's do something exceptionally simple: we will ask the user for two ints, and then add them 
    // together. We do this as follows:
    
    // First, we need variables to store the user inputs to:
    int int1, int2;
    
    // The following code is the "prompt" (description of the expected input for the user). 
    // Notice the absence of a new line: in this program, we will have the user give input on the same line as the 
    // prompt.
    printf("Enter an integer: ");
    
    // To receive the input, we use the scanf function, available along with printf from stdio.h:
    scanf("%d", &int1);
    
    // Once again, we use the format specifier %d.
    // In this case, %d tells scanf that we expect a decimal integer from the user.
    // The second argument, &int1, says to store to the user input to int1.
    
    // You are probably wondering what exactly that ampersand (&) is for.
    // Normally, variables appearing as function arguments may not be modified by the function.
    // printf for example just needs to output the variable's value: it doesn't need to actually modify the variable.
    // scanf however needs to actually modify the variable argument to store the result.
    // The ampersand allows this to happen: we will go into more detail when we talk about pointers.
    
    // When we call scanf, the program will wait until the user enters some input before proceeding.
    // Thus, the rest of the program will not before the input is given.
    
    // Now let's prompt for the second int and get it.
    printf("Enter another integer: ");
    scanf("%d", &int2);
    
    printf("You entered %d and %d\n", int1, int2);
    printf("%d + %d = %d\n", int1, int2, int1 + int2);
    
    // Note that, since ints are 32-bit (have up to 32 binary digits), they can represent a value only less than
    // 2^31 (half of 2^32 to accomodate negative numbers) or at least -2^31 when working with negative numbers.
    // Thus, some int inputs will result in undefined behavior 
    //(crashing, producing unexpected results, or appearing to work normally)
    // if the operands or sum is too large or too negative.
    
    // We could easily modify the above logic to work for doubles:
    double double1, double2;
    
    // For doubles, we use lf instead of f for scanf.
    // The reason for this is that printf will promote (convert to a more precise type) a float to a double
    // when printing with %f, so %f is fine for printf for both floats and doubles, but scanf needs to know the 
    // exact numeric type so that it knows how many bytes, so it uses %f for floats and %lf ("long float") for doubles.
    // This nuance isn't particularly important, and what printf is doing is actually kind of complicated so if you
    // don't get it don't worry about it (or look it up if you're curious), just know that %f works for both floats and 
    // doubles for printf, but %f is for floats only in scanf and %lf is for doubles only in scanf.
    printf("Enter a number: ");
    scanf("%lf", &double1);
    
    printf("Enter another number: ");
    scanf("%lf", &double2);
    
    printf("You entered %f and %f\n", double1, double2);
    printf("%f + %f = %f\n", double1, double2, double1 + double2);
    
    // We could similarly use %c if we wanted a single char, though that is less commonly the case.
    
    // ints and doubles are fairly straightforward, but strings are a bit trickier.
    // The reason is that we are not sure how many chars the user will enter.
    // Thus, we need to create storage long enough to capture reasonable user inputs.
    // Such storage is often called a buffer.
    char buffer[50];
    
    // Using this buffer, we can capture inputs as large as 50 chars.
    // Let's use this buffer to get the user's name:
    printf("Enter your name: ");
    
    // As you may have guessed, we use %s to extract a string.
    // However, notice that for strings, we omit the ampersand: this is because of nuances in how arrays work when
    // they are passed to functions. We will see why when we discuss pointers.
    scanf("%s", buffer);
    printf("Hi %s, your name is great!\n", buffer);
    
    // scanf will put the null terminator character at the end of the user input for us automatically.
    // Note that this means we are limited to accepting names with at most 49 characters.
    
    // As it stands, the above prompt will result in undefined behavior if the user enters a name longer than 49 chars.
    // There are several ways to approach this, but the most robust ways would involve resizing our buffer to accomodate
    // long names. This can be accomplished using dynamic memory allocation, an advanced concept that we will discuss
    // later.
    // Equally important would be checking the int and double inputs above to make sure they represent numbers,
    // and allowing the user to attempt the prompt again in case of failure.
    // We will see how to do this after we discuss conditionals.
    
    return 0;
}