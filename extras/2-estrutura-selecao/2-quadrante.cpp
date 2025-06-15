// # Quadrante

// Faça um programa para ler dois inteiros X e Y representando um ponto em um plano cartesiano. Imprima qual quadrante esse ponto de encontra. Caso o ponto esteja em algum eixo, imprima apenas a mensagem "eixos".

// ### Entrada

// A entrada consiste de duas linhas. A primeira linha contém o inteiro X. A segunda linha contém o inteiro Y.

// ### Saída

// A saída consiste de uma linha contendo a mensagem indicando qual o quadrante que o ponto está.

// ### Restrições

// - −100 ≤ X,Y ≤ 100

// | Exemplos de Entrada | Exemplos de Saída |
// | --- | --- |
// | 1
// 2 | Q1 |
// | -2
// 2 | Q2 |
// | -5
// -6 | Q3 |
// | 4
// -1 | Q4 |
// | 7
// 0 | eixos |

// #include <iostream>

// int main() {
//     int X, Y;
//     std::cin >> X >> Y;

//     if (X == 0 || Y == 0)
//         std::cout << "eixos";
//     else if (X > 0 && Y > 0)
//         std::cout << "Q1";
//     else if (X < 0 && Y > 0)
//         std::cout << "Q2";
//     else if (X < 0 && Y < 0)
//         std::cout << "Q3";
//     else
//         std::cout << "Q4";
// }

#include <iostream>

int main() {
    int X, Y;
    std::cin >> X >> Y;
    
    std::cout << ((X == 0 || Y == 0) ? "eixos" :
                  (X > 0) ? (Y > 0 ? "Q1" : "Q4") :
                           (Y > 0 ? "Q2" : "Q3"));
}