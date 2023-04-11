
#include <stdio.h>

struct exempleStruct {
    int a;
    int b;
    int c;
};

union exempleUnion {
    int a;
    int b;
    int c;
};


int main() {
    struct exempleStruct e;
    e.a = 1;
    e.b = 2;
    e.c = 3;
    printf("e.a = %d\n", e.a);
    printf("e.b = %d\n", e.b);
    printf("e.c = %d\n", e.c);

    union exempleUnion u;
    u.a = 1;
    u.b = 2;
    u.c = 4;
    printf("u.a = %d\n", u.a);
    printf("u.b = %d\n", u.b);
    printf("u.c = %d\n", u.c);
    return 0;
}

// the output is:
// e.a = 1
// e.b = 2
// e.c = 3
// u.a = 4
// u.b = 4
// u.c = 4

// The union exempleUnion is a special case of the struct exempleStruct.
// The difference is that the union exempleUnion uses the same memory space for all its members.
// this leads to the fact that the last value assigned to a member of the union exempleUnion is the only one that is kept.








