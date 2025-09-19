#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define TAM 5

typedef struct
{
    int items[TAM];
    int start;
    int end;
} Queue;

void create(Queue *q)
{
    q->start = 0; // Início tem que ser maior que o fim!
    q->end = -1;
}

int isQueueFull(Queue *q)
{
    return q->end == TAM - 1;
}

int isQueueEmpty(Queue *q)
{
    return q->start > q->end;
}

void createQueue(Queue *q, int value)
{
    if (isQueueFull(q))
    {
        printf("Fila Cheia! Nao podemos enfileirar\n");
    }
    else
    {
        q->end++;
        q->items[q->end] = value;
        printf("O numero %d entrou na fila\n", value);
    }
}

int endQueue(Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Fila vazia, nao podemos desenfileirar!\n");
        return -1;
    }
    else
    {
        int removed = q->items[q->start];
        q->start++;
        printf("O numero %d foi removido da fila\n", removed);
        return removed;
    }
}

void showQueue(Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Fila vazia\n");
    }
    else
    {
        printf("Fila: ");
        for (int i = q->start; i <= q->end; i++)
        {
            printf("%d - ", q->items[i]);
        }
        printf("\n");
    }
}

int main(void)
{
    Queue q;
    create(&q);
    int option;
    int value;
    system("cls");

    do
    {
        printf("\n-==========- FILA -==========-");
        printf("\n1 - Enfileirar \n2 - Desenfileirar \n3 - Exibir fila \n0 - Sair \n");
        printf("--- Escolha uma opcao: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Digite um numero: ");
            scanf("%d", &value);
            createQueue(&q, value);
            break;
        case 2:
            endQueue(&q);
            break;
        case 3:
            showQueue(&q);
            break;
        case 0:
            printf("Saindo do sistema...");
            break;
        default:
            printf("Opcao invalida! ");
        }
    } while (option != 0);
    return 0;
}