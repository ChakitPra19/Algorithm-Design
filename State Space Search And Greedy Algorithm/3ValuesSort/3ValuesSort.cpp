#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, one = 0, two = 0, three = 0, cur = 0;
  int w1_1 = 0, w1_2 = 0, w1_3 = 0, w2_1 = 0, w2_2 = 0, w2_3 = 0, w3_1 = 0,
      w3_2 = 0, w3_3 = 0;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] == 1)
      one++;
    else if (v[i] == 2)
      two++;
    else
      three++;
  }
  for (int i = 0; i < one; i++) {
    if (v[cur] == 1)
      w1_1++;
    else if (v[cur] == 2)
      w1_2++;
    else
      w1_3++;
    cur++;
  }
  for (int i = 0; i < two; i++) {
    if (v[cur] == 1)
      w2_1++;
    else if (v[cur] == 2)
      w2_2++;
    else
      w2_3++;
    cur++;
  }
  for (int i = 0; i < three; i++) {
    if (v[cur] == 1)
      w3_1++;
    else if (v[cur] == 2)
      w3_2++;
    else
      w3_3++;
    cur++;
  }
  int swap1_2 = min(w1_2, w2_1);
  int swap1_3 = min(w1_3, w3_1);
  int swap2_3 = min(w2_3, w3_2);
  int all = w1_2 + w1_3 + w2_1 + w2_3 + w3_1 + w3_2;
  int remain = all - (swap1_2 + swap1_3 + swap2_3) * 2;
  cout << swap1_2 + swap1_3 + swap2_3 + (remain / 3) * 2;
}