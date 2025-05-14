#include <bits/stdc++.h>

using namespace std;
// Run BFS for all monsters, now in BFS for each monster it
// has to update the minimum distance from a specific cell 
// from monster starting point.

// If you reach a existing node with lower distance from one 
// of the monster terminate the BFS(current monster, node).

// Now run BFS starting from the start position, mark the nodes
// as traversable if the Dist(A, cell) < Dist(anyofM, cell)
// Keep traversing along such Node if reached the Exit 

// Mark it as possible exit.

const int maxn = 1000;
const int INF  = 0x3f3f3f3f;

int h[] = {1,-1, 0, 0};
int v[] = {0, 0, 1,-1};
struct point {int x, y;};

int n, m, startx, starty;
bool visited[maxn][maxn];
char ans[maxn*maxn], c[maxn][maxn], p[maxn][maxn];
int d1[maxn][maxn], d2[maxn][maxn];
queue<point> Q;

bool inbounds(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}
void printvisited(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << visited[i][j];
        }
        cout << endl;
    }
}

void printparray(){
     for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << p[i][j];
        }
        cout << endl;
    }
}

void printd1(){
      for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << d1[i][j];
        }
        cout << endl;
    }
}

void printd2(){
      for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << d2[i][j];
        }
        cout << endl;
    }
}

void printsolution(int x, int y){
    int d = d2[x][y];
    cout << "YES" << endl;
    cout << d << endl;
    for(int i = d-1; i >= 0 ; i--){
        ans[i] = p[x][y];
        if(ans[i] == 'D')   x--;
        else if(ans[i] == 'U') x++;
        else if(ans[i] == 'R') y--;
        else if(ans[i] == 'L') y++;
    }
    for(int i = 0; i < d; i++){
        cout << ans[i];
    }
}

int main() {
   cin >> n >> m;
   // Take input
   for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        cin >> c[i][j];
        if(c[i][j] == '#') visited[i][j] = true;
        else if(c[i][j] == 'M'){
            visited[i][j] = true;
            Q.push({i, j});
        }
        else if(c[i][j] == 'A') startx = i, starty = j;
    }
   }
   // Write BFS for all the Monster Node Simultaneously
   while(!Q.empty()){
    point p = Q.front(); Q.pop();
    for(int i = 0; i<4; i++){
        int x = p.x + h[i], y = p.y + v[i];
        if(inbounds(x,y) && !visited[x][y]){
            d1[x][y] = d1[p.x][p.y] + 1;
            visited[x][y] = true;
            Q.push({x,y});
        }
    }
   }
   //Prepare for BFS wrt to the A node(our start node)
   for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if(!visited[i][j]) d1[i][j] = INF;
        visited[i][j] = (c[i][j] == '#');
    }
   }
  // Run BFS through the A and update the distance D2 matrix
   visited[startx][starty] = true;
   Q.push({startx, starty});
   while(!Q.empty()){
    point P = Q.front(); Q.pop();
    for(int i = 0; i < 4; i++){
        int x = P.x + h[i];
        int y = P.y + v[i];
        if(inbounds(x,y) && !visited[x][y] && d2[P.x][P.y] + 1 < d1[x][y]){
            if(i == 0)     p[x][y] = 'D';
            if(i == 1)     p[x][y] = 'U';
            if(i == 2)     p[x][y] = 'R';
            if(i == 3)     p[x][y] = 'L';
            d2[x][y] = d2[P.x][P.y] + 1;
            visited[x][y] = true;
            Q.push({x, y});
        } 
    }
   }
//    printvisited();
//    cout << endl;
//    printparray();
//    cout << endl;
//    printd1();
//    cout << endl;
//    printd2();
//    cout << endl;
  // Visited vertices are the vertices where it is safe for us to travel without risking capture.
  
  for(int i = 0; i < n; i++){ 
      if(c[i][0] != '#' && c[i][0] != 'M' && visited[i][0]){
         printsolution(i, 0);
         return 0;
      }
      else if(c[i][m-1] != '#' && c[i][m-1] != 'M' && visited[i][m-1]){
        printsolution(i, m-1);
        return 0;
      }
  }

  for(int i = 0; i < m; i++){
      if(c[0][i] != '#' && c[0][i] != 'M' && visited[0][i]){
         printsolution(0,i);
         return 0;
      }
      else if(c[n-1][i] != '#' && c[n-1][i] != 'M' && visited[n-1][i]){
        printsolution(n-1, i);
        return 0;
      }
  }
   cout << "NO" << endl;
   return 0;
}
