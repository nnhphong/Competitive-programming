#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int dp[N][1010], n, m, c, moo[N];
long long ttl = 0, pos = -1;
vector<int> adj[N];

int main() {
  ios::sync_with_stdio(); cin.tie(NULL); cout.tie(NULL);
  freopen("time.in", "r", stdin);
  freopen("time.out", "w", stdout);

  cin >> n >> m >> c;
  for (int i = 1; i <= n; i++)
    cin >> moo[i];
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
  }

  for (int t = 0; t <= 1000; t++)
    for (int u = 1; u <= n; u++)
      dp[u][t] = -1;
  dp[1][0] = 0;

  for (int t = 1; t <= 1000; t++) {
    for (int u = 1; u <= n; u++)
      for (int v : adj[u])
        if (dp[u][t - 1] >= 0)
          dp[v][t] = max(dp[v][t], dp[u][t - 1] + moo[v]);
    ttl = max(ttl, dp[1][t] - 1ll * t * t * c);
  }
  cout << ttl << endl;
}
