#include <bits/stdc++.h>
using namespace std;
int N, A, B, a, b;
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
vector<vector<int>> grid;

int inBound(int r, int c){
    return (r>=1 && r<=1000 && c>=1 && c<=1000);
}

int dijk(){
    vector<vector<int>> dist(1001, vector<int>(1001, INT_MAX));
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    pq.push({0, {A,B}});
    dist[A][B] = 0;

    while(!pq.empty()){
        auto [cost, position] = pq.top();
        auto [x, y] = position;
        pq.pop();

        if(x == 1 || x == 1000 || y == 1 || y == 1000){
            return cost;
        }
        
        for(auto d: dir){
            int nr = x+d[0];
            int nc = y+d[1];
            
            if(!inBound(nr, nc)) continue;
            if(cost > dist[nr][nc]) continue;
            if(dist[x][y]+grid[nr][nc] < dist[nr][nc]){
                dist[nr][nc] = dist[x][y]+grid[nr][nc];
                pq.push({dist[nr][nc], {nr, nc}});
            }
        }
    }
    return -1;
}

int main()
{
    cin >> N >> A >> B;
    grid.resize(1001, vector<int>(1001, 0));
    for(int i=0; i<N; i++){
        cin >> a >> b;
        grid[a][b] = 1;
    }
    cout << dijk();
}