#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 6
#define NAME_LEN 30

typedef struct
{
    int top;
    char Elem[LEN][NAME_LEN];
} Stack;

void make(Stack *s)
{
    s->top = -1;
}

int isEmptyStack(Stack *s)
{
    return (s->top == -1);
}

int isFullStack(Stack *s)
{
    return (s->top == LEN - 1);
}

void empilhar(Stack *s, char caixa[])
{
    if (isFullStack(s))
    {
        printf("\nA pilha está cheia! Não é possível adicionar mais caixas.\n\n");
    }
    else
    {
        s->top++;
        strcpy(s->Elem[s->top], caixa);
        printf("%s foi empilhada!\n\n", caixa);
    }
}

void desempilhar(Stack *s)
{
    if (isEmptyStack(s))
    {
        printf("\nA pilha está vazia! Nenhuma caixa para remover.\n\n");
    }
    else
    {
        printf("%s foi removida do topo da pilha!\n\n", s->Elem[s->top]);
        s->top--;
    }
}

void mostrarTopo(Stack *s)
{
    if (isEmptyStack(s))
    {
        printf("\nA pilha está vazia!\n\n");
    }
    else
    {
        printf("\nCaixa no topo: %s\n\n", s->Elem[s->top]);
    }
}

void listar(Stack *s)
{
    if (isEmptyStack(s))
    {
        printf("\nA pilha está vazia!\n\n");
    }
    else
    {
        printf("\nCaixas empilhadas: \n");
        for (int i = s->top; i >= 0; i--)
        {
            printf("%d. %s\n", (s->top - i) + 1, s->Elem[i]);
        }
        printf("\n");
    }
}

int main()
{
    Stack pilha;
    make(&pilha);

    int option;
    char nome[NAME_LEN];

    system("clear");
    do
    {
        printf("\n======== PILHA DE CAIXAS NO DEPÓSITO ========\n");
        printf("1. Empilhar \n2. Desempilhar \n3. Topo \n4. Listar \n0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Digite o nome da caixa (ex: Caixa1): ");
            scanf("%f", nome);
            empilhar(&pilha, nome);
            break;

        case 2:
            desempilhar(&pilha);
            break;

        case 3:
            mostrarTopo(&pilha);
            break;

        case 4:
            listar(&pilha);
            break;

        case 0:
            printf("Encerrando o programa...\n");
            break;

        default:
            printf("\nOpção inválida!\n");
            break;
        }
    } while (option != 0);

    return 0;
}
