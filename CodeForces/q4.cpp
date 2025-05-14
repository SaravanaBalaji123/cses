#include <iostream>

using namespace std;

typedef long long ll;

const int INF_int = 1e8 +9;
const ll INF_ll = 1e17;
void solve(){
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int maximumval = 0, l = 0, r = 0;
  int curr_value = 0;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
        if(a[i] > a[j]){
            curr_value++;
        }else{
            curr_value--;
        }
        if(curr_value > maximumval){
           maximumval = curr_value;
           l = i;
           r = j;
        }
    }
    int curr_value = 0;
  }
  cout << l+1 << " " << r+1 << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
