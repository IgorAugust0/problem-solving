// # Positivo, Negativo ou Nulo

// Faça um programa para ler um inteiro x. Imprima a mensagem "positivo" se o valor for positivo. Imprima a mensagem "negativo" caso o valor seja negativo. Imprima a mensagem "nulo" se o valor for zero.

// ### Entrada

// A entrada consiste de uma linha contendo um inteiro.

// ### Saída

// A saída consiste de uma linha contendo uma mensagem.

// ### Restrições

// - o valor fornecido não terá valor absoluto maior que 1000.

// | Exemplos de Entrada | Exemplos de Saída |
// | --- | --- |
// | 7 | positivo |
// | -8 | negativo |
// | 0 | nulo |

// #include <iostream>

// int main() {
//     int x;
//     std::cin >> x;

//     if (x > 0) {
//         std::cout << "positivo";
//     } else if (x < 0) {
//         std::cout << "negativo";
//     } else {
//         std::cout << "nulo";
//     }
// }

#include <iostream>

int main() {
    int x;
    std::cin >> x;
    std::cout << (x > 0 ? "positivo" : x < 0 ? "negativo" : "nulo");
}