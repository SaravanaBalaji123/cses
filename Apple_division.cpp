#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll minimum_difference(int index, vector<ll> &p, ll sum1, ll sum2,ll N){
    if(index == N){
       return abs(sum1 - sum2);
    }
    ll choose = minimum_difference(index + 1, p, sum1 + p[index], sum2, N);
    ll notChoose =  minimum_difference(index + 1, p, sum1, sum2 + p[index], N);

    return min(choose, notChoose);
    
}

int main(){
    int N;
    cin >> N;
    int j;
    vector<ll> p(N);
    ll totalSum = 0;
    for(int i = 0; i < N; i++){
        cin >> p[i];
        totalSum += p[i];
    }
    //Dp inintialized with -1
    ll ans = minimum_difference(0, p, 0, 0, N);
    cout << ans << endl;
}