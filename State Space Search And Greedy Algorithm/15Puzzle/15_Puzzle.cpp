#include <bits/stdc++.h>
using namespace std;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool bound(int r, int c) { return r >= 0 && r < 4 && c >= 0 && c < 4; }

int score(vector<int> &g) {
  int sum = 0;
  for (int i = 0; i < 16; i++) {
    if (g[i] == 0)
      continue;
    int gr = (g[i] - 1) / 4;
    int gc = (g[i] - 1) % 4;
    int r = i / 4;
    int c = i % 4;
    sum += abs(gr - r) + abs(gc - c);
  }
  return sum;
}

int main() {
  vector<int> goal = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
  vector<int> grid(16);
  map<vector<int>, int> dist;
  for (int i = 0; i < 16; i++) {
    cin >> grid[i];
  }
  priority_queue<tuple<int, int, vector<int>>,
                 vector<tuple<int, int, vector<int>>>, greater<>>
      pq;
  pq.push({score(grid), 0, grid});
  dist[grid] = 0;

  while (!pq.empty()) {
    auto [sc, move, g] = pq.top();
    pq.pop();

    if (g == goal) {
      cout << move;
      break;
    }
    if (move > dist[g])
      continue;
    int pos;
    for (int i = 0; i < 16; i++) {
      if (g[i] == 0)
        pos = i;
    }
    int r = pos / 4;
    int c = pos % 4;
    for (auto d : dir) {
      int nr = r + d[0];
      int nc = c + d[1];

      if (!bound(nr, nc))
        continue;
      int next = (nr * 4) + nc;
      vector<int> tmp = g;
      swap(tmp[pos], tmp[next]);
      if (!dist.count(tmp) || move + 1 < dist[tmp]) {
        dist[tmp] = move + 1;
        pq.push({score(tmp) + move + 1, move + 1, tmp});
      }
    }
  }
  return 0;
}