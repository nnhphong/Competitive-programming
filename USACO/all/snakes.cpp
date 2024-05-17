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
 
#define task "snakes"
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
 
const int N = 4e2 + 7;
const ll inf = 1e9;

int n, m, a[N], dp[N][N];

int main() {
#ifndef ONLINE_JUDGE
  freopen(task".in", "r", stdin);
  freopen(task".out", "w", stdout);
#endif
  // fastIO;

  forw(i, 0, N) forw(j, 0, N) dp[i][j] = inf;
  dp[0][0] = 0;

  scanf("%d %d", &n, &m);

  int sum = 0, mx = 0;
  forw(i, 1, n + 1) {
    scanf("%d", &a[i]);
    sum += a[i], mx = max(mx, a[i]);
    dp[i][0] = mx * i - sum;
  }

  forw(i, 1, n + 1) {
    scanf("%d", &a[i]);
    forw(j, 1, m + 1) {
      int sum = 0, mx = 0;
      forb(k, i, 1) {
        sum += a[k], mx = max(mx, a[k]);
        dp[i][j] = min(1LL * dp[i][j], dp[k - 1][j - 1] + mx * (i - k + 1) - sum);
      }
    }
  }
  cout << dp[n][m] << endl;
}