#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// Funcao para inverter e trocar p por q e vice-versa
string visualizarPorDentro(string s) {
    // Inverte a string
    reverse(s.begin(), s.end());

    // Troca p por q e vice-versa
    for (char& c : s) {
        if (c == 'p')
            c = 'q';
        else if (c == 'q')
            c = 'p';
        // w permanece w
    }

    return s;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        cout << visualizarPorDentro(s) << endl;
    }

    return 0;
}
