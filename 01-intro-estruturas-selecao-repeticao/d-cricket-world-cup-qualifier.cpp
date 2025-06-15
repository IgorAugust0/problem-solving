#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;

    if (1 <= x && x <= 20) {  // Verificar restricoes
        if (x >= 12) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        cout << "Entrada invalida" << endl;
    }

    return 0;
}