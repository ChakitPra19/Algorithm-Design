#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k, ans = INT_MAX;
  cin >> n >> m >> k;
  vector<int> a(n);
  vector<set<int>> tmp(m + 1);
  tmp[0].insert(0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = m; j >= 1; j--) {
      for (auto c : tmp[j - 1]) {
        tmp[j].insert(c + a[i]);
      }
    }
  }
  for (auto sm : tmp[m]) {
    ans = min(ans, abs(sm - k));
  }
  cout << ans;
}