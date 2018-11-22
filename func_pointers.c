#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int product(int a, int b) {
    return a * b;
}

int sum(int a, int b) {
    return a + b;
}

int difference(int a, int b) {
    return a - b;
}


// The syntax for a function pointer is a little barbaric
// We definitely do not wan to type it more than once
// So we create an alias using typedef
// Note that the typedef syntax is a litle unusual
typedef int (*OperationPointer)(int a, int b);


OperationPointer get_operation(char op) {

    switch (op) {
    case '*':
        return &product;
        break;
    case '+':
        return &sum;
        break;
    case '-':
        return &difference;
        break;
    default:
        printf("Operation %c is not supported\n",op);
        exit(1);
    }

}


void usage() {

  printf("Enter an arithmetic expressions of the form: INT OP INT\n");
  printf("Note: make sure to escape any special characters such as *\n");

}

/*
 * This program is a simple integer calculator
 */
int main(int argc, char** argv) {
    
    if ( argc < 4 ) {
        usage();
        return 1;
    }

    // We should perform error checking on the arguments
    // We skip this step to simplify the example
    int x = atoi(argv[1]);
    char op = argv[2][0];
    int y = atoi(argv[3]);
    

    // First find the appropriate operation
    OperationPointer operation = get_operation(op);

    // Now execute it
    int result = operation(x,y);
    
    // Finally, print the result
    printf("Nicer method:    %d %c %d = %d \n",x,op,y,result); 




    // We can do it all in one step:
    printf("Faster method:   %d %c %d = %d \n",x,op,y,get_operation(op)(x,y)); 
    


    // Same as above but without the typedef... just to show you why we really
    // want to use typedefs here
    int (*my_operation)(int a, int b) = get_operation(op);
    int r1 = (*my_operation)(x,y);
    int r2 = my_operation(x,y);
    printf("Uglier method:   %d %c %d = %d \n",x,op,y,r1); 
    printf("This also works: %d %c %d = %d \n",x,op,y,r2); 


    return 0;

}
