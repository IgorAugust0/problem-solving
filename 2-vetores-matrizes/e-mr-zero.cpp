#include <iostream>
#include <vector>
#include <set>
using namespace std;

int contar_posicoes_zero(int linhas, int colunas, vector<vector<int>>& matriz) {
    // Encontra linhas que são todas zeros
    set<int> linhas_zero;
    for (int i = 0; i < linhas; i++) {
        bool todos_zeros = true;
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] != 0) {
                todos_zeros = false;
                break;
            }
        }
        if (todos_zeros) {
            linhas_zero.insert(i);
        }
    }
    
    // Encontra colunas que são todas zeros
    set<int> colunas_zero;
    for (int j = 0; j < colunas; j++) {
        bool todos_zeros = true;
        for (int i = 0; i < linhas; i++) {
            if (matriz[i][j] != 0) {
                todos_zeros = false;
                break;
            }
        }
        if (todos_zeros) {
            colunas_zero.insert(j);
        }
    }
    
    // Retorna o número de interseções
    return linhas_zero.size() * colunas_zero.size();
}

int main() {
    int linhas, colunas;
    cin >> linhas >> colunas;
    
    // Lê a matriz
    vector<vector<int>> matriz(linhas, vector<int>(colunas));
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cin >> matriz[i][j];
        }
    }
    
    // Imprime o resultado
    cout << contar_posicoes_zero(linhas, colunas, matriz) << endl;
    
    return 0;
}