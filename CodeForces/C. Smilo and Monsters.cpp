#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void print(ll arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }cout << endl;
}

void solve(){
    int n; cin >> n;
    ll arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll combo = 0;
    int i = 0, j = n-1;
    ll attacks = 0;
    sort(arr, arr+n);
    // print(arr, n);
    while(j > i){
        if(combo + arr[i] < arr[j]){
            // Completely destroy the smallest horde.
            combo += arr[i];
            attacks += arr[i];
            arr[i] = 0;
            i++;
        }else{
            int needed = arr[j]-combo;
            arr[i] -= needed;
            attacks += needed;
            combo += needed;
            // Perform combo on the largest horde
            attacks += 1;
            arr[j] -=  combo;
            combo = 0;
            if(arr[j] == 0) j--;
        }
        // print(arr, n);
    }
    if(i == j && arr[j] > 0){
        if(combo >= arr[j]){
            attacks += 1;
        }else{
            if(arr[j] == 1) attacks += 1;
            else{
                attacks += arr[j] - (int)((arr[j] + combo)/2) + 1;
            }
        }
    }
    cout << attacks << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}