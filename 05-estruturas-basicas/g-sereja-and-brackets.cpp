#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define MAX 1000005
using namespace std;

typedef pair<int, int> pii;
char sequencia[MAX];

struct no {
    int seq_correta, aberto, fechado;  // seq_correta - sequência correta, aberto - parêntese aberto, fechado - parêntese fechado
} arvore[4 * MAX];

no combinar(no a, no b) {
    no resultado;
    int temp = min(a.aberto, b.fechado);                           // Mínimo de parênteses abertos ou fechados
    resultado.seq_correta = a.seq_correta + b.seq_correta + temp;  // incrementa sequência correta
    resultado.aberto = a.aberto + b.aberto - temp;                 // subtrai temp, pois já consideramos na sequência correta
    resultado.fechado = a.fechado + b.fechado - temp;

    return resultado;
}

void construir(int numeroNo, int inicio, int fim) {
    if (inicio == fim) {
        if (sequencia[inicio] == '(') {
            arvore[numeroNo].seq_correta = arvore[numeroNo].fechado = 0;
            arvore[numeroNo].aberto = 1;
        } else {
            arvore[numeroNo].seq_correta = arvore[numeroNo].aberto = 0;
            arvore[numeroNo].fechado = 1;
        }
        return;
    }

    int meio = (inicio + fim) >> 1;
    construir(numeroNo * 2, inicio, meio);
    construir(numeroNo * 2 + 1, meio + 1, fim);

    arvore[numeroNo] = combinar(arvore[numeroNo * 2], arvore[numeroNo * 2 + 1]);
}

no consulta(int numeroNo, int inicio, int fim, int esquerda, int direita) {
    if (esquerda == inicio && fim == direita)
        return arvore[numeroNo];
    int meio = (inicio + fim) >> 1;

    if (direita <= meio) {
        return consulta(numeroNo * 2, inicio, meio, esquerda, direita);
    }
    if (esquerda > meio)
        return consulta(numeroNo * 2 + 1, meio + 1, fim, esquerda, direita);

    return combinar(consulta(numeroNo * 2, inicio, meio, esquerda, meio),
                    consulta(numeroNo * 2 + 1, meio + 1, fim, meio + 1, direita));
}

int main() {
    int qtd_consultas;  // número de consultas
    scanf("%s", sequencia);

    int tamanho = strlen(sequencia);

    scanf("%d", &qtd_consultas);

    int inicio_consulta, fim_consulta;

    construir(1, 0, tamanho - 1);

    for (int i = 0; i < qtd_consultas; i++) {
        scanf("%d %d", &inicio_consulta, &fim_consulta);
        inicio_consulta--, fim_consulta--;  // indexação baseada em 0
        no resposta = consulta(1, 0, tamanho - 1, inicio_consulta, fim_consulta);
        printf("%d\n", resposta.seq_correta * 2);
    }

    return 0;
}