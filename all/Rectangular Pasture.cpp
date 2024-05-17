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
 
const int N = 25e2 + 7;
const ll inf = 2e9;

int n, pre[N][N];
ar<int, 2> p[N];
vector<ar<int, 2>> P;

int sum(int i1, int j1, int i2, int j2) {
  return pre[i2][j2] - pre[i1 - 1][j2] - pre[i2][j1 - 1] + pre[i1 - 1][j1 - 1];
}

bool ycomp(ar<int, 2> x, ar<int, 2> y) {
  return x[1] < y[1];
}

int main() {
// #ifndef ONLINE_JUDGE
//   freopen(task".inp", "r", stdin);
//   freopen(task".out", "w", stdout);
// #endif
  // fastIO;

  scanf("%d", &n);
  forw(i, 1, n + 1) {
    scanf("%d %d", &p[i][0], &p[i][1]);
    P.push_back({p[i][0], p[i][1]});
  }

  sort(all(P));
  forw(i, 0, n) P[i][0] = i + 1;
  sort(all(P), ycomp);
  forw(i, 0, n) P[i][1] = i + 1;

  forw(i, 0, n) pre[P[i][0]][P[i][1]] = 1;
  forw(i, 1, n + 1) forw(j, 1, n + 1)
    pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];

  ll ans = 0;
  forw(i, 0, n) forw(j, i, n) {
    int x1 = min(P[i][0], P[j][0]);
    int x2 = max(P[i][0], P[j][0]); 
    
    ans += 1LL * sum(1, i + 1, x1, j + 1) * sum(x2, i + 1, n, j + 1);
  }
  cout << ans + 1 << endl;
}  
