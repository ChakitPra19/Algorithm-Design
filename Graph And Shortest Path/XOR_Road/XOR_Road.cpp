#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
vector<vector<ll>> grid;

ll prim(){
    vector<bool> visited(n+1, false);
    priority_queue<pair<ll,ll>> pq;
    pq.push({0, 1});
    ll total_score = 0;
    ll total_len = 0;
    
    while(!pq.empty() && total_len <= (n-1)){
        auto [cost, node] = pq.top();
        pq.pop();
        
        if(!visited[node]){
            visited[node] = true;
            total_len ++;
            total_score += cost;
            
            for(ll i=1; i<=n; i++){
                if(!visited[i] && grid[node][i] != -1){
                    pq.push({grid[node][i], i});
                }
            }
        }
    }
    return total_score;
}

int main()
{
    cin >> n;
    vector<ll> beauty(n+1, -1);
    grid.resize(n+1, vector<ll>(n+1, -1));
    for(ll i=1; i<=n; i++){
        cin >> beauty[i];
    }
    for(ll i=1; i<n; i++){
        for(ll j=i; j<=n; j++){
            if(i==j){
                grid[i][j] = 0;
            }else{
                grid[i][j] = beauty[i]^beauty[j];
                grid[j][i] = grid[i][j];
            }
        }
    }
    cout << prim();
}