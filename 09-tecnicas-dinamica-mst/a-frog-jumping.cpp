#include <iostream>
using namespace std;

int main() {
    int t;
    for (cin >> t; t--;) {
        long long a, b, k;
        cin >> a >> b >> k;
        cout << (k / 2) * (a - b) + (k % 2 ? a : 0) << '\n';
    }
    return 0;
}
