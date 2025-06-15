#include <stdio.h>
#define VALOR_ABSOLUTO(x) ((x) >= 0 ? (x) : -(x))

int main() {
    // Coordenadas de origem (x1,y1) e destino (x2,y2)
    int x1, y1, x2, y2;

    // Lê as coordenadas até o fim da entrada
    while (scanf("%d%d%d%d", &x1, &y1, &x2, &y2) == 4) {
        // movimentos[0] = Torre, movimentos[1] = Bispo, movimentos[2] = Rei
        int movimentos[3] = {0};

        // Se origem e destino são iguais, nenhum movimento é necessário
        if (x1 == x2 && y1 == y2) {
            movimentos[0] = movimentos[1] = movimentos[2] = 0;
        } else {
            // Calcula movimentos da Torre
            movimentos[0] = (x1 == x2 || y1 == y2) ? 1 : 2;

            // Calcula movimentos do Bispo
            int distanciaTotal = VALOR_ABSOLUTO(x1 - x2) + VALOR_ABSOLUTO(y1 - y2);
            if (distanciaTotal % 2 == 0) {
                if (VALOR_ABSOLUTO(x1 - x2) == VALOR_ABSOLUTO(y1 - y2))
                    movimentos[1] = 1;
                else
                    movimentos[1] = 2;
            } else {
                movimentos[1] = 0;  // Impossível alcançar com Bispo
            }

            // Calcula movimentos do Rei
            int distanciaX = VALOR_ABSOLUTO(x1 - x2);
            int distanciaY = VALOR_ABSOLUTO(y1 - y2);
            movimentos[2] = (distanciaX > distanciaY) ? distanciaX : distanciaY;
        }

        printf("%d %d %d\n", movimentos[0], movimentos[1], movimentos[2]);
    }
    return 0;
}