#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> numeros(N);

    // Le todos os numeros primeiro
    for (int i = 0; i < N; i++) {
        cin >> numeros[i];
    }

    // Verifica se esta em ordem crescente
    bool ascendente = true;
    for (int i = 1; i < N; i++) {
        if (numeros[i] <= numeros[i - 1]) {
            ascendente = false;
            break;
        }
    }

    cout << (ascendente ? "Yes" : "No") << endl;

    return 0;
}
