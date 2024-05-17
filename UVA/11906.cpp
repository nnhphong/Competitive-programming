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
const int INF = 1e9;

int n, cnt = 0;
vi a[mxN+1], low(mxN+1, 0), num(mxN+1, 0), pa(mxN+1, -1);

// tarjan
void dfs(int u) {
  low[u] = INF;
  num[u] = ++cnt;

  for (int v: a[u]) {
    if (v == pa[u]) continue;
    else if (num[v] != 0) {
      low[u] = min(low[u], num[v]);
    } else {
      pa[v] = u;
      dfs(v);
      low[u] = min(low[u], low[v]);
    }
  }
}

int main() {
  fastIO;

  #ifndef ONLINE_JUDGE
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  #endif // ONLINE_JUDGE

  while (cin >> n) {
    forw(i, 1, n+1) a[i].clear();
    fill(all(pa), -1);
    fill(all(num), 0);
    fill(all(low), 0);
    cnt = 0;

    forw(i, 0, n) {
      int t;
      string s;
      cin >> t >> s;
      s = s.substr(1, s.length()-1);
      int k = stoi(s);
      forw(j, 0, k) {
        int v; cin >> v;
        a[t+1].pb(v+1);
      }
    }

    forw(i, 1, n+1)
      if (num[i] == 0) {
        pa[i] = -1;
        dfs(i);
      }

    vii res;
    forw(v, 1, n+1) {
      int u = pa[v];
      if (u == -1) continue;
      if (low[v] >= num[v]) res.pb({min(u, (int)v), max(u, (int)v)});
    }
    cout << sz(res) << " critical links" << endl;

    sort(all(res));
    for (auto it: res) {
      cout << it.first-1 << " - " << it.second-1 << endl;
    }
    cout << endl;
  }
}
