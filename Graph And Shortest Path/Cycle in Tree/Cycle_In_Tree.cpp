#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj;
vector<int> depth;
int ans=0;
    
void dfs(int cur, int parent){
    visited[cur] = true;
    
    for(auto nb: adj[cur]){
        if(!visited[nb]){
            visited[nb] = true;
            depth[nb] = depth[cur] + 1;
            dfs(nb, cur);
        }else if(nb != parent){
            ans = max(ans, depth[cur] - depth[nb] + 1);
        }
    }
}

int main() {
    int n, a, b;
    cin >> n;
    visited.resize(n, false);
    adj.resize(n);
    depth.resize(n, 0);
    for(int i=0; i<n; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    cout << ans;
}