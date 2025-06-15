#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<i64> a(n);
        for (auto& i : a) cin >> i;

        sort(a.rbegin(), a.rend());
        i64 cnt = 1, ans = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] * cnt >= x) {
                ans++;
                cnt = 1;
            } else {
                cnt++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
