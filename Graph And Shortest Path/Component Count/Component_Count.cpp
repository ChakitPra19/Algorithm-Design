#include <bits/stdc++.h>
using namespace std;

void dfs(int start, vector<bool>&visited, vector<vector<int>>&adj){
    stack<int> s;
    s.push({start});
    visited[start] = true;
    
    while(!s.empty()){
        auto t = s.top();
        s.pop();
        
        for(auto nb: adj[t]){
            if(!visited[nb]){
                visited[nb] = true;
                s.push({nb});
            }
        }
    }
}

int main() {
    int v, e, a, b;
    cin >> v >> e;
    vector<bool> visited(v+1, false);
    vector<vector<int>>adj(v+1);
    for(int i=0; i<e; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans=0;
    for(int i=1; i<=v; i++){
        if(!visited[i]){
            dfs(i, visited, adj);
            ans++;
        }
    }
    cout << ans;
}