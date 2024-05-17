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
 
#define task "cowmbat"
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
const int MOD = 1e9 + 7;

int n, m, k;
int mn[N], a[30][30], dp[N][30], pref[N][30];
string s;

int sum(int l, int r, int j) {
  return pref[r][j] - pref[l][j];
}

int main() {
#ifndef ONLINE_JUDGE
  freopen(task".in", "r", stdin);
  freopen(task".out", "w", stdout);
#endif
  // fastIO;

  cin >> n >> m >> k >> s;
  forw(i, 1, m + 1) forw(j, 1, m + 1)
    cin >> a[i][j];

  forw(k, 1, m + 1) forw(i, 1, m + 1) forw(j, 1, m + 1)
    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);

  s = ' ' + s;
  forw(i, 1, n + 1) forw(j, 1, m + 1) 
    pref[i][j] = pref[i - 1][j] + a[s[i] - 'a' + 1][j];

  memset(dp, 0x3f, sizeof dp);
  memset(mn, 0x3f, sizeof mn);
  cout<< dp[0][0] << endl;
  mn[0] = 0;
  forw(i, 1, n + 1) forw(j, 1, m + 1) {
    dp[i][j] = dp[i - 1][j] + a[s[i] - 'a' + 1][j];
    if (i >= k) dp[i][j] = min(dp[i][j], mn[i - k] + pref[i][j] - pref[i - k][j]);
    mn[i] = min(mn[i], dp[i][j]);
  }

  cout << mn[n] << endl;
}
