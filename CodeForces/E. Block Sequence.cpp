#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), dp(n + 2, n + 1); // dp size n+2 to avoid bounds checking

    for (int i = 0; i < n; i++)
        cin >> a[i];

    dp[n] = 0; // Base case: at position n, we need 0 operations
    dp[n - 1] = 1; // At last position, we need exactly one operation

    for (int i = n - 2; i >= 0; i--) {
        int next_pos = i + a[i] + 1;
        if (next_pos > n)
            next_pos = n + 1; // out of bounds, set to default large value
        dp[i] = min(dp[i + 1] + 1, dp[next_pos]);
    }

    cout << dp[0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
