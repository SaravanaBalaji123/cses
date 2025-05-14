#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll t, n, m, l, mx;
int main(){
   cin >> t;
   while(t--){
    cin >> n >> m;
    mx=0;
    for(int i=1; i<=n; i++){
        cin >> l;
        set<ll>a;
        int f=0;
        for(int j=0; j<l; j++){
            ll x; 
            cin >> x;
            a.insert(x);
        }
        for(ll j=0; ; j++){
            if(a.find(j) == a.end()){
                if(!f)f=1;
                else{
                    mx=max(mx,j);
                    break;
                }
            }
        }
    }
    if(mx>=m)cout<<mx*(m+1)<<endl;
    else cout << (mx+1)*mx+(m-mx)*(m+mx+1)/2 << endl;
   }
}