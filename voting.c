#include <stdio.h>
#include <stdlib.h>

int candidate1 = 0, candidate2 = 0, candidate3 = 0;

void vote() {
    int candidateChoice;
    printf("Digite o número do candidato em quem deseja votar (1, 2 ou 3): ");
    scanf("%d", &candidateChoice);

    switch (candidateChoice) {
        case 1:
            candidate1++;
            printf("Voto registrado com sucesso! \n");
            break;
        case 2:
            candidate2++;
            printf("Voto registrado com sucesso! \n");
            break;
        case 3:
            candidate3++;
            printf("Voto registrado com sucesso! \n");
            break;
        default:
            printf("Candidato inválido! \n");
    }
}

void showResults() {
    printf("\nResultado da eleição:\n");
    printf("Candidato 1: %d votos\n", candidate1);
    printf("Candidato 2: %d votos\n", candidate2);
    printf("Candidato 3: %d votos\n", candidate3);
}

void saveResults() {
    FILE *file = fopen("resultado.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar arquivo!\n");
        return;
    }
    fprintf(file, "Resultado da eleição:\n");
    fprintf(file, "Candidato 1: %d votos\n", candidate1);
    fprintf(file, "Candidato 2: %d votos\n", candidate2);
    fprintf(file, "Candidato 3: %d votos\n", candidate3);
    fclose(file);
    printf("Resultado salvo em 'resultado.txt' com sucesso!\n");
}

int main() {
    int option;
    do {
        printf("\nBem-vindo ao Sistema de Votacao\n");
        printf("Menu:\n");
        printf("1. Votar\n");
        printf("2. Resultado\n");
        printf("3. Encerrar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                vote();
                break;
            case 2:
                showResults();
                break;
            case 3:
                saveResults();
                printf("Encerrando a votação\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (option != 3);

    return 0;
}
