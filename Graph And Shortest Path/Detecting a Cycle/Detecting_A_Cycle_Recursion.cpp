#include <bits/stdc++.h>
using namespace std;

bool bfs(int cur, vector<vector<int>>&adj, vector<bool>&visited, int parent){
    visited[cur] = true;
    for(auto nb: adj[cur]){
        if(!visited[nb]){
            visited[nb] = true;
            if(bfs(nb, adj, visited, cur)){
                return true;
            };
        }else if(nb != parent){
            return true;
        }
    }return false;
}

bool isCircle(int v, vector<vector<int>>&adj){
    vector<bool>visited(v+1, false);
    
    for(int i=1; i<=v; i++){
        if(!visited[i]){
            if(bfs(i, adj, visited, -1)){
                return true;
            }
        }
    }return false;
}


int main()
{
    int t, n, e, a, b;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n >> e;
        vector<vector<int>> adj(n+1);
        for(int j=0; j<e; j++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(isCircle(n, adj)){
            cout << "YES";
        }else{
            cout << "NO";
        };
        cout << endl;
    }
}