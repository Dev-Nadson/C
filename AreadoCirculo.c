#include <stdio.h>

float areaO(float raio)
{
    float pi = 3.1416;
    return ((raio * raio) * pi);
}

int main()
{
    float raio;
    printf("Insira o raio do círculo: ");
    scanf("%f", &raio);
    printf("%.2f", areaO(raio));
    return 0;
}