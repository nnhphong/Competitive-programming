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

struct Fenwick {
  vi fen;
  int n;

  Fenwick(int n):
    fen(n+1, 0), n(n) {}

  void update(int p, int x) {
    for (; p <= n; p += (p & -p))
      fen[p] += x;
  }

  int sum(int p) {
    int ret = 0;
    for (; p > 0; p -= (p & -p))
      ret += fen[p];
    return ret;
  }

  int sum_range(int l, int r) {
    return sum(r) - sum(l - 1);
  }
};

int main() {
  fastIO;

  #ifndef ONLINE_JUDGE
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  #endif // ONLINE_JUDGE

  string cmd;
  int n;
  int tc = 1;
  while (cin >> n && n != 0) {
    if (tc > 1) cout << endl;
    cout << "Case " << tc++ << ":" << endl;
    Fenwick fen(n);

    forw(i, 1, n+1) {
      int x;
      cin >> x;
      fen.update(i, x);
    }

    while (cin >> cmd && cmd != "END") {
      int x, y;
      cin >> x >> y;

      if (cmd == "S") {
        int v = fen.sum_range(x, x);
        fen.update(x, y - v);
      }
      else cout << fen.sum_range(x, y) << endl;
    }
  }
}
