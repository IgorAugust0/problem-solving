#include <iostream>
#include <string>
using namespace std;

int main() {
    string jon, doctor;

    // Le as duas strings
    cin >> jon >> doctor;

    // Compara o comprimento das strings
    // Como ambas terminam em 'h', basta comparar os tamanhos totais
    if (jon.length() >= doctor.length()) {
        cout << "go" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
