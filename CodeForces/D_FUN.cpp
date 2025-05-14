#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int t; cin >> t;
    while(t--){
        ll ans = 0;
        int n, x; cin >> n >> x;
        for(int a = 1; a <= min(x, n); a++){
            for(int b = 1; a*b <= n && a+b <= x; b++){
                int high = min(x - (a + b), (n-a*b) / (a + b));
                ans += high;
            }
        } 
        cout << ans << endl;
    }
}