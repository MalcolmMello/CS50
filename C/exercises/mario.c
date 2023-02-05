#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Only let the user choose between 1 and 8
    int n;
    do
    {
        n = get_int("Number of columns: ");
        if(n > 8 || n < 1)
        {
            printf("Choose a number between 1 and 8!\n");
        }
    }
    while(n > 8 || n < 1);

    // Constant for the loop 2
    int k = 1;
    // Constant for the loop 3
    int y = n - 1;

    // Number of rows
    for(int i = 0; i < n; i++)
    {
        // Number of dots in the row
        for(int x = 0; x < y; x++)
        {
            printf(" ");
        }
        y--;

        // Number of hashes in the row
        for(int j = 0; j < k; j++)
        {
            printf("#");
        }
        printf(" ");
        for(int u = 0; u < k; u++)
        {
            printf("#");
        }
        printf("\n");
        k++;
    }
}