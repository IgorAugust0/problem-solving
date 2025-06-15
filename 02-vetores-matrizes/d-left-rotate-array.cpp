#include <iostream>
#include <vector>
using namespace std;

// Funcao para rotacionar array para a esquerda
void rotacionarArray(vector<int>& arr, int n, int d) {
    // Calcula rotacoes efetivas
    d = d % n;

    // Cria array temporario
    vector<int> temp(n);

    // Calcula nova posicao de cada elemento
    for (int i = 0; i < n; i++) {
        int nova_pos = (i - d + n) % n;
        temp[nova_pos] = arr[i];
    }

    // Copia de volta para o array original
    arr = temp;
}

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> arr(n);

    // Le os elementos do array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Realiza a rotacao
    rotacionarArray(arr, n, d);

    // Imprime o resultado
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
