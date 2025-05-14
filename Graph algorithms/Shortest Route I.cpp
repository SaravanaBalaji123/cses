#include<bits/stdc++.h>
using namespace std;

const long long INF  = 0x1A2B3C4D5E6F7890;
int n, m, a, b, c;
vector<vector<pair<int, int>>> graph;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
// Min heap
vector<int> parent; 

// Djistra's algorthm  
int main(){
    // Input the graph
    vector<long long> distance;
    cin >> n >> m;
    graph.resize(n + 1);
    parent.resize(n + 1);
    distance.resize(n + 1, INF);
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        graph[a].emplace_back(b,c);
    }
    int start = 1;
    distance[start] = 0;
    // Start the priority queue for the graph
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
    for(int i = 0; i < n; i++){
        cout << distance[i+1] << " ";
    }
}
// Djistras Algorithm pseudo-code
//    Take the start node, distance = 0 
//    push in to min heap
//    Now for every neighbour of the heap.top
//      if(distance(heap.top) + weight(heap.top, nbr) < distance[neighbour])
//         Makeparent(neighbour) = heap.top
//         distance(neighbour) = distance(node) + weight(heap.top, nbr)
//         push(distance(neighbour), neighbour) to minheap

// Lemmas : Doesn't work for graph with negative cycle and edges
//          A node is pushed into the heap if a better path to it found so 
//          as to find all the better paths through the newly found better path
// This is kind of proof for this algo also
