#include <bits/stdc++.h>
using namespace std;

// Definições de tipos
typedef long long inteiro;
typedef vector<inteiro> vetor_int;
typedef pair<inteiro, inteiro> par_int;
typedef vector<par_int> vetor_par;
typedef unordered_map<inteiro, inteiro> mapa_int;

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
 * Troca caracteres '0' e '1' na string usando no máximo k movimentos
 */
void resolver() {
    inteiro n, k;
    string s;
    cin >> n >> k >> s;

    // Armazena as posições dos zeros
    set<inteiro> posicoes_zeros;
    for (inteiro i = 0; i < n; i++) {
        if (s[i] == '0') {
            posicoes_zeros.insert(i);
        }
    }

    // Processa cada caractere da string
    for (inteiro i = 0; i < n; i++) {
        if (s[i] == '1') {
            // Verifica se existe um zero à direita
            auto it = posicoes_zeros.lower_bound(i);
            if (it == posicoes_zeros.end()) {
                break;  // Não há mais zeros à direita
            }

            inteiro pos_zero = *it;
            inteiro distancia = pos_zero - i;

            // Se a distância for menor ou igual a k, faz a troca
            if (distancia <= k) {
                s[i] = '0';
                s[pos_zero] = '1';
                posicoes_zeros.erase(pos_zero);
                k -= distancia;
            }
        }
    }

    cout << s << "\n";
}

int main() {
    // Otimização de I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Lê o número de casos de teste
    inteiro num_casos;
    cin >> num_casos;

    // Processa cada caso de teste
    for (inteiro i = 0; i < num_casos; i++) {
        resolver();
    }

    return 0;
}