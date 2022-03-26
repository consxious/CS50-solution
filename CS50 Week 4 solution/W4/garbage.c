// Take a peek into garbage values
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    //Create an array of 3
    int scores[3];

    //Print 3 random garbage values
    //scores[0] have big random values
    //scores[1] have 3276X
    //scores[2] have 0
    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", scores[i]);
    }
}

