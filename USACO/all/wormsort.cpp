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

int n, m, vis[mxN+1];
vii a[mxN+1];
vi g[mxN+1];
vi p(mxN+1);

void dfs(int u, int c) {
  vis[u] = c;
  for (int v: g[u])
    if (vis[v] == -1) dfs(v, c);
}

bool isOK(int w) {
  forw(u, 1, n+1) {
    g[u].clear();
    vis[u] = -1;
    for (ii e : a[u]) {
      int v = e.fi;
      int c = e.se;

      if (c >= w) {
        g[u].pb(v);
      }
    }
  }

  int c = 0;
  forw(u, 1, n+1)
    if (vis[u] == -1) dfs(u, ++c);

  forw(u, 1, n+1)
    if (vis[p[u]] != vis[u]) {
      return false;
    }
  return true;
}

int main() {
  fastIO;

  #ifndef ONLINE_JUDGE
  freopen("wormsort.in", "r", stdin);
  freopen("wormsort.out", "w", stdout);
  #endif // ONLINE_JUDGE

  cin >> n >> m;

  bool ok = false;
  forw(i, 1, n+1) {
    cin >> p[i];
    if (p[i] != i) ok = true;
  }
  if (!ok) {
    cout << -1 << endl;
    return 0;
  }

  vi w(m);
  forw(i, 0, m) {
    int u, v, c;
    cin >> u >> v >> c;
    a[u].pb({v, c});
    a[v].pb({u, c});
    w[i] = c;
  }

  sort(all(w));
  int lo = 0, hi = m, ans = -1;
  while (lo <= hi) {
    int mid = (lo + hi)/2;
    if (isOK(w[mid])) {
      lo = mid + 1;
      ans = w[mid];
    }
    else hi = mid - 1;
  }
  cout << ans << endl;
}
