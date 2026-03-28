#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, tmp;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> deg(n, 0);
    for(int i=0; i<n; i++){
        cin >> a;
        for(int j=0; j<a; j++){
            cin >> tmp;
            adj[tmp].push_back(i);
            deg[i]++;
        }
    }
    queue<int>q;
    for(int i=0; i<n; i++){
        if(deg[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        
        for(auto nb: adj[cur]){
            deg[nb]--;
            
            if(deg[nb] == 0){
                q.push({nb});
            }
        }
    }
}