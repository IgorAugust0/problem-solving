#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Vetores para armazenar as cores dos uniformes
    vector<int> uniformeCasa(n);
    vector<int> uniformeVisitante(n);

    // Leitura das cores dos uniformes para cada equipe
    for (int i = 0; i < n; i++) {
        cin >> uniformeCasa[i] >> uniformeVisitante[i];
    }

    int contadorTrocas = 0;

    // Verifica cada possível jogo
    for (int equipeCasa = 0; equipeCasa < n; equipeCasa++) {
        for (int equipeVisitante = 0; equipeVisitante < n; equipeVisitante++) {
            // Ignora jogos da equipe contra ela mesma
            if (equipeCasa == equipeVisitante) {
                continue;
            }

            // Verifica se há conflito de cores
            if (uniformeCasa[equipeCasa] == uniformeVisitante[equipeVisitante]) {
                contadorTrocas++;
            }
        }
    }

    cout << contadorTrocas << endl;

    return 0;
}
