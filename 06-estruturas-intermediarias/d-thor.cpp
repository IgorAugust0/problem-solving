#include <bits/stdc++.h>
using namespace std;

int main() {
    long totalServidores, totalConsultas;
    scanf("%ld %ld", &totalServidores, &totalConsultas);

    // Conjunto para armazenar os IDs dos eventos ativos
    set<long> eventosAtivos;

    // Vetor para armazenar todos os eventos em ordem cronológica
    vector<long> todosEventos;

    // Vetor de vetores para armazenar eventos por servidor
    vector<vector<long>> eventosPorServidor(totalServidores + 1);

    // Último evento processado pelo tipo 3
    long ultimoProcessado = 0;

    for (long consulta = 0; consulta < totalConsultas; consulta++) {
        long tipoConsulta, parametro;
        scanf("%ld %ld", &tipoConsulta, &parametro);

        if (tipoConsulta == 1) {
            // Adiciona um novo evento ao servidor
            todosEventos.push_back(consulta);
            eventosPorServidor[parametro].push_back(consulta);
            eventosAtivos.insert(consulta);
        } else if (tipoConsulta == 2) {
            // Remove todos os eventos de um servidor específico
            for (int i = 0; i < eventosPorServidor[parametro].size(); ++i) {
                eventosAtivos.erase(eventosPorServidor[parametro][i]);
            }
            eventosPorServidor[parametro].clear();
        } else if (tipoConsulta == 3) {
            // Remove todos os eventos até um certo ponto
            while (ultimoProcessado < parametro) {
                eventosAtivos.erase(todosEventos[ultimoProcessado]);
                ultimoProcessado++;
            }
        }

        // Imprime o número de eventos ativos após cada consulta
        printf("%ld\n", eventosAtivos.size());
    }

    return 0;
}