#include<bits/stdc++.h>
using namespace std;

const long long INF  = 0x1A2B3C4D5E6F7890;
int n, m, a, b, c;
vector<vector<pair<int, int>>>graph;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;// Min heap
vector<int> parent; 

// Djistra's algorthm  
int main(){
    // Input the graph
    vector<long long> distance;
    cin >> n >> m;
    graph.resize(2*n + 1);
    parent.resize(2*n + 1);
    distance.resize(2*n + 1, INF);
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        // Clever manipulation of graph on djikstra's did the trick
        graph[a].emplace_back(b,c); // State 1: Normal edge and I didn't use the coupon yet.
        graph[a].emplace_back(n + b, c/2); // State 2: I used the coupon and the traversed the edge as c/2
        graph[n + a].emplace_back(n + b, c); // State 3: I was in a edge and I had already used my coupon so I had to take the whole edge and can't take c/2
        // State 4 : Such edge can't exist because I can't go from node which has used coupon to node which has not used coupon.
        // Node a, b are nodes that are actuall nodes and I have not yet used the coupon to reach them
        // Node n + a, n + b are virtual nodes and I have already used a coupon once to reach them
    }
    int start = 1;
    distance[start] = 0;
    pq.push({distance[start], start});
    while(!pq.empty()){
        auto [dist, node] = pq.top();
        pq.pop();
        if(dist > distance[node]) continue;

        for(auto [neighbour, weight] : graph[node]){
            if(distance[node] + weight < distance[neighbour]){
               distance[neighbour] = distance[node] + weight;
               parent[neighbour] = node; 
               pq.push({ distance[neighbour], neighbour});
            }

        }
    }
    // Output: The minimum of nth nodes with and without token states.
    cout << min(distance[n], distance[n + n]) << " ";
    return 0;
}
// Djistras Algorithm pseudo-code
// Just modify the graph nodes into two different states, look into the graph inserted place 