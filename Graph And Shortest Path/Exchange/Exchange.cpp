#include <bits/stdc++.h>
using namespace std;

void bellman(int n, vector<vector<double>>&grid){
    vector<double>dist(n, 1.0);
    bool update;
    
    for(int i=0; i<n; i++){
        update = false;
        for(int a=0; a<n; a++){
            for(int b=0; b<n; b++){
                if(dist[a]*grid[a][b] > dist[b]){
                    dist[b] = dist[a]*grid[a][b];
                    update = true;
                }
            }
        }
        if(!update){
            break;
        }
    }
    if(update){
        cout << "YES" << "\n";
        return;
    }else{
        cout << "NO" << "\n";
        return;
    }
}

int main()
{
    int K, N;
    cin >> K;
    for(int i=0; i<K; i++){
        cin >> N;
        vector<vector<double>> grid(N, vector<double>(N));
        for(int r=0; r<N; r++){
           for(int c=0; c<N; c++){
                cin >> grid[r][c];
            } 
        }
        bellman(N, grid);
    }
}