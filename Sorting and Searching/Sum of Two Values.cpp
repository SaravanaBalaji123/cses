#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;cin>>n>>x;
    map<int, int> seen;
    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        int comp = x - num;
        if(seen.find(comp)!=seen.end()){
           cout <<  seen[comp] << " " << i << endl;
           return 0;
        }
        else if(seen.find(comp) == seen.end()){
           seen[num] = i;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}