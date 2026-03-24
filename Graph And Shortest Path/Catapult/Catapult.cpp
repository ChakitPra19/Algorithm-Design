#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj, adj_rev;

void dfs_stack(int v, vector<bool>&visited, stack<int>&st){
    visited[v] = true;
    
    for(auto nb: adj[v]){
        if(!visited[nb]){
            dfs_stack(nb, visited, st);
        }
    }
    st.push(v);
}

void dfs_size(int v, vector<bool>&visited, int &sz){
    visited[v] = true;
    sz++;
    
    for(auto nb: adj_rev[v]){
        if(!visited[nb]){
            dfs_size(nb, visited, sz);
        }
    }
}

int main()
{
    int n, c, a;
    cin >> n;
    vector<bool> visited_stack(n, false),  visited_size(n, false);
    adj.resize(n); 
    adj_rev.resize(n);
    stack<int> st;
    for(int i=0; i<n; i++){
        cin >> c;
        for(int j=0; j<c; j++){
            cin >> a;
            adj[i].push_back(a);
            adj_rev[a].push_back(i);
        }
    }
    for(int i=0; i<n; i++){
        if(!visited_stack[i]){
            dfs_stack(i, visited_stack, st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        int t = st.top();
        st.pop();
        
        if(!visited_size[t]){
            int sz = 0;
            dfs_size(t, visited_size, sz);
            ans.push_back(sz);
        }
    }
    sort(ans.begin(), ans.end());
    for(auto i: ans){
        cout << i << " ";
    }
}