#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k, d, e, l;
  cin >> n >> m >> k;
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>
      pq;
  queue<int> supply, request;
  for (int i = 0; i < k; i++) {
    cin >> d >> e >> l;
    pq.push({d, e, l});
  }
  while (!pq.empty()) {
    auto [day, event, label] = pq.top();
    pq.pop();

    if (event == 0) {
      if (!request.empty()) {
        cout << request.front() << "\n";
        request.pop();
      } else {
        supply.push(label);
        cout << 0 << "\n";
      }
    } else {
      if (!supply.empty()) {
        cout << supply.front() << "\n";
        supply.pop();
      } else {
        request.push(label);
        cout << 0 << "\n";
      }
    }
  }
}