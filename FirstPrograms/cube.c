#include "cube.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Deseja calcular outro valor do cubo? 1-Sim ou 0-Nao\n");
    scanf("%d", &op);
    if (op == 1)
    {
        calculaCubo();
    }
    else

    {
        printf("Finalizando o programa......");
    }
    return 0;
}