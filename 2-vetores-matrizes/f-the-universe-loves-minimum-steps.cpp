#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

// Funcao para encontrar o numero minimo de passos
int encontrarPassosMinimos(vector<int>& arr) {
    int maior_abs = 0;

    // Encontra o maior valor absoluto no array
    for (int num : arr) {
        maior_abs = max(maior_abs, abs(num));
    }

    // O numero minimo de passos sera igual ao maior valor absoluto
    return maior_abs;
}

int main() {
    int T;  // Numero de casos de teste
    cin >> T;

    for (int caso = 1; caso <= T; caso++) {
        int N;  // Tamanho do array
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        int resultado = encontrarPassosMinimos(arr);
        cout << "Case " << caso << ": " << resultado << endl;
    }

    return 0;
}
