#include <bits/stdc++.h>
using namespace std;

bool dfs(int start, vector<bool>&visited, vector<vector<int>>&adj){
    stack<pair<int, int>> s;
    s.push({start, -1});
    visited[start] = true;
    
    while(!s.empty()){
        auto [t, parent] = s.top();
        s.pop();
        
        for(auto nb: adj[t]){
            if(!visited[nb]){
                visited[nb] = true;
                s.push({nb, t});
            }else if(nb != parent){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int t, n, e, a, b;
    cin >> t;
    for(int i=0; i<t; i++){
       cin >> n >> e;
       vector<bool> visited(n, false);
       vector<vector<int>> adj(n);
       for(int j=0; j<e; j++){
           cin >> a >> b;
           adj[a].push_back(b);
           adj[b].push_back(a);
       }
       bool check = false;
       for(int k=0; k<n; k++){
           if(!visited[k]){
               if(dfs(k, visited, adj)){
                   check = true;
                   break;
               }
           }
       }
       if(check){
           cout << "YES" << "\n";
       }else{
           cout << "NO" << "\n";
       }
   }
}