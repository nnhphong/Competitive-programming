#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;
 
#define task "pump"
#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i, l, r) for( ll i = (l) ; i < (r) ; i++ )
#define forb(i, r, l) for( ll i = (r) ; i >= (l) ; i-- )
#define sz(x) (int)x.size()
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()
#define numBit(x) __builtin_popcount(x)
#define lb lower_bound
#define ub upper_bound
#define ar array
#define endl '\n'
 
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
 
const int N = 2e3 + 7;
const ll inf = 1e9;

int n, m, d[N][N];
vector<ar<int, 3>> adj[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen(task".in", "r", stdin);
  freopen(task".out", "w", stdout);
#endif
  fastIO;

  cin >> n >> m;
  forw(i, 0, m) {
  	int u, v, c, f;
  	cin >> u >> v >> c >> f;
  	adj[u].pb({c, v, f});
  	adj[v].pb({c, u, f});
  }

  priority_queue<ar<int, 3>, vector<ar<int, 3>>,  greater<ar<int, 3>>> pq;
  forw(i, 1, N) forw(j, 1, N) d[i][j] = inf;
  double ret = -1;
  pq.push({0, 1, 1000});
  d[1][1000] = 0;
  while (sz(pq)) {
  	ar<int, 3> u = pq.top();
  	pq.pop();

  	if (u[1] == n) {
  		ret = max(ret, u[2] * 1.0 / d[u[1]][u[2]]);
 			// cout << u[2] << ' ' << d[u[1]][u[2]] << endl;
  		continue;
  	}

  	for (ar<int, 3> v: adj[u[1]]) {
  		int nf = min(v[2], u[2]);
  		// cout << d[u[1]][u[2]] + v[0] << ' ' << d[v[1]][nf] << endl;
  		if (d[u[1]][u[2]] + v[0] < d[v[1]][nf]) {
  			d[v[1]][nf] = d[u[1]][u[2]] + v[0];
  			pq.push({d[v[1]][nf], v[1], nf});
  		}
  	}
  }
  cout << (int)(1000000 * ret) << endl;
}