#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<ld> vld;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i,l,r) for( ll i = (l) ; i < (r) ; i++ )
#define forb(i,r,l) for( ll i = (r) ; i >= (l) ; i-- )
#define sz(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define cntbit(x) __builtin_popcount(x)
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
/** ORDERED SET **/
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fkey order_of_key

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

const int N = 5e5+7;
const ll inf = 1e9;

struct DSU {
  vi p;
  void init(int n) {
    p = vi(2*n+1, -1);
  }
  int get(int x) {
    return p[x] < 0 ? x : (p[x] = get(p[x]));
  }
  bool sameSet(int x, int y) {
    return get(x) == get(y);
  }
  bool join(int x, int y) {
    if ((x = get(x)) == (y = get(y))) return 0;
    if (p[x] > p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
    return 1;
  }
};

DSU dsu;

bool areFriends(int xr, int yr) {
  return dsu.sameSet(xr, yr);
}

bool areEnemies(int xr, int yr, int exr, int eyr) {
  return dsu.sameSet(xr, eyr) || dsu.sameSet(yr, exr);
}

void setFriends(int xr, int yr, int exr, int eyr) {
  if (areEnemies(xr, yr, exr, eyr)) cout << -1 << endl;
  else {
    dsu.join(xr, yr);
    dsu.join(exr, eyr);
  }
}

void setEnemies(int xr, int yr, int exr, int eyr) {
  if (areFriends(xr, yr)) cout << -1 << endl;
  else {
    dsu.join(xr, eyr);
    dsu.join(yr, exr);
  }
}

void solve() {
  int n;
  cin >> n;

  int c, x, y;
  dsu.init(n);
  while (cin >> c >> x >> y && (x != 0 || y != 0 || c != 0)) {
    int xr = dsu.get(x), yr = dsu.get(y);
    int exr = dsu.get(x+n), eyr = dsu.get(y+n);

//    cout << c << ":";
    if (c == 1) {
//      cout << "FUCK" << endl;
      setFriends(xr, yr, exr, eyr);
    }
    else if (c == 2) {
      setEnemies(xr, yr, exr, eyr);
    }
    if (c == 3) {
      cout << areFriends(xr, yr) << endl;
    }
    else if (c == 4) {
      cout << areEnemies(xr, yr, exr, eyr) << endl;
    }
  }
}

int main() {
  fastIO;
  #ifndef ONLINE_JUDGE
  freopen("10158.inp", "r", stdin);
  freopen("10158.out", "w", stdout);
  #endif

  solve();
}

/* stuff you should look for
    - int overflow, array bounds
    - special cases (n=1?)
    - do smth instead of do nothing and stay organized
    - WRITE STUFF DOWN
    - DONT JUST STICK ON ONE APPROACH
*/

