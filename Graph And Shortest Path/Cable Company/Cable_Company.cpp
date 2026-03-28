#include <bits/stdc++.h>
using namespace std;
int n;

int prim(vector<vector<int>>&costMST){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(n ,false);
    pq.push({0, 0});
    int total_sum = 0;
    // Pruning (Optional)
    int sum_node = 0;
    
    while(!pq.empty() && sum_node<n){
        auto [cost, node] = pq.top();
        pq.pop();
        
        if(!visited[node]){
            visited[node] = true;
            total_sum += cost;
            // Pruning
            sum_node++;
            for(int i=0; i<n; i++){
                if(i!=node && !visited[i]){
                    pq.push({costMST[node][i], i});
                }
            }
        }
    }
    return total_sum;
}

int main() {
    cin >> n;
    vector<vector<int>> costMST(n, vector<int>(n, 0));
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            cin >> costMST[i][j];
            costMST[j][i] = costMST[i][j];
        }
    }
    cout << prim(costMST);
}