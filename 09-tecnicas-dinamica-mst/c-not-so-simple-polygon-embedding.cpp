#include <bits/stdc++.h>
using namespace std;
#define M_PI 3.14159265358979323846

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        double angle = M_PI / n;
        double x = 0.5 / sin(angle / 2);
        double angle2 = (round(n / 4.0)) * angle;

        double ans = x / sin(M_PI / 4) * (sin(angle2) + sin(M_PI / 2 - angle2));
        printf("%.9lf\n", ans);
    }
    return 0;
}