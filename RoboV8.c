#include <stdio.h>
#include <stdlib.h>

char Matriz[8][8][4];
int l, c, i;
int EstX, EstY, auxC, auxL;
int AnteriorL, AnteriorC;
int volD, volE, Volc, VolB, cont, control;

int Sujeira()
{
    if (
        Matriz[0][0][1] == '#' || Matriz[0][1][1] == '#' || Matriz[0][2][1] == '#' || Matriz[0][3][1] == '#' || Matriz[0][4][1] == '#' || Matriz[0][5][1] == '#' || Matriz[0][6][1] == '#' || Matriz[0][7][1] == '#' ||
        Matriz[1][0][1] == '#' || Matriz[1][1][1] == '#' || Matriz[1][2][1] == '#' || Matriz[1][3][1] == '#' || Matriz[1][4][1] == '#' || Matriz[1][5][1] == '#' || Matriz[1][6][1] == '#' || Matriz[1][7][1] == '#' ||
        Matriz[2][0][1] == '#' || Matriz[2][1][1] == '#' || Matriz[2][2][1] == '#' || Matriz[2][3][1] == '#' || Matriz[2][4][1] == '#' || Matriz[2][5][1] == '#' || Matriz[2][6][1] == '#' || Matriz[2][7][1] == '#' ||
        Matriz[3][0][1] == '#' || Matriz[3][1][1] == '#' || Matriz[3][2][1] == '#' || Matriz[3][3][1] == '#' || Matriz[3][4][1] == '#' || Matriz[3][5][1] == '#' || Matriz[3][6][1] == '#' || Matriz[3][7][1] == '#' ||
        Matriz[4][0][1] == '#' || Matriz[4][1][1] == '#' || Matriz[4][2][1] == '#' || Matriz[4][3][1] == '#' || Matriz[4][4][1] == '#' || Matriz[4][5][1] == '#' || Matriz[4][6][1] == '#' || Matriz[4][7][1] == '#' ||
        Matriz[5][0][1] == '#' || Matriz[5][1][1] == '#' || Matriz[5][2][1] == '#' || Matriz[5][3][1] == '#' || Matriz[5][4][1] == '#' || Matriz[5][5][1] == '#' || Matriz[5][6][1] == '#' || Matriz[5][7][1] == '#' ||
        Matriz[6][0][1] == '#' || Matriz[6][1][1] == '#' || Matriz[6][2][1] == '#' || Matriz[6][3][1] == '#' || Matriz[6][4][1] == '#' || Matriz[6][5][1] == '#' || Matriz[6][6][1] == '#' || Matriz[6][7][1] == '#' ||
        Matriz[7][0][1] == '#' || Matriz[7][1][1] == '#' || Matriz[7][2][1] == '#' || Matriz[7][3][1] == '#' || Matriz[7][4][1] == '#' || Matriz[7][5][1] == '#' || Matriz[7][6][1] == '#' || Matriz[7][7][1] == '#')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void PrintMatriz()
{
    system("cls");
    for (int l = 0; l < 8; l++)
    {
        for (int c = 0; c < 8; c++)
        {
            printf("|%s", Matriz[l][c]);
        }
        printf("|\n");
    }
    printf("\n");
}

void PrintMatrizAcao() // Printando a matriz na "Animação"
{
    Sleep(500);
    system("cls");
    for (int ln = 0; ln < 8; ln++)
    {
        for (int cn = 0; cn < 8; cn++)
        {
            printf("|%s", Matriz[ln][cn]);
        }
        printf("|\n");
    }
    printf("\n");
}

void InicializarRobo() // Inicializar estação do robo
{
    printf("Insira o robo: \n");
    printf("Insira a linha e coluna: \n");
    scanf("%d %d", &EstX, &EstY);
    while (EstX < 0 || EstX > 7 || EstY < 0 || EstY > 7)
    {
        printf("Coordenada inválida, insira novamente:\n");
        scanf("%d %d", &EstX, &EstY);
    }
    Matriz[EstX][EstY][0] = ' ';
    Matriz[EstX][EstY][1] = 'E';
    Matriz[EstX][EstY][2] = ' ';
}

void LoopSujeira()
{
    while (l != -1 && c != -1)
    {
        PrintMatriz();
        printf("Insira a linha e coluna: \n Digite -1 e -1 para finalizar.\n");
        scanf("%d %d", &l, &c);
        if (l != -1 && c != -1)
        {
            while (l < 0 || l > 7 || c < 0 || c > 7 || (l == EstX && c == EstY))
            {
                printf("Coordenada inválida, insira novamente:\n");
                scanf("%d %d", &l, &c);
            }
        }

        if ((l >= 0 && l <= 7) && (c >= 0 && c <= 7))
        {
            i = 0;
            while (i < 3)
            {
                Matriz[l][c][i] = '#';
                i++;
            }
        }
    }
}

void FuncaoRef()
{
    Matriz[EstX][EstY][0] = ' ';
    Matriz[EstX][EstY][1] = 'E'; // ponto de ref
    Matriz[EstX][EstY][2] = ' ';
}

// Funções Andar

void AndarDireita()
{
    while (
        (c < 7 && Matriz[l][c + 1][1] == '#') ||
        (Matriz[l][c + 1][1] == ' ' && Matriz[l][c + 2][1] == '#') ||
        (Matriz[l][c + 1][1] == ' ' && Matriz[l][c + 2][1] == ' ' && Matriz[l][c + 3][1] == '#') ||
        (Matriz[l][c + 1][1] == ' ' && Matriz[l][c + 2][1] == ' ' && Matriz[l][c + 3][1] == ' ' && Matriz[l][c + 4][1] == '#'))
    {
        Matriz[l][c][0] = ' ';
        Matriz[l][c][1] = ' ';
        Matriz[l][c][2] = ' ';
        FuncaoRef();

        c++;

        Matriz[l][c][0] = ' ';
        Matriz[l][c][1] = '@';
        Matriz[l][c][2] = ' ';
        PrintMatrizAcao();
        auxL = l;
        control = 1;
    }
}

void AndarEsquerda()
{
    while (
        (c > 0 && Matriz[l][c - 1][1] == '#') ||
        (Matriz[l][c - 1][1] == ' ' && Matriz[l][c - 2][1] == '#') ||
        (Matriz[l][c - 1][1] == ' ' && Matriz[l][c - 2][1] == ' ' && Matriz[l][c - 2][1] == '#') ||
        (Matriz[l][c - 1][1] == ' ' && Matriz[l][c - 2][1] == ' ' && Matriz[l][c - 3][1] == ' ' && Matriz[l][c - 4][1] == '#'))
    {
        Matriz[l][c][0] = ' ';
        Matriz[l][c][1] = ' ';
        Matriz[l][c][2] = ' ';
        FuncaoRef();

        c--;

        Matriz[l][c][0] = ' ';
        Matriz[l][c][1] = '@';
        Matriz[l][c][2] = ' ';
        PrintMatrizAcao();
        auxL = l;
        control = 2;
    }
}

void AndarBaixo()
{
    while (
        (l < 7 && Matriz[l + 1][c][1] == '#') ||
        (Matriz[l + 1][c][1] == ' ' && Matriz[l + 2][c][1] == '#') ||
        (Matriz[l + 1][c][1] == ' ' && Matriz[l + 2][c][1] == ' ' && Matriz[l + 3][c][1] == '#') ||
        (Matriz[l + 1][c][1] == ' ' && Matriz[l + 2][c][1] == ' ' && Matriz[l + 3][c][1] == ' ' && Matriz[l + 4][c][1] == '#'))
    {
        Matriz[l][c][0] = ' ';
        Matriz[l][c][1] = ' ';
        Matriz[l][c][2] = ' ';
        FuncaoRef();

        l++;

        Matriz[l][c][0] = ' ';
        Matriz[l][c][1] = '@';
        Matriz[l][c][2] = ' ';
        PrintMatrizAcao();
        auxC = c;
        control = 3;
    }
}

void AndarCima()
{
    while (
        (l >= 0 && Matriz[l - 1][c][1] == '#') ||
        (Matriz[l - 1][c][1] == ' ' && Matriz[l - 2][c][1] == '#') ||
        (Matriz[l - 1][c][1] == ' ' && Matriz[l - 2][c][1] == ' ' && Matriz[l - 3][c][1] == '#') ||
        (Matriz[l - 1][c][1] == ' ' && Matriz[l - 2][c][1] == ' ' && Matriz[l - 3][c][1] == ' ' && Matriz[l - 4][c][1] == '#'))
    {
        Matriz[l][c][0] = ' ';
        Matriz[l][c][1] = ' ';
        Matriz[l][c][2] = ' ';
        FuncaoRef();

        l--;

        Matriz[l][c][0] = ' ';
        Matriz[l][c][1] = '@';
        Matriz[l][c][2] = ' ';
        PrintMatrizAcao();
        auxC = c;
        control = 4;
    }
}

// Funções Voltar

void VoltarDireita()
{
    if (l == EstX)
    {
        while (
            (Matriz[l][c - 1][1] == ' ' || Matriz[l][c - 1][1] == 'E') &&
            (Matriz[l + 1][c][1] != '#' && Matriz[l - 1][c][1] != '#'))
        {
            if ((Matriz[l - 1][c][1] == ' ' && Matriz[l - 2][c][1] == '#') ||
                (Matriz[l + 1][c][1] == ' ' && Matriz[l + 2][c][1] == '#'))
            {
                break; // Aumentar a área de scan
            }
            Matriz[l][c][0] = ' ';
            Matriz[l][c][1] = ' ';
            Matriz[l][c][2] = ' ';
            FuncaoRef();
            c--;
            Matriz[l][c][0] = ' ';
            Matriz[l][c][1] = '@';
            Matriz[l][c][2] = ' ';
            PrintMatrizAcao();
            if (c == EstY)
            {
                break;
            }
        }
    }
    else
    {
        while ((c >= auxC && Matriz[l + 1][c][1] != '#' && Matriz[l - 1][c][1] != '#'))
        {
            if (
                (Matriz[l][c - 1][1] == ' ' || Matriz[l][c - 1][1] == 'E') &&
                (Matriz[l + 1][c][1] != '#' && Matriz[l - 1][c][1] != '#'))
            {
                if ((Matriz[l - 1][c][1] == ' ' && Matriz[l - 2][c][1] == '#') ||
                    (Matriz[l + 1][c][1] == ' ' && Matriz[l + 2][c][1] == '#'))
                {
                    break; // Aumentar a área de scan
                }
                Matriz[l][c][0] = ' ';
                Matriz[l][c][1] = ' ';
                Matriz[l][c][2] = ' ';
                FuncaoRef();
                c--;
                Matriz[l][c][0] = ' ';
                Matriz[l][c][1] = '@';
                Matriz[l][c][2] = ' ';
                PrintMatrizAcao();
            }
        }
    }
}

void VoltarEsquerda()
{
    if (l == EstX)
    {
        while (
            (Matriz[l][c + 1][1] == ' ' || Matriz[l][c + 1][1] == 'E') &&
            (Matriz[l + 1][c][1] != '#' && Matriz[l - 1][c][1] != '#'))
        {
            if ((Matriz[l - 1][c][1] == ' ' && Matriz[l - 2][c][1] == '#') ||
                (Matriz[l + 1][c][1] == ' ' && Matriz[l + 2][c][1] == '#'))
            {
                break; // Aumentar a área de scan
            }
            Matriz[l][c][0] = ' ';
            Matriz[l][c][1] = ' ';
            Matriz[l][c][2] = ' ';
            FuncaoRef();
            c++;
            Matriz[l][c][0] = ' ';
            Matriz[l][c][1] = '@';
            Matriz[l][c][2] = ' ';
            PrintMatrizAcao();

            if (c == EstY)
            {
                break;
            }
        }
    }
    else
    {
        while (c <= auxC && Matriz[l + 1][c][1] != '#' && Matriz[l - 1][c][1] != '#')
        {
            if (
                (Matriz[l][c + 1][1] == ' ' || Matriz[l][c + 1][1] == 'E') &&
                (Matriz[l + 1][c][1] != '#' && Matriz[l - 1][c][1] != '#'))
            {
                if ((Matriz[l - 1][c][1] == ' ' && Matriz[l - 2][c][1] == '#') ||
                    (Matriz[l + 1][c][1] == ' ' && Matriz[l + 2][c][1] == '#'))
                {
                    break; // Aumentar a área de scan
                }
                Matriz[l][c][0] = ' ';
                Matriz[l][c][1] = ' ';
                Matriz[l][c][2] = ' ';
                FuncaoRef();
                c++;
                Matriz[l][c][0] = ' ';
                Matriz[l][c][1] = '@';
                Matriz[l][c][2] = ' ';
                PrintMatrizAcao();
            }
        }
    }
}

void VoltarBaixo()
{
    while (
        (Matriz[l - 1][c][1] == ' ' || Matriz[l - 1][c][1] == 'E') &&
        (Matriz[l][c - 1][1] != '#' && Matriz[l][c + 1][1] != '#'))
    {
        if ((Matriz[l][c - 1][1] == ' ' && Matriz[l][c - 2][1] == '#') ||
            (Matriz[l][c + 1][1] == ' ' && Matriz[l][c + 2][1] == '#'))
        {
            break;
        }

        Matriz[l][c][0] = ' ';
        Matriz[l][c][1] = ' ';
        Matriz[l][c][2] = ' ';
        FuncaoRef();
        l--;
        Matriz[l][c][0] = ' ';
        Matriz[l][c][1] = '@';
        Matriz[l][c][2] = ' ';
        PrintMatrizAcao();

        if ((l == EstX && c == EstY))
        {
            break;
        }
    }
}

void VoltarCima()
{
    while (
        (Matriz[l + 1][c][1] == ' ' || Matriz[l + 1][c][1] == 'E') &&
        (Matriz[l][c - 1][1] != '#' && Matriz[l][c + 1][1] != '#'))
    {
        if ((Matriz[l][c - 1][1] == ' ' && Matriz[l][c - 2][1] == '#') ||
            (Matriz[l][c + 1][1] == ' ' && Matriz[l][c + 2][1] == '#'))
        {
            break;
        }

        Matriz[l][c][0] = ' ';
        Matriz[l][c][1] = ' ';
        Matriz[l][c][2] = ' ';
        FuncaoRef();
        l++;
        Matriz[l][c][0] = ' ';
        Matriz[l][c][1] = '@';
        Matriz[l][c][2] = ' ';
        PrintMatrizAcao();

        if ((l == EstX && c == EstY))
        {
            break;
        }
    }
}

// Main

int main()
{
    for (l = 0; l < 8; l++)
    {
        for (c = 0; c < 8; c++)
        {
            i = 0;
            while (i < 3)
            {
                Matriz[l][c][i] = '-'; // inicializando a matriz
                i++;
            }
        }
    }

    PrintMatriz();
    InicializarRobo();
    LoopSujeira();

    l = EstX;
    c = EstY;

    do
    {
        do
        {
            AnteriorC = c;
            AndarDireita();
            if (c != AnteriorC)
            {
                VoltarDireita();
            }

            AnteriorL = l;
            AndarBaixo();
            if (l != AnteriorL)
            {
                VoltarBaixo();
            }

            AnteriorC = c;
            AndarEsquerda();
            if (c != AnteriorC)
            {
                VoltarEsquerda();
            }

            AnteriorL = l;
            AndarCima();
            if (l != AnteriorL)
            {
                VoltarCima();
            }

            if (l < EstX)
            {
                VoltarCima();
            }
            if (l > EstX)
            {
                VoltarBaixo();
            }
            if (c < EstY)
            {
                VoltarEsquerda();
            }
            if (c > EstY)
            {
                VoltarDireita();
            }

        } while (((l != EstX && c != EstY) || (l != EstX || c != EstY)));

        cont = Sujeira();

    } while (cont != 1);

    return 0;
}