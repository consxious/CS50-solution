// Incorrectly gets a string from user using scanf

#include <stdio.h>

int main (void)
{
    char *s;
    printf("s: ");
    // Error as s = NULL and uninitialliazed
    scanf("%s",s);
    printf("s: %s\n",s);
}