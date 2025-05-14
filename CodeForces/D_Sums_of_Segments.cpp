#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1<<19;

int n, a[maxn];
long long c[maxn], s[maxn], s2[maxn];

int main(){
    cin >> n;
    // f
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i-1]; // Prefix Sum
        s2[i] = s2[i-1] + a[i]; // Secondary Prefix Sum
        c[i] = c[i-1] + n - i + 1;
    }
    for(int i = 1; i <= n; i++){
        s[i] = s[i-1] + s2[n] - s2[i-1] - 1LL*(n-i+1)*a[i-1];
    }

    auto calc = [&](long long x){
        int p = lower_bound(c + 1, c + n + 1, x) - c;
        return s[p-1] + s2[p+x-c[p-1]-1] - s2[p-1] - a[p-1]*(x-c[p-1]);
    };

    int q;cin >> q;
    while(q--){
        long long l, r;
        cin >> l >> r;
        cout << calc(r) - calc(l-1) << endl;
    }
    return 0;
}