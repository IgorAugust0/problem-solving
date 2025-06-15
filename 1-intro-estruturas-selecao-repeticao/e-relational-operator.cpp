#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    // Verifica se esta dentro das restricoes
    if (0 < t && t < 15) {
        while (t--) {
            long long a, b;  // Usando 'long long' para grandes numeros
            cin >> a >> b;

            if (a > b)
                cout << ">" << endl;
            else if (a < b)
                cout << "<" << endl;
            else
                cout << "=" << endl;
        }
    }

    return 0;
}