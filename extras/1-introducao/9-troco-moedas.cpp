// # Troco em Moedas

// Bino tem que fornecer C centavos de troco e deseja fornecer esse troco com a menor quantidade possível de moedas. Bino possui infinitas moedas de um real, cinquenta centavos, vinte e cinco centavos, dez centavos, cinco centavos e de um centavo.

// Faça um programa para ler um inteiro C representando a quantidade de centavos que Bino tem que fornecer de troca. Imprima a quantidade de moedas que Bino forneceu e em seguida imprima a quantidade de cada tipo de moeda que Bino forneceu. **Tome muito cuidado com a formatação da sua saída**.

// ### Entrada

// A entrada consiste de uma única linha contendo o inteiro C.

// ### Saída

// A saída consiste de sete linhas. A primeira consiste de um inteiro representando a quantidade total de moedas. A segunda consiste na quantidade de moedas de um real utilizadas. A terceira consiste na quantidade de moedas de cinquenta centavos utilizadas. A quarta consiste na quantidade de moedas de vinte e cinco centavos utilizadas. A quinta consiste na quantidade de moedas de dez centavos utilizadas. A sexta consiste na quantidade de moedas de cinco centavos utilizadas. A sétima linha consiste na quantidade de moedas de um centavo utilizadas.

// ### Restrições

// - O valor fornecido não será negativo nem maior que 10000

// | Exemplos de Entrada | Exemplos de Saída |
// | --- | --- |
// | 80 | 3
// 0
// 1
// 1
// 0
// 1
// 0 |
// | 999 | 1
// 7
// 9
// 1
// 1
// 2
// 0
// 4 |

#include <iostream>

int main() {
    int C, total = 0;
    std::cin >> C;

    int coins[] = {100, 50, 25, 10, 5, 1};
    int count[6] = {0};

    for (int i = 0; i < 6; i++) {
        count[i] = C / coins[i];
        C %= coins[i];
        total += count[i];
    }

    std::cout << total << std::endl;
    for (int i = 0; i < 6; i++) {
        std::cout << count[i] << std::endl;
    }

    return 0;
}