// # Basquete de Robôs

// A organização da OIBR, Olimpíada Internacional de Basquete de Robô, está começando a ter problemas com dois times: os Bit Warriors e os Byte Bulls. É que os robôs desses times acertam quase todos os lançamentos, de qualquer posição na quadra! Pensando bem, o jogo de basquete ficaria mesmo sem graça se jogadores conseguissem acertar qualquer lançamento, não é mesmo? Uma das medidas que a OIBR está implantando é uma nova pontuação para os lançamentos, de acordo com a distância do robô para o início da quadra. A quadra tem 2000 centímetros de comprimento, como na figura.

// !https://api.neps.academy/image/1297.png

// **Figura 1**

// Dada a distância D do robô até o início da quadra, onde está a cesta, a regra é a seguinte:

// - Se D ≤ 800, a cesta vale 1 ponto;

//     D≤800

// - Se 800 < D ≤ 1400, a cesta vale 2 pontos;

//     800 < D ≤ 1400

// - Se 1400 < *D* ≤ 2000, a cesta vale 3 pontos.

//     1400 < D ≤ 2000

// A organização da OIBR precisa de ajuda para automatizar o placar do jogo. Dado o valor da distância D, você deve escrever um programa para calcular o número de pontos do lançamento.

// ### Entrada

// A primeira e única linha da entrada contém um inteiro D indicando a distância do robô para o início da quadra, em centímetros, no momento do lançamento

// ### Saída

// Seu programa deve produzir uma única linha, contendo um inteiro, 1, 2 ou 3, indicando a pontuação do lançamento.

// ### Restrições

// - 0 ≤ D ≤ 20000 ≤ D **≤ 2000

// | Exemplos de Entrada | Exemplos de Saída |
// | --- | --- |
// | 1720 | 3 |
// | 250 | 1 |
// | 1400 | 2 |

// #include <iostream>

// int main() {
//     int D;
//     std::cin >> D;

//     if (D <= 800)
//         std::cout << 1;
//     else if (D <= 1400)
//         std::cout << 2;
//     else
//         std::cout << 3;
// }

#include <ios>
#include <iostream>

int main() {
    int d;
    std::cin.tie(0)->sync_with_stdio(0);
    std::cin >> d;
    std::cout << (d <= 800 ? 1 : d <= 1400 ? 2 : 3);
}
