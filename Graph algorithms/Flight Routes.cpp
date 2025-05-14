#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, ll> edge;
typedef pair<ll, int> node;
const int maxn = 2e5 + 1;

int n, m, k;
priority_queue<node, vector<node>, greater<node>> pq;
vector<edge> graph[maxn];
int cnt[maxn];

int main(){
    cin >> n >> m >> k;
    for(int i = 0, a, b; i < m; i++){
        ll c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b,c);
        
    }
    // cout << "YES" << endl;
    pq.push({0, 1});
    while(!pq.empty()){
        auto [currentdistance, node] = pq.top();
        pq.pop();
        cnt[node]++;
        // cout << node << endl;
        if(node == n){
            cout << currentdistance;
            if(cnt[node] == k){
                cout << endl;
                return 0;
            }
            else{
                cout << " ";
            }
        }
        //  cout << node << " " << cnt[node] << endl;
        if(cnt[node] <= k){
            for(auto [nextnode, edgeweight] : graph[node]){
                //  cout << edgeweight + currentdistance << " " << nextnode << endl;
                pq.push({edgeweight + currentdistance, nextnode});
            }
        }
    }
    return 0;
}