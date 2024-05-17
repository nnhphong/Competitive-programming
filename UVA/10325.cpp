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
#define all(x) x.begin(), x.end()
#define numBit(x) __builtin_popcount(x)
#define lb lower_bound
#define ub upper_bound
#define ar array
#define endl '\n'
 
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
 
const int N = 1e5 + 7;
const ll inf = 1e9;

ll n, m;
int a[N];

ll lcm(ll a, ll b) {
	return a * b / __gcd(a, b);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen(task".inp", "r", stdin);
  freopen(task".out", "w", stdout);
#endif
  fastIO;

  while (~scanf("%lld %lld", &n, &m)) {
  	forw(i, 0, m) scanf("%d", &a[i]);

  	ll ans = 0;
  	forw(mask, 0, (1 << m)) {
  		int num = numBit(mask);
  		ll ret = 1;
  		forw(i, 0, m) if (mask & (1 << i)) ret = lcm(ret, 1ll * a[i]);

  		if (num & 1) ans -= n / ret; else ans += n / ret;
  	} 
  	cout << ans << endl;
  }
}