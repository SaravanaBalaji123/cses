#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n], zero = 0, one = 0;
    string s;

    // Take inputs
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> s;

    // Calculate the zero xor, one xor;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            zero ^= a[i];
    }

    int pre[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] ^ a[i-1];
    }
    one = pre[n] ^ zero;

    // Process the queries.
    int q;
    cin >> q;
    int type;
    while (q--)
    {
        cin >> type;

        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            one ^= (pre[r] ^ pre[l - 1]);
            zero ^= (pre[r] ^ pre[l - 1]);
        }

        else if (type == 2)
        {
            int ch;
            cin >> ch;
            if (ch == 0)
            {
                cout << zero << " ";
            }
            else if (ch == 1)
            {
                cout << one << " ";
            }
        }
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
