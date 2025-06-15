// # Área do Retângulo

// Faça um programa para ler dois valores inteiros A e B e imprima a área de um retângulo que tenha lados A e B.

// ### Entrada

// A entrada consiste de duas linhas. A primeira linha contém o inteiro A e a segunda linha contém o inteiro B.

// ### Saída

// A saída consiste de uma linha contendo a área de um retângulo que tenha lados A e B.

// ### Restrições

// - Os inteiros fornecidos não terem valor maior que 1000 ou menor que 1.

// | Exemplos de Entrada | Exemplos de Saída |
// | --- | --- |
// | 23 | 6 |
// | 42 | 8 |
// | 1010 | 100 |

#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;
    std::cout << A * B << std::endl;
    return 0;
}