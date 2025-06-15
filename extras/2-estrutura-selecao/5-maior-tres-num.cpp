// # Maior Entre Três Números

// Bino recebeu de Cino três inteiros de presente e gostaria de saber qual dos três inteiros é o maior.

// ### Entrada

// A entrada consiste de três linhas. Cada linha contém um inteiro que Bino recebeu de presente.

// ### Saída

// A saída consiste de uma linha contendo o maior inteiro que Bino recebeu de presente.

// ### Restrições

// - Todos os valores fornecidos tem valor absoluto menor ou igual a 1000.

// | Exemplos de Entrada | Exemplos de Saída |
// | --- | --- |
// | 4
// 4
// 4 | 4 |
// | 1
// 2
// 3 | 3 |
// | 3
// 1
// -3 | 3 |
// | 2
// 9
// 6 | 9 |

// #include <iostream>
// #include <algorithm>

// int main() {
//     int a, b, c;
//     std::cin >> a >> b >> c;
//     std::cout << std::max({a, b, c});
// }

#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;

    std::cout << max;
}
