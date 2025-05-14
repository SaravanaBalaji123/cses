#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 200005;

int n;
int a[N];

bool c[N];
void doit()
{
    for (int i = 1; i <= n; ++i)
        c[i] = false;
    int maxu = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (c[a[i]])
            maxu = max(maxu, a[i]);
        c[a[i]] = true;
        a[i] = maxu;
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    // cout << "First : ";
    // for(int i = 1; i <= n; ++i) 
    //     cout << a[i] << " ";
    // cout << endl;
    
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += a[i];
    doit();

    // cout << "Second : ";
    // for(int i = 1; i <= n; ++i)
    //     cout << a[i] << " ";
    // cout << endl;

    for (int i = 1; i <= n; ++i)
        ans += a[i];
    doit();

    // cout << "Third : ";
    // for(int i = 1; i <= n; ++i) 
    //     cout << a[i] << " ";
    // cout << endl;

    for (int i = 1; i <= n; ++i)
        ans += (n - i + 1) * 1LL * a[i];
    cout << ans << "\n";
 
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}