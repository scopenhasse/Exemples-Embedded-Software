// passage par valeur

#include <stdio.h>

void change(unsigned long int a, unsigned long int b){
    long int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    unsigned long int a = 10,b=15;
    change(a,b);
    printf("a = %lu, b = %lu", a, b);
    return 0;
}

// Output:
// a = 10, b = 15

// the function change() is taking the values of the variables a and b.
// so this function is not able to modify the values of the variables a and b.
// the values of the variables a and b are not modified. out of the function change().
