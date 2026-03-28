#include <bits/stdc++.h>
using namespace std;
int r, c, T;
vector<vector<int>> grid;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

bool inBound(int a, int b){
    return a>=0 && a<r && b>=0 && b<c && grid[a][b] != 2;
}

int main() {
    cin >> r >> c >> T;
    grid.resize(r, vector<int>(c, -1));
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    queue<pair<int, int>>q;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 1){
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    int ans=0, day=0;
    while(!q.empty()){
        int sz = q.size();
        ans += sz;
        if(day == T){
            break;
        }
        for(int i=0; i<sz; i++){
            auto [x, y] = q.front();
            q.pop();
            
            for(auto d: dir){
                int nx = x+d[0];
                int ny = y+d[1];
                
                if(!inBound(nx, ny)) continue;
                if(!visited[nx][ny]){
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        day++;
    }
    cout << ans;
}