#include <bits/stdc++.h>
using namespace std;

void dijkstra(int n, vector<vector<int>>&grid){
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[0] = 0;
    pq.push({0, 0});
    
    while(!pq.empty()){
        auto [cost, node] = pq.top();
        pq.pop();
        if(cost > dist[node]) continue;
        
        for(int i=0; i<n; i++){
            if(i != node && grid[node][i] != -1 && (dist[node] + grid[node][i] < dist[i])){
                dist[i] = dist[node] + grid[node][i];
                pq.push({dist[i], i});
            }
        }
    }
    int mx = INT_MIN;
    for(auto i: dist){
        if(i == INT_MAX){
            cout << -1;
            return;
        }
        mx = max(mx, i);
    }
    cout << mx;
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    dijkstra(n, grid);
}