#include <iostream>
#include <string>
#include <vector>
using namespace std;

// encontra o tamanho da maior subsequencia crescente
int encontrarLIS(const string& s) {
    vector<int> dp(s.length(), 1);
    int max_len = 0;

    // para cada posicao, verifica as anteriores
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < i; j++) {
            if (s[i] > s[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_len = max(max_len, dp[i]);
    }

    return max_len;
}

int main() {
    string s;
    cin >> s;

    // o numero minimo de letras a adicionar eh
    // 26 (alfabeto completo) menos o tamanho da maior subsequencia crescente
    int resultado = 26 - encontrarLIS(s);

    cout << resultado << endl;

    return 0;
}
