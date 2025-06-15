// # Medalhas

// A natação foi um dos esportes mais emocionantes das Olimpíadas do Rio. Houve até uma prova na qual três atletas chegaram empatados, cada um recebendo uma medalha de prata! Normalmente, porém, os três primeiros colocados terminam a prova em tempos distintos e, portanto, temos a distribuição mais comum de medalhas: o nadador que terminou no menor tempo recebe medalha de ouro; o nadador que terminou com o segundo menor tempo recebe medalha de prata; e o que terminou com o terceiro menor tempo recebe medalha de bronze. Neste problema, dados os três tempos distintos de finalização da prova, dos três nadadores que ganharam medalhas, seu programa deve dizer quem ganhou medalha de ouro, quem ganhou prata e quem ganhou bronze.

// ### Entrada

// A primeira linha da entrada contém um inteiro T1, indicando o tempo em que o nadador 1 terminou a prova. A segunda linha da entrada contém um inteiro T2, indicando o tempo de finalização do nadador 2. Por fim, a terceira linha da entrada contém um inteiro T3, indicando o tempo em que o nadador 3 terminou a prova.

// ### Saída

// Seu programa deve imprimir três linhas na saída. A primeira linha deve conter o número do nadador que ganhou medalha de ouro; a segunda linha, o número do nadador que ganhou prata; e a terceira linha, o número do nadador que levou bronze.

// ### Restrições

// - Os tempos T1, T2 e T3 são inteiros distintos, com valores entre 1 e 1000, inclusive.

// | Exemplos de Entrada | Exemplos de Saída |
// | --- | --- |
// | 230
// 183
// 234 | 2
// 1
// 3 |
// | 46
// 47
// 48 | 1
// 2
// 3 |
// | 11
// 21
// 7 | 3
// 1
// 2 |

// #include <iostream>
// #include <array>
// #include <algorithm>

// int main() {
//     std::array<std::pair<int, int>, 3> times;

//     for(int i = 0; i < 3; i++) {
//         int time;
//         std::cin >> time;
//         times[i] = {time, i + 1};
//     }

//     std::sort(times.begin(), times.end());

//     for(const auto& t : times)
//         std::cout << t.second << '\n';
// }

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int T1, T2, T3;
    std::cin >> T1 >> T2 >> T3;

    std::vector<std::pair<int, int>> times = {
        {T1, 1}, {T2, 2}, {T3, 3}};

    std::sort(times.begin(), times.end());

    for (const auto& t : times)
        std::cout << t.second << '\n';
}
