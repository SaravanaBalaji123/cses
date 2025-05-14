#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
      int n; cin >> n;
      int ans = 0;
      for(int i = 1; i < n-2; i++){
        cout << i << " ";
        ans ^= i;
      }
      int value1 = 1 << 29;
      int value2 = 1 << 30;
      cout << value1 << " " << value2 << " ";
      ans = ans ^ value1 ^ value2;
      cout << ans << endl;
    }
}