#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        // Sort r1, r2, r3, r4....descending order
        // Now assign largest frequency to smallest number value
        int n; cin >> n;
        int s1, s2; cin >> s1 >> s2;
        vector<int> a, b;
        vector<pair<int, int>> arr;
        int k;
        for(int i = 0; i < n; i++){
            cin >> k;
            arr.push_back({k, i});
        }
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        // .second is the color, .first is the frequency
        // largest frequency gets the smallest largest (greedy)
        int aptr = 1, bptr = 1;
        for(auto [frequency, color] : arr){
            if(aptr*s1 > bptr*s2){
                b.push_back(color);
                aptr++;
            }else{
                b.push_back(color);
                bptr++;
            }
        }

        cout << a.size() << " ";
        for(int i = 0; i < a.size(); i++){
            cout << a[i] << " ";
        }cout << endl;

        cout << b.size() << " ";
        for(int i = 0; i < b.size(); i++){
            cout << b[i] << " ";
        }cout << endl;
        
    }
}