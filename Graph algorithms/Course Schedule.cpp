#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int n, m;
vector<vector<int>> graph;
stack<int> stk;
int visited[MAXN] = {0};
vector<int> ans;
bool hasCycle = false;

int main(){
    cin >> n >> m;
    graph.resize(n+1);
    for(int i = 0, a, b; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
    }

    function<void(int)> dfs = [&](int node){
        visited[node] = 1;
        for(int nbr : graph[node]){
            if(visited[nbr] == 0){
                dfs(nbr);
            }
            else if(visited[nbr] == 1){
                hasCycle = true;
            }
        }
        visited[node] = 2;
        stk.push(node);
    };
    
    for(int i = 1; i <= n; i++){
        if(visited[i]==0){
            dfs(i);
        }
    }
    if(hasCycle){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    // Graph is ready yummy.
    // Now I have to topological sort this.
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }

    for(int node : ans){
        cout << node << " ";
    }
}