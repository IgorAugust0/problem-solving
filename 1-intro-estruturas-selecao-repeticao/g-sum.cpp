#include <iostream>

int main() {
    int t;
    std::cin >> t;  // Número de casos de teste

    // Processa cada caso de teste
    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;

        // Verifica se algum número é a soma dos outros dois
        // Testa todas as possibilidades: a+b=c, b+c=a, a+c=b
        if (a + b == c || b + c == a || a + c == b) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}