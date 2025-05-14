#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int main(){
   cin >> n >> m >> k;
   // Ai be the desired apartment size for a person.
   // I have to allot him Ai+x or Ai-x.
   // So each Ai has an interval, my problem arises when intervals overlap
   // Think about largest and smallest Ai's is it possible to assign them freely?
   int a[n];
   int b[m];
   for(int i = 0; i < n; i++) cin >> a[i];
   for(int i = 0; i < m; i++) cin >> b[i];
   sort(a, a+n);
   sort(b, b+m);
   int aptr=0, bptr = 0;
   int ans = 0;
   while(aptr < n){
    while(bptr < m && b[bptr]<a[aptr]-k) bptr++;
    if(bptr<m && a[aptr]<=b[bptr]+k && a[aptr]>=b[bptr]-k){
        ans++;
        aptr++;
        bptr++;
    }else{
        aptr++;
    }
   }
   cout << ans << endl;
}