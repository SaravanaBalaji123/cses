#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
vector<vector<int>> graph;
vector<int> visited; // Declare the visited vector

bool dfs(int node, int color){
    visited[node] = color;
    for(int nbr : graph[node]){
    if (visited[nbr] == 0){
       if (!dfs(nbr, 3-color)){
          return false;
       }
    }
    else if(visited[nbr] == color){
        return false;
    }
    }
    return true;
}


int main(){
    int n, m, a, b;
    cin >> n >> m;
    graph.resize(n+1);
    visited.resize(MAX_N, 0);
    // Creating graph
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    } 
    
    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){
          if(!dfs(i, 1)){
            cout << "IMPOSSIBLE" << endl;
            return 0;
          }
        }
    }
    
    for(int i = 1; i <= n; i++ ){
        cout << visited[i] << endl;
    } 
    cout << endl;
    return 0;
}