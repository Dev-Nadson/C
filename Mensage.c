#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char name[25];
    printf("Digite seu nome: ");
    gets(name);

    printf("Olá, %s! Bem vindo!", name);

    return 0;
}