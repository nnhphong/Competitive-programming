#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef complex<ld> cp;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<cp> vcp;
typedef vector<ld> vld;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i,l,r) for( ll i = (l) ; i < (r) ; i++ )
#define forb(i,r,l) for( ll i = (r) ; i >= (l) ; i-- )
#define log2i(x) (32 - __builtin_clz((x)) - 1)
#define log2ll(x) (64 - __builtin_clzll((x)) - 1)
#define Pi 3.141592653589793
#define sz(x) (int)x.size()
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int mxN = 1e5;

vector<bool> vis(mxN+1, false);
vi topo;
vi a[mxN+1];

void dfs1(int u) {
  vis[u] = true;
  for (int v: a[u]) {
    if (vis[v]) continue;
    dfs1(v);
  }
  topo.pb(u);
}

void dfs2(int u) {
  vis[u] = true;
  for (int v: a[u]) {
    if (vis[v]) continue;
    vis[v] = true;
    dfs2(v);
  }
}

int main() {
  fastIO;

  #ifndef ONLINE_JUDGE
  freopen("test.inp", "r", stdin);
  #endif // ONLINE_JUDGE

  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;

    fill(all(vis), false);
    topo.clear();
    forw(i, 0, n+1) a[i].clear();

    forw(i, 0, m) {
      int u, v;
      cin >> u >> v;
      a[u].pb(v);
    }

    forw(i, 1, n+1)
      if (!vis[i]) {
        dfs1(i);
      }

    fill(all(vis), false);
    reverse(all(topo));
    int cnt = 0;
    for (int u : topo) {
      if (vis[u]) continue;
      ++cnt;
      dfs2(u);
    }
    cout << cnt << endl;
  }
}

