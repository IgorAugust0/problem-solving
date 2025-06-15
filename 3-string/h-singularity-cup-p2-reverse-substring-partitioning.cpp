#include <iostream>
#include <string>
#include <vector>
using namespace std;

// verifica se podemos fazer uma operacao RSP no indice i
bool podeExecutarRSP(const string& s, int i) {
    // ultima letra da primeira parte (revertida) deve ser igual
    // a primeira letra da segunda parte (revertida)
    return s[0] == s[s.length() - 1];
}

int encontrarMenorComprimento(string s) {
    int n = s.length();

    // se a string tem tamanho 2 ou menos, nao podemos reduzir mais
    if (n <= 2) return n;

    // se primeira e ultima letra sao iguais, podemos reduzir em 2
    // recursivamente ate nao ser mais possivel
    if (s[0] == s[n - 1]) {
        return encontrarMenorComprimento(s.substr(1, n - 2));
    }

    return n;
}

int main() {
    int N;
    string S;

    cin >> N;
    cin >> S;

    cout << encontrarMenorComprimento(S) << endl;

    return 0;
}
