#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e, a, b, inp;
    cin >> n >> e;
    vector<vector<int>> adj(n+1);
    vector<int> deg(n+1, 0);
    for(int i=0 ;i<e; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b] += 1;
    }
    for(int i=0; i<5; i++){
        auto tmp = deg;
        bool fail = true;
        for(int j=0; j<n; j++){
            cin >> inp;
            if(tmp[inp] != 0){
                fail = false;
            }
            for(auto k: adj[inp]){
                tmp[k]--;
            }
        }
        if(fail){
            cout << "SUCCESS" << endl;
        }else{
            cout << "FAIL" << endl;
        }
    }
}