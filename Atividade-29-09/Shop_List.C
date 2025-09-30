#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    char item[30];
    int quantidade;
    struct No *prox;
} No;

No *criar(const char *texto, int qtd)
{
    No *novo = (No *)malloc(sizeof(No));
    if (!novo)
    {
        printf("Erro de memória!\n");
        exit(1);
    }

    strncpy(novo->item, texto, sizeof(novo->item));
    novo->item[sizeof(novo->item) - 1] = '\0';

    novo->quantidade = qtd;
    novo->prox = NULL;
    return novo;
}

No *buscar(No *cabeca, const char *item_busca)
{
    No *atual = cabeca;
    while (atual != NULL)
    {
        if (strcmp(atual->item, item_busca) == 0)
            return atual;
        atual = atual->prox;
    }
    return NULL;
}

void adicionar(No **cabeca, const char *texto, int qtd)
{
    No *existente = buscar(*cabeca, texto);

    if (existente != NULL)
    {
        existente->quantidade += qtd;
        printf("Item atualizado: %s: %d\n", existente->item, existente->quantidade);
        return;
    }
    No *novo = criar(texto, qtd);

    if (*cabeca == NULL)
    {
        *cabeca = novo;
    }
    else
    {
        No *atual = *cabeca;
        while (atual->prox != NULL)
            atual = atual->prox;
        atual->prox = novo;
    }
    printf("Item adicionado: %s: %d\n", texto, qtd);
}

int remover(No **cabeca, const char *alvo_rem)
{
    No *atual = *cabeca, *anterior = NULL;
    while (atual && strcmp(atual->item, alvo_rem) != 0)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (!atual)
        return 0;

    if (!anterior)
        *cabeca = atual->prox;
    else
        anterior->prox = atual->prox;

    free(atual);
    return 1;
}

void listar(No *cabeca)
{
    if (!cabeca)
    {
        printf("Lista de compras vazia.\n");
        return;
    }

    printf("\n-===== Lista de Compras =====-\n");
    for (No *dado = cabeca; dado != NULL; dado = dado->prox)
    {
        printf("%s: %d\n", dado->item, dado->quantidade);
    }
}

void limpar(No *cabeca)
{
    while (cabeca)
    {
        No *prox = cabeca->prox;
        free(cabeca);
        cabeca = prox;
    }
}

int main(void)
{
    No *lista = NULL;
    int opcao = -1;
    char item[30];
    int quantidade;

    while (opcao != 0)
    {
        puts("\n-===== Lista de Compras =====-");
        puts("1) ADD item (adicionar)");
        puts("2) Remover item ");
        puts("3) Listar itens ");
        puts("0) Sair ");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1)
        {
            puts("Entrada inválida.");
            break;
        }
        getchar();

        switch (opcao)
        {
        case 1:
            printf("Nome do item: ");
            if (scanf("%[^\n]", item) != 1)
            {
                puts("Entrada inválida");
                break;
            }
            getchar();

            printf("Quantidade: ");
            if (scanf("%d", &quantidade) != 1)
            {
                puts("Quantidade inválida");
                break;
            }
            getchar();

            if (quantidade <= 0)
            {
                puts("Quantidade deve ser maior que zero!");
                break;
            }

            adicionar(&lista, item, quantidade);
            break;

        case 2:
            printf("Item a ser removido: ");
            if (scanf("%[^\n]", item) != 1)
            {
                puts("Entrada invalida");
                break;
            }
            getchar();
            if (remover(&lista, item))
                puts("Item removido!");
            else
                puts("Item não encontrado!");
            break;

        case 3:
            listar(lista);
            break;

        case 0:
            puts("Encerrado");
            break;

        default:
            puts("Opcao invalida");
            break;
        }
    }

    limpar(lista);
    return 0;
}