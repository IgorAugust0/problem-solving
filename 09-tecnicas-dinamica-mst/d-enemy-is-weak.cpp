#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1000010;

ll n, ans, a[N], b[N], ft[N];

inline ll get(ll idx) {
    ll ret = 0;
    while (idx) ret += ft[idx], idx -= idx & -idx;
    return ret;
}

inline void add(ll idx) {
    while (idx <= n) ft[idx]++, idx += idx & -idx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], b[i] = a[i];
    sort(b, b + n);

    for (int i = 0; i < n; i++) {
        ll pos = lower_bound(b, b + n, a[i]) - b + 1;
        ll cur = get(pos);
        ans += (i - cur) * (pos - 1 - cur);
        add(pos);
    }

    cout << ans << '\n';
    return 0;
}
