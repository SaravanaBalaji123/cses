#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e9;

int main(){
    int n;
    cin >> n;
    ll curr_sum = 0, max_sum = -INF;
    ll arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        max_sum = max(max_sum, arr[i]);
    }
    for(int i = 0; i<n; i++){
        curr_sum+=arr[i];
        max_sum = max(max_sum, curr_sum);
        if(curr_sum < 0){
            curr_sum = 0;
        }
    }
    cout << max_sum << endl;
    return 0;
}