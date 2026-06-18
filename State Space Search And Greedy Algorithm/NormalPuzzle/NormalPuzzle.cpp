#include <bits/stdc++.h>
using namespace std;
int n;

int score(vector<vector<int>> &g) {
  int total = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int gr = (g[i][j] - 1) / n;
      int gc = (g[i][j] - 1) % n;
      total += abs(gr - i) + abs(gc - j);
    }
  }
  return total;
}

int main() {
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));
  vector<vector<int>> goal(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  if (n == 2) {
    goal = {{1, 2}, {3, 4}};
  } else if (n == 3) {
    goal = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  } else {
    goal = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  }
  map<vector<vector<int>>, int> dist;
  priority_queue<tuple<int, pair<int, string>, vector<vector<int>>>,
                 vector<tuple<int, pair<int, string>, vector<vector<int>>>>,
                 greater<>>
      pq;
  dist[grid] = 0;
  pq.push({score(grid), {0, {}}, grid});

  while (!pq.empty()) {
    auto [sc, p, g] = pq.top();
    auto [m, v] = p;
    pq.pop();

    if (g == goal) {
      cout << v.size() / 2 << "\n";
      for (int i = 0; i < v.size(); i += 2) {
        cout << v[i] << v[i + 1] << "\n";
      }
      break;
    }
    if (m > dist[g])
      continue;

    for (int i = 0; i < 4; i++) {
      if (i == 0) { // Up
        for (int c = 0; c < n; c++) {
          auto tmp = g;
          string u = v;
          for (int r = 0; r < n - 1; r++) {
            swap(tmp[r][c], tmp[r + 1][c]);
          }
          if (!dist.count(tmp) || m + 1 < dist[tmp]) {
            dist[tmp] = m + 1;
            if (c == 0) {
              u += "1U";
            } else if (c == 1) {
              u += "2U";
            } else if (c == 2) {
              u += "3U";
            } else if (c == 3) {
              u += "4U";
            }
            pq.push({score(tmp) + m + 1, {m + 1, u}, tmp});
          }
        }
      } else if (i == 1) { // Down
        for (int c = 0; c < n; c++) {
          auto tmp = g;
          string u = v;
          for (int r = n - 1; r > 0; r--) {
            swap(tmp[r][c], tmp[r - 1][c]);
          }
          if (!dist.count(tmp) || m + 1 < dist[tmp]) {
            dist[tmp] = m + 1;
            if (c == 0) {
              u += "1D";
            } else if (c == 1) {
              u += "2D";
            } else if (c == 2) {
              u += "3D";
            } else if (c == 3) {
              u += "4D";
            }
            pq.push({score(tmp) + m + 1, {m + 1, u}, tmp});
          }
        }
      } else if (i == 2) { // Left
        for (int r = 0; r < n; r++) {
          auto tmp = g;
          string u = v;
          for (int c = 0; c < n - 1; c++) {
            swap(tmp[r][c], tmp[r][c + 1]);
          }
          if (!dist.count(tmp) || m + 1 < dist[tmp]) {
            dist[tmp] = m + 1;
            if (r == 0) {
              u += "1L";
            } else if (r == 1) {
              u += "2L";
            } else if (r == 2) {
              u += "3L";
            } else if (r == 3) {
              u += "4L";
            }
            pq.push({score(tmp) + m + 1, {m + 1, u}, tmp});
          }
        }
      } else if (i == 3) { // Right
        for (int r = 0; r < n; r++) {
          auto tmp = g;
          string u = v;
          for (int c = n - 1; c > 0; c--) {
            swap(tmp[r][c], tmp[r][c - 1]);
          }
          if (!dist.count(tmp) || m + 1 < dist[tmp]) {
            dist[tmp] = m + 1;
            if (r == 0) {
              u += "1R";
            } else if (r == 1) {
              u += "2R";
            } else if (r == 2) {
              u += "3R";
            } else if (r == 3) {
              u += "4R";
            }
            pq.push({score(tmp) + m + 1, {m + 1, u}, tmp});
          }
        }
      }
    }
  }
}
