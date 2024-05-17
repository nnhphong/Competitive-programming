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
 
#define task "cowjog"
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
 
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
 
const int N = 2e5+7;
const ll inf = 1e18;

ll n, t, a[N];

void solve() {
	cin >> n >> t;
	forw(i, 0, n) {
		ll x, y; cin >> x >> y;
		a[i] = x + y * t;
	}

	vll lis;
	forw(i, 0, n) {
		auto p = upper_bound(all(lis), a[i]);
		if (p == lis.end()) 
			lis.pb(a[i]);
		else 
			lis[(p - lis.begin())] = a[i];
	}
	cout << sz(lis) << endl;
}
 
int main() {
  fastIO;
  #ifndef ONLINE_JUDGE
  freopen(task".in", "r", stdin);
  freopen(task".out", "w", stdout);
  #endif
 
  int tc = 1;
  // cin >> tc;
  while (tc--) {
    solve();
  }
}