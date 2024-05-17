#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(false); cin.tie(0);

int main() {
  fastIO;
  freopen("540.inp", "r", stdin);


  int t, k = 1;

  while (cin >> t, t) {
    vector<int> group(1000001, 0);
    vector<queue<int>> teamQueue(1001);

    for (int i = 0; i < t; i++) {
      int n; cin >> n;
      while (n--) {
        int x; cin >> x;
        group[x] = i;
      }
    }

    printf("Scenario #%d\n", k++);

    queue<int> combinedQueue;
    string s;
    while (cin >> s && s[0] != 'S') {
      if (s[0] == 'E') {
        int x;
        cin >> x;

        int team = group[x];
        if (teamQueue[team].empty()) combinedQueue.push(team);
        teamQueue[team].push(x);
      } else if (s[0] == 'D') {

        int team = combinedQueue.front();
        cout << teamQueue[team].front() << endl;
        teamQueue[team].pop();

        if (teamQueue[team].empty()) combinedQueue.pop();
      }
    }
    cout << endl;
  }
}

