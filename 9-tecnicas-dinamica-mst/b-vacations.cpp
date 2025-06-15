#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<vector<int>> dp(n + 1, vector<int>(3, n + 1));
    fill(dp[0].begin(), dp[0].end(), 0);

    for (int i = 1; i <= n; i++) {
        dp[i][0] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;
        if (a[i - 1] & 1) dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        if (a[i - 1] & 2) dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
    return 0;
}