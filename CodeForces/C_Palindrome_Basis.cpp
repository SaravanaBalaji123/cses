#include <bits/stdc++.h>
using namespace std;

const int MAX_LIMIT = 4e4+1;
const int MOD = 1e9 + 7;
vector<int> palin_odd, palin_even, palin;

// Function to generate odd-length and even-length palindromes
void precomputePalin() {
    for (int i = 1; i < 10; i++) {
        palin_odd.push_back(i);
    }
    // Generate odd-length palindromes
    for (int half = 1; half < 41; ++half) {
        string s = to_string(half);
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        for (int j = 0; j < 10; ++j) { // Insert a digit in the middle
            int palindrome = stoi(s + to_string(j) + rev_s);
            if (palindrome < MAX_LIMIT) {
                palin_odd.push_back(palindrome);
            }
        }
    }

    // Generate even-length palindromes
    for (int half = 1; half < 100; ++half) {
        string s = to_string(half);
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        int palindrome = stoi(s + rev_s); // Directly append the reversed half
        if (palindrome < MAX_LIMIT) {
            palin_even.push_back(palindrome);
        }
    }
}

// Merge odd and even palindromes into a single sorted array
void mergePalindromes() {
    int i = 0, j = 0;
    while (i < palin_odd.size() && j < palin_even.size()) {
        if (palin_odd[i] < palin_even[j]) {
            palin.push_back(palin_odd[i++]);
        } else {
            palin.push_back(palin_even[j++]);
        }
    }
    while (i < palin_odd.size()) {
        palin.push_back(palin_odd[i++]);
    }
    while (j < palin_even.size()) {
        palin.push_back(palin_even[j++]);
    }
}

int main() {
    // Precompute palindromes
    precomputePalin();
    mergePalindromes();
    
    int t;
    cin >> t;
    
    int k = 4e4 + 10;
    vector<int> dp(k + 1, 0); // Use vector for dynamic size
    dp[0] = 1; // Base case
    
    for (auto x : palin) {
        for(int j = 0; j <= k-x; j++){
            dp[j+x] = (dp[j+x]+dp[j])%MOD;
        }
    }
    // auto it = lower_bound(dp.begin(), dp.end(), 362757533) - dp.begin();
    // cout << it << endl;
    
    // Print total palindromes
    // cout << "Total Palindromes: " << palin.size() << endl;
    // for (int p : palin) {
    //     cout << p << endl;
    // }
    
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << endl; // 1-indexed correction removed
    }
    
    return 0;
}
