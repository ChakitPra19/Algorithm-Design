#include <bits/stdc++.h>
using namespace std;

void bellman(int n, int v, vector<tuple<int, int, int>>t){
    vector<int> dist(n+1, INT_MAX);
    dist[n] = 0;
    bool update;
    for(int i=0; i<n; i++){
        update = false;
        for(auto edge: t){
            auto [a, b, w] = edge;
            if(dist[a] != INT_MAX && dist[a]+w < dist[b]){
                dist[b] = dist[a] + w;
                update = true;
            }
        }
        if(!update) break;
    }
    if(update){
        cout << "Have cycle!";
        return;
    }else{
        cout << dist[v];
    }
}

int main()
{
    int n, m, k, v, a, b, w;
    cin >> n >> m >> k;
    cin >> v;
    vector<int>start(k);
    vector<tuple<int, int, int>>t;
    for(int i=0; i<k; i++){
        cin >> start[i];
    }
    for(int i=0; i<m; i++){
        cin >> a >> b >> w;
        t.push_back({a, b, w});
    }
    int s = n;
    for(int i=0; i<k; i++){
        t.push_back({s, start[i], 0});
    }
    bellman(n, v, t);
}