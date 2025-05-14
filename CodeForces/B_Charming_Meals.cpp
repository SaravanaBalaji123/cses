#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    // Among all such ai and bi pairings find minimum value for
    // Maximize{min(|ai - bi| for all i)}
    // Does having both sorted help?
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}