#include <bits/stdc++.h>
using namespace std;
int R, C, K;
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0, -1}};
stack<pair<int,int>> h;

bool inBound(int r, int c, vector<vector<int>>&grid){
    return (r>=1 && r<=R && c>=1 && c<=C && grid[r][c] != 1);
}

int bfs(int r, int c, vector<vector<int>>&grid, vector<vector<bool>> &visited){
    if(grid[r][c] == 1) return 0;
    queue<pair<int, int>> q;
    q.push({r,c});
    visited[r][c] = true;
    int count = 0;
    
    while(!q.empty()){
        auto [rq, cq] = q.front();
        if(grid[rq][cq] == 3){
            h.push({rq, cq});
        }
        count++;
        q.pop();
        
        for(auto d: dir){
            int nr = rq + d[0];
            int nc = cq + d[1];
            if(!inBound(nr, nc, grid)) continue;
            if(!visited[nr][nc]){
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
    return count;
}

int main()
{
    int a, b;
    cin >> R >> C >> K;
    vector<vector<int>> n_grid(R+1, vector<int>(C+1, -1)), s_grid(R+1, vector<int>(C+1, -1));
    vector<pair<int ,int>> hole(K);
    vector<vector<bool>> visitedN(R+1, vector<bool>(C+1, false)), visitedS(R+1, vector<bool>(C+1, false));
    for(int r=1; r<=R; r++){
        for(int c=1; c<=C; c++){
            cin >> n_grid[r][c];    
        }
    }
    for(int r=1; r<=R; r++){
        for(int c=1; c<=C; c++){
            cin >> s_grid[r][c];    
        }
    }
    for(int i=0; i<K; i++){
        cin >> a >> b;
        if(n_grid[a][b] != 1){
            n_grid[a][b] = 3;
        }
    }
    int ans = bfs(1, 1, n_grid, visitedN);
    int mx = INT_MIN;
    while(!h.empty()){
        auto [n, m] = h.top();
        h.pop();
        if(s_grid[n][m] != 0) continue;
        if(!visitedS[n][m]){
            mx = max(mx, bfs(n, m, s_grid, visitedS));
        }
    }
    if(mx != INT_MIN){
        cout << ans+mx;
    }else{
        cout << ans;
    }
}