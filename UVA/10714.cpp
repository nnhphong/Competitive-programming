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
 
int n, m, x;

int main() {
#ifndef ONLINE_JUDGE
  freopen(task".inp", "r", stdin);
  freopen(task".out", "w", stdout);
#endif
  fastIO;

  int tc;
  scanf("%d", &tc);
  while (tc--) {
  	scanf("%d %d", &m, &n);

  	int ans1 = 0, ans2 = 0;
  	forw(i, 1, n + 1) {
  		scanf("%d", &x);
  		ans1 = max(ans1, min(x, m - x));
  		ans2 = max(ans2, max(x, m - x));
  	}
  	cout << ans1 << ' ' << ans2 << endl;
  }
}