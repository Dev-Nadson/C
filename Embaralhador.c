#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char Nome[51];
char aux;
int l, tam, key;

int main()
{
    printf("Insira a Palavra: \n");
    gets(Nome);

    tam = strlen(Nome);
    tam--;

    srand(time(NULL));
    key = 1 + rand() % tam;
    l = 0;

    for (int i = 0; i < tam; i++) {

        key = (i + rand()) % tam; 

        aux = Nome[i];
        Nome[i] = Nome[key];
        Nome[key] = aux;
    }
    

    printf("A palavra alterada: \n%s", Nome);
}