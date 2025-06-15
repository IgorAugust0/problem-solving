#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;  // Número máximo de nós
const int M = N * 2;    // Número máximo de arestas (duplicadas para grafo não-direcionado)

// Estrutura para Union-Find (Conjuntos Disjuntos)
int pai[N], nivel[N];

// Encontrar o representante do conjunto
int encontrarRepresentante(int x) {
    return pai[x] ? pai[x] = encontrarRepresentante(pai[x]) : x;
}

// Unir dois conjuntos
bool unir(int x, int y) {
    int a = encontrarRepresentante(x);
    int b = encontrarRepresentante(y);

    if (a == b) return false;  // Já estão no mesmo conjunto

    if (nivel[a] < nivel[b]) {
        pai[a] = b;
    } else {
        pai[b] = a;
        if (nivel[a] == nivel[b]) nivel[a]++;
    }
    return true;  // União realizada com sucesso
}

// Informações das arestas de entrada
int origem[N], destino[N], peso[N];

// Estrutura para representar o grafo
int cabeca[N];  // Lista de adjacência
int proximo[M], vertice[M], valorAresta[M];
int contadorArestas;  // Contador de arestas

// Adicionar aresta ao grafo
void adicionarAresta(int u, int v, int w) {
    vertice[++contadorArestas] = v;
    valorAresta[contadorArestas] = w;
    proximo[contadorArestas] = cabeca[u];
    cabeca[u] = contadorArestas;
}

int n, m;                 // Número de nós e arestas
int *criterioComparacao;  // Ponteiro para critério de comparação

// Função de comparação para ordenar arestas por peso
bool compararIndices(int i, int j) {
    return criterioComparacao[i] < criterioComparacao[j];
}

// Vetor de índices para ordenação
int indices[N];

// Algoritmo de Kruskal para encontrar a árvore geradora mínima
ll kruskal() {
    ll resultado = 0;

    // Inicializa o vetor de índices
    for (int i = 1; i <= m; i++)
        indices[i] = i;

    // Ordena as arestas por peso
    criterioComparacao = peso;
    sort(indices + 1, indices + 1 + m, compararIndices);

    // Constrói a árvore geradora mínima
    for (int i = 1; i <= m; i++) {
        int indice = indices[i];
        if (unir(origem[indice], destino[indice])) {
            // Adiciona a aresta à MST
            adicionarAresta(origem[indice], destino[indice], peso[indice]);
            adicionarAresta(destino[indice], origem[indice], peso[indice]);
            resultado += peso[indice];
            peso[indice] = 0;  // Marca a aresta como incluída na MST
        }
    }
    return resultado;
}

const int LOG = 19;  // Aproximadamente log₂(N)

// Estruturas para LCA (Lowest Common Ancestor)
int ancestral[N][LOG], pesoMaximo[N][LOG];
int profundidade[N];

// DFS para preencher informações de ancestrais e pesos
void dfs(int u, int pai = 0, int pesoPai = 0, int prof = 0) {
    ancestral[u][0] = pai;
    pesoMaximo[u][0] = pesoPai;
    profundidade[u] = prof;

    for (int i = cabeca[u]; i; i = proximo[i]) {
        int v = vertice[i];
        if (v == pai) continue;
        dfs(v, u, valorAresta[i], prof + 1);
    }
}

int logN;  // log₂(n) arredondado para cima

// Encontra o peso máximo no caminho entre dois nós
int encontrarPesoMaximo(int u, int v) {
    int resultado = 0;

    // Coloca os nós na mesma profundidade
    if (profundidade[u] < profundidade[v]) swap(u, v);
    for (int i = logN; i >= 0; i--)
        if (profundidade[u] - (1 << i) >= profundidade[v]) {
            resultado = max(resultado, pesoMaximo[u][i]);
            u = ancestral[u][i];
        }

    if (u == v) return resultado;

    // Sobe na árvore até encontrar o LCA
    for (int i = logN; i >= 0; i--)
        if (ancestral[u][i] != ancestral[v][i]) {
            resultado = max(resultado, max(pesoMaximo[u][i], pesoMaximo[v][i]));
            u = ancestral[u][i];
            v = ancestral[v][i];
        }

    return max(resultado, max(pesoMaximo[u][0], pesoMaximo[v][0]));
}

int main() {
    // Leitura dos dados
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &origem[i], &destino[i], &peso[i]);
    }

    // Encontra a árvore geradora mínima
    ll valorMST = kruskal();

    // Constrói a tabela de ancestrais
    dfs(1);
    logN = ceil(log2(n));

    // Preenche a tabela de ancestrais para consulta LCA em O(log n)
    for (int j = 1; j <= logN; j++) {
        for (int i = 1; i <= n; i++)
            if (ancestral[i][j - 1]) {
                ancestral[i][j] = ancestral[ancestral[i][j - 1]][j - 1];
                pesoMaximo[i][j] = max(pesoMaximo[i][j - 1], pesoMaximo[ancestral[i][j - 1]][j - 1]);
            }
    }

    // Para cada aresta, calcula o valor da MST incluindo essa aresta
    for (int i = 1; i <= m; i++) {
        if (peso[i] == 0) {
            // Aresta já está na MST
            printf("%lld\n", valorMST);
        } else {
            // Aresta não está na MST, calcula o novo valor
            // Adicionando essa aresta e removendo a aresta de maior peso no ciclo formado
            printf("%lld\n", valorMST + peso[i] - encontrarPesoMaximo(origem[i], destino[i]));
        }
    }

    return 0;
}