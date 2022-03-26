#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    //Getting user input
    string s = get_string("Text : ");
    printf("%s\n", s);
    
    int letters = 0; //Count letters (upper & lower)
    int words = 1; //Count words
    int sentences = 0; //Count sentences
    for (int i = 0; i < strlen(s); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            letters++;
        }
        if (s[i] == ' ')
        {
            words++;
        }
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
    }
    //printf("%i letter(s)\n", letters);
    //printf("%i word(s)\n", words);
    //printf("%i sentence(s)\n", sentences);
    
    //Coleman-Liau index
    float grade = 0.0588 * (100 * (float)letters / (float)words) - 0.296 * (100 * (float)sentences / (float)words) - 15.8;
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    } 
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    } 
    else 
    {
        printf("Grade %.f\n", grade);
    }
}