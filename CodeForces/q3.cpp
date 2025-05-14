#include <bits/stdc++.h>
using namespace std;

long long or_range(long long m) {
    if (m == 0) return 0;
    long long p = 1;
    while (p * 2 <= m) p *= 2;
    return (m == p) ? m - 1 : 2 * p - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, x;
        cin >> n >> x;

        if (n == 1) {
            cout << x << "\n";
            continue;
        }

        long long j = 0;
        while (((x >> j) & 1LL) == 1LL) j++;
        long long L0 = (1LL << j);
        long long candidate = min(n, L0);

        long long m;
        if (n == candidate) {
            m = (or_range(candidate) != x) ? candidate - 1 : candidate;
        } else {
            m = candidate;
        }

        vector<long long> ans;
        ans.reserve(n);

        long long cur = 0;
        for (long long num = 0; num < m; num++) {
            ans.push_back(num);
            cur |= num;
        }

        long long missing = x & (~cur);
        long long extra = n - m;

        if (extra > 0) {
            if (missing != 0) {
                ans.push_back(missing);
                extra--;
            }
            for (int i = 0; i < extra; i++) ans.push_back(0);
        }

        for (int i = 0; i < (int)ans.size(); i++) {
            cout << ans[i] << (i + 1 < (int)ans.size() ? ' ' : '\n');
        }
    }

    return 0;
}
