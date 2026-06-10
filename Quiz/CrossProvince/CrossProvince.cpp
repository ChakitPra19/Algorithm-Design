#include <bits/stdc++.h>

using namespace std;
int n, m, k;
vector<vector<pair<int, int>>> adj;
vector<int> dist;

void dijkstra(int start) {
  dist[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, start});

  while (!pq.empty()) {
    auto [cost, cur] = pq.top();
    pq.pop();

    if (cost > dist[cur])
      continue;

    for (auto [v, w] : adj[cur]) {
      if (dist[cur] + w < dist[v]) {
        dist[v] = dist[cur] + w;
        pq.push({dist[v], v});
      }
    }
  }
}

int main() {
  int x, y, z, a, b;
  cin >> n >> m >> k;
  adj.resize(2 * n);
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> z;
    adj[x].push_back({y, z});
    adj[y].push_back({x, z});
  }
  dist.resize(2 * n, INT_MAX);
  dijkstra(n);
  for (int i = 0; i < k; i++) {
    cin >> a >> b;
    cout << dist[a] + dist[b] << "\n";
  }
}
