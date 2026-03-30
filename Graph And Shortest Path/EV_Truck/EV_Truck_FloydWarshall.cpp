#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, b, w;
    cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for(int i=0; i<n; i++){
        dist[i][i] = 0;
    }
    for(int i=0; i<m; i++){
        cin >> a >> b >> w;
        dist[a][b] = w;
        dist[b][a] = w;
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    dist[j][i] = dist[i][j];
                }
            }
        }
    }
    int mx = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(dist[i][j] != INT_MAX){
                mx = max(mx, dist[i][j]);
            }
        }
    }
    cout << mx;
}