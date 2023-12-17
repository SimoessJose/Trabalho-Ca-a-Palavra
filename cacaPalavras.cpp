#include <iostream>
#include <cstring>
#define LINHAS 100
#define COLUNAS 100

using namespace std;

//Feito por Bruno
void converteCaracteres(char mat[][COLUNAS], int linha, int coluna){
    // Converte todos os caracteres da matriz para minusculo
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (mat[i][j] >= 'A' && mat[i][j] <= 'Z')
            {
                mat[i][j] = mat[i][j] + ('a' - 'A');
            }
            else
            {
                mat[i][j] = mat[i][j];
            }
        }
    }
}

//Feito por Bruno
void convertePalavra (char palavraRecebe[][COLUNAS], int qtdJogadas){
    // Converte todos os caracteres das palavras para minúsculo
    for (int i=0; i< qtdJogadas; i++){
        int tamanho = strlen(palavraRecebe[i]);
        for (int j=0; j<tamanho; j++){
            if (palavraRecebe[i][j] >= 'A' && palavraRecebe[i][j] <= 'Z')
            {
                palavraRecebe[i][j] = palavraRecebe[i][j] + ('a' - 'A');
            }
            else
            {
                palavraRecebe[i][j] = palavraRecebe[i][j];
            }
        }
    }
}

//Feito por José
void testaPosicoes(char mat[][COLUNAS], char palavraRecebe[][COLUNAS], int lin, int col, int qtdJogadas)
{
    //Testa a posição de cada palavra da matriz de palavras
    for (int i = 0; i < qtdJogadas; i++)
    {
        bool encontrou = false;
        for (int linha = 0; linha < lin; linha++)
        {
            int tamanho = strlen(palavraRecebe[i]);
            for (int coluna = 0; coluna < col; coluna++)
            {
                // Verifica se a palavra está na horizontal
                if (coluna + tamanho <= col)
                {
                    encontrou = true;
                    for (int j = 0; j < tamanho; j++)
                    {
                        if (mat[linha][coluna + j] != palavraRecebe[i][j])
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

                // Verifica se a palavra está na vertical
                if (linha + tamanho <= lin)
                {
                    encontrou = true;
                    for (int j = 0; j < tamanho; j++)
                    {
                        if (mat[linha + j][coluna] != palavraRecebe[i][j])
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

                // Verifica se a palavra está na diagonal
                if (linha + tamanho <= lin && coluna + tamanho <= col)
                {
                    encontrou = true;
                    for (int j = 0; j < tamanho; j++)
                    {
                        if (mat[linha + j][coluna + j] != palavraRecebe[i][j])
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
            //Código passa para próxima verificação caso encontre a posição
            if (encontrou)
            {
                break;
            }
        }
        //Código imprime qual palavra da matriz de palavras não foi encontrada
        if (!encontrou)
        {
            cout << "A palavra ''" << palavraRecebe[i] << "'' nao foi encontrada!\n";
        }
    }
}

//Feito por Bruno e José
int main()
{
    int qtdJogadas, lin, col;

    cout << "Digite a quantidade de palavras que deseja encontrar:";
    cin >> qtdJogadas;
    cout << "Digite as dimensoes da matriz:\n";
    cin >> lin;
    cout << " X \n";
    cin >> col;

    char matrizRecebe[LINHAS][COLUNAS];
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

    cout << "Matriz de caracteres:\n";
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrizRecebe[i][j];
        }
    }
    converteCaracteres (matrizRecebe, lin, col);
    convertePalavra (palavraRecebe,qtdJogadas);
    testaPosicoes(matrizRecebe, palavraRecebe, lin, col, qtdJogadas);

    return 0;
}

//Bruno Cesario Menezes - 202335003; José Simões de Araújo Neto - 202335035
