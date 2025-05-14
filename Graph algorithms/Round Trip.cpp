#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 1e5 + 1; // Maximum no of nodes
int n, m, a, b; // No of nodes, edges, temporary node values.
int parent[MAX_NODES], disjointSet[MAX_NODES];
vector<int> cycle, graph[MAX_NODES]; // To store cycle and adjacency list
// n cities, m roads
// Design: A round trip that begins in a city, goes through one or more cities, finally returns to start city.
// A cycle through the initial city
// => Just find any cycle and print the cycle in the graph

// Input: Node indexed from 1 to n
//        m inputs to the edges
//        node1 and node2 for each edge information.
// After input you graph is complete.
// Ouput: If there exitst solution print the no of cities in the list
//        There doesn't exist a solution print "IMPOSSIBLE"

// Method 1 : Run DFS through the graph now print the cycle. O(m+n)(worst case)
// Method 2 : As you are inserting edges into the adjacency list, keep checking for cycle detection.
//            Method 2 can be done by implementing a DSU, if the new edge forms a ege between an existing set. 

void dfs(int u){
    for(int v : graph[u]){
        if(v != parent[u]){
            parent[v] = u;
            dfs(v);
        }
    }
}
int findparent(int u){
    if(disjointSet[u] < 0) return u;
    disjointSet[u] = findparent(disjointSet[u]);
    return disjointSet[u];
}

bool merge(int u, int v){
    u = findparent(u);
    v = findparent(v);
    if(u==v) return false;
    if(disjointSet[u] < disjointSet[v]) swap(u,v);
    // Here the disjointset actually is dual function
    // Fn1 : For leader it is the size of the tree
    // Fn2 : For member nodes it is the parent of the node.
    // **Doesn't matter large is updated to smaller or smaller is merged with larger**
    disjointSet[v] += disjointSet[u];
    disjointSet[u] = v;
    return true;
}

int main() {
   cin >> n >> m;
   // Initialize disjointSet representing that each node is parent of its own.
   fill(disjointSet + 1, disjointSet + n + 1, -1);
   for(int i = 0; i < m; i++){
       cin >> a >> b;
       // Not able to merge the edges a,b 
       if(!merge(a,b)){
           //Peform DFS to from one end of cycle.
           dfs(a);
           // Dfs forms a directional parent array tracing whom form b you will surely reach a
           // Trace back the cycle using the parent array
           int u = b;
           while(u != 0){
                cycle.push_back(u);
                u = parent[u];
           }
       //Print the cycle found
       int cyclesize = cycle.size();
       cout << cyclesize + 1 << endl;
       for(auto node : cycle){
        cout << node << " ";
       }
       cout << b << endl;
       return 0;
    }
    else{
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
   }
   cout << "IMPOSSIBLE" << endl;
   return 0;

}
