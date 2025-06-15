#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Usamos um conjunto para armazenar combinações únicas de espécie e cor
    set<pair<string, string>> folhasUnicas;

    for (int i = 0; i < n; i++) {
        string especie, cor;
        cin >> especie >> cor;

        // Inserir a combinação no conjunto
        folhasUnicas.insert({especie, cor});
    }

    // Saída: número de folhas únicas (tamanho do conjunto)
    cout << folhasUnicas.size() << endl;

    return 0;
}
