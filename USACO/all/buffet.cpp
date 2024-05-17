#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;
 
#define task "test"
#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i, l, r) for( ll i = (l) ; i < (r) ; i++ )
#define forb(i, r, l) for( ll i = (r) ; i >= (l) ; i-- )
#define sz(x) (int)x.size()
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define numBit(x) __builtin_popcount(x)
#define lb lower_bound
#define ub upper_bound
#define ar array
#define endl '\n'
 
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
 
const int N = 1e3 + 7;
const ll inf = 1e9;

int n, E, dp[N], d[N], dist[N][N];
bool vis[N];
vi indx, adj[N];

void bfs(int s) {
  memset(vis, 0, sizeof vis);
  queue<int> Q;
  Q.push(s);
  vis[s] = 1;
  dist[s][s] = 0;
  
  while (sz(Q)) {
    int u = Q.front(); Q.pop();
    for (int v: adj[u]) {
      if (!vis[v]) {
        vis[v] = 1;
        Q.push(v);
        dist[s][v] = dist[s][u] + 1;
      }
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen(task".inp", "r", stdin);
  freopen(task".out", "w", stdout);
#endif
  // fastIO;

  scanf("%d %d", &n, &E);
  for (int i = 1, q; i <= n; i++) {
    scanf("%d %d", &d[i], &q);
    for (int j = 1, v; j <= q; j++) {
      scanf("%d", &v);
      adj[i].push_back(v);
    }
  }

  memset(dist, -1, sizeof dist);
  forw(i, 1, n + 1) bfs(i);

  indx.push_back(0);
  forw(i, 1, n + 1) indx.push_back(i);
  sort(indx.begin() + 1, indx.end(), [&](int x, int y) {
    return d[x] < d[y];
  }); 

  int ans = 0;
  forb(i, n, 1) {
    int u = indx[i];
    dp[u] = d[u];

    forw(v, 1, n + 1) if (u != v && dist[u][v] != -1) {
      dp[u] = max(dp[u], dp[v] - E * dist[u][v] + d[u]);
    }
    ans = max(ans, dp[u]);
  }

  cout << ans << endl;
}