#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.
// You can either lengthen and shorten each stick. Both operations cost x where x is the difference between the new and original length.
// What is the minimum total cost?


// Surprisingly median is the optimal length. This is dues to it being middle is minimum at differentiation.
int main(){
   int n;
   cin >> n;
   ll arr[n];
   for(int i = 0; i < n; i++){
       cin >> arr[i];
   }
   sort(arr, arr+n);
   ll median = arr[(n-1)/2];
   ll sum = 0;
   for(int i = 0; i < n; i++){
       sum += abs(arr[i] - median);
   }
   cout << sum << endl;
}