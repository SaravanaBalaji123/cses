#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
using lol = long long int;
void solve(){
    int n, a, b; cin >> n >> a >> b;
    vector<lol> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    // Go till the last i that is divisible by 3

    
    lol p[n+1] = {0};
    for(int i = 1; i <= n; i++){
        p[i] = p[i-1] + c[i-1];
        // cout << p[i] << "," << i << "; "; 
    }
    // cout << endl;

    lol  ans = b*(p[n]);
    // cout << ans << " ";

    for(int i = 1; i <= n; i++){
        lol temp = a*(c[i-1]) + b*(p[n] - p[i] - (n-(i+1))*c[i-1]);
        // cout << temp << " ";
        if(ans > temp ) ans = temp;
        else{
            break;
        }
    }

    cout << ans << endl;

    
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}