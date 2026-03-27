#include <bits/stdc++.h>
using namespace std;
int node, inner_node, leaf_node;
vector<bool>visited;
vector<vector<int>> adj;

void dfs(int v){
    node++;
    visited[v] = true;
    if(adj[v].size() == 1){
        leaf_node++;
    }else if(adj[v].size() == 2){
        inner_node++;
    }
    for(auto nb: adj[v]){
        if(!visited[nb]){
            visited[nb] = true;
            dfs(nb);
        }
    }
}

bool isLinear(int v){
    node = 0;
    inner_node = 0;
    leaf_node = 0;
    dfs(v);
    return (node == 1 || (leaf_node == 2 && (leaf_node+inner_node == node)));
}

int main() {
    int v, e, a, b, ans=0;
    cin >> v >> e;
    adj.resize(v);
    visited.resize(v, false);
    for(int i=0; i<e; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0; i<v; i++){
        if(!visited[i]){
            if(isLinear(i)){
                ans++;
            }
        }
    }
    cout << ans;
}