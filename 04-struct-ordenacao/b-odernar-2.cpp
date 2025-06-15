#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    // Declaração de variáveis
    int t;
    cin >> t;

    for (int caso = 0; caso < t; caso++) {
        // Se não for o primeiro caso, adicione uma linha em branco antes
        if (caso > 0) {
            cout << endl;
        }

        int n;
        cin >> n;

        // Ignorar o resto da linha depois de ler n
        cin.ignore();

        // Mapa para contar ocorrências de cada conta
        map<string, int> contasContador;

        // Ler n contas
        for (int i = 0; i < n; i++) {
            string conta;
            getline(cin, conta);
            contasContador[conta]++;
        }

        // Converter para vetor para ordenar
        vector<pair<string, int>> contasOrdenadas;
        for (const auto& par : contasContador) {
            contasOrdenadas.push_back(par);
        }

        // Ordenar contas pelo número da conta (já está ordenado pelo map)

        // Imprimir resultado
        for (const auto& conta : contasOrdenadas) {
            cout << conta.first << " " << conta.second << endl;
        }
    }

    return 0;
}

// #include <algorithm>
// #include <iostream>
// #include <map>
// #include <string>
// #include <vector>
// using namespace std;

// int main() {
//     // Declaração de variáveis
//     int t;
//     cin >> t;

//     for (int caso = 0; caso < t; caso++) {
//         // Se não for o primeiro caso, adicione uma linha em branco antes
//         if (caso > 0) {
//             cout << endl;
//         }

//         int n;
//         cin >> n;

//         // Mapa para contar ocorrências de cada conta
//         map<string, int> contasContador;

//         // Ler n contas
//         for (int i = 0; i < n; i++) {
//             string controlDigits, bankCode, id1, id2, id3, id4;
//             cin >> controlDigits >> bankCode >> id1 >> id2 >> id3 >> id4;

//             // Construir o número da conta completo
//             string contaCompleta = controlDigits + " " + bankCode + " " +
//                                    id1 + " " + id2 + " " + id3 + " " + id4;

//             contasContador[contaCompleta]++;
//         }

//         // Imprimir resultado
//         for (const auto& conta : contasContador) {
//             cout << conta.first << " " << conta.second << endl;
//         }
//     }

//     return 0;
// }