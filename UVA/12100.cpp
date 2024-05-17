#include <bits/stdc++.h>

using namespace std;

int main() {
//  freopen("12100.inp", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    int n, m, val;
    cin >> n >> m;

    map<int, int> MP;
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (i == m) val = x;
      MP[x]++;
      Q.push(make_pair(x, i));
    }

    int times = 1;
    bool ex = false;
    for (int i = 9; i >= 0; i--) {
      while (MP[i] > 0) {
        if (Q.front().first == i) {
          if (i == val && Q.front().second == m) {
            ex = true;
            break;
          }
          MP[i]--;
          ++times;
          Q.pop();
          continue;
        }
        Q.push(Q.front());
        Q.pop();
      }
      if (ex) break;
    }
    cout << times << endl;
  }
}
