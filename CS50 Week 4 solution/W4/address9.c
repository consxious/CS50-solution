// Prints a string's chars

#include <stdio.h>
#include <cs50.h>

int main (void)
{
    string s = "HI!";
    printf("%c\n",s[0]);
    printf("%c\n",s[1]);
    printf("%c\n",s[2]);
    printf("%c\n",s[3]);
    // Begin to access other location that we shouldn't be. It could consist other values.
    printf("%c\n",s[4]);
    printf("%c\n",s[5]);
    printf("%c\n",s[6]);
}