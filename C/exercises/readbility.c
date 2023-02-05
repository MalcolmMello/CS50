#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    string text = get_string("Write your text: ");
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i] != ' ')
        {
            letters++;
        }
        if(text[i] == ' ')
        {
            words++;
        }
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    };

    float L = (letters/(float)words) * 100;
    float S = (sentences/(float)words) * 100;

    float index = round(0.0588 * L - 0.296 * S - 15.8);

    if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %f\n", index);
    }
}