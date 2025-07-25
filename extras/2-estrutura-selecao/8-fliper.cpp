// # Flíper

// Flíper é um tipo de jogo onde uma bolinha de metal cai por um labirinto de caminhos até chegar na parte de baixo do labirinto. A quantidade de pontos que o jogador ganha depende do caminho que a bolinha seguir. O jogador pode controlar o percurso da bolinha mudando a posição de algumas portinhas do labirinto. Cada portinha pode estar na posição 0, que significa virada para a esquerda, ou na posição 1 que quer dizer virada para a direita. Considere o flíper da figura abaixo, que tem duas portinhas. A portinha P*P* está na posição 1 e a portinha R*R*, na posição 0. Desse jeito, a bolinha vai cair pelo caminho B.

// **Figura 1**

// Você deve escrever um programa que, dadas as posições das portinhas P e R, neste flíper da figura, diga por qual dos três caminhos, A, B ou C, a bolinha vai cair!

// ### Entrada

// A entrada é composta por apenas uma linha contendo dois números P e R, indicando as posições das duas portinhas do flíper da figura.

// ### Saída

// A saída do seu programa deve ser também apenas uma linha, contendo uma letra maiúscula que indica o caminho por onde a bolinha vai cair: 'A', 'B' ou 'C'.

// ### Restrições

// - O número P pode ser 0 ou 1. O número R pode ser 0 ou 1.

// | Exemplos de Entrada | Exemplos de Saída |
// | --- | --- |
// | 1 0 | B |
// | 0 0 | C |

// #include <iostream>

// int main() {
//     int P, R;
//     std::cin >> P >> R;

//     if (P == 0)
//         std::cout << 'C';
//     else if (R == 0)
//         std::cout << 'B';
//     else
//         std::cout << 'A';
// }

#include <iostream>

int main() {
    bool p, r;
    std::cin >> p >> r;
    std::cout << (p ? r ? 'A' : 'B' : 'C');
}