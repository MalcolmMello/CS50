#include <stdio.h>
#include <stdlib.h>

/*
    VALGRIND
    ferramenta para encontrar erros "invisíveis" envolvendo alocação de memória por exemplo
*/

int main(void)
{
    char *s = malloc(3);
    s[0] = 'H';
    S[1] = 'I';
    S[2] = '!';
    S[3] = '\0';
}