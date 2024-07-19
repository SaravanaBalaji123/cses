#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
    long long int n, ans = 1;
    cin >> n;
    while(n--){
        ans *= 2;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;

}