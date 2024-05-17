#include <bits/stdc++.h>

using namespace std;

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

const int N = 2e5+7;
const ll inf = 1e9;

ll n, bit[N], pre[N], cnt[N];

void update(ll p, ll v) {
  for (; p <= n; p += (p & -p)) bit[p] += v;
}

ll get(ll p) {
  ll ret = 0;
  for (; p > 0; p -= (p & -p)) ret += bit[p];
  return ret;
}

ll sum(ll l, ll r) {
  return get(r) - get(l-1);
}

void solve() {
  cin >> n;
  forw(i, 1, n+1) {
    int x; cin >> x;
    pre[i] = cnt[x];
    cnt[x] = i;
  }

  ll ret = 0;
  forw(r, 1, n+1) {
    ll l = pre[r];
    // range [l+1, r-1]
    if (l != 0) update(l, -1);
    ret += sum(l, r);
    update(r, 1);
  }

  cout << ret << endl;
}

int main() {
  fastIO;
  #ifndef ONLINE_JUDGE
//  freopen("test.inp", "r", stdin);
  #endif

  int tc = 1;
//  cin >> tc;
  while (tc--) {
    solve();
  }
}
