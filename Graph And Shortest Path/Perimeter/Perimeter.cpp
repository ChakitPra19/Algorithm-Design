#include <bits/stdc++.h>
using namespace std;
int n, e, k;
vector<vector<int>> adj;

int dfs(int v){
    vector<bool> visited(n+1, false);
    queue<int> q;
    q.push(v);
    visited[v] = true;
    int step = 0;
    
    while(!q.empty()){
        int sz = q.size();
        if(step == k){
            break;
        }
        for(int i=0; i<sz; i++){
            int cur =q.front();
            q.pop();
            
            for(auto nb: adj[cur]){
                if(!visited[nb]){
                    visited[nb] = true;
                    q.push(nb);
                }
            }
        }
        step++;
    }
    return q.size();
}

int main() {
    int a, b;
    cin >> n >> e >> k;
    adj.resize(n+1);
    for(int i=0; i<e; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << dfs(0);
}