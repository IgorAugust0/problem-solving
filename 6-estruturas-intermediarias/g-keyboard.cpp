#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Definição do teclado em linhas
    string linha1 = "qwertyuiop";
    string linha2 = "asdfghjkl;";
    string linha3 = "zxcvbnm,./";

    // Mapa para encontrar caractere original
    map<char, char> esquerda, direita;

    // Preencher mapas de deslocamento
    for (int i = 0; i < linha1.length(); i++) {
        if (i > 0) esquerda[linha1[i]] = linha1[i - 1];
        if (i < linha1.length() - 1) direita[linha1[i]] = linha1[i + 1];
    }
    for (int i = 0; i < linha2.length(); i++) {
        if (i > 0) esquerda[linha2[i]] = linha2[i - 1];
        if (i < linha2.length() - 1) direita[linha2[i]] = linha2[i + 1];
    }
    for (int i = 0; i < linha3.length(); i++) {
        if (i > 0) esquerda[linha3[i]] = linha3[i - 1];
        if (i < linha3.length() - 1) direita[linha3[i]] = linha3[i + 1];
    }

    // Ler direção do deslocamento
    char direcao;
    cin >> direcao;

    // Ler mensagem digitada
    string mensagemDigitada;
    cin >> mensagemDigitada;

    // Decodificar mensagem
    string mensagemOriginal;
    map<char, char>& mapa = (direcao == 'L' ? direita : esquerda);

    for (char c : mensagemDigitada) {
        mensagemOriginal += mapa[c];
    }

    // Imprimir resultado
    cout << mensagemOriginal << endl;

    return 0;
}
