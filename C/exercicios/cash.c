#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float requiredChange;

    do
    {
        requiredChange = get_float("Hom many is your change? ");
        if(requiredChange < 0)
        {
            printf("Type a positive number!\n");
        }
    } while(requiredChange < 0);

    int dollarsToCents = round(requiredChange * 100);
    float change = 0;
    int coinsAmount = 0;

    for(int i = 0; change < dollarsToCents; i++)
    {
        if(change + 25 <= dollarsToCents)
        {
            change += 25;
            coinsAmount++;
        }
        else if(change + 10 <= dollarsToCents)
        {
            change += 10;
            coinsAmount++;
        }
        else if(change + 5 <= dollarsToCents)
        {
            change += 5;
            coinsAmount++;
        }
        else if(change + 1 <= dollarsToCents)
        {
            change += 1;
            coinsAmount++;
        }
    }

    printf("%i\n", coinsAmount);
}
