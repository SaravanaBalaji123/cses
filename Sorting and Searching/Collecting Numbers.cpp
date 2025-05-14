#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll inv = 0;


int main(){
   int n; cin >> n;
   int arr[n];
   int pos[n];
   for(int i = 0; i < n; i++){
       cin >> arr[i];
       pos[arr[i] - 1] = i + 1;
   }
//    for(int val : pos){
//     cout << val << " ";
//    }
   int count = 1;
   for(int i = 0; i < n-1; i++){
    if(pos[i] > pos[i+1]){
        count++;
    }
   }
   cout << count << endl;
}