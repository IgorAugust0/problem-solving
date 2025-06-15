// # Divisão

// Faça um programa que leia dois números reais A e B digitados pelo teclado e imprima a divisão de A por B.

// ### Entrada

// A entrada consiste de dois números reais A*A* e B*B*, um em cada linha.

// ### Saída

// A saída do seu programa deve ser um número real S*S*, representando a divisão de A por B  com precisão de 2 casas decimais.

// | Exemplos de Entrada | Exemplos de Saída |
// | --- | --- |
// | 5
// | 2 | 2.50 |

// | 10
// | 2 | 5.00 |

#include <iomanip>
#include <iostream>

int main() {
    double A, B;
    std::cin >> A >> B;
    std::cout << std::fixed << std::setprecision(2) << A / B << std::endl;
    return 0;
}