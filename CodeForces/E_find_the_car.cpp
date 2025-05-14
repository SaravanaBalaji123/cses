#include <bits/stdc++.h>
#include <cmath>
using ll = long long;
using namespace std;
int main(){
    int t; 
    cin >> t;
    while(t--){
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> dist(k+1, 0), time(k+1, 0);
        for(int i = 1; i <= k; i++){
            cin >> dist[i];
        }
        for(int i = 1; i <= k; i++){
            cin >> time[i];
        }
        for(int i = 0; i < q; i++){
            ll d;
            cin >> d;   
            auto it = lower_bound(dist.begin(), dist.end(), d);
            int idx = it - dist.begin();
            if(dist[idx] == d){
                cout << time[idx] << " ";
            }else{
                int r = idx - 1;
                ll ans = time[r] + (d - dist[r]) * (time[idx] - time[r])/(dist[idx] -  dist[r]);
                cout << ans << " "; 
            }
        }
        cout << endl;
    }
}