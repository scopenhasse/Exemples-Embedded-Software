#include <stdio.h>

void increment_and_print()
{
    static int count = 0; // static variable initialization
    count++; // increment static variable
    printf("Count is now %d\n", count);
}

int main()
{
    increment_and_print();
    increment_and_print();
    increment_and_print();
    return 0;
}

/*
Output:
Count is now 1
Count is now 2
Count is now 3

as you can see, the static variable is initialized only once, and its value is retained between function calls.
which means that the static variable is not destroyed when the function is exited, but is kept in memory for the next time the function is called.
this is useful for keeping track of how many times a function has been called. 
and optimizing the code by not having to reinitialize the variable every time the function is called.

*/