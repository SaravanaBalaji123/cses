#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int MAX_N = 2e5+7;

int64_t factorial[MAX_N];

// Function to calculate (a^b) % MOD using fast exponentiation
int64_t power(int64_t a, int64_t b){
    int64_t result = 1;
    while(b > 0){
        if(b & 1) result = (result*a)%MOD; 
        a = (a*a)%MOD;
        b >>= 1;
    }
    return result;
}

//Function to calculate nCr % MOD using modular inverse
int64_t binomial_coefficient(int64_t n, int64_t r){
    if(n < r || r < 0 || n < 0) return 0LL; // Invalid Case
    int64_t denominator = (factorial[r]*factorial[n-r])%MOD;
    // cout << "n: " << n << ", r: " << r << ", denominator: " << denominator << "\n";
    return (factorial[n]*power(denominator, MOD-2))%MOD;
}

int main(){
    factorial[0] = 1;
    for(int64_t i = 1; i < MAX_N; i++){
        factorial[i] = (factorial[i-1]*i)%MOD;
    }

    // for(int i = 1; i < 10; i++){
    //     cout << factorial[i] << endl;
    // }

    int t; cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        vector<int> array(n);
        int total_ones = 0;

        for(int i  = 0; i < n; i++){
            cin >> array[i];
            if(array[i] == 1){
                total_ones++;
            }
        }
        // int64_t test = power(3, 5);
        // cout << test << endl;
        int64_t result = 0;
        int min_ones = (k + 1)/2;
        // cout << total_ones << " " << min_ones << endl;
        for(int count_ones = min_ones; count_ones <= total_ones; count_ones++){
            int64_t valid_ones = binomial_coefficient(total_ones, count_ones);
            int64_t valid_zeros = binomial_coefficient(n - total_ones, k - count_ones);
            result = (result + valid_ones*valid_zeros)%MOD;
        }
        cout << result << endl;
    }
    return 0;
}