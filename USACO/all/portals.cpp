#pragma GCC optimize("O3")
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
#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()
#define numBit(x) __builtin_popcount(x)
#define lb lower_bound
#define ub upper_bound
#define ar array
#define endl '\n'
 
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
 
const int N = 3e5 + 7;
const ll INF = 1e9;

int n, m, par[N];
vector<ar<int, 3>> E;

int root(int x) {
  return (par[x] < 0 ? x : par[x] = root(par[x]));
}

bool join(int x, int y) {
  if ((x = root(x)) == (y = root(y))) return 0;
  par[x] += par[y], par[y] = x;
  return 1;
}

int main() {
  fastIO;

  memset(par, -1, sizeof par);
  cin >> n;
  forw(i, 1, n + 1) {
    int p[4], c;
    cin >> c;
    forw(i, 0, 4) cin >> p[i];
    E.pb({0, p[0], p[1]});
    E.pb({0, p[2], p[3]});
    E.pb({c, p[0], p[3]});
  }

  sort(all(E));
  int ans = 0;
  for (auto it: E) if (join(it[1], it[2]))
    ans += it[0];
  cout << ans << endl;
}