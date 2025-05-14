#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// You have n coins with positive integer 
// values. What is the smallest sum you cannot 
// create using a subset of the coins?

int main(){
   int n; cin >> n;
   ll arr[n];
   for(int i = 0; i < n; i++){
       cin >> arr[i];
   }
   sort(arr, arr+n);
   ll ans = 1;
   for(int i = 0; i < n && arr[i] <= ans; i++){
      ans += arr[i];
   }
   cout << ans << endl;
}

// Why does this soluton work? Think of this as a reachability problem.
// Everything till ans is reachable using all the i elements
// New element is arr[i] is larger than the furthest reachable
// For ans+1 to be reachable, the reachability need to come from somwhere below 0
// WOWSERS!!!!