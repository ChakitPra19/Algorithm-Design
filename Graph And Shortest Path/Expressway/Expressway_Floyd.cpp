#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, c, k, a, b;
    cin >> n >> c;
    vector<vector<int>>dist(n+1, vector<int>(n+1, INT_MAX));
    dist[1][2] = c;
    dist[2][1] = c;
    for(int i = 1; i <= n; i++){
        dist[i][i] = 0;
    }
    
    for(int i=3; i<=n; i++){
        cin >> k;
        vector<pair<int, int>> new_edges(k);
        for(int j=0; j<k; j++){
            cin >> a >> b;
            dist[i][a] = b;
            dist[a][i] = b;
            new_edges[j] = {a, b};
        }
        for(int u=0; u<i; u++){
            for(auto edge: new_edges){
                auto [neighbor, cost] = edge;
                if(dist[u][neighbor] != INT_MAX){
                    dist[u][i] = min(dist[u][i], dist[u][neighbor]+cost);
                    dist[i][u] = dist[u][i];
                }
            }
        }
        for(int u=0; u<i; u++){
            for(int v=0; v<i; v++){
                if(dist[u][i] != INT_MAX && dist[i][v] != INT_MAX){
                    dist[u][v] = min(dist[u][v], dist[u][i]+dist[i][v]);
                }
            }   
        }
        cout << dist[1][2] << " ";
    }
    return 0;
}