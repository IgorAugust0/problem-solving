#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Número de elementos no array
    int n;
    cin >> n;
    
    // Vetor para armazenar os números
    vector<long long> numeros(n);
    
    // Leitura dos números
    for(int i = 0; i < n; i++) {
        cin >> numeros[i];
    }
    
    // Variável para contar o número mínimo de movimentos
    long long movimentos = 0;
    
    // Percorre o array a partir do segundo elemento
    for(int i = 1; i < n; i++) {
        // Se o elemento atual é menor que o anterior
        if(numeros[i] < numeros[i-1]) {
            // Calcula quantos movimentos são necessários para tornar
            // o elemento atual maior ou igual ao anterior
            movimentos += numeros[i-1] - numeros[i];
            // Atualiza o valor do elemento atual
            numeros[i] = numeros[i-1];
        }
    }
    
    // Imprime o resultado
    cout << movimentos << endl;
    
    return 0;
}