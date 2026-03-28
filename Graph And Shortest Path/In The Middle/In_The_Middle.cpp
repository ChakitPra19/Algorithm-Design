#include <bits/stdc++.h>
using namespace std;
int n, t1, t2, t3;
vector<vector<int>>adj;

vector<int> dijkstra(int start){
    vector<int> dist(n+1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()){
        auto [cost, cur] = pq.top();
        pq.pop();
        
        if(cost > dist[cur]) continue;
        for(auto nb: adj[cur]){
            if(dist[cur]!=INT_MAX && dist[cur]+1 < dist[nb]){
                dist[nb] = dist[cur]+1;
                pq.push({dist[nb], nb});
            }
        }
    }
    return dist;
}

int main() {
    int a, b;
    cin >> n;
    cin >> t1 >> t2 >> t3;
    adj.resize(n+1);
    for(int i=1; i<=n; i++){
        cin >> a;
        for(int j=0; j<a; j++){
            cin >> b;
            adj[i].push_back(b);
        }
    }
    auto dist1 = dijkstra(t1);
    auto dist2 = dijkstra(t2);
    auto dist3 = dijkstra(t3);
    int ans = INT_MAX;
    for(int i=1; i<=n; i++){
        int mx_per = INT_MIN;
        mx_per = max({dist1[i], dist2[i], dist3[i]});
        ans = min(ans, mx_per);
    }
    cout << ans;
}