#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 6
#define NAME_LEN 50

typedef struct
{
    char items[LEN][NAME_LEN];
    int first, last, length;
} Queue;

void init(Queue *q)
{
    q->first = 0;
    q->last = LEN - 1;
    q->length = 0;
}

int isFullQueue(Queue *q)
{
    return q->length == LEN;
}

int isEmptyQueue(Queue *q)
{
    return q->length == 0;
}

void entrar(Queue *q, char nome[])
{
    if (isFullQueue(q))
    {
        printf("Fila cheia! Não é possível adicionar mais clientes.\n\n");
    }
    else
    {
        q->last = (q->last + 1) % LEN;
        strcpy(q->items[q->last], nome);
        q->length++;
        printf("%s entrou na fila!\n\n", nome);
    }
}

void atender(Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("Fila vazia! Nenhum cliente para atender.\n\n");
    }
    else
    {
        printf("%s foi atendido e saiu da fila!\n\n", q->items[q->first]);
        q->first = (q->first + 1) % LEN;
        q->length--;
    }
}

void listar(Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("A fila está vazia!\n\n");
    }
    else
    {
        printf("Clientes na fila:\n");
        int i = q->first;
        for (int count = 0; count < q->length; count++)
        {
            printf("%d. %s\n", count + 1, q->items[i]);
            i = (i + 1) % LEN;
        }
        printf("\n");
    }
}

int main()
{
    Queue q;
    init(&q);

    int option;
    char nome[NAME_LEN];

    system("clear");
    do
    {
        printf("======== FILA DE ATENDIMENTO ========\n\n");
        printf("1. Entrar \n2. Atender \n3. Listar \n0. Sair");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Digite o nome do cliente: ");
            scanf("%f", nome);
            entrar(&q, nome);
            break;

        case 2:
            atender(&q);
            break;

        case 3:
            listar(&q);
            break;

        case 0:
            printf("Encerrando o programa...\n");
            break;

        default:
            printf("Opção inválida!\n\n");
        }

    } while (option != 0);
    return 0;
}
