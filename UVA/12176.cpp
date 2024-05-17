#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define fi first
#define se second
#define pb push_back

const int mxN = 3e3 + 5;

int n, m, W = 0, cost[mxN+1][mxN+1], pa[mxN+1];
vii g[mxN+1];
vector<pair<int, ii>> edge;

struct DSU {
  vi p;

  void init(int n) {
    p = vi(n+1, -1);
  }

  int get(int x) {
    return (p[x] < 0 ? x : p[x] = get(p[x]));
  }

  bool join(int x, int y) {
    if ((x = get(x)) == (y = get(y))) return 0;
    if (p[x] > p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
    return 1;
  }
};

void dfs(int u, int p, int des) {
  if (u == des) return;

  for (ii e: g[u]) {
    int v = e.fi;
    if (v == p) continue;
    pa[v] = u;
    dfs(v, u, des);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  #ifndef ONLINE_JUDGE
  freopen("test.inp", "r", stdin);
  #endif // ONLINE_JUDGE

  int tc;
  scanf("%d", &tc);

  for (int i = 1; i <= tc; i++) {
    cout << "Case " << i << endl;

    scanf("%d %d", &n, &m);

    edge.clear();
    for (int i = 1; i <= n; i++) g[i].clear();
    memset(cost, 0, sizeof cost);

    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);

      edge.pb({w, ii(u, v)});
    }

    // KRUSKAL
    DSU dsu;
    dsu.init(n);
    sort(edge.begin(), edge.end());
    for (pair<int, ii> e: edge) {
      if (dsu.join(e.se.fi, e.se.se)) {
        g[e.se.fi].pb(ii(e.se.se, e.fi));
        g[e.se.se].pb(ii(e.se.fi, e.fi));

        cost[e.se.fi][e.se.se] = cost[e.se.se][e.se.fi] = e.fi;
      }
    }

    int q;
    scanf("%d", &q);
    while (q--) {
      int x, y;
      scanf("%d %d", &x, &y);

      W = 0;
      memset(pa, -1, sizeof pa);
      dfs(x, -1, y);

      for (; pa[y] > 0; y = pa[y]) W = max(W, cost[y][pa[y]]);
      cout << W << endl;
    }
    cout << endl;
  }
}
