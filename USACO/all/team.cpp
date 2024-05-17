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
 
const int N = 1e3 + 7;
const ll inf = 2e9;
const int MOD = 1e9 + 9;

int n, m, l;
int dp[N][N][11];
int a[N], b[N];

int add(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}

int sub(int x, int y) {
  x -= y;
  return (x + MOD) % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen(task".inp", "r", stdin);
  freopen(task".out", "w", stdout);
#endif
  // fastIO;

  scanf("%d %d %d", &n, &m, &l);
  forw(i, 1, n + 1) scanf("%d", &a[i]);
  forw(i, 1, m + 1) scanf("%d", &b[i]);

  sort(a + 1, a + n + 1, greater<int>());
  sort(b + 1, b + m + 1, greater<int>());

  forw(i, 0, n + 1) forw(j, 0, m + 1) dp[i][j][0] = 1;
  forw(i, 1, n + 1) forw(j, 1, m + 1) {
    forw(k, 1, l + 1) {
      dp[i][j][k] = sub(add(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i - 1][j - 1][k]);
      if (a[i] > b[j]) dp[i][j][k] = add(dp[i][j][k], dp[i - 1][j - 1][k - 1]);
    }
  }
  cout << dp[n][m][l] << endl;
}   
