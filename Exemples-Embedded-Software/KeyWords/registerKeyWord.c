#include <stdio.h>

void sum(int n)
{
    register int i; // register variable declaration
    register int sum = 0; // register variable initialization
    
    for (i = 1; i <= n; i++) {
        sum += i; // add current value of i to sum
    }
    
    printf("Sum of first %d natural numbers is %d\n", n, sum);
}

int main()
{
    sum(10);
    sum(100);
    return 0;
}


/* 
if you run the command " objdump -d registerKeyWord.o " you will see that the register variable is not stored in memory, but is stored in a register.
by the use of edx instead of [ebp-0x4] in the assembly code.
this might not be the case for all compilers, but it is the case for gcc.
the registre keyword does not mean that the variable is stored in a register, but that the compiler is allowed to store the variable in a register.
which means that the compiler is allowed to optimize the code by storing the variable in a register, if it thinks that it is a good idea.
this is useful for optimizing the code, because the register variable is stored in a register, which is faster than memory.

*/