#include <bits/stdc++.h>

using namespace std;

const int INF = (1 << 31) - 1;

typedef long long ll;
typedef pair<int, int> pii;

const int LIMIT = 600;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  #ifndef ONLINE_JUDGE
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  #endif // ONLINE_JUDGE

  int n;
  while (cin >> n && n != 0) {
    vector<pii> a[n+1];
    int h, m; cin >> h;
    int c[h];
    for (int i = 0; i < h; i++) cin >> c[i];
    cin >> m;
    for (int i = 0; i < m; i++) {
      int u, v, f; cin >> u >> v >> f;
      a[u].push_back({v, f});
      a[v].push_back({u, f});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int dist[n+1];
    fill(dist, dist+n+1, 1e9);
    pq.push({0, 1});
    dist[1] = 0;
    while (!pq.empty()) {
      int u = pq.top().second, d = pq.top().first;
      pq.pop();
      if (d > dist[u]) continue;
      for (pii e: a[u]) {
        int v = e.first, cost = e.second;
        if (dist[v] > cost + dist[u]) pq.push({dist[v] = dist[u] + cost, v});
      }
    }

    sort(c, c+h);
    int ans = 0, time = 0;
    for (int i = 0; i < h; i++) {
      if (time + dist[c[i]] >= LIMIT) ++ans;
      else time += dist[c[i]];
    }
    cout << (ans == 0 ? -1 : ans) << endl;
  }
}
