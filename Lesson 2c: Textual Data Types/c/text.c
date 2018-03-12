// In this lesson, we will learn about characters and strings, C's textual data types.

#include <stdio.h>

int main(void) {
    // Let's take a look at hello world again:
    printf("Hello World!\n");
    
    // Inside the printf function, we gave an argument "Hello World!\n", which resulted in Hello World! being printed
    // on its own line in the terminal.
    
    // Outside of the printf call, we see that groups of characters have special meanings.
    // For example, int refers to the integer data type, double to the double data type, printf to the printf function,
    // and variables themselves have identifiers by which we reference them.
    // What makes the argument "Hello World!\n" truly special is that pair of double quotes.
    // To see what I mean, take a look at this example:
    printf("3 + 4 is %d\n", 3 + 4);
    
    // Here, we passed 3 + 4 as an int argument to printf.
    // So if the data type of 3 + 4 is int, then it is natural to ask what the data type of "3 + 4 is %d\n" is.
    // This data type is commonly referred to as a string.
    // "3 + 4 is %d\n" is a string literal, just like 5 is an int literal.
    // Strings are best understood as sequences of characters. 
    // This endows the char data type in C with significant importance:
    
    char a = 'a'; // Single characters use single quotes, not double quotes.
    printf("%c is a character\n", a); // %c is the format specifier for char.
    
    // The char data type represents a single character, which could be a letter, a digit, a space, a symbol like !,
    // or even a newline:
    char new_line = '\n';
    printf("%c This is surrounded by lines%c\n", new_line, new_line);
    
    // Note '\n' is a single character representing a new line. C treats a backslash '\' as a special 
    // character. If we want to refer to the backslash literally, we need to escape it like we did the percent sign
    // inside the printf function:
    
    char backslash = '\\';
    printf("%c is a backslash\n", backslash);
    
    // Note however that the percent sign is NOT a special character according to the C language, but rather to the
    // printf function itself. Thus, the following two lines give us another way to print a percent sign:
    char percent = '%';
    printf("A percent sign we don't need to escape: %c\n", percent);
    // Because the percent sign appears as an argument after the format string and not inside the format string,
    // we don't need to escape it.
    
    // Despite it's apparent special treatment, characters are actually an integral data type just like int:
    char char1 = 10;
    char char2 = 23;
    printf("char1 + char2 = %c\n", char1 + char2);
    
    // Contrary to what you likely expected, that printf call will print an exclamation point instead of 33.
    // This is because C will always print a char when formatted with %c.
    // So how does 33 become the exclamation point?
    // The answer is through the ASCII table, which you may find at https://www.asciitable.com/.
    // To get what 33 corresponds to, look up 33 in the Dec (decimal/base 10) column, and the result is given in the
    // Chr column. Indeed, 33 corresponds to !.
    // If we want to actually see 33 as the result, we need to use the %d specifier:
    printf("char1 + char2 = %d\n", char1 + char2);
    
    // We can even use the exclamation point directly:
    printf("'!' = %d\n", '!');
    
    // Indeed, there is no functional difference between the following two lines:
    char1 = 33;
    char1 = '!';
    
    // So while characters are commonly used to represent digits, letters, and symbols, they may represent numbers as
    // well. Underneath it all, a char is just a single byte, and a byte is only capable of representing the integers
    // from 0 to 255, inclusive. Or, if you prefer, it may represent up to 255 different characters, which is
    // enough for common use cases.
    // The reason that chars are able to represent both numbers and symbols is that we have the freedom to *interpret*
    // the underlying byte (data) however we want: it may represent whatever we want a permutation of 8 switches
    // to represent. When we use the format specifier %c, we say it represents a character.
    // When we use %d, it represents a number.
    
    // So if the data type for single characters is char, what is the data type for strings, which is a sequence of
    // characters?
    // It is not string, like you might be inclined to guess:
    const char* my_string = "Hello World!";
    
    // Instead, the type of a string literal is const char*. "Hello World!" is a const char* literal.
    // We will learn much more about why this is the case when we talk about arrays and pointers.
    // Nonetheless, I will give a brief intuitive appeal here:
    // An asterisk after a type name is a different type that, practically speaking, could represent a sequence of that
    // type. Thus, "char*" is a way to refer to a sequence of chars, which speaks to our intuition of what a string is.
    // On the otherhand, the "const" is not essential to the concept of a string, however it IS essential when we
    // are talking about string LITERALS. Essentially, without the const, we could change the characters that appear
    // in a string literal. Without const, we could, for example, make the literal "Hello World!" actual refer to the
    // string "!dlroW olleH". 
    // Now you might be wondering why we don't have the same problem with a const int, for example:
    int my_int = 3;
    my_int = 4;
    printf("3 = %d\n", 3);
    
    // Indeed, the previous statement will print 3 = 3 (thank god). The difference in strings has to due with the
    // combined meaning of const when paired with the asterisk (*). So the following is also safe:
    char my_char = 'a';
    my_char = 'b';
    printf("'a' = %c\n", 'a'); 
    
    // Indeed, the previous statement will print 'a' = a (thank god). Nonetheless, if the type of string literals
    // was char* instead of const char*, we could imagine a language in which the following line prints 
    // "three fives?\n":
    printf("Hello World!\n");
    
    // Again, the reasons why will become clearer when we discuss pointers and arrays.
    
    // Sometimes, we want to to insert other strings into strings just like we do ints, doubles, or chars.
    // To do so, we may use the %s specifier:
    
    const char* my_name = "Babbo";
    
    printf("Hello, my name is %s.\n", my_name);
    
    // Note that, despite that apparent "constness" of const char*, we can change the value of my_name.
    // This is because the "const" refers to the characters *of* the string, not the string itself:
    my_name = "Bobba";
    printf("Hello, my name is %s.\n", my_name);
    
    // If we want a string that cannot change, we need to put a const after the asterisk:
    
    const char* const my_format_string = "Hello, my name is %s.\n";
    // my_format_string = "Bye, %s\n" // ERROR: my_format_string is const.
    my_name = "Obbab";
    printf(my_format_string, my_name);
    
    // Notice that I assigned the format string to a variable and used it as an argument to printf.
    // This demonstrates that format strings are not special: they are just like any other string and are just 
    // interpreted in a special way by the printf function. Thus, it is how the printf function "handles" the string
    // that is special, not the string itself.
    
    const char* a_string = "Hi!";
    int an_int = 5;
    double a_double = 1.41;
    char a_char = '*';
    
    // Here's an example that uses all format specifiers we have covered.
    const char* a_format_string = "%s is a string, %d is an int, %f is a double, and %c is a char\n";
    printf(a_format_string, a_string, an_int, a_double, a_char);
}