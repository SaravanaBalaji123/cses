#include <bits/stdc++.h>
using namespace std;

// Define a constant for the maximum value of factorials to consider
const long long MAXAI = 1000000000000ll;

// Function to get the position of the first set bit (most significant bit) in a number
int get_first_bit(long long n) {
    return 63 - __builtin_clzll(n); // __builtin_clzll counts leading zeros in a 64-bit integer
}

// Function to count the number of set bits (1s) in a number
int get_bit_count(long long n) {
    return __builtin_popcountll(n); // __builtin_popcountll counts the number of 1s in a 64-bit integer
}

int main() {
    ios::sync_with_stdio(0); // Fast I/O
    cin.tie(0);
    cout.tie(0);

    int t; 
    cin >> t; // Number of test cases

    for (int test_number = 0; test_number < t; test_number++) {
        long long n; 
        cin >> n; // Input number for the current test case

        // Step 1: Precompute all factorials <= MAXAI starting from 4! = 24
        vector<long long> fact;
        long long factorial = 6, number = 4; // Start with 3! = 6 and compute onwards
        while (factorial <= MAXAI) {
            fact.push_back(factorial); // Store the factorial
            factorial *= number;      // Compute the next factorial
            number++;
        }

        // Step 2: Precompute all possible sums of subsets of factorials using bit masks
        vector<pair<long long, long long>> fact_sum(1 << fact.size());
        fact_sum[0] = {0, 0}; // Base case: sum = 0, bit count = 0

        for (int mask = 1; mask < (1 << fact.size()); mask++) {
            auto first_bit = get_first_bit(mask); // Get the position of the first set bit in the mask
            fact_sum[mask].first = fact_sum[mask ^ (1 << first_bit)].first + fact[first_bit]; // Update sum
            fact_sum[mask].second = get_bit_count(mask); // Count bits in mask
        }

        // Step 3: Find the minimum number of bits required to represent `n` using factorials and powers of two
        long long res = get_bit_count(n); // Initialize result with the bit count of `n` itself

        for (auto i : fact_sum) {
            if (i.first <= n) { 
                // If the current subset sum is less than or equal to `n`, calculate the remaining difference
                res = min(res, i.second + get_bit_count(n - i.first));
            }
        }

        cout << res << "\n"; // Output the result for this test case
    }

    return 0;
}
