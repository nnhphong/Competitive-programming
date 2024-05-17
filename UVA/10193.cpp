#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
/** ORDERED SET **/
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fkey order_of_key

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

const int N = 80;
const ll inf = 1e9;

int n, k, dp[N][N][6][4], a[N][N], ans = -inf;

bool valid(int i, int j) {
  return (i > 0 && i <= n && j > 0 && j <= n);
}

void dfs(int i, int j, int neg, int d) {
//  cout << i << " " << j << " " << neg << endl;
  if (i == n && j == n) {
    ans = max(ans, dp[i][j][neg][d]);
    return;
  }

  forw(dir, 1, 4) {
    int ii = i + dx[dir], jj = j + dy[dir];
//    cout << i << " " << jj << " " << valid(ii, jj) << endl;
    if (dir == d || !valid(ii, jj)) continue;
    if (neg + (a[ii][jj] < 0) > k) continue;
    int rdir = 0;
    if (dir == 1) rdir = 3; else if (dir == 3) rdir = 1;
    if (dp[i][j][neg][d] + a[ii][jj] > dp[ii][jj][neg + (a[ii][jj] < 0)][rdir]) {
      dp[ii][jj][neg + (a[ii][jj] < 0)][rdir] = dp[i][j][neg][d] + a[ii][jj];
      dfs(ii, jj, neg + (a[ii][jj] < 0), rdir);
    }
  }
}

void solve() {
  ans = -inf;
  forw(i, 1, n+1) forw(j, 1, n+1) {
    cin >> a[i][j];
    forw(k, 0, 6) forw(dir, 0, 4) dp[i][j][k][dir] = -inf;
  }

  dp[1][1][(a[1][1] < 0)][0] = a[1][1];
  dfs(1, 1, (a[1][1] < 0), 0);
  (ans == -inf ? cout << "impossible" << endl : cout << ans << endl);
}

int main() {
  fastIO;
  #ifndef ONLINE_JUDGE
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  #endif

  int tc = 1;
//  cin >> tc;
  while (cin >> n >> k && (n != 0 || k != 0)) {
    cout << "Case " << tc++ << ": ";
    solve();
  }
}

/* stuff you should look for
    - int overflow, array bounds
    - special cases (n=1?)
    - do smth instead of do nothing and stay organized
    - WRITE STUFF DOWN
    - DONT JUST STICK ON ONE APPROACH
*/

