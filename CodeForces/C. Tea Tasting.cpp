#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int upper_bound(ll arr[], int n, ll x) {
    int low = 0, high = n; // high is set to n (size of array)
    while (low < high) {
        int mid = low + (high - low) / 2; // Calculate mid-point
        if (arr[mid] > x) {
            high = mid; // Narrow down to the left half
        } else {
            low = mid + 1; // Narrow down to the right half
        }
    }
    return low; // Return the index of the first element greater than x
}


void solve(){
    int n; cin >> n;
    ll a[n], b[n], psum[n+1] = {0};

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) psum[i] = psum[i-1] + b[i-1];
    

    ll limit[n] = {0}, answer[n] = {0}, multi[n] = {0};
    for(int i = 0; i < n; i++) limit[i] = upper_bound(psum, n+1, a[i] + psum[i])-1;

    priority_queue<int, vector<int>, greater<int>> pq; 
    
    for(int i = 0; i < n; i++){
        while(!pq.empty() && pq.top() == i) pq.pop();
        if(limit[i] != i) pq.push(limit[i]);
        multi[i] = pq.size();
        answer[i] += multi[i]*b[i];
    }

    // Calculate bottle neck type addition
    for(int i = 0; i < n; i++) answer[limit[i]] += a[i] - (psum[limit[i]] -  psum[i]); 
    // cout << "Fi Ans: ";
    for(ll val : answer){
        cout << val << " ";
    }cout << endl;

}

int main() {
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
