#include <bits/stdc++.h>
using namespace std;

void bellman(int n, vector<vector<int>>&grid){
    vector<int>dist(n, INT_MAX);
    dist[0] = 0;
    bool update;
    
    for(int i=0; i<n; i++){
        update = false;
        for(int x=0; x<n; x++){
            for(int y=0; y<n; y++){
                if((x != y) && grid[x][y] != -1 && dist[x] != INT_MAX && (dist[x] + grid[x][y]) < dist[y]){
                    dist[y] = dist[x] + grid[x][y];
                    update = true;
                }
            }
        }
        if(!update) break;
    }
    if(update){
        cout << "Negative Cycle Detect!";
        return;
    }else{
        int mx = INT_MIN;
        for(auto i: dist){
            if(i == INT_MAX){
                cout << -1;
                return;
            }
            mx = max(mx, i);
        }
        cout << mx;
        return;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    bellman(n, grid);
}