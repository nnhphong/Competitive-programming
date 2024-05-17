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
 
#define task "talent"
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
 
const int N = 1e4+7;
const ll inf = 1e18;

ll n, w;
ll weight[N], talent[N];
ll dp[255][N]; 

bool DP(int x) {
	forw(i, 0, n + 1) forw(j, 0, w + 1) dp[i][j] = -inf;
	
	dp[0][0] = 0;
	forw(i, 1, n + 1) {
		ll inc = 1000 * talent[i] - x * weight[i];
		forw(j, 0, w + 1) {
			if (j < weight[i]) 
				dp[i][j] = max(dp[i - 1][j], inc); // single
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + inc); // group
		}
	}

	return dp[n][w] >= 0;
}

void solve() {
	cin >> n >> w;
	forw(i, 1, n + 1) cin >> weight[i] >> talent[i];
	
	int l = 0, r = 250 * 1000 * 1000 + 1, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;

		if (DP(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << endl;
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