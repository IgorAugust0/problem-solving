#include <iostream>

int main() {
    // Lê o número inicial
    long long n;
    std::cin >> n;

    // Imprime o primeiro número sem espaço no início
    std::cout << n;

    // Continua o algoritmo até n se tornar 1
    while (n != 1) {
        // Se n é par, divide por 2
        if (n % 2 == 0) {
            n = n / 2;
        }
        // Se n é ímpar, multiplica por 3 e soma 1
        else {
            n = n * 3 + 1;
        }

        // Imprime o próximo número com um espaço antes
        std::cout << " " << n;
    }

    std::cout << std::endl;

    return 0;
}