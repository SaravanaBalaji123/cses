#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fenwick Tree (Binary Indexed Tree) class
class FenwickTree {
public:
    vector<int> bit;
    int n;
    
    FenwickTree(int n) : n(n) {
        bit.assign(n + 1, 0);
    }
    
    // Increase the value at index 'idx' by 'val'
    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }
    
    // Returns the prefix sum from index 1 to 'idx'
    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int>> people(n);
        for (int i = 0; i < n; i++){
            cin >> people[i].first >> people[i].second;
        }
        
        // Sort people by their starting positions (a)
        sort(people.begin(), people.end(), [](const pair<int,int>& p1, const pair<int,int>& p2){
            return p1.first < p2.first;
        });
        
        // Extract the b array in the order of sorted a's
        vector<int> b(n);
        for (int i = 0; i < n; i++){
            b[i] = people[i].second;
        }
        
        // Coordinate compression for b values
        vector<int> sortedB = b;
        sort(sortedB.begin(), sortedB.end());
        // sortedB.erase(unique(sortedB.begin(), sortedB.end()), sortedB.end());
        
        unordered_map<int, int> comp;
        for (int i = 0; i < sortedB.size(); i++){
            comp[sortedB[i]] = i + 1; // 1-indexed positions
        }
        
        // Count inversions in the b array using a Fenwick Tree.
        // Inversions here correspond to greeting pairs.
        FenwickTree ft(sortedB.size());
        long long greetings = 0;
        
        // Process b from right to left.
        for (int i = n - 1; i >= 0; i--){
            int pos = comp[b[i]];
            // Query the number of b's (already processed) that are smaller than b[i]
            greetings += ft.query(pos - 1);
            // Mark b[i] as processed.
            ft.update(pos, 1); 
        }
        
        cout << greetings << "\n";
    }
    
    return 0;
}
