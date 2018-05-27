// This monstrosity of a program demonstrates that programs may also be inflated with extraneous whitespace
// in addition to being stripped of almost all whitespace.
// I have put every token that may be put on a separate line when it is possible to do so.
// Note that "#include" and "<stdio.h>" cannot be separated into two lines: however, large amounts of whitespace may be
// added between them.
// Also observe that I added no whitespace between the angle brackets (<>) containing "stdio.h": this results in C
// trying to find utilities with spaces in them and causes an error.

// Finally, note that "Hello World!\n" appears on its own line: putting more space inside the quotes would cause those
// extra spaces to be printed in the terminal.

#include                       <stdio.h>

  int
    main
      (
        void
          )
            {
              printf
                (
                  "Hello World!\n"
                    )
                      ;
                        return
                          0
                            ;
                              }
    