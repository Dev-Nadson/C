#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    int valor;
    No *esq;
    No *dir;
} No;

No *criar(int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo != NULL)
    {
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

No *inserir(No *raiz, int valor)
{
    if (raiz == NULL)
    {
        raiz = criar(valor);
    }
    else
    {
        if (valor < raiz->valor)
        {
            raiz->esq = inserir(raiz->esq, valor);
        }
        else if (raiz > raiz->valor)
        {
            raiz->dir = inserir(raiz->dir, valor);
        }
    }
    return raiz;
}

void mostrar(No *raiz, int nivel)
{
    int i;
    if (raiz != NULL)
    {
        mostrar(raiz->dir, nivel + 1);
        for (i = 0; i < nivel; i++)
        {
            printf("    ");
        }
        printf("%d\n", raiz->valor);
        mostrar(raiz->esq, nivel + 1);
    }
}

void limpar(No *raiz)
{
    if (raiz != NULL)
    {
        limpar(raiz->dir);
        limpar(raiz->esq);
        free(raiz);
    }
}

No *remover(No *raiz, int valor)
{
    if (raiz == NULL)
    {
        return NULL;
    }
    if (valor < raiz->valor)
    {
        raiz->esq = remover(raiz->esq, valor);
    }
    else
    {
        if (raiz->valor)
        {
        }
    }
}