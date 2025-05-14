#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
   int* keys;
   int t;
   struct Node**  children;
   int n;
   bool leaf;
   struct Node* next;
}Node;

// Insert adds new element to the tree and maintains tree property
// Delete key removes an element from the B+ tree
// Search for an element in the B+ tree using the key.
// Split, splits a full child node during the insertion O(m)
// Order of a B+ tree is the no of childs an internal node should have
// For a B+ tree of order 'm' should have m/2 <= internal neigbours < m
// Merge merges two node during deletion if necessary O(m)
// Display traverse the whole B+ tree and prints all the elements.

// ALGO for B+ Tree Insert Implementation
// 1. Check if the root node consists of at least two children.
// 2. Continue traversing the tree until reaching a leaf node.
// 3. If the leaf node is not full, insert the element into the key in increasing order.
// 

int main(){
   int even, odd;
   for(int i = 3; i <= 2e5; i++){
      for(int j = 0; j < i; j++){
         if(j%2 == 0) even ^= j;
         else if(j%2 == 1) odd ^= j; 
      }
      cout << i << " ";
      if(even == odd) cout << "YES" << endl;
      else cout << "NO" << " " << even - odd << endl;
   }
}