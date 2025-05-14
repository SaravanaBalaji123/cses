#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int best_delta = 0, best_l = 0, best_r = 0;

    for (int l = 0; l < n; l++) {
        int s = 0, current_best = 0, current_r = l;

        for (int r = l + 1; r < n; r++) {
            if (a[r] > a[l]) {
                s += 1;
            } else if (a[r] < a[l]) {
                s -= 1;
            }

            if (s < current_best) {
                current_best = s;
                current_r = r;
            }
        }

        if (current_best < best_delta) {
            best_delta = current_best;
            best_l = l;
            best_r = current_r;
        }
    }

    cout << best_l + 1 << " " << best_r + 1 << endl; // Convert 0-based to 1-based indexing
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
