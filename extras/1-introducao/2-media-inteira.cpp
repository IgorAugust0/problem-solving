// # Média Inteira

// Faça um programa para ler dois valores inteiros A e B e imprima a média inteira dos valores A e B.

// ### Entrada

// A entrada consiste de duas linhas. A primeira linha contém o inteiro A e a segunda linha contém o inteiro B.

// ### Saída

// A saída consiste de uma linha contendo a média inteira dos valores A e B.

// ### Restrições

// - Os inteiros fornecidos não terem valor absoluto maior que 1000.

// | Exemplos de Entrada | Exemplos de Saída |
// | --- | --- |
// | 2
// 2 | 2 |
// | 5
// 6 | 5 |
// | 1
// 14 | 7 |

#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;
    std::cout << (A + B) / 2 << std::endl;
    return 0;
}