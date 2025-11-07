#include <stdio.h>

int num, cubo, op;

void calculaCubo()
{
    printf("--- Cubo de um numero ---\n");
    printf("Digite o numero: ");
    scanf("%d", &num);
    cubo = num * num;
    printf("\nCubo de %d = %d\n", num, cubo);
}