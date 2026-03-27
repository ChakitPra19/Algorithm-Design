#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int n, a, mx = INT_MIN;;
    cin >> n;
    vector<int> ans(n, 0);
    for(int i=0; i<n; i++){
        int tmp = 0;
        for(int j=0; j<n; j++){
            cin >> a;
            if(a == 1) tmp++;
        }
        ans[tmp]++;
        mx = max(mx, tmp);
    }
    for(int i=0; i<=mx; i++){
        cout << ans[i] << " ";
    }
}