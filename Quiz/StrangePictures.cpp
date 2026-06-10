#include <bits/stdc++.h>
using namespace std;
int total = 0;
int n, k;

bool canDel(vector<int> &a, vector<int> &b) {
  vector<int> tmp(a.size());
  for (int i = 0; i < a.size(); i++) {
    if ((a[i] == 0 && b[i] == 1)) {
      return false;
    }
  }
  return true;
}

void del(vector<int> &a, vector<int> &b) {
  for (int i = 0; i < a.size(); i++) {
    if ((a[i] == 1 && b[i] == 1)) {
      a[i] = 0;
      total -= 1;
    }
  }
}

int main() {
  cin >> n >> k;
  vector<vector<int>> pics(k, vector<int>(n * n));
  vector<int> goal(n * n);
  vector<int> ans;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n * n; j++) {
      cin >> pics[i][j];
    }
  }
  for (int i = 0; i < n * n; i++) {
    cin >> goal[i];
    if (goal[i] == 1) {
      total += 1;
    }
  }
  vector<int> goal_1 = goal;
  for (int i = 0; i < k; i++) {
    if (canDel(goal_1, pics[i])) {
      del(goal, pics[i]);
      ans.push_back(i);
    }
    if (total == 0)
      break;
  }
  if (total > 0) {
    cout << -1;
  } else {
    cout << ans.size() << "\n";
    for (auto i : ans) {
      cout << i + 1 << " ";
    }
  }
}
