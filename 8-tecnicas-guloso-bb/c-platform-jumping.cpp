#include <bits/stdc++.h>
using namespace std;

// Definições de tipos
typedef long long inteiro;
typedef vector<inteiro> vetor_int;
typedef pair<inteiro, inteiro> par_int;
typedef pair<inteiro, pair<inteiro, inteiro>> trio_int;

// Constantes
const inteiro MOD = 1000000007;

/**
 * Arredonda a divisão para cima
 * @param x Numerador
 * @param y Denominador
 * @return Resultado arredondado para cima
 */
inteiro divisao_arredondada(inteiro x, inteiro y) {
    inteiro resultado = x / y;
    if (x % y != 0) {
        resultado++;
    }
    return resultado;
}

/**
 * Resolve um caso de teste
 * @param indice_caso Índice do caso atual
 * @param total_casos Total de casos de teste
 */
void resolver(inteiro indice_caso, inteiro total_casos) {
    // Leitura das variáveis de entrada
    inteiro n, m, d;
    cin >> n >> m >> d;

    inteiro resultado = n;
    vetor_int plataformas(m);
    vetor_int diferencas(m, 0);

    // Lê as plataformas
    inteiro soma_plataformas = 0;
    for (inteiro i = 0; i < m; i++) {
        cin >> plataformas[i];
        soma_plataformas += plataformas[i];
    }

    // Calcula a distância total disponível
    inteiro distancia = (n + 1) - soma_plataformas - d;
    d--;  // Ajusta d

    // Distribui as distâncias pelas plataformas
    for (inteiro i = 0; i < m; i++) {
        if (distancia <= 0) {
            break;
        } else {
            inteiro minimo = min(distancia, d);
            distancia -= minimo;
            diferencas[i] = minimo;
        }
    }

    // Atualiza a soma total
    for (inteiro i = 0; i < m; i++) {
        soma_plataformas += diferencas[i];
    }

    // Verifica se é possível distribuir todas as plataformas
    if (distancia <= 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
        return;
    }

    // Imprime a solução
    for (inteiro i = 0; i < m; i++) {
        // Imprime zeros (espaços vazios) antes de cada plataforma
        for (inteiro j = 0; j < diferencas[i]; j++) {
            cout << 0 << " ";
        }

        // Imprime a plataforma
        for (inteiro j = 0; j < plataformas[i]; j++) {
            cout << i + 1 << " ";
        }
    }

    // Imprime zeros finais se necessário
    for (inteiro i = soma_plataformas; i < n; i++) {
        cout << 0 << " ";
    }
}

int main() {
    // Otimização de I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Resolve o único caso de teste
    resolver(1, 1);

    return 0;
}