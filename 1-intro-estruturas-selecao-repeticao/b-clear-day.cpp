#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    // Verificar restricoes
    if (x >= 0 && x <= 7 && y >= 0 && y <= 7 && (x + y) <= 7) {
        cout << 7 - x - y << endl;
    } else {
        cout << "Entrada invalida" << endl;
    }

    return 0;
}