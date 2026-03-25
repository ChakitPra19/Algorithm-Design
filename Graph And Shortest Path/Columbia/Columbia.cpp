#include <bits/stdc++.h>
using namespace std;
int R, C;
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
vector<vector<int>>grid;

bool inBound(int r, int c){
    return r>=0 && r<R && c>=0 && c<C;
}

void dijkstra(){
    int mx = R * C;
    vector<vector<int>> dist(R, vector<int>(C, INT_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;
    pq.push({0, 0, 0});
    dist[0][0] = 0;
    int fill = 0;
    
    while(!pq.empty() && fill < mx){
        auto [cost, r, c] = pq.top();
        pq.pop();
        
        if(cost > dist[r][c]) continue;
        for(auto d: dir){
            int nr = r+d[0];
            int nc = c+d[1];
            
            if(!inBound(nr, nc)) continue;
            if((dist[r][c] + grid[nr][nc]) < dist[nr][nc]){
                dist[nr][nc] = dist[r][c] + grid[nr][nc];
                pq.push({dist[nr][nc], nr, nc});
            }
        }
        fill++;
    }
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cin >> R >> C;
    grid.resize(R, vector<int>(C));
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> grid[i][j];
        }
    }
    dijkstra();
}