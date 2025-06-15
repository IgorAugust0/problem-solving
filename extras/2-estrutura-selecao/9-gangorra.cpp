// # Gangorra

// Joãozinho acaba de mudar de escola e a primeira coisa que percebeu na nova escola é que a gangorra do parquinho não é simétrica, uma das extremidades é mais longa que a outra. Após brincar algumas vezes com um amigo de mesmo peso, ele percebeu que quando está em uma extremidade, a gangorra se desequilibra para o lado dele (ou seja, ele fica na parte de baixo, e o amigo na parte de cima), mas quando eles trocam de lado, a gangorra se desequilibra para o lado do amigo.

// Sem entender a situação, Joãozinho pediu ajuda a outro amigo de outra série, que explicou que o comprimento do lado interfere no equilíbrio da gangorra, pois a gangorra estará equilibrada quando P1 ⋅ C1 = P2 ⋅ C2 onde P1 e P2 são os pesos da criança no lado esquerdo e direito, respectivamente, e C1 e C2 são os comprimentos da gangorra do lado esquerdo e direito, respectivamente.

// Com a equação, Joãozinho já consegue dizer se a gangorra está equilibrada ou não mas, além disso, ele quer saber para qual lado a gangorra descerá caso esteja desequilibrada.

// ### Entrada

// A primeira e única linha da entrada contém 4 inteiros, P1, C1, P2 e C2, nesta ordem.

// ### Saída

// Seu programa deve produzir uma única linha, contendo um único inteiro. Se a gangorra estiver equilibrada, imprima '0'. Se ela estiver desequilibrada de modo que a criança esquerda esteja na parte de baixo, imprima '-1', senão, imprima '1'.

// ### Restrições

// - 10 ≤ P1 ≤ 100
// - 10 ≤ C1 ≤100
// - 10 ≤ P2 ≤100
// - 10 ≤ C2 ≤100

// | Exemplos de Entrada | Exemplos de Saída |
// | --- | --- |
// | 30 100 60 50 | 0 |
// | 40 40 38 60 | 1 |

// #include <iostream>

// int main() {
//     int P1, C1, P2, C2;
//     std::cin >> P1 >> C1 >> P2 >> C2;

//     int left = P1 * C1;
//     int right = P2 * C2;

//     if (left == right)
//         std::cout << 0;
//     else if (left > right)
//         std::cout << -1;
//     else
//         std::cout << 1;
// }

#include <iostream>

int main() {
    int p1, c1, p2, c2;
    std::cin >> p1 >> c1 >> p2 >> c2;
    std::cout << (p1 * c1 == p2 * c2 ? 0 : p1 * c1 > p2 * c2 ? -1 : 1);
}