#include <bits/stdc++.h>
using namespace std;

void bellman(int n, int v, vector<tuple<int, int, int>>t, int k, vector<int>start){
    vector<int> dist(n, INT_MAX);
    dist[v] = 0;
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
        int ans = INT_MAX;
        for(int i=0; i<k; i++){
            ans = min(ans, dist[start[i]]);
        }
        cout << ans;
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
        t.push_back({b, a, w});
    }
    bellman(n, v, t, k, start);
}