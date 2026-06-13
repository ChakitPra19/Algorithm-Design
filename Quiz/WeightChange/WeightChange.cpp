#include <bits/stdc++.h>

using namespace std;
int n, m, k;
using iii = tuple<int, int, int>;
vector<iii> adj;
vector<int> dist;
vector<int> pr;

void bellman(int start) {
  dist[start] = 0;
  for (int i = 1; i < n; i++) {
    for (auto [u, v, cost] : adj) {
      if (dist[u] != INT_MAX && dist[u] + cost < dist[v]) {
        dist[v] = dist[u] + cost;
      }
    }
  }
}

int main() {
  int x, y, z, c, u, v;
  cin >> n >> m;
  adj.resize(n + 1);
  dist.resize(n + 1, INT_MAX);
  pr.resize(n + 1, -1);
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> z;
    if (i == m - 1) {
      c = z;
      u = x;
      v = y;
    } else {
      adj.emplace_back(x, y, z);
    }
  }
  bellman(v);
  if (dist[u] == INT_MAX) {
    cout << "-inf";
  } else {
    cout << dist[u] * -1;
  }
}
