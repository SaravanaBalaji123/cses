#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t; cin >> t;
    while(t--){
        int h, n; cin >> h >> n;
        int a[n], c[n];        
        
        for(int i = 0; i < n; i++){
           cin >> a[i];
        }
        for(int i = 0; i < n; i++){
           cin >> c[i];
        } 
        
        auto check = [&](ll t){
            ll dmg = 0;
            for(int i = 0; i < n && dmg < h; i++){
                ll cnt = (t-1)/c[i] + 1;
                if(cnt >= h) return true;
                dmg += cnt*a[i];
            }
            return dmg >= h;
        };

        ll L = 1, H = 1e12;
        while(L < H){
           ll M = (L + H)/2;
           check(M)? H = M : L = M + 1;
        }

        cout << L << endl;   
    }
}
// a is attack power, c is cooldown
// So, I can attack all at once and dissmiss as soon as I hit the cooldown,
// For a given time I can calculate the amount of attack that I am able to deal in O(n)
// So, for any given time I can do this in O(n*log(n))
// This is binary search by answer but can I make it better,