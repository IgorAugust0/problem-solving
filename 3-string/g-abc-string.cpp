#include <iostream>
#include <string>
using namespace std;

int encontrarMinSubsequencias(const string& s) {
    int n = s.length();
    int count_a = 0, count_b = 0, count_c = 0;

    // conta ocorrencias de cada letra
    for (char c : s) {
        if (c == 'A')
            count_a++;
        else if (c == 'B')
            count_b++;
        else
            count_c++;
    }

    // como temos o mesmo numero de cada letra e cada subsequencia
    // precisa ter igual numero de A, B e C, precisamos de count_a/2
    // subsequencias (ou count_b/2 ou count_c/2, sao todos iguais)
    return count_a / 2;
}

int main() {
    string s;
    cin >> s;

    cout << encontrarMinSubsequencias(s) << endl;

    return 0;
}

// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string s;
//     cin >> s;

//     int n = s.length();
//     // Como temos mesmo número de cada letra e cada subsequencia
//     // precisa ter comprimento divisivel por 3, podemos usar n/6
//     // pois precisamos de pelo menos 2 subsequencias para dividir
//     // a string original (que tem n/3 de cada letra)
//     cout << 2 << endl;

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// // Função para verificar se uma string é bonita
// bool ehBonita(const string& texto) {
//     if (texto.length() % 3 != 0) return false;

//     int contadorA = 0, contadorB = 0, contadorC = 0;
//     for (char c : texto) {
//         if (c == 'A') contadorA++;
//         else if (c == 'B') contadorB++;
//         else contadorC++;
//     }

//     return contadorA == contadorB && contadorB == contadorC;
// }

// // Função para encontrar o número mínimo de subsequências bonitas
// int subsequenciasBonitasMinimas(const string& texto) {
//     int n = texto.length();
//     vector<vector<vector<int>>> dp(n + 1,
//         vector<vector<int>>(n/3 + 1,
//             vector<int>(n/3 + 1, n + 1)));

//     // Caso base: string vazia
//     dp[0][0][0] = 0;

//     // Para cada posição na string
//     for (int i = 0; i < n; i++) {
//         // Para cada quantidade de A's usados
//         for (int qtdA = 0; qtdA <= n/3; qtdA++) {
//             // Para cada quantidade de B's usados
//             for (int qtdB = 0; qtdB <= n/3; qtdB++) {
//                 // Pula estados inválidos
//                 if (dp[i][qtdA][qtdB] == n + 1) continue;

//                 // Não pega o caractere atual
//                 dp[i + 1][qtdA][qtdB] = min(dp[i + 1][qtdA][qtdB], dp[i][qtdA][qtdB]);

//                 // Pega o caractere atual
//                 if (texto[i] == 'A' && qtdA < n/3) {
//                     dp[i + 1][qtdA + 1][qtdB] = min(dp[i + 1][qtdA + 1][qtdB], dp[i][qtdA][qtdB]);
//                 }
//                 else if (texto[i] == 'B' && qtdB < n/3) {
//                     dp[i + 1][qtdA][qtdB + 1] = min(dp[i + 1][qtdA][qtdB + 1], dp[i][qtdA][qtdB]);
//                 }
//                 else if (texto[i] == 'C') {
//                     int qtdC = i - qtdA - qtdB;
//                     if (qtdC < n/3 && qtdA > 0 && qtdB > 0 && qtdC + 1 <= qtdA && qtdC + 1 <= qtdB) {
//                         dp[i + 1][qtdA][qtdB] = min(dp[i + 1][qtdA][qtdB], dp[i][qtdA][qtdB] + 1);
//                     }
//                 }
//             }
//         }
//     }

//     return dp[n][n/3][n/3];
// }

// int main() {
//     string textoEntrada;
//     cin >> textoEntrada;

//     // Verifica as restrições de entrada
//     int tamanho = textoEntrada.length();
//     if (tamanho % 3 != 0) {
//         cout << "O comprimento da string deve ser divisível por 3" << endl;
//         return 1;
//     }

//     int qtdA = 0, qtdB = 0, qtdC = 0;
//     for (char c : textoEntrada) {
//         if (c == 'A') qtdA++;
//         else if (c == 'B') qtdB++;
//         else if (c == 'C') qtdC++;
//         else {
//             cout << "Caractere inválido na string" << endl;
//             return 1;
//         }
//     }

//     if (qtdA != qtdB || qtdB != qtdC) {
//         cout << "A string deve conter quantidades iguais de A, B e C" << endl;
//         return 1;
//     }

//     cout << subsequenciasBonitasMinimas(textoEntrada) << endl;
//     return 0;
// }

