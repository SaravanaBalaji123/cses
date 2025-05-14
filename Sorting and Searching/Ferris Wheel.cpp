#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int n, x, a;
int main(){
    cin >> n >> x;
    int a[n], ans = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int start = 0, end = n-1;
    while(start < end){
        if(a[start]+a[end]<=x){
            ans++;
            start++;
            end--;
        }else{
            end--;
        }
    }
    cout << n-ans << endl;
}