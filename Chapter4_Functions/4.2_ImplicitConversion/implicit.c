// In this file we discuss "implicit conversions" between numeric types.

#include <stdio.h>


// First, let's define some functions that will be helpful for our understanding.
int twice_int(int num) {
    return num * 2;
}

double twice_double(double num) {
    return num * 2;
}

int main(void) {
    // Below are initialized variables of the data types int, long, float, and double.
    // On the right-hand-sides are literals corresponding to each type.
    int an_int = 1;
    
    // "long" is an integer type that typically has more bytes than ints: 64 instead of 32.
    // This means longs may represent much larger numbers.
    long a_long = 2L; // long literals have an "L" (lowercase or capital, conventionally capital) at the end.
    
    // Recall that floats are floating point numbers with 4 bytes, instead of 8 like double.
    float a_float = 3.14f; // float literals have an "f" (lowercase or capital, conventionally lowercase) at the end.
    double a_double = 2.72;
    
    // Despite having different data types, numeric types can be used together in arithmetic operations:
    printf("%d + %f = %f\n", an_int, a_float, an_int + a_float); // 4.14
    
    // The result of a sum between an int and a float is itself a float.
    float float_result = an_int + a_float;
    
    // Note however that the arithmetic operators in C act only on two values of the exact same type.
    // Not even ints and longs, or floats and doubles are directly added.
    // For float_result, an_int is implicitly converted to a float.
    // Thus, the computation of float_result is essentially the same as in the following statement:
    // (Note that the conversion occurs for an_int before the addition)
    float_result = (float) an_int + a_float;
    
    // This is called an implicit conversion, being the automatic conversion from a value of one type to a value of
    // another type based on the usage context.
    // In this case, the context is standard arithmetic.
    // In standard arithmetic, if one argument is a floating point type (float or double) and the other is an
    // integral type (char, short, int, or long), the integral type is converted to the other argument's type:
    
    // This statement...
    double double_result = an_int - a_double;
    
    // ...is the same as
    double_result = (double) an_int - a_double;
    
    // Similarly, this statement...
    float_result = a_long * a_float;
    
    // ...is the same as
    float_result = (float) a_long * a_float;
    
    // This is often referred to as an "integer promotion", since a type which can only represent integers is converted
    // to a type which can represent both integers and fractional numbers.
    // Note however that it is not always the case that a conversion of an integral value to a floating-point value
    // will be exact, though it usually is, and I will not get into that right now.
    
    // When two floating point values of different types are involved in an arithmetic operation, the value with the 
    // less precise (using fewer bytes) type is likewise "promoted":
    
    // This statement...
    double_result = a_float / a_double;
    
    // ...is the same as
    double_result = (double) a_float / a_double;

    // This is because double is the more precise type.
    
    // A similar rule applies to integral types.
    
    // This statement...
    long long_result = an_int % a_long;
    
    // ...is the same as
    long_result = (long) an_int % a_long;

    // Implicit conversions also occur to conform with an expected type.
    
    int my_int = 1.23;
    printf("my_int is %d\n", my_int);
    
    // The above statement is of course, odd, because 1.23 is not an integer.
    // However, it does compile, and is basically the same as
    my_int = (int) 1.23;
    
    // So my_int is 1. This is called "demotion" since the fractional part of 1.23 is during the conversion.
    // Implicit demotions of data is one of the most controversial features of C, and for good reason.
    // Many other languages will fail to compile when a float or double is used where an integral type is expected
    // without an explicit cast to convert it.
    // Unfortunately, many C compilers will not even emit a warning when demotions implicitly take place; mine doesn't.
    // Thus, you should be aware that the loss of precision incurred when floating point types are converted to integral
    // types can be a source of error.
    
    // A much less harmful example that you will often see is
    double my_double = 7;
    printf("my_double is %f\n", my_double);
    
    
    // Predictably, this is the same as
    my_double = (double) 7;
    
    // So my_double is 7.0.
    // Often, programmers will explicitly include a decimal point to make clear that the intent was to have the double
    // value 7.0:
    my_double = 7.0;
    
    // I see both styles (assigning to an int, and assigning to a double which is an integral value) 
    // on a regular basis in my work.
    
    // Finally, it should be noted that implicit conversion to conform with an expected type also occurs when 
    // calling functions.
    
    // See if you can predict the output of the following statements:
    printf("twice_int(%f) = %d\n", 9.8, twice_int(9.8));
    printf("twice_double(%d) = %f\n", 11, twice_double(11));
    
    // There are additional nuances in the rules of implicit conversions for numeric types, particularly for integral 
    // types in arithmetic, but what I have described covers the majority of cases that arise. 
    
    return 0;
}