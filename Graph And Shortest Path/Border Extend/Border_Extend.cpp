#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid;
vector<vector<bool>> visited;
queue<pair<int,int>> q;
int R, C, k, dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

bool inBound(int r, int c){
    return r>=1 && r<=R && c>=1 && c<=C && grid[r][c]==0;
}

void bfs(){
    int day = 0;
    while(!q.empty()){
        int sz = q.size();
        if(day == k){
            return;
        }
        for(int i=0; i<sz; i++){
            auto [x, y] = q.front();
            q.pop();
            
            for(auto d: dir){
                int nx = x+d[0];
                int ny = y+d[1];
                
                if(!inBound(nx, ny))continue;
                if(!visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    // จะสร้าง Array ใหม่มาเก็บคำตอบก็ได้ แต่นี่แทนลงไปเลย
                    grid[nx][ny] = 2;
                }
            }
        }
        day++;
    }
    return;
}

int main() {
    cin >> R >> C >> k;
    grid.resize(R+1, vector<int>(C+1, -1));
    visited.resize(R+1, vector<bool>(C+1, false));
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 1){
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    bfs();
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}