#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        deque<int> v; // Double ended queue, you can use it as a stack, queue as you please
        // push_front(), pop_front(), push_back(), pop_back(). Use them in combination to get the data structure
        ll ans = 0;
        for(int i = n; i >= 1; i--){
            if(s[i-1] == '1'){
               v.push_back(i); // Back contains the smallest 1's
            }else{
                ans+=i;
                if(v.size() > 0){
                    v.pop_front(); // Front contains the largest 1's so pair it up with 0's
                }
            }
        }

        int z = (v.size()/2) + (v.size()%2);
        // Z may be empty -> loop is skipped
        // If not empty the largest half from front can be paired with something.
        // So, pop the stack from back, total - maximum pairs and add it to the total.
        while(z > 0){
            z-=1;
            ans += v.back();
            v.pop_back();
        }
        cout << ans << endl;
    }
}