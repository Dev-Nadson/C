#include <stdio.h>

int Sum(int number){
    int sum = 0;
    int i = 1;
    if (number <= 0) {
        printf("Erro: Por favor, digite um numero inteiro positivo.\n");
        return 1;
    }

    while (i <= number) {
        sum += i;
        i++;
    }
    return sum;
}

int main() {
    int number;
    printf("Digite um numero: ");
    scanf("%d", &number);

    printf("A soma de todos os numeros ate %d e: %d\n", number, Sum(number));
    return 0;
}
