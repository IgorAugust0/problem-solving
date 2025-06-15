#include <iostream>
#include <string>
using namespace std;

int main() {
    string nome;
    cin >> nome;

    string resultado = "";

    // Adiciona o primeiro caractere
    if (!nome.empty()) {
        resultado += nome[0];
    }

    // Compara cada caractere com o anterior
    for (int i = 1; i < nome.length(); i++) {
        if (nome[i] != nome[i - 1]) {
            resultado += nome[i];
        }
    }

    cout << resultado << endl;

    return 0;
}
