#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Mapa para armazenar nomes e suas contagens
    map<string, int> registros;

    // Número de solicitações
    int numSolicitacoes;
    cin >> numSolicitacoes;

    while (numSolicitacoes--) {
        string nome;
        cin >> nome;

        // Verifica se o nome já existe
        if (registros[nome] == 0) {
            cout << "OK" << endl;
            registros[nome] = 1;
        } else {
            // Encontra o próximo número disponível
            int contador = registros[nome];
            string novoNome = nome + to_string(contador);

            while (registros[novoNome] > 0) {
                contador++;
                novoNome = nome + to_string(contador);
            }

            cout << novoNome << endl;
            registros[novoNome] = 1;
            registros[nome]++;
        }
    }

    return 0;
}
