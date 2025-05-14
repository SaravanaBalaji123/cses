#include<bits/stdc++.h>
using namespace std;

void solve(){
    // No Input for this question.
    int left = 2, right = 1000;
    while(left < right){
        int mid = left + (right - left)/2;
        cout << "? 1 " << mid << endl;
        int resp; cin >> resp;
        if(resp == mid){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    cout << "! " << left << endl;
}

int main(){
    // 3 possible cases, a<x && b<x, a>=x && b<x, a>=x && b>=x
    // Cases: a*b, a+a*b, a*b+a+b+1
    int t; cin>>t;
    while(t--){
        solve();
    }
}