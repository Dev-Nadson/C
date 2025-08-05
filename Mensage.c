#include <stdio.h>
#include <string.h>

int main()
{
    char name[25];
    printf("Digite seu nome: ");
    gets(name);

    printf("Olá, %s! Bem vindo!", name);

    return 0;
}