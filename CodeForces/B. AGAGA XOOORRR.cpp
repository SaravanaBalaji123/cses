#include <bits/stdc++.h>
using namespace std;

int prefxor[2005]; 

int main() {
    int t;
    cin >> t; 

    while (t--) {
        int n;
        cin >> n; 

        // Compute prefix XOR
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            prefxor[i] = prefxor[i - 1] ^ a; // Prefix XOR computation
        }

        bool isPossible = (prefxor[n] == 0); // Entire array XOR is 0
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Check the condition for three equal parts
                if (prefxor[i] == (prefxor[j] ^ prefxor[i]) &&
                    prefxor[i] == (prefxor[n] ^ prefxor[j])) {
                    isPossible = true;
                    break;
                }
            }
            if (isPossible) break; // No need to check further if condition is met
        }

        // Output result for the current test case
        cout << (isPossible ? "YES" : "NO") << endl;
    }

    return 0;
}
