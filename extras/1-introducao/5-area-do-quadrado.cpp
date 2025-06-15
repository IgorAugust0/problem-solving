// # Área do Quadrado

// Faça um programa para um inteiro L e imprima a área de uma quadrado de lado L.

// ### Entrada

// A entrada consiste de uma linha contendo um inteiro L.

// ### Saída

// A saída consiste de uma linha contendo a área do quadrado de lado L.

// ### Restrições

// - Os inteiros fornecidos não terem valor maior que 1000 ou menor que 1

// | Exemplos de Entrada | Exemplos de Saída |
// | --- | --- |
// | 1 | 1 |
// | 2 | 4 |
// | 3 | 9 |

#include <iostream>

int main() {
    int L;
    std::cin >> L;
    std::cout << L * L << std::endl;
    return 0;
}