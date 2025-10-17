#include <stdio.h>
#define LEN 6

typedef struct
{
    int items[LEN], first, last, lenth;
} Queue;

void init(Queue *q)
{
    q->first = 0;
    q->last = LEN - 1;
    q->lenth = 0;
}

int isFullQueue(Queue *q)
{
    return q->lenth == LEN;
}

int isEmptyQueue(Queue *q)
{
    return q->lenth == 0;
}

void makeQueue(Queue *q, int value)
{
    if (isFullQueue(q))
    {
        printf("Fila Cheia, não é possível enfileirar\n\n");
    }
    else
    {
        q->last = (q->last + 1) % LEN;
        q->items[q->last] = value;
        q->lenth++;
        printf("%d Adicionado na fila!\n\n", value);
    }
}

int endQueue(Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("Fila vazia, não é possível desenfileirar\n\n");
    }
    else
    {
        int removed = q->items[q->first];
        q->first = (q->first + 1) % LEN;
        q->lenth--;
        printf("%d Saiu da fila!\n\n", removed);
    }
}

void showQueue(Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("A fila está vazia!\n\n");
    }
    else
    {
        printf("Fila: ");
        int i = q->first;
        for (int index = 0; index < q->lenth; index++)
        {
            printf("%d - ", q->items[i]);
            i = (i + 1) % LEN;
        }
        printf("\n");
    }
}

int main()
{
    Queue q;
    init(&q);
    int option, value;

    system("clear");
    do
    {
        printf("-======== SISTEMA DE FILA CIRCULAR ========-\n\n");
        printf("1. Enfileirar \n2.Desenfileirar \n3.Exibir \n0.sair \nEscolha uma opção: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Digite o valor para enfileirar: ");
            scanf("%d", &value);
            makeQueue(&q, value);
            break;

        case 2:
            endQueue(&q);
            break;

        case 3:
            showQueue(&q);
            break;

        case 0:
            printf("Encerrando o programa...");

        default:
            break;
        };
    } while (option != 0);

    return 0;
}