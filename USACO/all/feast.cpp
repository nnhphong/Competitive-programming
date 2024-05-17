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
 
#define task "feast"
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
 
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
 
const int N = 5e6 + 7;
const ll inf = 1e15;
const int MOD = 1e9 + 7;

int t, a, b;
bool dp[N][2];

void solve() {
   cin >> t >> a >> b;
   dp[a][0] = dp[b][0] = 1;
   dp[a / 2][1] = dp[b / 2][1] = 1;

   forw(i, 0, t + 1) {
    if (dp[i][0]) {
      if (i + a <= t) dp[i + a][0] = 1, dp[(i + a) / 2][1] = 1;
      if (i + b <= t) dp[i + b][0] = 1, dp[(i + b) / 2][1] = 1;
    }

    if (dp[i][1]) {
      if (i + a <= t) dp[i + a][1] = 1;
      if (i + b <= t) dp[i + b][1] = 1;
    }
   }

  forb(i, t, 0)
    if (dp[i][0] || dp[i][1]) {
      cout << i << endl;
      return;
    }
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