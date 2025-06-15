#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// Funcao para calcular a soma da ampulheta em uma posicao especifica
int somaAmpulheta(vector<vector<int>>& arr, int row, int col) {
    int soma = 0;

    // Linha superior da ampulheta
    soma += arr[row][col];
    soma += arr[row][col + 1];
    soma += arr[row][col + 2];

    // Centro da ampulheta
    soma += arr[row + 1][col + 1];

    // Linha inferior da ampulheta
    soma += arr[row + 2][col];
    soma += arr[row + 2][col + 1];
    soma += arr[row + 2][col + 2];

    return soma;
}

int main() {
    const int N = 6;
    vector<vector<int>> arr(N, vector<int>(N));

    // Le a matriz 6x6
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    // Encontra a maior soma entre todas as ampulhetas
    int maior_soma = INT_MIN;

    // Itera por todas as posicoes possiveis de ampulheta
    for (int i = 0; i <= N - 3; i++) {
        for (int j = 0; j <= N - 3; j++) {
            int soma_atual = somaAmpulheta(arr, i, j);
            maior_soma = max(maior_soma, soma_atual);
        }
    }

    cout << maior_soma << endl;

    return 0;
}
