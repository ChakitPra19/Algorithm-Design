#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, mod=1000003;
    cin >> n >> k;
    vector<int>choc(k);
    vector<int>dp(n+1, 0);
    for(int i=0; i<k; i++){
        cin >> choc[i];
    }
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        for(auto j: choc){
            if(i-j >= 0){
                dp[i] += (dp[i-j])%mod;
            }
        }
    }
    cout << dp[n]%mod;
}