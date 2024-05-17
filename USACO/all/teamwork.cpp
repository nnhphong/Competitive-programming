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
 
#define task "teamwork"
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

int n, k, a[N], dp[N];

int main() {
// #ifndef ONLINE_JUDGE
  freopen(task".in", "r", stdin);
  freopen(task".out", "w", stdout);
// #endif
  // fastIO;

  scanf("%d %d", &n, &k);
  forw(i, 1, n + 1) scanf("%d", &a[i]);

  int ans = 0;
  forw(i, 1, n + 1) {
    int mx = 0;
    forb(j, i, max(1LL, i - k + 1))
      mx = max(mx, a[j]), dp[i] = max(1LL * dp[i], dp[j - 1] + mx * (i - j + 1));
  }
  cout << dp[n] << endl;
}