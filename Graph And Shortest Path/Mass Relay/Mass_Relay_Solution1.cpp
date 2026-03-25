#include <bits/stdc++.h>
using namespace std;
vector<int>value;
vector<int>ans;

int find(int a){
    if(value[a] == -1) return a;
    value[a] = find(value[a]);
    return value[a];
}

void uni(int a, int b){
    int rootA = find(a);
    int rootB = find(b);
    
    if(rootA!=rootB){
        value[rootB] = rootA;
    }
}

void kruskal(int n, vector<tuple<int, int, int>>&t){
    int region = n;
    value.resize(n, -1);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;
    for(auto i: t){
        pq.push(i);
    }
    while(!pq.empty() && region > 1){
        auto [w, a, b] = pq.top();
        pq.pop();
    
        if(find(a) == find(b)) continue;
        uni(a, b);
        ans[region] = w;
        region --;
    }
}

int main()
{
    int N, M, Q, a, b, c, inp;
    cin >> N >> M >> Q;
    vector<tuple<int, int, int>>t(M);
    ans.resize(N+1);
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        t[i] = {c, a, b};
    }
    kruskal(N, t);
    for(int i=0; i<Q; i++){
        cin >> inp;
        cout << ans[inp+1] << endl;
    }
}