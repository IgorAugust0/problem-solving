#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    // Verificar restricoes
    if (1 <= a && a <= 2025 && 1 <= b && b <= 2025) {
        long long sum = a + b;
        cout << sum * sum << endl;
    } else {
        cout << "Invalid input" << endl;
    }

    return 0;
}