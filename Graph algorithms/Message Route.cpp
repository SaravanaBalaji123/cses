#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
vector<vector<int>> graph;
vector <bool> visited(MAX_N, false);

vector<int> BFS(int n){
    vector<int> parent(n+1,-1);
    queue<int> q;
    
    // Enqueue the start node
    q.push(1);
    visited[1] = true;
    parent[1] = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int next : graph[curr]){
            if(!visited[next]){
                // Updating data of newly discovered node
                visited[next] = true;
                parent[next] = curr;
                q.push(next);
                // Destination found
                if(next == n){
                    vector<int> path;
                    int node = n;
                    while(node != 0){
                        path.push_back(node);
                        // Load up value in the path
                        node = parent[node];
                    }
                    // reverse the path as it is the actual answer
                    reverse(path.begin(), path.end());
                    return path;
                }
            }
        }
    }
    return {};

}

int main(){
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);//Because we used 1-based indexing
    
    int a, b;

    // Declaration of the graph
    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // BFS to find a shortest path
    vector<int> path = BFS(n);
    if(path.empty()){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << path.size() << endl;
        for(int node: path){
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}