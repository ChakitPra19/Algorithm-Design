#include <bits/stdc++.h>
using namespace std;
int N, M;

vector<string> grid;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool inBound(int r, int c) {
  return r >= 0 && r < N && c >= 0 && c < M && grid[r][c] != 'X';
}

void bfs(int n, int m, int sx, int sy) {
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  queue<tuple<int, int, int>> q;
  q.push({0, sx, sy});
  visited[sx][sy] = true;
  vector<bool> shoot_v(m, false);
  vector<bool> shoot_h(n, false);

  while (!q.empty()) {
    auto [cost, x, y] = q.front();
    q.pop();

    if (grid[x][y] == 'T') {
      cout << cost;
      return;
    } else if (grid[x][y] == '#') {
      if (!shoot_v[y]) {
        shoot_v[y] = true;
        for (int i = 0; i < N; i++) {
          if (!inBound(i, y))
            continue;
          if (!visited[i][y]) {
            visited[i][y] = true;
            q.push({cost + 1, i, y});
          }
        }
      }
      if (!shoot_h[x]) {
        shoot_h[x] = true;
        for (int i = 0; i < M; i++) {
          if (!inBound(x, i))
            continue;
          if (!visited[x][i]) {
            visited[x][i] = true;
            q.push({cost + 1, x, i});
          }
        }
      }
    } else {
      for (auto d : dir) {
        int nx = x + d[0];
        int ny = y + d[1];

        if (!inBound(nx, ny))
          continue;
        if (!visited[nx][ny]) {
          visited[nx][ny] = true;
          q.push({cost + 1, nx, ny});
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int sx, sy;
  cin >> N >> M;
  grid.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> grid[i];
    for (int j = 0; j < M; j++) {
      if (grid[i][j] == 'S') {
        sx = i;
        sy = j;
      }
    }
  }
  bfs(N, M, sx, sy);
}