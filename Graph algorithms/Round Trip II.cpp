#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+8;
vector<vector<int>> graph;
int vis[MAXN] = {0};
int par[MAXN] = {-1};
int start = 0, finish;
vector<int> ans;

void dfs(int node){
    vis[node] = 1;
    for(auto nbr : graph[node]){
        if(vis[nbr] == 0){
            par[nbr] = node;
            dfs(nbr);
            if(start) return;
            // For any non-zero start it returns
        }
        else if (vis[nbr] == 1){
            start = nbr;
            finish = node; 
            return;
        }
    }
    vis[node] = 2; 
    // State of back tracked from the node, 
    //all the cycles through this has been explored and none of them have a cycle through start
}

int main(){
    int n, m; 
    cin >> n >> m;
    int a, b;
    graph.resize(n+1);
    for(int i = 0; i < m; i++){
       cin >> a >> b;
       graph[a].push_back(b);
    }
    int i;
    for(int i = 0; i < n && !start; i++){
        if(vis[i] == 0){
            dfs(i);
        }
    }
    if(!start){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    ans.push_back(start);
    for(int u = finish; u!= start; u = par[u]){
        ans.push_back(u);
    }
    ans.push_back(start);
    reverse(ans.begin(), ans.end());

    int k = (int) ans.size();
    cout << k << endl;
    for(auto x : ans){
        cout << x<< " ";
    }
}