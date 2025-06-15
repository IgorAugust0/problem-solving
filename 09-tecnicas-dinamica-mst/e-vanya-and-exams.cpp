#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, r, avg, count = 0;
    cin >> n >> r >> avg;

    vector<pair<ll, ll>> s;
    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        count += a;
        s.push_back({b, a});
    }

    sort(s.begin(), s.end());
    ll target = avg * n - count;
    ll result = 0;

    for (auto &p : s) {
        if (target <= 0) break;
        ll possible = r - p.second;
        ll take = min(target, possible);
        result += take * p.first;
        target -= take;
    }

    cout << result;
    return 0;
}
