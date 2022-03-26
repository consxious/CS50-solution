// Demonstrates memory errors via valgrind

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    // Declare pointer with memory allocation
    int *x = malloc(3 * sizeof(int));

    // Assign values into pointer
    // Should be starting from x[0] to x[2]
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;
    free(x);
}
