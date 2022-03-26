// Dangerously gets a string from user using scanf

#include <stdio.h>

int main(void)
{
    char s[4];
    printf("s: ");
    // If the user key in more than 4 or more char, it will lead to segmentation fault
    scanf("%s",s);
    printf("s: %s\n",s);
}