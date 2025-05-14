#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
int main(){
    int t; cin >> t;
    while(t--){
       int n;
       cin >> n;
       vector<ll> A(n);
       for(int i=0; i<n; i++){
        cin >> A[i];
       }
       map<ll, vector<ll>>adj;
       for(int i = 1; i < n; i++){
          ll u = A[i] + i;
          ll v  = u + i;
          //if(u >= n)
           adj[u].push_back(v);
       }
       set<ll> vis;// To keep track of all the possible large values achievable.
       function<void(ll)> dfs = [&](ll u) -> void{
        if(vis.count(u))return;
        vis.insert(u);
        for(ll v : adj[u]) dfs(v);
       };
       dfs(n);
       cout << *vis.rbegin() << endl;
   }
}