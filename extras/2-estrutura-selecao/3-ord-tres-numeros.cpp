// # Ordenação de Três Números

// Bino recebeu três inteiros de Cino. Bino gostaria de ordenar esses três valores em ordem crescente. Ajude Bino em ordenar seus números queridos.

// ### Entrada

// A entrada consiste de três linhas. Cada uma das linhas consiste de um inteiro representando um inteiro que Bino recebeu.

// ### Saída

// A saída consiste de três linhas. Cada linha consiste de um dos números que Bino recebeu. Os números serão apresentados em ordem crescente.

// ### Restrições

// - Todos os valores fornecidos tem valor absoluto menor ou igual a 1000.

// | Exemplos de Entrada | Exemplos de Saída |
// | --- | --- |
// | 1
// 2
// 3 | 1
// 2
// 3 |
// | 3
// 2
// 1 | 1
// 2
// 3 |
// | 2
// 2
// 2 | 2
// 2
// 2 |
// | 1
// 2
// 1 | 1
// 1
// 2 |

// #include <iostream>
// #include <algorithm>
// #include <array>

// int main() {
//     int a, b, c;
//     std::cin >> a >> b >> c;
    
//     std::array<int, 3> nums = {a, b, c};
//     std::sort(nums.begin(), nums.end());
    
//     std::cout << nums[0] << '\n' 
//               << nums[1] << '\n'
//               << nums[2] << '\n';
// }

#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    
    int temp;
    if (a > b) { temp = a; a = b; b = temp; }
    if (b > c) { temp = b; b = c; c = temp; }
    if (a > b) { temp = a; a = b; b = temp; }
    
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
}