#include <cs50.h>
#include <stdio.h>

void draw(int h);

int main(void)
{
     int height = get_int("Altura: ");
     draw(height);
}


// usando loop
void draw(int h)
{
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= i; j++)
        {
             printf("#");
        }
        printf("\n");
     }
}
// usando recursividade
    void draw(int h)
    {
        if (h == 0)
        {
             return;
        }

        draw(h - 1);

        for (int i = 0; i < h; i++)
        {
             printf("#");
        }

        printf("\n");
    }

/*
    a função draw irá parar alguma hora, porém se a chamarmos muitas vezes
    causará stackoverflow
*/