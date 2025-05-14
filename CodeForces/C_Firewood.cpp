#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; ll k; 
        cin >> n >> k;
        int count = 0;
        if(k == 0){
            count = 64;
        }
        else{
          while((k&1) == 0){
            k >>= 1;
            count++;;
          }
        }
        int ans = n - count;
        cout << ans << endl;
    }
}