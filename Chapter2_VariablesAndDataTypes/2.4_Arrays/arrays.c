// In this lesson, we will go over how strings are sequences of chars, and how to build strings one 
// char at a time.

#include <stdio.h>

int main(void) {
    // In the previous lesson, we saw how we may assign string literals to variables.
    // This lesson will show us how to make strings from individual characters.
    // The following line declares what is called an "array" of chars with "length" 6.
    char my_char_array[6];
    
    // An array is simply a sequence of a single data type, in this case char.
    // We can change the value of an array "element" with the following square bracket syntax.
    my_char_array[0] = 'H';
    
    // The previous line assigns the first element of my_char_array, which is at "index" 0, to the character 'H'.
    // Arrays in C are 0-indexed, meaning the first element is at index 0, the second is at 1, and so on.
    // Thus for our length 6 array, the index of the last element is 5.
    // For an array of length N, the index of the last element is N - 1.
    
    // Like declared but unassigned variables, the other elements in the array have undefined values until we
    // assign them, so let's do that.
    my_char_array[1] = 'e';
    my_char_array[2] = 'l';
    my_char_array[3] = 'l';
    my_char_array[4] = 'o';
    
    // We have now assigned all but the last element. As you can see, we have made assignments to my_char_array so
    // that the first five chars spell out "Hello".
    // Indeed, my_char_array resembles a string, but may we print it?
    // Almost. When a C program is printing a string, it does not know the length of the string.
    // Thus, when we show the program a piece of memory and say "this is the start of a string", the program does
    // not immediately know how many chars will be printed until it stops.
    // You might think "Alright, well the program should just print until it reaches the end of the array."
    // However, the program does not even know the length of the array.
    // To understand why, you must first understand that memory itself (be it harddisk or RAM) is a
    // sequence of bytes, and these bytes are not fundamentally special or otherwise distinguishable from each
    // other. The ONLY information that a C program uses to print out a string is where the byte of the FIRST
    // char in the string is located in memory. Arrays are "contiguous" in memory, meaning each element in the array
    // immediately follows the previous element of the array in memory. But again, C does not know the length of the
    // array, so it cannot infer that the last element in the array is indeed the last element, and it will 
    // continue to print chars in memory, starting with the first char in the array and possibly not stopping until
    // long after it has read many chars PAST the end of the array. When does it stop? The program will stop
    // printing chars in a string when it encounters what is called the "null" character. The null character is the
    // character corresponding to the value 0 (refer again to the ASCII table). The null character has the
    // literal representation '\0' and effectively denotes the end of a string. Thus, to complete our "Hello"
    // string, we should make the last char the null character.
    my_char_array[5] = '\0';
    
    // Now we can print our string.
    printf("%s\n", my_char_array);
    
    // Note that it is a security risk to use strings other than string literals  or const char* to as the first 
    // argument to printf (the "format string"). 
    // Thus, we will not be using strings created in this way as format strings.
    
    // Note that we are not required to to put the null character at the end of the array.
    // In fact, it is often desirable to put the null character in the middle of array for reasons that will
    // be explained in the next lesson.
    // The following will result in "Hell" being printed to the terminal.
    my_char_array[4] = '\0';
    printf("%s\n", my_char_array);
    
    // Constructing strings one character at a time is clearly quite tedious.
    // We may actually initialize char arrays with string literals.
    char my_string[3] = "Hi";
    
    // Note again that the array length is 3 even though there are only 2 characters in Hi, so that the null
    // character is added at the end. This is done automatically for us.
    printf("%s\n", my_string);
    
    // While initialization to string literals is fine, assigning a char array to a string literal outside of 
    // initialization is not allowed.
    // my_string = "Yo"; // ERROR
    
    // We can omit the length when initialization an array in this way, if we want.
    char my_other_string[] = "Goodbye"; // Notice how there is no number between the brackets.
    
    // We may also use a much more verbose and explicit initialization syntax.
    char my_other_char_array[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    printf("%s\n", my_other_char_array);
    
    // That syntax is not preferred for initializing strings, but it is nice for initializing 
    // arrays of other data types.
    int my_int_array[] = {3, -5, 17};
    
    printf("my_int_array[0] = %d\n", my_int_array[0]);
    printf("my_int_array[1] = %d\n", my_int_array[1]);
    printf("my_int_array[2] = %d\n", my_int_array[2]);
    
    // We will give more attention to arrays of data types other than char when it becomes more useful to us.
    // For now, we will just be using char arrays for string manipulation.
}