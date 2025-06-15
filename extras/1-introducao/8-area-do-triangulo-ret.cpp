// # Área do Triângulo Retângulo

// Faça um programa para ler dois valores inteiros A e B e imprima a área inteira de um triângulo retângulo que tenha bases A e B.

// ### Entrada

// A entrada consiste de duas linhas. A primeira linha contém o inteiro A e a segunda linha contém o inteiro B.

// ### Saída

// A saída consiste de uma linha contendo a área inteira de um triângulo retângulo que tenha bases A e B.

// ### Restrições

// - Os inteiros fornecidos não terem valor maior que 1000 ou menor que 1.

// | Exemplos de Entrada | Exemplos de Saída |
// | --- | --- |
// | 2
// 3 | 3 |
// | 4
// 2 | 4 |
// | 10
// 10 | 50 |

#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;
    std::cout << (A * B) / 2 << std::endl;
    return 0;
}