#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

// Function to compute the sum of the first x natural numbers modulo MOD
ll sum_of_natural_numbers(ll x) {
    return ((x % MOD) * ((x + 1) % MOD) / 2) % MOD;
}

int main() {
    ll N, total_sum = 0;
    scanf("%lld", &N);
    
    for (ll left = 1; left <= N; ) {
        // Find the maximum right value where N / left remains the same
        ll right = N / (N / left);
        
        // Contribution of the current segment
        ll segment_sum = (N / left) % MOD * (sum_of_natural_numbers(right) - sum_of_natural_numbers(left - 1) + MOD) % MOD;
        total_sum = (total_sum + segment_sum) % MOD;
        
        // Move to the next segment
        left = right + 1;
    }
    
    printf("%lld\n", total_sum);
    return 0;
}
