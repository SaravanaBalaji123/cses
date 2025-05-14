#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node){
    visited[node] = true;
    for (int neighbour : adj[node]){
        if(!visited[neighbour]){
            dfs(neighbour);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    adj.resize(n+1);
    visited.resize(n+1, false);

    // Create the adjacency list
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Find all connected components
    vector<int> components;
    for(int i = 1; i <= n; i++){// Because indexed from 1 to n
        if(!visited[i]){
            components.push_back(i);
            dfs(i);
        }
    }
// Here components is the kind of the root node of each component
    // Calculate the number of new roads needed
    int new_roads = components.size()-1;
    cout << new_roads << endl;

    //Connect the components by connecting root nodes one by one
    for(int i = 1; i < components.size(); i++){
        cout << components[i-1] << " " << components[i] <<  endl;
    }


    return 0;

}