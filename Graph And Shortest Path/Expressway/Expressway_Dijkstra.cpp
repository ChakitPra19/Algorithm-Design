#include <bits/stdc++.h>
using namespace std;

void dijkstra(int n, vector<vector<int>>&cost){
    vector<int> dist(n+1, INT_MAX);
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({0, 1});
    
    while(!pq.empty()){
        auto [c, node] = pq.top();
        pq.pop();
        
        if(c > dist[node]) continue;
        
        for(int i=1; i<=n; i++){
            if(node != i && dist[node] != INT_MAX && cost[node][i] != -1 && (dist[node]+cost[node][i]<dist[i])){
                dist[i] = dist[node]+cost[node][i];
                pq.push({dist[i], i});
            }
        }
    }
    cout << dist[2] << " ";
    return;
}

int main()
{
    int n, c, k, a, b;
    cin >> n >> c;
    vector<vector<int>>cost(n+1, vector<int>(n+1, -1));
    cost[1][2] = c;
    cost[2][1] = c;
    
    for(int i=3; i<=n; i++){
        cin >> k;
        for(int j=0; j<k; j++){
            cin >> a >> b;
            cost[i][a] = b;
            cost[a][i] = b;
        }
        dijkstra(n, cost);
    }
}