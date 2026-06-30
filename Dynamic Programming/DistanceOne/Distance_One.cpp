#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, mod = 100000007;
  cin >> n >> k;
  int dp[n + 1] = {};
  for (int i = 1; i <= k; i++) {
    dp[i] = (i + 1) % mod;
  }
  for (int i = k + 1; i <= n; i++) {
    dp[i] = (dp[i - 1] + dp[i - k]) % mod;
  }
  cout << dp[n] % mod;
}