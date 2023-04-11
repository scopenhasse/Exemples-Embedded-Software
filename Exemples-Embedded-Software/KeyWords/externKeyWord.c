
#include <stdio.h>

extern int x; // Declare variable x as external
// the extern keyword is used to declare a variable that is defined elsewhere.
// The extern keyword is used to declare a global variable or function in another file.
// the variable x is defined in the file KeyWords/declarationExtern.c

int main() {
    printf("The value of x is %d\n", x);
    return 0;
}
