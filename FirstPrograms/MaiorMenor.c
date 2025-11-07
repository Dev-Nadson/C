#include <stdio.h>

int main()
{
    int num1 = 0;
    int num2 = 0;

    printf("Digite o valor do primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o valor do segundo número: ");
    scanf("%d", &num2);

    if (num1 > num2)
    {
        printf("O primeiro número %d é maior que o segundo %d", num1, num2);
    }
    else if (num2 > num1)
    {
        printf("O primeiro número %d é maior que o segundo %d", num1, num2);
    }
    else
    {
        printf("O primeiro número %d é igual ao segundo %d", num1, num2);
    }
}