#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
vector<string> labyrinth;

vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
vector<char> dir_char = {'L',  'R', 'U', 'D'};

bool bfs(int start_x, int start_y, int end_x, int end_y, int n, int m){
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>> (m, {-1, -1}));

    q.push({start_x, start_y});
    visited[start_x][start_y] = true;

    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;

        if(x == end_x && y == end_y){
            cout << "YES" << endl;

            vector<char> path;
            while (parent[x][y] != make_pair(-1, -1)){
                pair<int, int> p = parent[x][y];
                int px = p.first, py = p.second;
                for(int i = 0; i < 4; i++){
                    if(px + directions[i].first == x && py + directions[i].second == y){
                        path.push_back(dir_char[i]);
                        break;
                    }
                }  
                x = px;
                y = py;
            }
            reverse(path.begin(), path.end());
            cout << path.size() << endl;
            for(char c : path) cout << c;
            cout << endl;
            return true;
        }
        for(int i = 0; i < 4; i++){
            int new_x = x + directions[i].first;
            int new_y = y + directions[i].second;
            if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m
               && !visited[new_x][new_y] && labyrinth[new_x][new_y] != '#'){
               visited[new_x][new_y] = true;
               parent[new_x][new_y] = {x, y};
               q.push({new_x, new_y});
            }
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;

    labyrinth.resize(n);
    pair<int, int> start, end;
    for(int i = 0; i < n; i++){
        cin >> labyrinth[i];
        for(int j = 0; j < m; j++){
            if(labyrinth[i][j] == 'A') start = {i, j};
            if(labyrinth[i][j] == 'B') end = {i, j};
        }
    }

    if(!bfs(start.first, start.second, end.first, end.second, n, m)){
        cout << "NO" << endl;
    }
    return 0;
}