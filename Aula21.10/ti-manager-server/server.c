#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOME 50
#define MAX_DESCRICAO 100
#define ARQ_OS "dados_os.txt"
#define ARQ_ESTOQUE "dados_estoque.txt"
#define MAX_OS 100
#define MAX_ESTOQUE 50

typedef struct
{
    int id;
    char cliente_nome[MAX_NOME];
    char telefone[15];
    char equipamento[MAX_NOME];
    char problema_relatado[MAX_DESCRICAO];
    char status[20];
    float valor_servico;
    char pecas_usadas[MAX_DESCRICAO];
} OrdemServico;

typedef struct
{
    int id;
    char nome[MAX_NOME];
    int quantidade;
    int estoque_minimo;
} ItemEstoque;

OrdemServico lista_os[MAX_OS];
int total_os = 0;
ItemEstoque lista_estoque[MAX_ESTOQUE];
int total_estoque = 0;

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void ler_string_segura(char *destino, int tamanho)
{
    fgets(destino, tamanho, stdin);
    destino[strcspn(destino, "\n")] = 0;
}

void salvar_os()
{
    FILE *f = fopen(ARQ_OS, "w");
    if (f == NULL)
    {
        printf("ERRO: Nao foi possivel salvar as Ordens de Servico.\n");
        return;
    }
    for (int i = 0; i < total_os; i++)
    {
        fprintf(f, "%d|%s|%s|%s|%s|%s|%.2f|%s\n",
                lista_os[i].id,
                lista_os[i].cliente_nome,
                lista_os[i].telefone,
                lista_os[i].equipamento,
                lista_os[i].problema_relatado,
                lista_os[i].status,
                lista_os[i].valor_servico,
                lista_os[i].pecas_usadas);
    }
    fclose(f);
}

void carregar_os()
{
    FILE *f = fopen(ARQ_OS, "r");
    if (f == NULL)
    {

        total_os = 0;
        return;
    }
    OrdemServico os;
    total_os = 0;
    while (fscanf(f, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%f|%[^\n]\n",
                  &os.id,
                  os.cliente_nome,
                  os.telefone,
                  os.equipamento,
                  os.problema_relatado,
                  os.status,
                  &os.valor_servico,
                  os.pecas_usadas) == 8 &&
           total_os < MAX_OS)
    {
        lista_os[total_os++] = os;
    }
    fclose(f);
}

void salvar_estoque()
{
    FILE *f = fopen(ARQ_ESTOQUE, "w");
    if (f == NULL)
    {
        printf("ERRO: Nao foi possivel salvar o Estoque.\n");
        return;
    }
    for (int i = 0; i < total_estoque; i++)
    {
        fprintf(f, "%d|%s|%d|%d\n",
                lista_estoque[i].id,
                lista_estoque[i].nome,
                lista_estoque[i].quantidade,
                lista_estoque[i].estoque_minimo);
    }
    fclose(f);
}

void carregar_estoque()
{
    FILE *f = fopen(ARQ_ESTOQUE, "r");
    if (f == NULL)
    {
        total_estoque = 0;
        return;
    }
    ItemEstoque item;
    total_estoque = 0;
    while (fscanf(f, "%d|%[^|]|%d|%d\n",
                  &item.id,
                  item.nome,
                  &item.quantidade,
                  &item.estoque_minimo) == 4 &&
           total_estoque < MAX_ESTOQUE)
    {
        lista_estoque[total_estoque++] = item;
    }
    fclose(f);
}

void nova_os()
{
    if (total_os >= MAX_OS)
    {
        printf("Limite de Ordens de Servico atingido (%d).\n", MAX_OS);
        return;
    }

    printf("\n--- NOVA ORDEM DE SERVICO ---\n");
    int id_atual = (total_os > 0) ? lista_os[total_os - 1].id + 1 : 1;
    lista_os[total_os].id = id_atual;

    printf("ID da OS: %d\n", id_atual);
    printf("Nome do Cliente: ");
    limpar_buffer();
    ler_string_segura(lista_os[total_os].cliente_nome, MAX_NOME);

    printf("Telefone/Contato: ");
    ler_string_segura(lista_os[total_os].telefone, 15);

    printf("Equipamento (Ex: Notebook Dell, PC Desktop): ");
    ler_string_segura(lista_os[total_os].equipamento, MAX_NOME);

    printf("Problema Relatado: ");
    ler_string_segura(lista_os[total_os].problema_relatado, MAX_DESCRICAO);

    strcpy(lista_os[total_os].status, "Recebido");
    lista_os[total_os].valor_servico = 0.0;
    strcpy(lista_os[total_os].pecas_usadas, "Nenhuma");

    printf("\nOS #%d para %s registrada com sucesso! Status: Recebido.\n", id_atual, lista_os[total_os].cliente_nome);
    total_os++;
    salvar_os();
}

void listar_os_ativas()
{
    printf("\n--- ORDENS DE SERVICO ATIVAS (Nao Entregues) ---\n");
    int encontrou = 0;
    for (int i = 0; i < total_os; i++)
    {
        if (strcmp(lista_os[i].status, "Entregue") != 0)
        {
            printf("ID: %d | Cliente: %s | Equipamento: %s | Status: %s\n",
                   lista_os[i].id, lista_os[i].cliente_nome, lista_os[i].equipamento, lista_os[i].status);
            encontrou = 1;
        }
    }
    if (!encontrou)
    {
        printf("Nenhuma Ordem de Servico ativa encontrada.\n");
    }
}

void atualizar_status_os()
{
    int id;
    int indice = -1;

    printf("\n--- ATUALIZAR STATUS DA OS ---\n");
    printf("Digite o ID da OS a ser atualizada: ");
    if (scanf("%d", &id) != 1)
    {
        printf("Entrada invalida. Tente novamente.\n");
        limpar_buffer();
        return;
    }
    limpar_buffer();

    for (int i = 0; i < total_os; i++)
    {
        if (lista_os[i].id == id)
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
    {
        printf("OS com ID %d nao encontrada.\n", id);
        return;
    }

    printf("\nOS Encontrada: ID %d - Cliente: %s - Status Atual: %s\n",
           lista_os[indice].id, lista_os[indice].cliente_nome, lista_os[indice].status);

    printf("1 - Em Reparo\n2 - Pronto (Para ligar para o cliente!)\n3 - Entregue (Servico Finalizado e Cobrado)\n");
    printf("Nova Opcao de Status: ");
    int opcao;
    if (scanf("%d", &opcao) != 1)
    {
        printf("Opcao invalida.\n");
        limpar_buffer();
        return;
    }
    limpar_buffer();

    switch (opcao)
    {
    case 1:
        strcpy(lista_os[indice].status, "Em Reparo");
        break;
    case 2:
        strcpy(lista_os[indice].status, "Pronto");
        printf("AVISO! OS Pronta. Lembre de ligar para o cliente: %s - Telefone: %s\n",
               lista_os[indice].cliente_nome, lista_os[indice].telefone);

        printf("Digite o valor cobrado (Ex: 150.00): ");
        scanf("%f", &lista_os[indice].valor_servico);
        limpar_buffer();
        printf("Pecas/Descricao do Servico realizado: ");
        ler_string_segura(lista_os[indice].pecas_usadas, MAX_DESCRICAO);
        break;

    case 3:
        strcpy(lista_os[indice].status, "Entregue");
        printf("OS finalizada e entregue. Valor: R$%.2f. Nao esqueca de cobrar!\n", lista_os[indice].valor_servico);
        break;

    default:
        printf("Opcao de status invalida. Nada foi alterado.\n");
        return;
    }

    printf("Status da OS %d atualizado para: %s\n", id, lista_os[indice].status);
    salvar_os();
}

void listar_estoque()
{
    printf("\n--- ESTOQUE ATUAL ---\n");
    printf("ID | Nome da Peca | Quantidade | Minimo\n");
    printf("---|---|---|---\n");
    int alerta = 0;
    for (int i = 0; i < total_estoque; i++)
    {
        printf("%d | %s | %d | %d",
               lista_estoque[i].id, lista_estoque[i].nome, lista_estoque[i].quantidade, lista_estoque[i].estoque_minimo);

        if (lista_estoque[i].quantidade <= lista_estoque[i].estoque_minimo)
        {
            printf(" <<< ALERTA! PRECISA COMPRAR!");
            alerta = 1;
        }
        printf("\n");
    }
    if (total_estoque == 0)
    {
        printf("Estoque vazio.\n");
    }
    if (alerta)
    {
        printf("\nATENCAO: Ha itens abaixo do estoque minimo!\n");
    }
}

void adicionar_ou_atualizar_estoque()
{
    char nome_peca[MAX_NOME];
    int quantidade;
    int indice = -1;

    printf("\n--- ATUALIZAR ESTOQUE ---\n");
    printf("Nome da Peca (Ex: SSD 240GB): ");
    limpar_buffer();
    ler_string_segura(nome_peca, MAX_NOME);

    for (int i = 0; i < total_estoque; i++)
    {
        if (strcasecmp(lista_estoque[i].nome, nome_peca) == 0)
        {
            indice = i;
            break;
        }
    }

    printf("Digite a quantidade a ADICIONAR ou REMOVER (use - para remover, ex: -2): ");
    if (scanf("%d", &quantidade) != 1)
    {
        printf("Entrada invalida.\n");
        limpar_buffer();
        return;
    }

    if (indice != -1)
    {

        lista_estoque[indice].quantidade += quantidade;
        printf("Estoque de '%s' atualizado. Novo total: %d.\n", lista_estoque[indice].nome, lista_estoque[indice].quantidade);
    }
    else
    {

        if (total_estoque >= MAX_ESTOQUE)
        {
            printf("Limite de itens no estoque atingido (%d).\n", MAX_ESTOQUE);
            return;
        }

        if (quantidade < 0)
        {
            printf("Peca nova nao pode ter estoque inicial negativo. Adicione-a primeiro.\n");
        }
        else
        {
            lista_estoque[total_estoque].id = (total_estoque > 0) ? lista_estoque[total_estoque - 1].id + 1 : 1;
            strcpy(lista_estoque[total_estoque].nome, nome_peca);
            lista_estoque[total_estoque].quantidade = quantidade;

            printf("Digite o estoque minimo para '%s': ", nome_peca);
            if (scanf("%d", &lista_estoque[total_estoque].estoque_minimo) != 1)
            {
                printf("Estoque minimo invalido. Padrao 5.\n");
                lista_estoque[total_estoque].estoque_minimo = 5;
            }

            total_estoque++;
            printf("Peca '%s' adicionada ao estoque com %d unidades.\n", nome_peca, quantidade);
        }
    }

    salvar_estoque();
}

void exibir_menu_principal()
{
    printf("\n============================================\n");
    printf("   SISTEMA DE GESTAO DE MANUTENCAO CLEITINHO\n");
    printf("============================================\n");
    printf("  [1] Ordem de Servico (OS)\n");
    printf("  [2] Controle de Estoque\n");
    printf("  [0] Sair do Sistema\n");
    printf("--------------------------------------------\n");
    printf("Escolha uma opcao: ");
}

void menu_os()
{
    int opcao;
    do
    {
        printf("\n--- MENU ORDEM DE SERVICO ---\n");
        printf("  [1] Nova OS (Novo Cliente/Equipamento)\n");
        printf("  [2] Listar OS Ativas (Em Reparo/Pronto)\n");
        printf("  [3] Atualizar Status, Valor e Pecas Usadas\n");
        printf("  [0] Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1)
        {
            printf("ERRO: Opcao invalida. Digite um numero.\n");
            limpar_buffer();
            opcao = -1;
            continue;
        }

        switch (opcao)
        {
        case 1:
            nova_os();
            break;
        case 2:
            listar_os_ativas();
            break;
        case 3:
            atualizar_status_os();
            break;
        case 0:
            printf("Voltando ao menu principal...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

void menu_estoque()
{
    int opcao;
    do
    {
        printf("\n--- MENU ESTOQUE ---\n");
        printf("  [1] Listar Estoque (Com Alerta de Compra)\n");
        printf("  [2] Adicionar/Remover Peca (Nova compra ou uso em OS)\n");
        printf("  [0] Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1)
        {
            printf("ERRO: Opcao invalida. Digite um numero.\n");
            limpar_buffer();
            opcao = -1;
            continue;
        }

        switch (opcao)
        {
        case 1:
            listar_estoque();
            break;
        case 2:
            adicionar_ou_atualizar_estoque();
            break;
        case 0:
            printf("Voltando ao menu principal...\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

int main()
{

    carregar_os();
    carregar_estoque();

    int opcao;

    do
    {
        exibir_menu_principal();
        if (scanf("%d", &opcao) != 1)
        {
            printf("ERRO: Opcao invalida. Digite um numero.\n");
            limpar_buffer();
            opcao = -1;
            continue;
        }
        limpar_buffer();

        switch (opcao)
        {
        case 1:
            menu_os();
            break;
        case 2:
            menu_estoque();
            break;
        case 0:
            printf("\nSalvando dados e encerrando o Sistema. Ate mais, Cleitinho!\n");

            salvar_os();
            salvar_estoque();
            break;
        default:
            printf("Opcao invalida. Por favor, escolha 1, 2 ou 0.\n");
        }

    } while (opcao != 0);

    return 0;
}