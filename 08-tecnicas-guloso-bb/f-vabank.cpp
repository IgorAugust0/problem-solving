#include <bits/stdc++.h>
using namespace std;

// Definições de tipos
typedef long double real_longo;
typedef long long inteiro;
typedef unsigned long long uint_longo;
typedef pair<inteiro, inteiro> par_int;
typedef vector<inteiro> vetor_int;
typedef vector<par_int> vetor_par;
typedef tuple<inteiro, inteiro, inteiro> tupla_int;

// Funções auxiliares de matemática
template <typename T, typename U>
T teto(T x, U y) { return (x > 0 ? (x + y - 1) / y : x / y); }

template <typename T, typename U>
T piso(T x, U y) { return (x > 0 ? x / y : (x - y + 1) / y); }

template <class T, class S>
bool max_atualiza(T &a, const S b) { return (a < b ? a = b, 1 : 0); }

template <class T, class S>
bool min_atualiza(T &a, const S b) { return (a > b ? a = b, 1 : 0); }

// Funções de manipulação de bits
int contar_bits(int x) { return __builtin_popcount(x); }
int contar_bits(inteiro x) { return __builtin_popcountll(x); }
int bit_mais_alto(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int bit_mais_alto(inteiro x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int bit_mais_baixo(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int bit_mais_baixo(inteiro x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

// Redefinição de int como long long
#define int long long

// Macros para loops
#define para(i, a, b) for (int i = (a); i <= (b); i++)
#define rpara(i, a, b) for (int i = (a); i >= (b); i--)

/**
 * Lê um número inteiro da entrada
 * @return O número lido
 */
int ler_numero() {
    int x = 0, sinal = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-') sinal = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * sinal;
}

// Variáveis globais
int posicao_atual, contador_consultas;
const int limite_valor = 1e14;
const int limite_consultas = 105;

/**
 * Realiza uma consulta com valor x
 * @param x Valor a ser consultado
 * @return 1 se moveu para a esquerda, 0 se moveu para a direita
 */
int consultar(int x) {
    if (x > limite_valor) return 0;

    contador_consultas++;
    if (contador_consultas > limite_consultas) assert(0);

    printf("? %lld\n", x);
    fflush(stdout);

    static char resposta[10];
    scanf("%s", resposta);

    if (resposta[0] == 'L')
        return posicao_atual += x, 1;
    else if (resposta[1] == 'r')
        return posicao_atual -= x, 0;
    else
        return exit(0), 0;
}

/**
 * Reporta o resultado final
 * @param x Valor a ser reportado
 */
void reportar(int x) {
    printf("! %lld\n", x);
}

/**
 * Resolve um caso de teste
 */
void resolver() {
    posicao_atual = 1;
    contador_consultas = 0;

    int x = 2;

    // Verifica o caso base
    if (!consultar(1)) {
        reportar(0);
        return;
    }

    // Busca exponencial para encontrar um intervalo
    for (; consultar(x); x <<= 1);

    // Busca binária adaptativa
    int esquerda = x / 2, direita = x;
    while (esquerda < direita - 1) {
        // Garante que estamos dentro do intervalo válido
        while (posicao_atual < direita) consultar(esquerda);

        // Cálculo adaptativo do próximo ponto de consulta
        real_longo e = 1. * posicao_atual / (esquerda * __lg(direita - esquerda));
        real_longo p = 0;

        if (e > 1)
            p = 0.5;
        else
            p = 0.3 + 0.2 * e;

        int k = esquerda + max(1LL, (int)(p * (direita - esquerda)));

        // Atualiza os limites com base na resposta
        if (consultar(k))
            esquerda = k;
        else
            direita = k;
    }

    // Reporta o resultado final
    reportar(esquerda);
}

signed main() {
    int num_casos = ler_numero();
    while (num_casos--) resolver();
    return 0;
}