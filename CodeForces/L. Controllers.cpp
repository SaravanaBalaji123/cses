#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    string s;cin >> s;
    int p = 0,m = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '+') p++;
        else {m++;}
    }
    // cout << p << " " << m << endl;

    int q; cin >> q;
    int x, y;
    
    while(q--){
        cin >> x >> y;
        if(p == m) {
            cout << "YES\n";
            continue;
        }

        ll nume = (ll)(p-m)*y;
        ll demo = y-x;
        // cout << nume << " " << demo << endl;
        if(demo == 0){
            cout << "NO\n";
            continue;
        }
        if(nume%demo == 0){
            ll val = nume/demo;
            if(-1*m <= val && val <= p){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            cout << "NO" << endl;
        }
    }

}