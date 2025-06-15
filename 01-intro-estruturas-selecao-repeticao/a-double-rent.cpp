#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;

    if (1 <= x && x <= 10) {
        cout << x * 2 << endl;
    } else {
        cout << "Digite um numero entre 1 e 10" << endl;
    }
    return 0;
}