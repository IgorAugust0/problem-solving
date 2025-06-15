// # Média Inteira Ponderada

// Faça um programa para ler dois valores inteiros A e B e imprima a média ponderada dos dois valores. O peso de A é 4 e o peso de B é 6.

// ### Entrada

// A entrada consiste de duas linhas. A primeira linha contém o inteiro A e a segunda linha contém o inteiro B.

// ### Saída

// A saída consiste de uma linha contendo a média ponderada **(apenas a parte inteira)** dos dois valores.

// ### Restrições

// - Os inteiros fornecidos não terem valor absoluto maior que 1000.

// | Exemplos de Entrada | Exemplos de Saída |
// | --- | --- |
// | 0
// 5 | 3 |
// | 5
// 0 | 2 |
// | 6
// 6 | 6 |

#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;
    std::cout << (2 * A + 3 * B) / 5 << std::endl;
    return 0;
}