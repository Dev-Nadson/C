#include <stdio.h>
#define LEN 4

typedef struct
{
    int top, total;
    float Elem[LEN];
} Stack;

void make(Stack *s)
{
    s->top = -1;
    s->total = LEN;
}

int isEmptyStack(Stack *s)
{
    return (s->top == -1);
}

int isFullStack(Stack *s)
{
    return (s->top == s->total - 1);
}

void initStack(Stack *s, float data)
{
    if (!isFullStack(s))
    {
        s->top++;
        s->Elem[s->top] = data;
    }
    else
    {
        printf("Fila cheia!\n\n");
    }
}

float endStack(Stack *s)
{
    if (isEmptyStack(s))
    {
        printf("Fila Vazia!\n\n");
        return -1;
    }
    else
    {
        float data = s->Elem[s->top];
        s->top--;
        printf("%.1f Foi removido da fila!", data);
    }
}

float showTop(Stack *s)
{
    if (!isEmptyStack(s))
    {
        return s->Elem[s->top];
    }
    printf("\nPilha vazia!");
    return -1;
}

int main()
{
    Stack newStack;
    int option;
    float value;
    make(&newStack);

    system("clear");
    do
    {
        printf("\n-======== Teste de Pilha ========-\n\n");
        printf("1. Empilhar \n2. Desempilhar \n3. Mostrar Topo \n4. Sair\n");
        printf("Selecione uma opção: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nDigite um número:");
            scanf("%f", &value);
            initStack(&newStack, value);
            printf("O valor %.1f foi adicionado a fila", value);
            break;

        case 2:
            endStack(&newStack);
            break;

        case 3:
            value = showTop(&newStack);
            if (value != -1)
            {
                printf("O valor do topo é %.1f", value);
            }
            break;

        case 4:
            printf("Saindo do sistema");
            break;

        default:
            break;
        }
    } while (option != 4);

    return 0;
}