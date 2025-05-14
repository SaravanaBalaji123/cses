#include<bits/stdc++.h>
using namespace std;
int n;
set<int> s;
int main(){
   cin >> n;
   int x;
   for(int i = 0; i <= n; i++){
    cin >> x;
    s.insert(x);
   }
   cout << s.size() << endl;
}