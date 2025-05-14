#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAXLL = 1000000000000ll;
// 12 zeros

int get_first_bit(ll n){
    return 63-__builtin_clzll(n);
    // __builtin_clzll Counts the number of leading zeros in a number
}

int get_bit_count(ll n){
    return __builtin_popcountll(n);
}

int main(){
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> fact;
        ll factorial = 6, number = 4;
        while(factorial <= MAXLL){
            fact.push_back(factorial);
            factorial*=number;
            number++;
        }
        vector<pair<ll, ll>> fact_sum(1 << fact.size());
        fact_sum[0] = {0, 0};
        for(int mask = 1; mask < (1 << fact.size()); mask){
            auto first_bit = get_first_bit(mask);
            fact_sum[mask].first = fact_sum[mask ^ (1 << first_bit)].first + fact[first_bit];
            fact_sum[mask].second = get_bit_count(mask);
        }
        ll res = get_bit_count(n);
        for(auto i : fact_sum){
            if(i.first <= n){
                res = min(res, i.second + get_bit_count(n - i.first));
            }
        }
        cout << res << endl;
    }
    return 0;
}