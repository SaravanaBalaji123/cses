#include<bits/stdc++.h>
using namespace std;
#define  ll long long 
const ll INF  = 1e18;
const int maxn = 2501;
const int maxm = 5001;
struct edge{
   int a, b; ll c;
}edges[maxm];

// n rooms and m tunnels
// Your initial score is 0, and each tunnel increases your 
// score by x where x may be both positive or negative.
// You may go through a tunnel several times.


int n, m;
ll dp[maxn];
bool vis[maxn], visr[maxm];
vector<int> G[maxn], GR[maxn];
ll c;

void dfs(int n){
    vis[n] = true;
    for(auto nbr : G[n]){
        if(!vis[nbr]) dfs(nbr);
    }
}

void dfsr(int n){
    visr[n] = true;
    for(auto nbr : GR[n]){
        if(!visr[nbr]) dfsr(nbr);
    }
}
// Bellman-ford Algorithm
int main(){
   cin >> n >> m;

   // Input graph
   for(int i = 0, a, b; i < m; i++){
       cin >> a >> b >> c;
       edges[i] = {a, b, -c};
       G[a].push_back(b);
       GR[b].push_back(a);
   }
   dfs(1); dfsr(n);
   fill(dp, dp+n+1, INF);
   dp[1] = 0;
   bool improvement = true; // To detect negative cycle
   for(int itr = 0; itr < n && improvement; itr++){
      improvement = false;
      for(int i = 0; i < m; i++){
        int u = edges[i].a;
        int v = edges[i].b;
        ll wt = edges[i].c;
        if(dp[v] > dp[u] + wt && dp[u]!= INF){
            improvement = true;
            dp[v] = dp[u] + wt;
            if(itr == n-1 && vis[v] && visr[v]){
                cout << -1 << endl;
                return 0;
            }
        }
      }
   }
   cout << -1*dp[n] << endl;
   return 0;
}
// time complexiety : O(n*m)
// For every edge iterate it for N-1 times for the all the minimum values to update for the shortest path
// The shortest path for any node may take a worst cast to reach the node is same as the number of edges in the shortest path
// Order/sequence in which edges are processed is insignificant.
// After N-1 iterations there should be no room for improvement for any edges to get updated.
// If update happens in Nth iteration then a negative or in this case positive cycle appear so you can keep cycling till you get even larger maximums. Return -1.
// it should be visitable in the path from both 1 to n and from n to 1 for reversed