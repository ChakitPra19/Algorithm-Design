#include <bits/stdc++.h>
using namespace std;
int node, inner_node, leaf_node;
vector<bool>visited;
vector<vector<int>> adj;
vector<int> beauty;
int sum = 0;
void dfs(int v){
    visited[v] = true;
    sum -= beauty[v];
    
    for(auto nb: adj[v]){
        if(!visited[nb]){
            dfs(nb);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k, a, b;
    cin >> n >> m >> k;
    vector<int> fire(k);
    beauty.resize(n);
    visited.resize(n, false);
    adj.resize(n);
    for(int i=0; i<n; i++){
        cin >> beauty[i];
        sum += beauty[i];
    }
    for(int i=0; i<k; i++){
        cin >> fire[i];
    }
    for(int i=0; i<m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for(auto i: fire){
        if(!visited[i]){
            dfs(i);
            cout << sum << " ";
        }else{
            cout << sum << " ";
        }
    }
}