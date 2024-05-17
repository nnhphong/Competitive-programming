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

const int N = 5e5+7;
const ll inf = 1e9;

ll mat[30][30], sz = 0;
ll cost[30], dist[30], vis[30];
stack<int> st;

void topo(int u) {
  vis[u] = true;
  forw(i, 0, sz) if (mat[u][i] && !vis[i]) topo(i);
  st.push(u);
}

void solve() {
  forw(i, 0, 30) {
    cost[i] = dist[i] = vis[i] = 0;
    forw(j, 0, 30) mat[i][j] = 0;
  }
  sz = 0;
  char start, nodes;
  string buf;

  while (getline(cin, buf) && buf != "") {
    stringstream s(buf);
    int w;
    s >> start >> w;
//    cout << start << " " << w << endl;
    cost[start - 'A'] = dist[start - 'A'] = w;
    while (s >> nodes) mat[nodes - 'A'][start - 'A'] = 1;
    ++sz;
  }

  forw(i, 0, sz) if (!vis[i]) topo(i);

  ll ttl = 0, u;
  for (; sz(st); u = st.top(), st.pop()) {
    forw(v, 0, sz) if (mat[u][v] && dist[v] < dist[u] + cost[v]) {
      dist[v] = dist[u] + cost[v];
    }
  }
  forw(i, 0, sz) ttl = max (ttl, dist[i]);
  cout << ttl << endl << endl;
}

int main() {
  fastIO;
  #ifndef ONLINE_JUDGE
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  #endif

  int tc;
  cin >> tc;

  cin.get(); cin.get();
  while (tc--) {
//    cout << "TC = " << tc << endl;
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

