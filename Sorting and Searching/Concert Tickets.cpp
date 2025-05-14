#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    multiset<int> tickets;
    int price;

    // Read ticket prices into a multiset
    for (int i = 0; i < n; i++) {
        cin >> price;
        tickets.insert(price);
    }

    int max_price;
    for (int i = 0; i < m; i++) {
        cin >> max_price;

        // Find the largest ticket price <= max_price
        auto it = tickets.upper_bound(max_price);
        
        if (it == tickets.begin()) {
            // No ticket available within the price range
            cout << "-1" << endl;
        } else {
            // Move iterator to the valid ticket
            --it;
            cout << *it << endl;

            // Remove the ticket from the multiset
            tickets.erase(it);
        }
    }

    return 0;
}
