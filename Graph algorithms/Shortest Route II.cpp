#include<bits/stdc++.h>
using namespace std;

const long long INF  = 1e18;
int n, m, q, a, b, c, i, j, k;
vector<vector<pair<int, long long>>> graph;
vector<int> parent; 

void printtable(vector<vector<long long>> &dp){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dp[i][j] == INF) cout << "I" << " ";
            else {cout << dp[i][j] << " ";}
        }
        cout << endl;
    }
}

// Floyd-warshall algorithm  

// This can be solved by dp, so you have a dp state dp[i][j][k] which stores the minimum value for
// every path from i to j including only the k in the path.
// Transition : dp[i][j][k] = min(dp[i][j][k-1], dp[i][k][k-1] + dp[k][j][k-1])
// You can think of it like this, i to j minimum path using first k nodes
// Has to arise from the i to j minimum path of first k-1 nodes
// Or minimum of all the paths i to k in k-1 nodes + minimum of all path k to j in k-1
// We can simplify the 3D matrix to 2D matrix by dp[i][j][k] is next update
// From previous update min(dp[i][j][k-1], dp[i][k][k-1] + dp[k][j][k-1])
// It boils down to dp[i][j](updated) =  min(dp[i][j](existing), dp[i][k](existing) + dp[j][k](existing))

int main(){
    // Input the graph
    cin >> n >> m >> q;
    vector<vector<long long>> dp(n+1, vector<long long>(n+1, INF));
    // Self loops are zero
    for(i = 0; i < n; i++){ 
        dp[i+1][i+1] = 0;
    }
    for(i = 0; i < m; i++){
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], 1LL*c);
        dp[b][a] = min(dp[b][a], 1LL*c);
    }
    // Graph created, time to run Floyd-Warshal
    for(k = 1; k <= n; k++){
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                if(dp[i][k] < INF && dp[k][j] < INF)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    // printtable(dp);
    // My 2D matrix contains minimum for all the possible queries
    for(i = 0; i < q; i++){
        cin >> a >> b;
        if(dp[a][b] == INF){
            cout << -1 << endl;
        }
        else{
            cout << dp[a][b] << endl;
        }
    }
    return 0;
}