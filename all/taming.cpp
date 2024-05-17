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
 
#define task "taming"
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
 
const int N = 1e2 + 7;
const ll inf = 2e9;

int n, a[N], dp[N][N], pre[N][N];

int main() {
#ifndef ONLINE_JUDGE
  freopen(task".in", "r", stdin);
  freopen(task".out", "w", stdout);
#endif
  // fastIO;

  
  scanf("%d", &n);
  forw(i, 1, n + 1) scanf("%d", &a[i]);

  /*
    dp[i][j]: xet toi ngay thu i voi j la so lan dat, k ngay cuoi cung
  */

  memset(dp, 0x3f, sizeof dp);
  
  dp[1][1] = (a[1] != 0);
  forw(i, 2, n + 1) dp[i][1] = dp[i - 1][1] + (a[i] != i - 1);

  forw(i, 1, n + 1) forw(j, i, n + 1) forw(k, i, j + 1) 
    pre[i][j] += (a[k] != k - i);

  forw(j, 2, n + 1) forw(i, j - 1, n + 1) forw(k, j - 1, i + 1) 
    dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + pre[k][i]);

  forw(i, 1, n + 1) cout << dp[n][i] << endl;
}    
