#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if(argc == 2)
    {
        int key = atoi(argv[1]);

        if(key != 0)
        {
            string text = get_string("Plaintext: ");

            printf("Ciphertext: ");
            for(int i = 0, n = strlen(text); i < n; i++)
            {
                if(text[i] >= 'a' && text[i] <= 'z')
                {
                   if(text[i] + key > 'z')
                    {

                        int counter = 0;
                        int charCounter = text[i];
                        for(int j = 0; charCounter + 1 <= 'z'; j++)
                        {
                            counter++;
                            charCounter++;
                        }
                        char newAlphaBchar = 'z' - 26;
                        int newIndex = key - counter;
                        printf("%c", newAlphaBchar + newIndex);
                    }
                    else
                    {
                        printf("%c", text[i] + key);
                    }
                }
                else if(text[i] >= 'A' && text[i] <= 'Z')
                {
                    if(text[i] + key > 'Z')
                    {

                        int counter = 0;
                        int charCounter = text[i];
                        for(int j = 0; charCounter + 1 <= 'Z'; j++)
                        {
                            counter++;
                            charCounter++;
                        }
                        char newAlphaBchar = 'Z' - 26;
                        int newIndex = key - counter;
                        printf("%c", newAlphaBchar + newIndex);
                    }
                    else
                    {
                        printf("%c", text[i] + key);
                    }
                }
                else
                {
                    printf("%c", text[i]);
                }
            }
            printf("\n");
        }
        else
        {
            printf("Type a intenger number bigger than 0!\n");
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
    }
}
