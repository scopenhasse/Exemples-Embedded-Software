#include <stdio.h>


int main() {
    volatile int x = 10;
    int y = 0;

    while (x == 10) {
        y++;
    }

    printf("The value of y is %d\n", y);

    return 0;
}


/*
in this snippet, the volatile keyword is used to tell the compiler that the variable x is volatile.
volatile means that the variable can change at any time, and that the compiler should not make any assumptions about the value of the variable.
The value of y is 29443446
the value of x is 10, but the value of y is not 0, but 29443446. this means that the compiler made an assumption about the value of x, and that the while loop was not executed.
*/