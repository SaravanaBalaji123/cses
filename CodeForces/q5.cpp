#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> binomial_coeff;

// Function to precompute nC2 for n up to 500
void precompute_binomial() {
    binomial_coeff.push_back(0); // C(0,2) = 0
    for (int n = 1; n <= 500; n++) {
        binomial_coeff.push_back((n * (n - 1)) / 2);
    }
}

// Function to find the largest n such that C(n,2) <= k
int find_max_n(int k) {
    int left = 0, right = 500, best_n = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (binomial_coeff[mid] <= k) {
            best_n = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return best_n;
}

// Function to solve a single test case
void solve() {
    int k;
    cin >> k;

    if (k == 0) {
        cout << "0\n";
        return;
    }

    int n = find_max_n(k);
    int remaining_k = k - binomial_coeff[n];

    vector<pair<int, int>> points;
    
    // Place n points in a vertical line
    for (int i = 0; i < n; i++) {
        points.emplace_back(0, i);
    }

    // Place extra remaining_k points in a horizontal line
    for (int i = 0; i < remaining_k; i++) {
        points.emplace_back(i + 1, 0);
    }

    cout << points.size() << "\n";
    for (auto &[x, y] : points) {
        cout << x << " " << y << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    precompute_binomial();  // Precompute nC2 values

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
