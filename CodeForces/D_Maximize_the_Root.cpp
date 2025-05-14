#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = 1e17;
const int MAXN = 200005;

vector<int> adj[MAXN];  
ll a[MAXN];            
ll dp[MAXN];         
bool vis[MAXN];         

void dfs(int node) {
    vis[node] = true;
    dp[node] = INF;  
    bool isLeaf = true; 

    for (int v : adj[node]) {
        if (!vis[v]) {
            isLeaf = false;
            dfs(v);  
            dp[node] = min(dp[node], dp[v]);
        }
    }
   
    if (isLeaf) {
        dp[node] = a[node];
    }

    if (node != 0) {
        ll excess = dp[node] - a[node];
        if (excess > 0) {
            dp[node] = a[node] + excess / 2LL; 
        }
    }
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i < n; ++i) {
        int parent;
        cin >> parent;
        parent--;  
        adj[parent].push_back(i);
    }

    dfs(0);

    cout << dp[0] + a[0] << endl;

    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        vis[i] = false;
    }
}

int main() {
    int t; 
    cin >> t;

    while (t--) {
       solve();
    }

  return 0;
}