#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll inv = 0;


int main(){
   int n, m; cin >> n >> m; 
   int arr[n];
   int pos[n];
   for(int i = 0; i < n; i++){
       cin >> arr[i];
       pos[arr[i] - 1] = i + 1;
   }

   // If two indices were swapped.
   // They  might have been in good terms with one another, 
   // They might be part of the chain.
   // They might be forming a chain after connecting, like the missing piece.
   // int p1 = pos[x-1], int p2 = pos[y-1]
   // After change swap(pi, p2)
   // pos[x-1]
   int count = 1;
   for(int i = 0; i < n-1; i++){
    if(pos[i] > pos[i+1]){
        count++;
    }
   }
   cout << count << endl;
}