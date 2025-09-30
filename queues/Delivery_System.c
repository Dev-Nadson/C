#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pedido
{
    int id_pedido;
    char nome_cliente[50];
    struct Pedido *prox;
} Pedido;

Pedido *criar_pedido(int id, const char *cliente)
{
    Pedido *novo = (Pedido *)malloc(sizeof(Pedido));
    if (!novo)
    {
        printf("Erro de memória!\n");
        exit(1);
    }

    novo->id_pedido = id;
    strncpy(novo->nome_cliente, cliente, sizeof(novo->nome_cliente));
    novo->nome_cliente[sizeof(novo->nome_cliente) - 1] = '\0';

    novo->prox = NULL;
    return novo;
}

int buscar_pedido(Pedido *cabeca, int id)
{
    Pedido *atual = cabeca;
    while (atual)
    {
        if (atual->id_pedido == id)
            return 1;
        atual = atual->prox;
    }
    return 0;
}

void cadastrar_pedido(Pedido **cabeca, int id, const char *cliente)
{

    Pedido *novo = criar_pedido(id, cliente);
    if (*cabeca == NULL)
    {
        *cabeca = novo;
    }
    else
    {

        Pedido *atual = *cabeca;
        while (atual->prox != NULL)
            atual = atual->prox;
        atual->prox = novo;
    }

    printf("✓ Pedido cadastrado com sucesso!\n");
    printf("  ID: %d do Cliente: %s\n", id, cliente);
}

int marcar_entregue(Pedido **cabeca, int id)
{
    Pedido *atual = *cabeca, *anterior = NULL;

    while (atual && atual->id_pedido != id)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (!atual)
        return 0;

    char cliente_temp[50];
    strncpy(cliente_temp, atual->nome_cliente, sizeof(cliente_temp));
    cliente_temp[sizeof(cliente_temp) - 1] = '\0';

    if (!anterior)
        *cabeca = atual->prox;
    else
        anterior->prox = atual->prox;

    free(atual);

    printf("Pedido numero: %d do cliente: (%s) entregue e removido da lista!\n", id, cliente_temp);
    return 1;
}

void listar_pendentes(Pedido *cabeca)
{
    if (!cabeca)
    {
        printf("Nenhum pedido pendente no momento\n");
        return;
    }

    int contador = 0;
    Pedido *temp = cabeca;

    while (temp)
    {
        contador++;
        temp = temp->prox;
    }

    printf("PEDIDOS PENDENTES (%d)\n", contador);
    for (Pedido *dado = cabeca; dado != NULL; dado = dado->prox)
    {
        printf("ID: %d | Cliente: %s\n", dado->id_pedido, dado->nome_cliente);
    }
}

void limpar_pedidos(Pedido *cabeca)
{
    while (cabeca)
    {
        Pedido *prox = cabeca->prox;
        free(cabeca);
        cabeca = prox;
    }
}

int main(void)
{
    Pedido *lista_pedidos = NULL;
    int opcao = -1;
    int id_pedido;
    char nome_cliente[50];
    int proximo_id = 0;

    while (opcao != 0)
    {
        printf("-========== Menu Principal ==========-\n");
        printf("1 - Cadastrar novo pedido\n");
        printf("2 - Marcar pedido como ENTREGUE\n");
        printf("3 - Listar pedidos pendentes\n");
        printf("0 - Sair do sistema\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &opcao) != 1)
        {
            puts("Entrada inválida. Tente novamente.");
            while (getchar() != '\n')
                ;
            continue;
        }
        getchar();

        switch (opcao)
        {
        case 1:
            printf("\n=== CADASTRAR NOVO PEDIDO ===\n");
            printf("ID do pedido: ");

            scanf("%d", &id_pedido);
            getchar();

            printf("Nome do cliente: ");
            scanf("%[^\n]", nome_cliente);
            getchar();

            cadastrar_pedido(&lista_pedidos, id_pedido, nome_cliente);

            if (id_pedido >= proximo_id)
                proximo_id = id_pedido + 1;
            break;

        case 2:
            if (!lista_pedidos)
            {
                printf("\nNenhum pedido pendente para entregar!\n");
                break;
            }

            printf("\n=== MARCAR PEDIDO COMO ENTREGUE ===\n");
            listar_pendentes(lista_pedidos);

            printf("ID do pedido entregue: ");
            if (scanf("%d", &id_pedido) != 1)
            {
                puts("ID inválido");
                while (getchar() != '\n')
                    ;
                break;
            }
            getchar();

            if (!marcar_entregue(&lista_pedidos, id_pedido))
            {
                printf("Pedido numero: %d não encontrado na lista!\n", id_pedido);
            }
            else
            {
                printf("\n Lista atualizada após entrega:\n");
                listar_pendentes(lista_pedidos);
            }
            break;

        case 3:
            listar_pendentes(lista_pedidos);
            break;

        case 0:
            printf("Encerrando o sistema\n");
            break;

        default:
            puts("Opção inválida!");
            break;
        }
    }

    limpar_pedidos(lista_pedidos);
    return 0;
}