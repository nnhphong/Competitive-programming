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

vi topo;
vi a[mxN+1];

int main() {
  fastIO;

  #ifndef ONLINE_JUDGE
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  #endif // ONLINE_JUDGE

  int n, m, cnt = 0;
  while (cin >> n) {
    topo.clear();
    forw(i, 1, n+1) a[i].clear();

    unordered_map<string, int> id;
    vector<string> st(n);
    forw(i, 0, n) {
      cin >> st[i];
      id[st[i]] = i+1;
    }

    cin >> m;
    forw(i, 0, m) {
      string u, v;
      cin >> u >> v;
      a[id[u]].pb(id[v]);
    }

    vi indeg(n+1, 0);
    forw(u, 1, n+1)
      for (int v: a[u])
        indeg[v]++;

    priority_queue<int, vi, greater<int>> q;
    forw(i, 1, n+1)
      if (indeg[i] == 0) q.push(i);
    while (q.size()) {
      int u = q.top();
      q.pop();
      topo.pb(u);

      for (int v: a[u])
        if (--indeg[v] == 0) q.push(v);
    }

    cout << "Case #" << ++cnt << ": Dilbert should drink beverages in this order:";
    for (int u: topo)
      cout << " " << st[u-1];
    cout << "." << endl << endl;
  }
}


