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

const int mxN = 2e5;

int nodes = 0;
vi adj[mxN+1];

struct DSU {
  vi p;
  void init(int n) {
    p = vi(n+1, -1);
  }

  int get(int x) {
    return (p[x] < 0 ? x : p[x] = get(p[x]));
  }

  bool isSameSet(int x, int y) {
    return get(x) == get(y);
  }

  int getSize(int x) {
    return -p[get(x)];
  }

  bool join(int x, int y) {
    if ((x = get(x)) == (y = get(y))) return 0;
    if (p[x] > p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
    return 1;
  }
};

int main() {
  fastIO;

  #ifndef ONLINE_JUDGE
  freopen("closing.in", "r", stdin);
  freopen("closing.out", "w", stdout);
  #endif // ONLINE_JUDGE

  int n, m;
  scanf("%d %d", &n, &m);

  int u[m], v[m];
  forw(i, 0, m) {
    scanf("%d %d", &u[i], &v[i]);
  }

  vi order(n+1), place(n+1);
  forw(i, 0, n) {
    scanf("%d", &order[i]);
    place[order[i]] = i;
  }

  forw(i, 0, m)
    if (place[u[i]] > place[v[i]]) adj[v[i]].pb(u[i]);
    else adj[u[i]].pb(v[i]);

  DSU dsu;
  dsu.init(n);
  vector<bool> ans;

  int comps = 0;
  forb(i, n-1, 0) {
    int u = order[i];
    comps++;

//    cout << comps << " ";
    for (int v: adj[u])
      if (dsu.join(u, v)) {
        --comps;
      }
//    cout << comps << endl;
    ans.pb((comps <= 1));
  }

  reverse(all(ans));
  forw(i, 0, n)
    cout << (ans[i] ? "YES" : "NO") << endl;
}
