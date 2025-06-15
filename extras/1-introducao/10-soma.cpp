// # Soma

// Faça um programa que leia dois números inteiros digitados pelo teclado e imprima a soma deles.

// ### Entrada

// A entrada consiste de dois números inteiros X e Y, um em cada linha.

// ### Saída

// A saída do seu programa deve ser um inteiro S, representando a soma de X e Y.

// | Exemplos de Entrada | Exemplos de Saída |
// | --- | --- |
// | 3
// 4 | 7 |
// | 1
// 1 | 2 |

#include <iostream>

int main() {
    int X, Y;
    std::cin >> X >> Y;
    std::cout << X + Y << std::endl;
    return 0;
}