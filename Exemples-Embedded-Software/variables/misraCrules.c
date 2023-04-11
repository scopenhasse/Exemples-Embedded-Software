// this is a set of MISRA C rules and their associated checks


//Rule 5.1:
// two or more identifiers with external linkage shall not have the same name

int global_var;  // variable declared in the global namespace

void foo() {
    int local_var;  // variable declared in the local namespace
    // ...
}

// Rule 5.2:
// same variable name shall not be reused in the same scope

void foo2(int x) {
    int y;  // variable declaration
    // ...
    {
        int y;  // redeclaration of variable y within the same scope
        // ...
    }
}

// Rule 9.1:
// All automatic variables shall have been assigned a value before being used.

void foo3() {
    int x;  // variable declaration
    // ...
    x = 42;  // variable assignment
    // ...
    int y = x + 1;  // using variable x after initialization
    // ...
}




// Rule 12.2:
// The right hand operand of a logical && or || operator shall not contain persistent side effects.

int foo4() {
    // ...
}

int main(int argc, char const *argv[], char *envp[])
{
    int x = 1;
    if (x == 1 || foo4() == 0) {  // using a function call with a side effect as a logical operand
    // ...
    }


    // Rule 10.1:
    // The value of a composite expression shall not be cast to a narrower or different essential type.

    float f = 3.14;
    int i = (int)f;  // casting a float to an int
    
    return 0;
}

