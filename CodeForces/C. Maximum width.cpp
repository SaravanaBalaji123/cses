#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n, m;
  cin >> n >> m;
  string a, b;
  int fd[m], bk[m];
  cin >> a;
  cin >> b;
  int j = 0;
  for(int i = 0; i < n; i++){
     if(a[i] == b[j] && j < m){
        fd[j] = i + 1; 
        j++;
     }
  }
  j = m - 1;
  for(int i = n-1; i > -1; i--){
     if(a[i] == b[j] && j > 0){
        bk[j] = i + 1;
        j--;
     }
  }
  int res = 0;
  for(int i = 0;i < m - 1; i++){
    res = max(res, bk[i+1] - fd[i]);
  } 
  cout << res << endl;  
}