#include <iostream>
#include <string>

int main() {
    std::string dna;
    std::cin >> dna;

    // Variáveis para controle
    int maxRep = 1;      // Maior sequência encontrada
    int currentRep = 1;  // Sequência atual sendo contada

    // Percorre a string comparando caracteres adjacentes
    for (int i = 1; i < dna.length(); i++) {
        // Se o caractere atual é igual ao anterior
        if (dna[i] == dna[i - 1]) {
            currentRep++;
            // Atualiza o máximo se necessário
            maxRep = std::max(maxRep, currentRep);
        }
        // Se for diferente, reinicia a contagem
        else {
            currentRep = 1;
        }
    }

    std::cout << maxRep << std::endl;

    return 0;
}