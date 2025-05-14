#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

ll son(ll x){
    return ((x%mod)*((x+1)%mod)/2)%mod;
}

int main(){
    ll n, ts = 0;
    cin >> n;

    for(ll left = 1; left <= n;){
        ll right = n/(n/left);
        // The number left has to multiplied (int) n/left times.
        // So find all the segments that to be multiplied by n/left times.
        // This is a segment of numbers given by the range [left, right].
        // So add all those numbers and multiply by n/left.
        ll seg_sum = (n/left)%mod * (son(right) - son(left-1) + mod)% mod;
        ts = (ts+seg_sum)%mod;

        left = right + 1;
    }    
    
    cout << ts << endl;
    return 0;
}