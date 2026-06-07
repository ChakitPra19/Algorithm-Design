#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n+1] = {};
    int dp[n+1][n+1] = {};
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<n; i++){
        dp[i][i+1] = max(a[i], a[i+1]);
    }
    for(int len=4; len<=n; len+=2){
        for(int l=1; l+len-1<=n; l++){
            int r=l+len-1;
            dp[l][r] = max({
                max(a[l],a[r])+dp[l+1][r-1],
                max(a[l],a[l+1])+dp[l+2][r],
                max(a[r],a[r-1])+dp[l][r-2],
            });
        }
    }
    cout << dp[1][n];
}