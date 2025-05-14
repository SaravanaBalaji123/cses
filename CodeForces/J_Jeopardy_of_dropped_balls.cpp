#include<bits/stdc++.h>
using namespace std;

int modify(int start, vector<vector<int>>& mat, int n, int m){
    int x = 0, y = start - 1;
    while(x < n ||(x == n-1 && mat[x][y] != 2) ){
    //    cout << "{" << x << "," << y << "}" << endl;
       int value = mat[x][y];
       mat[x][y] = 2;
        if(value == 1){
            // Edge cases handled by the input itself. Voila!
            y++;
        }
        else if(value == 2){
            // Check path compress
            x++;
        }
        else if(value == 3){
            y--;
        }
    }

    return y + 1;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> mat(n + 1, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    for(int i = 0, a; i < k; i++){
        cin >> a;
        int coloumn = modify(a, mat, n, m);
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //        cout << mat[i][j] <<" ";
        //     }
        //     cout << endl;
        // }
        cout << coloumn << " ";
        // cout << endl;
    }
}