// This program is a variant of the hello world example we did in lesson 1.
// It demonstrates that while white space may make your program neater, it is often unnecessary and most of it may be
// removed. This program does the same thing as the first hello world program but with as much whitespace removed as
// possible. Note that "#include<stdio.h>" must still be on its own line: this is true for all lines starting with #.
// Additionally, note that we cannot squeeze "int main" into "intmain": it is important that "int" and "main" be
// interpretted as different sequences of alphanumeric (letters and numbers) characters. Such sequences are often
// called "tokens", and they are "parsed" by the compiler.

#include<stdio.h>
int main(void){printf("Hello World!\n");return 0;}