#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cartas(n);
    for (int i = 0; i < n; i++) {
        cin >> cartas[i];
    }

    int pontuacaoSereja = 0;
    int pontuacaoDima = 0;

    int esquerda = 0;
    int direita = n - 1;
    bool turnoSereja = true;

    while (esquerda <= direita) {
        int valorEscolhido;

        // Escolhe a carta com o maior valor (esquerda ou direita)
        if (cartas[esquerda] > cartas[direita]) {
            valorEscolhido = cartas[esquerda];
            esquerda++;
        } else {
            valorEscolhido = cartas[direita];
            direita--;
        }

        // Adiciona o valor à pontuação do jogador atual
        if (turnoSereja) {
            pontuacaoSereja += valorEscolhido;
        } else {
            pontuacaoDima += valorEscolhido;
        }

        // Alterna o turno
        turnoSereja = !turnoSereja;
    }

    cout << pontuacaoSereja << " " << pontuacaoDima << endl;

    return 0;
}
