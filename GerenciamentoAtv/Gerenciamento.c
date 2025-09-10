#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readItems(FILE *arquivo)
{
    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        printf("%s", linha);
    }
    fclose(arquivo);
}

void createItems(FILE *arquivo, char *item)
{
    fprintf(arquivo, "%s\n", item);
    printf("Produto adicionado!\n");
    fclose(arquivo);
}

void updateItems(const char *item, const char *novoItem)
{
    FILE *arquivo = fopen("items.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char linha[256];
    int found = 0;

    if (arquivo == NULL || temp == NULL)
    {
        perror("Erro ao abrir arquivo");
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        linha[strcspn(linha, "\n")] = 0;
        if (strcmp(linha, item) == 0)
        {
            fprintf(temp, "%s\n", novoItem);
            found = 1;
        }
        else
        {
            fprintf(temp, "%s\n", linha);
        }
    }
    fclose(arquivo);
    fclose(temp);
    remove("items.txt");
    rename("temp.txt", "items.txt");
    if (found)
        printf("Produto atualizado com sucesso!\n");
    else
        printf("Produto não encontrado.\n");
}

void deleteItems(const char *item)
{
    FILE *arquivo = fopen("items.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    char linha[256];
    int found = 0;

    if (arquivo == NULL || temp == NULL)
    {
        perror("Erro ao abrir arquivo");
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        linha[strcspn(linha, "\n")] = 0;

        if (strcmp(linha, item) == 0)
        {
            found = 1;
        }
        else
        {
            fprintf(temp, "%s\n", linha);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("items.txt");
    rename("temp.txt", "items.txt");

    if (found)
        printf("Produto removido com sucesso!\n");
    else
        printf("Produto não encontrado.\n");
}

int main()
{
    int option;
    char item[50];
    char novoItem[50];
    FILE *arquivo;

    do
    {
        printf("\nOpcoes: \n");
        printf("1 - Listar Produtos\n");
        printf("2 - Cadastrar Produto\n");
        printf("3 - Editar Produto\n");
        printf("4 - Deletar Produto\n");
        printf("5 - Sair\n");
        printf("Selecione a opcao desejada: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            arquivo = fopen("items.txt", "r");
            if (arquivo != NULL)
                readItems(arquivo);
            else
                printf("Nenhum produto cadastrado ainda.\n");
            break;

        case 2:
            arquivo = fopen("items.txt", "a");
            printf("--- Digite o produto a ser adicionado: ");
            scanf("%s", item);
            createItems(arquivo, item);
            break;

        case 3:
            printf("Digite o produto a ser editado: ");
            scanf("%s", item);
            printf("Digite o novo nome do produto: ");
            scanf("%s", novoItem);
            updateItems(item, novoItem);
            break;

        case 4:
            printf("Digite o produto a ser removido: ");
            scanf("%s", item);
            deleteItems(item);
            break;

        case 5:
            printf("Encerrando...\n");
            break;

        default:
            printf("Opcao invalida.\n");
            break;
        }
    } while (option != 5);

    return 0;
}
