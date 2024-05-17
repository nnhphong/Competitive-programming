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
vii adj[mxN+1];
vi topo;
vector<bool> vis(mxN+1, false);

void dfs(int u) {
  vis[u] = true;
  for (ii e: adj[u]) {
    int v = e.first;
    if (vis[v]) continue;
    dfs(v);
  }
  topo.pb(u);
}

int main() {
  fastIO;
  #ifndef ONLINE_JUDGE
  freopen("timeline.in", "r", stdin);
  freopen("timeline.out", "w", stdout);
  #endif // ONLINE_JUDGE

  int n, m, c;
  cin >> n >> m >> c;
  vi s(n+1);
  forw(i, 1, n+1)
    cin >> s[i];
  forw(i, 0, c) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].pb({v, c});
  }

  forw(i, 1, n+1)
    if (!vis[i]) dfs(i);

  reverse(all(topo));
  vi res = s;
  for (int u: topo) {
    for (ii e: adj[u]) {
      int v = e.first;
      int c = e.second;
      if (res[u] + c > m) continue;
      res[v] = max(res[v], res[u] + c);
    }
  }

  forw(i, 1, n+1)
    cout << res[i] << endl;
}
