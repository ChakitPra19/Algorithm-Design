#include <bits/stdc++.h>
using namespace std;
int N, E, K;
vector<vector<int>>adj;

int bfs(int start){
    vector<bool>visited(N, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int step = 0, sum = 0;
    
    while(!q.empty()){
        int sz = q.size();
        sum += sz;
        if(step == K){
            return sum;
        }
        for(int i=0; i<sz; i++){
            int cur = q.front();
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
    return -1;
}

int main() {
    int ans = INT_MIN, a , b;
    cin >> N >> E >> K;
    adj.resize(N);
    for(int i=0; i<E; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0; i<N; i++){
        ans = max(ans, bfs(i));
    }
    cout << ans;
}