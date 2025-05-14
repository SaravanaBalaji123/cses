#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF_int = 1e8+9;
const ll INF_ll = 1e17;

void solve(){
  int n;
  cin >> n;
  char a;
  ll u = 0, h = 0;
  for(int i = 0; i < n; i++){
    cin >> a;
    if(a == '_'){
      h++;
    }
    if(a == '-'){
      u++;
    }
  }
  ll l = (u+1)/2;
  ll r = u/2;
  ll ans = h*l*r;
  cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
