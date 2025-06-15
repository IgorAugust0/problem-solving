#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;

int n;
int valor[MAX_N];
int anterior[MAX_N], proximo[MAX_N];
bool processado[MAX_N];

// Verifica se um elemento pode ser removido (se possui predecessor)
bool removivel(int i) {
    if (i < 1 || i > n) {
        return false;
    }
    return valor[anterior[i]] == valor[i] - 1 || valor[proximo[i]] == valor[i] - 1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int casos;
    cin >> casos;

    while (casos--) {
        cin >> n;

        // Inicialização
        priority_queue<pair<int, int>> fila_prioridade;
        for (int i = 1; i <= n; i++) {
            anterior[i] = i - 1;
            proximo[i] = i + 1;
            processado[i] = false;
            cin >> valor[i];
        }

        // Valores sentinela para facilitar borda do array
        valor[n + 1] = valor[0] = -2;

        // Adiciona elementos removíveis à fila de prioridade
        for (int i = 1; i <= n; i++) {
            if (removivel(i)) {
                processado[i] = true;
                fila_prioridade.push({valor[i], i});
            }
        }

        // Processa elementos removíveis em ordem decrescente
        while (!fila_prioridade.empty()) {
            pair<int, int> topo = fila_prioridade.top();
            int i = topo.second;
            fila_prioridade.pop();

            // Atualiza ponteiros da lista duplamente encadeada
            proximo[anterior[i]] = proximo[i];
            anterior[proximo[i]] = anterior[i];

            // Verifica se vizinhos tornaram-se removíveis
            if (!processado[anterior[i]] && removivel(anterior[i])) {
                processado[anterior[i]] = true;
                fila_prioridade.push({valor[anterior[i]], anterior[i]});
            }

            if (!processado[proximo[i]] && removivel(proximo[i])) {
                processado[proximo[i]] = true;
                fila_prioridade.push({valor[proximo[i]], proximo[i]});
            }
        }

        // Análise final
        int minimo = n, nao_processados = 0;
        for (int i = 1; i <= n; i++) {
            if (!processado[i]) {
                nao_processados++;
            }
            minimo = min(valor[i], minimo);
        }

        // Output do resultado
        if (nao_processados == 1 && minimo == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}