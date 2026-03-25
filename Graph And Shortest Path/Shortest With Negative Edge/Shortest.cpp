#include <bits/stdc++.h>
using namespace std;

void bellman(int n, int e, int s, vector<tuple<int,int,int>> edges){
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;
    bool update;
    
    for(int i=0; i<n; i++){
        update = false;
        for(auto [a, b, w] : edges){
            if(dist[a] != INT_MAX && dist[a] + w < dist[b]){
                dist[b] = dist[a] + w;
                update = true;
            }
        }
        if(!update) break;
    }
    
    if(update){
        cout << -1;
        return;
    }else{
        for(int i=0; i<n; i++){
            cout << dist[i] << " ";
        }
    }
}

int main()
{
    int n, e, s, a, b, c;
    cin >> n >> e >> s;
    vector<tuple<int,int,int>> edges(e);
    for(int i=0; i<e; i++){
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    };
    bellman(n, e, s, edges);
}