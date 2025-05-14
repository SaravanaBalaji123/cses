#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool check_compatibility(int factor, string s, int n){
    int satisfy = 2;
    for(int i = 0; i < factor; i++){
        for(int j = i + factor; j < n; j += factor){
            if(s[j] != s[i]){
                satisfy--;
            }
             if(satisfy <= 0) break;
                
        }
         if(satisfy <= 0) break; 
    }
    if(satisfy > 0){
        return true;
    }
    satisfy = 2;
    for(int i = n-factor; i < n; i++){
        for(int j = i-factor; j >= 0; j-=factor){
            if(s[j] != s[i]){
                satisfy--;
                if(satisfy <= 0) return false;
            }
        }
       
    }
    if(satisfy > 0){
        return true;
    }
    return false;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        set<int> fact;
        for(int i = 1; i*i<=n; i++){
            if(n%i == 0){
                fact.insert(i);
                fact.insert(n/i);
            }
        }
        for(int factor: fact){
            if(check_compatibility(factor, s, n)){
                cout << factor << endl;
                break;
            }
        }
    }
}