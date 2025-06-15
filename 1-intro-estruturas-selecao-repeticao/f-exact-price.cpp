#include <iostream>

int main() {
    int X;
    std::cin >> X;

    // Primeiro verifica se está dentro dos limites permitidos
    if (X < 0 || X > 1000) {
        std::cout << "Valor invalido: X deve estar entre 0 e 1000" << std::endl;
        return 0;
    }

    // Se estiver dentro dos limites, verifica as condições do problema
    // 1. É divisível por 100
    // 2. É maior ou igual a 100 (pelo menos uma moeda)
    if (X >= 100 && X % 100 == 0) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}