// Prints address of first char of a string

#include <cs50.h>
#include <stdio.h>

int main (void)
{
    string s = "HI!";
    char c = s[0];
    // 1st char of the string is copied into char c
    char *p = &c;
    printf("%p\n",p);
}