#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2505;
const int maxm = 5005;
const ll INF = 0x3f3f3f3f3f3f3f3f;
struct edge{
    int a, b;
    ll c;
}edges[maxm];

int n, m, parent[maxn];
ll dist[maxn];

int main(){
    cin >> n >> m;
    // Don't fill the distance with infinity, as
    // for disconnected graphs we don't know the starting points.
    // So all the node has to initialized with 0 just to start the algo.
    for(int i = 0, a, b; i < m; i++){
        ll c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }    
    int changednode = -1;
    for(int itr = 0; itr < n; itr++){
        changednode = 0;
        for(int i = 0; i < m; i++){
            int u = edges[i].a;
            int v = edges[i].b;
            ll w = edges[i].c;
            if(dist[u] != INF && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                parent[v] = u;
                changednode = v;
            }
        }
    }

    if(!changednode){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    for(int i = 0; i<n; i++){
        changednode = parent[changednode];
    }
    

   vector<int> cycle;
   int start = changednode;

    while(true){
      cycle.push_back(start);
      start = parent[start];
      if(start == changednode) break;
    }

   cycle.push_back(start); // Add the starting node again to complete the cycle.
   reverse(cycle.begin(), cycle.end()); // Reverse to get the cycle in correct order.

    for(int node : cycle) {
       cout << node << " ";
    }
   cout << endl;
   return 0;
}