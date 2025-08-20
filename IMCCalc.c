#include <stdio.h>

float IMC(float height, float weight)
{
    return (weight / (height * height));
}

int main()
{
    float height = 0;
    float weight = 0;

    printf("Insira a sua altura: ");
    scanf("%f", &height);
    printf("Insira a seu peso: ");
    scanf("%f", &weight);

    if (height < 0 || weight < 0)
    {
        return printf("Altura ou peso inválidos \n");
    };

    float imc = IMC(height, weight);
    printf("O seu IMC é %.2f ", imc);
    if (imc < 20)
    {
        printf("Abaixo do peso");
    }
    else if (imc > 20 && imc < 30)
    {
        printf("Peso ideal");
    }
    else if (imc > 30 && imc < 35)
    {
        printf("Obeso");
    }
    else if (imc > 35)
    {
        printf("Muito Obeso");
    };
    return 0;
}