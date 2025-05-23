#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

void Pescador()
{
    int pesoPeixe, multa;
    printf("Esse algoritmo ir� calcular a multa para peixes que passam dos 50kg.\n");
    printf("Informe o peso do peixe: ");
    scanf("%d", &pesoPeixe);
    if (pesoPeixe > 50)
    {
        multa = (pesoPeixe - 50) * 4;
        printf("Peso do peixe: %d\n", pesoPeixe);
        printf("Multa: R$ %d\n", multa);
    }
    else
    {
        printf("Peso do peixe: %d\n", pesoPeixe);
        printf("Sem multa\n");
    }
}

void Tintas()
{
    float AreaPintada, TotalLitros, Latas, ValorTotal;
    printf("Esse algoritmo ir� receber a �rea para pintura e calcular a quantidade de latas de tinta e o valor total.\n");
    printf("Informe a �rea a ser pintada em metros quadrados: ");
    scanf("%f", &AreaPintada);
    TotalLitros = AreaPintada / 3;
    Latas = TotalLitros / 18;
    Latas = ceil(Latas);
    ValorTotal = Latas * 80;
    printf("A quantidade de latas �:%.0f\nE o valor total �: R$ %.2f\n", Latas, ValorTotal);
}

void Banco()
{
    int atd = 0;
    float saldo = 1000.00, saque, deposito, transf;
    printf("Esse algoritmo ir� simular o menu de atendimento de um banco.");

    while (atd != 5)
    {
        printf("\nOp��es de Atendimento: \n1 - Saldo \n2 - Saque\n3 - Deposito\n4 - Transfer�ncia\n5 - Sair\n");
        printf("Selecione a op��o desejada: ");
        scanf("%d", &atd);

        switch (atd)
        {
        case 1:
            printf("Seu saldo �: R$ %.2f\n", saldo);
            break;
        case 2:
            printf("Informe o valor do saque: ");
            scanf("%f", &saque);
            if (saque > saldo)
            {
                printf("N�o foi poss�vel sacar, saldo insuficiente.\n");
            }
            else
            {
                saldo = saldo - saque;
                printf("Saque realizado com sucesso.\n");
            }
            break;
        case 3:
            printf("Informe o valor do dep�sito: ");
            scanf("%f", &deposito);
            saldo = saldo + deposito;
            printf("Dep�sito realizado com sucesso.\n");
            break;
        case 4:
           printf("Informe o valor da transfer�ncia: ");
            scanf("%f", &transf);
            if (transf > saldo)
            {
                printf("N�o foi poss�vel realizar a transfer�ncia, saldo insuficiente.\n");
            }
            else
            {
                saldo = saldo - transf;
                printf("Transfer�ncia realizada com sucesso.\n");
            }
            break;
        case 5:
            break;
        
        default:
            printf("Op��o inv�lida.\n");
            break;
        }
    }
}

void Primo()
{
    int num, i = 1, cont = 0;
    printf("Esse algoritmo ir� verificar se o n�mero � primo.\n");
    printf("Digite um n�mero: ");
    scanf("%d", &num);

    while (i <= num)
    {
        if (num % i == 0)
        {
            cont++;
        }
        i++;
    }

    if (cont == 2 && num > 0)
    {
        printf("O n�mero %d � primo.\n", num);
    }
    else
    {
        printf("O n�mero %d n�o � primo.\n", num);
    }
}

void Multa()
{
    float velocidade, maxpermitida, multa110, multa120;
    printf("Esse algoritmo ir� verificar sua velocidade e se � passivo de multa\n");
    printf("Insira a velocidade do veiculo: ");
    scanf("%f", &velocidade);
    printf("insira a velocidade m�xima permitida: ");
    scanf("%f", &maxpermitida);

    multa110 = (maxpermitida * 1.1);
    multa120 = (maxpermitida * 1.2);

    if (velocidade > maxpermitida)
    {
        if (velocidade <= multa110)
        {
            printf("Sua multa � no valor de R$50,00");
        }
        else if (velocidade > multa110 && velocidade <= multa120)
        {
            printf("Sua multa � no valor de R$100,00");
        }
        else if (velocidade > multa120)
        {
            printf("Sua multa � no valor de R$200,00");
        }
    }
    else
    {
        printf("A velocidade est� dentro do m�ximo permitido");
    }
}

void Hotel()
{
    int dias, opQuarto;
    float valorT;
    printf("Esse algoritmo ir� calcular o valor da hospedagem de um hotel.\n");
    printf("1. Quarto Simples - R$ 150 por di�ria \n2. Quarto Duplo - R$ 250 por di�ria \n3. Su�te - R$ 400 por di�ria\n");
    printf("Informe a op��o de quarto desejada: ");
    scanf("%d", &opQuarto);
    printf("Informe a quantidade de dias: ");
    scanf("%d", &dias);

    switch (opQuarto)
    {
    case 1:
        valorT = dias * 150;
        break;
    case 2:
        valorT = dias * 250;
        break;
    case 3:
        valorT = dias * 400;
        break;
    default:
        printf("Op��o inv�lida.\n");
        return;
    }
    printf("O valor da hospedagem �: R$ %.2f\n", valorT);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    int opcao;
    printf("Op��es: \n1 - Pescador \n2 - Tintas\n3 - Banco\n4 - Primo\n5 - Multa\n6 - Hotel\n");
    printf("Selecione a op��o desejada: ");
    scanf("%d", &opcao);
    switch (opcao)
    {

    case 1:
        Pescador();
        break;

    case 2:
        Tintas();
        break;

    case 3:
        Banco();
        break;

    case 4:
        Primo();
        break;

    case 5:
        Multa();
        break;
    case 6:
        Hotel();
        break;
    default:
    printf("Op��o inv�lida.\n");
        break;
    }

    return 0;
}