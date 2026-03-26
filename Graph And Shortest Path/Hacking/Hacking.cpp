#include <bits/stdc++.h>
using namespace std;

void dijkstra(int n, vector<vector<int>>&cable, vector<int>&timer){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    vector<int>dist(n+1, INT_MAX);
    dist[n] = 0;
    pq.push({0, n});
    
    while(!pq.empty()){
        auto [cost, node] = pq.top();
        pq.pop();
        
        if(cost > dist[node]) continue;
        for(auto i: cable[node]){
            if(dist[node]!=INT_MAX && (dist[node] + timer[i] < dist[i])){
                dist[i] = dist[node] + timer[i];
                pq.push({dist[i], i});
            }
        }
    }
    int mx=INT_MIN;
    for(auto i: dist){
        if(i==INT_MAX){
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
    int N, M, K, a, b;
    cin >> N >> M >> K;
    vector<int>start(K);
    vector<int>timer(N);
    vector<vector<int>>cable(N+1);
    for(int i=0; i<K; i++){
        cin >> start[i];
    }
    for(int i=0; i<N; i++){
        cin >> timer[i];
    }
    for(int i=0; i<M; i++){
        cin >> a >> b;
        cable[a].push_back(b);
        cable[b].push_back(a);
    }
    for(int i=0; i<K; i++){
        cable[N].push_back(start[i]);
    }
    dijkstra(N, cable, timer);
}