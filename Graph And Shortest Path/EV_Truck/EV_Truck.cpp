#include <bits/stdc++.h>
using namespace std;

int dijkstra(int n, vector<vector<int>>&grid, int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    vector<int>dist(n, INT_MAX);
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()){
        auto [cost, node] = pq.top();
        pq.pop();
        
        if(cost > dist[node]) continue;
        
        for(int i=0; i<n; i++){
            if(grid[node][i] != -1 && (dist[node]+grid[node][i] < dist[i])){
                dist[i] = dist[node]+grid[node][i];
                pq.push({dist[i], i});
            }
        }
    }
    int mx = INT_MIN;
    for(auto i: dist){
        if(i!=INT_MAX){
            mx = max(mx, i);
        }
    }
    return mx;
}

int main()
{
    int n, m, a, b, e;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(n, -1));
    for(int i=0; i<m; i++){
        cin >> a >> b >> e;
        grid[a][b] = e;
        grid[b][a] = e;
    }
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        ans = max(ans, dijkstra(n, grid, i));
    }
    cout << ans;
}