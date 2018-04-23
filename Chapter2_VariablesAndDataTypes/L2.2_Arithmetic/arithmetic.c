// This lesson explores data types other than int and how to do arithmetic in C.

#include <stdio.h>

int main(void) {
    // "float" stands for "floating point number."
    // floating point numbers are numbers which may have fractional parts.
    // 3.14 in this case is a float literal.
    float my_float = 3.1416;
    
    // Printing a float is as simply as printing an int, except we use the "%f" format specifier instead of "%d":
    printf("my_float = %f\n", my_float);
    
    // We can also modify the format specifier to print only a given number of digits:
    printf("my_float to 2 digits is %.2f\n", my_float);
    
    // In that example, the .2 in %.2f means "truncate the digits past the second decimal place."
    
    // "double" stands for "double-precision floating point number."
    // It uses twice as much space (8 bytes instead of 4 bytes) but is more precise than a float.
    // Because doubles are much more widely used than floats by programmers, we will use double instead of float 
    // from now on.
    double my_double = 2.718281828;
    printf("my_double to 4 digits is %.4f\n", my_double);
    
    // Arithmetic is simply in C. Let's start by doing some common operations on ints.
    int a = 13;
    int b = 5;
    
    // Sum will be initialized to the sum of a and b.
    // The right hand side (RHS) "a + b" is called an "expression.""
    int sum = a + b;
    printf("sum = %d\n", sum);
    
    // We may mix variables and literals, or just use literals in expression:
    sum = b + 10;
    printf("sum = %d\n", sum);
    
    sum = 80 + 17 + a;
    printf("sum = %d\n", sum);
    
    // Subtraction and multiplication are also intuitive. Multiplication is denoted by an asterisk (*).
    // Note that C follows the standard order of operations.
    int result = a - b * 3; // b * 3 happens first, then a - (b * 3);
    printf("result = %d\n", result);
    
    // We can use parentheses to disambiguate and control the order that operations are evaluated.
    printf("(%d - %d) * 3 = %d\n", a, b, (a - b) * 3); // a - b happens first, then that is multiplied by 3.
    
    // I used a more complicated printf that time. 
    // Instead of putting (a - b) * 3, I inserted the actual values of a and b.
    // This makes the result easier to see on the terminal.
    // Also note that I put an expression for the result.
    // Functions may receive expressions as well as variables and literals as arguments.
    
    // Our last of the four canonical arithmetic operations is division.
    printf("%d / %d = %d\n", a, b, a / b);
    
    // That last printf will print "12 / 5 = 2".
    // Why not 2.6, the correct answer? Or it could've at least rounded to 3!
    // When doing division between integers in C, C will keep the result of the division as an integer as well.
    // To do this, C will round the result of division between integers towards 0.
    
    // We can, however, get a fractional result by converting the ints to doubles:
    double a_double = (double) a;
    double b_double = (double) b;
    
    printf("%.0f / %.0f = %.2f\n", a_double, b_double, a_double / b_double);
    
    // Converting one data type to another is called "casting" in C.
    // We say that we "casted" the int "a" to a double and assigned it to "a_double."
    
    // Now let's look at arithmetic between doubles instead of ints.
    a_double = 3.14;
    b_double = 2.72;
    printf("%.2f + %.2f = %f\n", a_double, b_double, a_double + b_double);
    printf("%.2f - %.2f = %f\n", a_double, b_double, a_double - b_double);
    printf("%.2f * %.2f = %f\n", a_double, b_double, a_double * b_double);
    printf("%.2f / %.2f = %f\n", a_double, b_double, a_double / b_double);
    
    // As you can see, the syntax is the same.
    // You can even interweave arithmetic between doubles and ints:
    printf("%d / %.2f = %f\n", a, a_double, a / a_double);
    printf("%.2f / %d = %f\n", b_double, b, b_double / b);
    
    // You will notice in the output that neither of these statements truncate the result as in int division,
    // even though there is an int present in the expression.
    // Technically speaking, C only does arithmetic between two data types that are the same, such as two ints, 
    // two floats, two doubles, etc.
    // When two different data types are in the same expression, C will "implicitly" cast one of the arguments to a
    // the more "precise" data type of the two.
    // Since doubles may represent fractional numbers and ints may not, C will implicitly cast ints to doubles when they
    // both appear in the same expression.
    // Similarly, since doubles have more precision than floats, C will implicitly cast floats to doubles.
    // Therefore, an easy way to get a fractional result from the division of two ints is to just cast one to a double.
    a = 17;
    b = 3;
    printf("%d / %d = %f\n", a, b, (double) a / b);
    
    // In C, type-casting has higher precedence than any of the arithmetic operations, so it will happen before 
    // the division. Sometimes, it is still helpful to add parentheses to disambiguate:
    printf("%d / %d = %f\n", a, b, ((double) a) / b);  // Same result as before.
    
    // One final useful operator that this lesson will cover is the modulo (%) operator.
    // The modulo operator works only for two integral types, 
    // and will give the remainder of division of the first by the second:
    a = 83;
    b = 5;
    
    printf("%d %% %d = %d\n", a, b, a % b);
    
    // Notice how I used "%%" instead of "%" in the first argument to printf: this is because printf recognizes
    // the percent sign % as a special character, and will not actually print a percent sign if we put one by itself.
    // If we want to literally print "%", we use two percent signs (%%).
    // The process of using a special syntax to suppress the special meaning of a character is called "escaping."
    // In this example, we "escaped" a percent sign by using two percent signs.
}