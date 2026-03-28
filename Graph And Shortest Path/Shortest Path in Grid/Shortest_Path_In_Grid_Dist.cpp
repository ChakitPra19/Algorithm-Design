#include <bits/stdc++.h>
using namespace std;
int R, C;
vector<vector<char>> grid;

int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

bool inBound(int r, int c){
    return r>=1 && r<=R && c>=1 && c<=C && grid[r][c] != '#';
}

int bfs(int r, int c){
    vector<vector<bool>>visited(R+1, vector<bool>(C+1, false));
     vector<vector<int>>dist(R+1, vector<int>(C+1, -1));
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;
    dist[r][c] = 0;
    
    while(!q.empty()){
        int sz = q.size();
        for(int i=0; i<sz; i++){
            auto [x, y] = q.front();
            q.pop();
            
            if(x == R && y == C){
                return dist[x][y];
            }
            
            for(auto d: dir){
                int nr = x + d[0];
                int nc = y + d[1];
                
                if(!inBound(nr, nc)) continue;
                if(!visited[nr][nc]){
                    visited[nr][nc] = true;
                    dist[nr][nc] = dist[x][y]+1;
                    q.push({nr, nc});
                }
            }
        }
    }
    return -1;
}

int main() {
    cin >> R >> C;
    grid.resize(R+1, vector<char>(C+1));
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> grid[i][j];
        }
    }
    cout << bfs(1, 1);
}