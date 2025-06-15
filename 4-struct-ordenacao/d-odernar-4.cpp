// #include <iostream>
// #include <vector>
// using namespace std;

// // tempo de complexidde: O(n + m*n)
// int main() {
//     // Declaração de variáveis
//     int n, m;
//     cin >> n >> m;

//     // Leitura do array inicial
//     vector<int> array(n + 1);  // Indexado a partir de 1
//     for (int i = 1; i <= n; i++) {
//         cin >> array[i];
//     }

//     // Array para armazenar a posição de cada número
//     vector<int> posicoes(n + 1);
//     for (int i = 1; i <= n; i++) {
//         posicoes[array[i]] = i;
//     }

//     // Função para calcular o número de voltas necessárias
//     auto calcularVoltas = [&]() {
//         int voltas = 1;
//         for (int i = 1; i < n; i++) {
//             if (posicoes[i] > posicoes[i + 1]) {
//                 voltas++;
//             }
//         }
//         return voltas;
//     };

//     // Para cada operação de troca
//     for (int op = 0; op < m; op++) {
//         int a, b;
//         cin >> a >> b;

//         // Executar a troca
//         int numA = array[a];
//         int numB = array[b];

//         // Atualizar o array
//         array[a] = numB;
//         array[b] = numA;

//         // Atualizar as posições
//         posicoes[numA] = b;
//         posicoes[numB] = a;

//         // Calcular e imprimir o número de voltas após a troca
//         cout << calcularVoltas() << endl;
//     }

//     return 0;
// }





// #include <iostream>
// #include <vector>
// using namespace std;

// // Tempo de complexidade de O(n + m)

// int main() {
//     int n, m;
//     cin >> n >> m;

//     // Leitura do array inicial (indexado a partir de 1)
//     vector<int> array(n + 1);
//     for (int i = 1; i <= n; i++) {
//         cin >> array[i];
//     }

//     // Posição de cada número
//     vector<int> posicoes(n + 1);
//     for (int i = 1; i <= n; i++) {
//         posicoes[array[i]] = i;
//     }

//     // Calcular voltas iniciais
//     int voltas = 1;
//     for (int i = 1; i < n; i++) {
//         if (posicoes[i] > posicoes[i + 1]) {
//             voltas++;
//         }
//     }

//     // Para cada operação de troca
//     for (int op = 0; op < m; op++) {
//         int a, b;
//         cin >> a >> b;
        
//         int numA = array[a];
//         int numB = array[b];

//         // Não precisamos fazer nada se os valores já são iguais
//         if (numA == numB) {
//             cout << voltas << endl;
//             continue;
//         }

//         // Verificar relações afetadas antes da troca
//         // 1. Para numA, olhamos se ele forma uma inversão com numA-1 e numA+1
//         if (numA > 1 && posicoes[numA-1] > posicoes[numA]) voltas--;
//         if (numA < n && posicoes[numA] > posicoes[numA+1]) voltas--;
        
//         // 2. Para numB, olhamos se ele forma uma inversão com numB-1 e numB+1
//         if (numB > 1 && posicoes[numB-1] > posicoes[numB]) voltas--;
//         if (numB < n && posicoes[numB] > posicoes[numB+1]) voltas--;
        
//         // Caso especial: Se numA e numB são consecutivos, evitamos dupla contagem
//         if (abs(numA - numB) == 1) {
//             int menor = min(numA, numB);
//             if (posicoes[menor] > posicoes[menor+1]) voltas++;
//         }

//         // Executar a troca
//         array[a] = numB;
//         array[b] = numA;

//         // Atualizar as posições
//         posicoes[numA] = b;
//         posicoes[numB] = a;

//         // Verificar novas relações após a troca
//         // 1. Para numA, olhamos se ele forma uma inversão com numA-1 e numA+1
//         if (numA > 1 && posicoes[numA-1] > posicoes[numA]) voltas++;
//         if (numA < n && posicoes[numA] > posicoes[numA+1]) voltas++;
        
//         // 2. Para numB, olhamos se ele forma uma inversão com numB-1 e numB+1
//         if (numB > 1 && posicoes[numB-1] > posicoes[numB]) voltas++;
//         if (numB < n && posicoes[numB] > posicoes[numB+1]) voltas++;
        
//         // Caso especial: Se numA e numB são consecutivos, evitamos dupla contagem
//         if (abs(numA - numB) == 1) {
//             int menor = min(numA, numB);
//             if (posicoes[menor] > posicoes[menor+1]) voltas--;
//         }

//         cout << voltas << endl;
//     }

//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// /**
//  * @brief Calcula o número de rodadas necessárias para coletar todos os números
//  * 
//  * @param posicoes Vetor com as posições de cada número no array
//  * @param n Tamanho do vetor
//  * @return int Número de rodadas
//  */
// int calcularRodadas(const vector<int>& posicoes, int n) {
//     int rodadas = 1;
//     int ultimaPosicao = -1;
    
//     // Para cada número de 1 a n em ordem
//     for (int i = 1; i <= n; i++) {
//         // Se a posição do número atual for menor que a posição do número anterior,
//         // precisamos de uma nova rodada
//         if (posicoes[i] < ultimaPosicao) {
//             rodadas++;
//         }
//         ultimaPosicao = posicoes[i];
//     }
    
//     return rodadas;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     int n, m;
//     cin >> n >> m;
    
//     vector<int> array(n + 1);
//     vector<int> posicoes(n + 1);
    
//     // Lê o array inicial
//     for (int i = 1; i <= n; i++) {
//         cin >> array[i];
//         posicoes[array[i]] = i; // Armazena a posição de cada número
//     }
    
//     // Processa cada operação de troca
//     for (int i = 0; i < m; i++) {
//         int a, b;
//         cin >> a >> b;
        
//         // Troca os números nas posições a e b
//         int valorA = array[a];
//         int valorB = array[b];
        
//         array[a] = valorB;
//         array[b] = valorA;
        
//         // Atualiza as posições
//         posicoes[valorA] = b;
//         posicoes[valorB] = a;
        
//         // Calcula e imprime o número de rodadas
//         cout << calcularRodadas(posicoes, n) << "\n";
//     }
    
//     return 0;
// }

// #include <iostream>
// #include <vector>

// using namespace std;

// int main(int argc, char const *argv[])
// {
//     int n;
//     cin >> n;
//     vector <int> v(n + 1), pos(n + 1);
//     for(int i = 1; i <= n; ++i){
//         cin >> v[i];
//         pos[v[i]] = i;
//     }
//     int total_rounds = 1; // we'll always need at least one round because the input sequence will never be empty
//     for(int i = 2; i <= n; ++i){
//         if(pos[i] < pos[i - 1]) total_rounds++;
//     }
//     cout << total_rounds << '\n';
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// #define int long long
// #define endl '\n'

// signed main(){
//     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
//     int n,m; cin>>n>>m;
//     int l = 1;
//     int ind[n+2] = {0}, a[n+1] = {0};
//     ind[n+1] = n+1;
//     for (int i = 1; i <= n; i++) {
// 		int x; cin>>x;
// 		ind[x] = i;
// 		a[i] = x;
//     }
//     int c = 1;
//     for (int i = 1; i <= n; i++) {
// 		if (l > ind[i]) 
// 		c++;
// 		l = ind[i];
//     }
//     while(m--) {
// 		int x,y; cin>>x>>y;
// 		int r = a[x], s = a[y];
// 		swap(a[x], a[y]);
// 		if (ind[r-1] <= ind[r] && ind[r-1] > y) c++;
// 		if (ind[r-1] > ind[r] && ind[r-1] <= y) c--;
// 		if (ind[r] <= ind[r+1] && y > ind[r+1]) c++;
// 		if (ind[r] > ind[r+1] && y <= ind[r+1]) c--;		
// 		ind[r] = y;
// 		if (ind[s-1] <= ind[s] && ind[s-1] > x) c++;
// 		if (ind[s-1] > ind[s] && ind[s-1] <= x) c--;
// 		if (ind[s] <= ind[s+1] && x > ind[s+1]) c++;
// 		if (ind[s] > ind[s+1] && x <= ind[s+1]) c--;	
// 		ind[s] = x;
// 		cout<<c<<endl;
//     }
// }

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    int ultimaPosicao = 1;
    int rodadas = 1;
    vector<int> posicaoDoNumero(n+2, 0);
    vector<int> numeroNaPosicao(n+1, 0);
    
    posicaoDoNumero[n+1] = n+1;
    
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        posicaoDoNumero[x] = i;
        numeroNaPosicao[i] = x;
    }
    
    for (int i = 1; i <= n; i++) {
        if (ultimaPosicao > posicaoDoNumero[i]) 
            rodadas++;
        ultimaPosicao = posicaoDoNumero[i];
    }
    
    while(m--) {
        int x, y;
        cin >> x >> y;
        
        int r = numeroNaPosicao[x];
        int s = numeroNaPosicao[y];
        swap(numeroNaPosicao[x], numeroNaPosicao[y]);
        
        if (posicaoDoNumero[r-1] <= posicaoDoNumero[r] && posicaoDoNumero[r-1] > y) rodadas++;
        if (posicaoDoNumero[r-1] > posicaoDoNumero[r] && posicaoDoNumero[r-1] <= y) rodadas--;
        if (posicaoDoNumero[r] <= posicaoDoNumero[r+1] && y > posicaoDoNumero[r+1]) rodadas++;
        if (posicaoDoNumero[r] > posicaoDoNumero[r+1] && y <= posicaoDoNumero[r+1]) rodadas--;
        
        posicaoDoNumero[r] = y;
        
        if (posicaoDoNumero[s-1] <= posicaoDoNumero[s] && posicaoDoNumero[s-1] > x) rodadas++;
        if (posicaoDoNumero[s-1] > posicaoDoNumero[s] && posicaoDoNumero[s-1] <= x) rodadas--;
        if (posicaoDoNumero[s] <= posicaoDoNumero[s+1] && x > posicaoDoNumero[s+1]) rodadas++;
        if (posicaoDoNumero[s] > posicaoDoNumero[s+1] && x <= posicaoDoNumero[s+1]) rodadas--;
        
        posicaoDoNumero[s] = x;
        
        cout << rodadas << endl;
    }
    
    return 0;
}