#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> tempoAtendimento(n);
    for (int i = 0; i < n; i++) {
        cin >> tempoAtendimento[i];
    }

    // Ordenar os tempos de atendimento em ordem crescente
    sort(tempoAtendimento.begin(), tempoAtendimento.end());

    long long tempoEspera = 0;
    int pessoasNaoDecepcionadas = 0;

    for (int i = 0; i < n; i++) {
        // Se o tempo de espera atual não excede o tempo de atendimento
        // da pessoa, então ela não ficará decepcionada
        if (tempoEspera <= tempoAtendimento[i]) {
            pessoasNaoDecepcionadas++;
            tempoEspera += tempoAtendimento[i];
        }
        // Se o tempo de espera excede, a pessoa ficará decepcionada
        // e não precisamos adicionar seu tempo de atendimento (podemos pular)
    }

    cout << pessoasNaoDecepcionadas << endl;

    return 0;
}
