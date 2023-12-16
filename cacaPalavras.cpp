#include <iostream>
#include <cstring>
#define LINHAS 100
#define COLUNAS 100

using namespace std;

void matrizCaractere(char mat[][COLUNAS], char palavraRecebe[][COLUNAS], int l, int c, int qtdJogadas)
{
    char palavra[LINHAS][COLUNAS];

    for (int i = 0; i < qtdJogadas; i++)
    {
        int tamanho = strlen(palavraRecebe[i]);

        // Modifica palavras da entrada para apenas letras minúsculas
        for (int j = 0; j < tamanho; j++)
        {
            if (palavraRecebe[i][j] >= 'A' && palavraRecebe[i][j] <= 'Z')
            {
                palavra[i][j] = palavraRecebe[i][j] + ('a' - 'A');
            }
            else
            {
                palavra[i][j] = palavraRecebe[i][j];
            }
        }

        bool encontrou = false;

        for (int linha = 0; linha < l; linha++)
        {
            for (int coluna = 0; coluna < c; coluna++)
            {
                // Verifica Horizontal
                if (coluna + tamanho <= c)
                {
                    encontrou = true;
                    for (int j = 0; j < tamanho; j++)
                    {
                        if (mat[linha][coluna + j] != palavra[i][j])
                        {
                            encontrou = false;
                            break;
                        }
                    }
                    if (encontrou)
                    {
                        cout << "A palavra ''" << palavraRecebe[i] << "'' foi localizada Horizontalmente a partir da posicao (" << linha << "," << coluna << ")\n";
                        break;
                    }
                }

                // Verifica Vertical
                if (linha + tamanho <= l)
                {
                    encontrou = true;
                    for (int j = 0; j < tamanho; j++)
                    {
                        if (mat[linha + j][coluna] != palavra[i][j])
                        {
                            encontrou = false;
                            break;
                        }
                    }
                    if (encontrou)
                    {
                        cout << "A palavra ''" << palavraRecebe[i] << "'' foi localizada Verticalmente a partir da posicao (" << linha << "," << coluna << ")\n";
                        break;
                    }
                }

                // Verifica Diagonal
                if (linha + tamanho <= l && coluna + tamanho <= c)
                {
                    encontrou = true;
                    for (int j = 0; j < tamanho; j++)
                    {
                        if (mat[linha + j][coluna + j] != palavra[i][j])
                        {
                            encontrou = false;
                            break;
                        }
                    }
                    if (encontrou)
                    {
                        cout << "A palavra ''" << palavraRecebe[i] << "'' foi localizada Diagonalmente a partir da posicao (" << linha << "," << coluna << ")\n";
                        break;
                    }
                }
            }
            if (encontrou)
            {
                break;
            }
        }
        if (!encontrou)
        {
            cout << "A palavra ''" << palavra[i] << "'' nao foi encontrada!\n";
        }
    }
}

int main()
{
    int qtdJogadas, lin, col;

    cout << "Digite a quantidade de palavras que deseja encontrar:";
    cin >> qtdJogadas;
    cout << "Digite as dimençoes da matriz:\n";
    cin >> lin;
    cout << " X \n";
    cin >> col;

    char matrizRecebe[LINHAS][COLUNAS];
    char matriz[LINHAS][COLUNAS];
    char palavraRecebe[LINHAS][COLUNAS];

    for (int i = 0; i < qtdJogadas; i++)
    {
        cout << "Digite a palavra que deseja encontrar: ";
        cin >> palavraRecebe[i];
        int tam = strlen(palavraRecebe[i]);
        if(tam<4){
            cout << "Palavra deve conter no mínimo 4 caracteres!\n";
            i--;
        }
    }

    cout << "Matriz de caracters:\n";
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrizRecebe[i][j];
        }
    }

    // Modifica matriz para apenas letras minúsculas
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrizRecebe[i][j] >= 'A' && matrizRecebe[i][j] <= 'Z')
            {
                matriz[i][j] = matrizRecebe[i][j] + ('a' - 'A');
            }
            else
            {
                matriz[i][j] = matrizRecebe[i][j];
            }
        }
    }

    matrizCaractere(matriz, palavraRecebe, lin, col, qtdJogadas);

    return 0;
}
