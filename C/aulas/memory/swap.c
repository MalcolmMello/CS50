#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b)
{
    int tmp = *a;

    *a = *b;

    *b = tmp;
}

/*
    MEMORY LAYOUT
    
    machine code = where all the 0's and 1's are
    globals = global variables;
    heap = where malloc uses memory;
    stack = my own functions like main or whatever I create;
    
    stackoverflow: use so many memory that stack area will overflow heap area and my program will crash
    buffer: going beyond the bounderes of that array or mallock
*/