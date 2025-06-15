#include <cctype>
#include <iostream>
#include <string>
using namespace std;

// Funcao para verificar se uma string eh palindromo
bool ehPalindromo(const string& str, int inicio, int fim) {
    while (inicio < fim) {
        if (str[inicio] != str[fim]) return false;
        inicio++;
        fim--;
    }
    return true;
}

// Funcao para verificar se existe algum palindromo na string
bool temPalindromo(const string& str) {
    int n = str.length();

    // Verifica todas as substrings possiveis de tamanho >= 2
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ehPalindromo(str, i, j)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string linha;
    getline(cin, linha);

    // Processa a string: remove nao-alfabeticos e converte para minusculas
    string processada = "";
    for (char c : linha) {
        if (isalpha(c)) {
            processada += tolower(c);
        }
    }

    // Verifica se existe palindromo
    if (temPalindromo(processada)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Anti-palindrome" << endl;
    }

    return 0;
}
