#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    // Min Heap use greater int
    priority_queue<pair<int, int>, vector<pair<int,int>> , greater<pair<int, int>>> pq;
    int start, end;
    for(int i = 0; i<n; i++){
        cin >> start >> end;
        pq.push({end, start});
    }
    int ans = 0;  
    int latestfinish = 0;
    while(!pq.empty()){
        auto [end, start] = pq.top();
        if(latestfinish <= start){
            latestfinish = end;
            ans++;
        }
        pq.pop();  
    }
    cout << ans << endl;
}