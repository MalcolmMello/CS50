#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if(argc == 2)
    {
        string key = argv[1];

        if(strlen(key) < 26)
        {
            printf("Key must contains 26 characters and only alphabetic characters.");
        };

        for(int i = 0, n = strlen(key); i < n; i++)
        {
            if(!isalpha(key[i]))
            {
                printf("Key must only contains alphabetic characters.");
            };
        };

        string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string abc = "abcdefghijklmnopqrstuvwxyz";
        string text = get_string("Plaintext: ");

        printf("Ciphertext: ");

        for(int j = 0, m = strlen(text); j < m; j++)
        {
            int abcIndex = 0;
            if(text[j] == '!' || text[j] == '?' || text[j] == '.' || text[j] == ',' || text[j] == ' ')
            {
                printf("%c", text[j]);
            }
            else
            {
                for(int k = 0, o = strlen(ABC); k < o; k++)
                {
                    if(text[j] >= 'A' && text[j] <= 'Z')
                    {
                        if(ABC[k] != text[j])
                        {
                            abcIndex++;
                        }
                        else
                        {
                            printf("%c", toupper(key[abcIndex]));
                        }
                    }
                    else if(text[j] >= 'a' && text[j] <= 'z')
                    {
                        if(abc[k] != text[j])
                        {
                            abcIndex++;
                        }
                        else
                        {
                            printf("%c", tolower(key[abcIndex]));
                        }
                    }
                }
            }
        }
        printf("\n");
    }
    else
    {
         printf("Usage: ./substitution key\n");
    }
}