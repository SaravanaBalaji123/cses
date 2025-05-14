#include<bits/stdc++.h>
using namespace std;

int main(){
    multiset<int> l;
    multiset<int> r;
    int q; cin >> q;
    char c;
    for(int i = 0, a, b; i < q; i++){
        cin >> c >> a >> b;
        if(c == '+'){
           l.insert(a);
           r.insert(b);
        }
        else if(c == '-'){
           auto it1 = l.find(a);
           auto it2 = r.find(b);
           if(it1 != l.end()){
             l.erase(it1);
           }
           if(it2 != r.end()){
             r.erase(it2);
           }
        }
        if(!l.empty() && !r.empty()){
           int rightsmallest = *r.begin();
           int leftlargest = *l.rbegin();
        
           if(leftlargest > rightsmallest && l.size() > 1){
              cout << "YES" << endl;
           }
           else{
              cout << "NO" << endl;
           }
        }
        else{
            cout << "NO" << endl;
        }
    }
}