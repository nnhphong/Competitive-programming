#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;

#define task "milkvisits"
#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i, l, r) for( ll i = (l) ; i < (r) ; i++ )
#define forb(i, r, l) for( ll i = (r) ; i >= (l) ; i-- )
#define numBit(x) (__builtin_popcountll(1ll * (x)))
#define getBit(x, i) ((x) >> (i) & 1)
#define sz(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second
#define ar array
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(x) cerr << #x << " = " << x << '\n';

const int N = 1e5 + 7;
const ll inf = 0x3f3f3f3f;
const int LOG = 20;

int n, m, timer, in[N], T[N];
vi adj[N], tin[N], tout[N];

void dfs(int u, int p) {
    in[u] = timer;
    tin[T[u]].pb(timer++);
    for (int v: adj[u]) if (v ^ p)
        dfs(v, u);
    tout[T[u]].pb(timer++);
}

int par[N][LOG], h[N];
void dfs(int u) {
    for (int v: adj[u]) if (v != par[u][0])
        par[v][0] = u, h[v] = h[u] + 1, dfs(v);
}

void buildLCA() {
    forw(j, 0, LOG) forw(i, 1, n + 1) par[i][j] = -1;
    dfs(1);
    for (int j = 1; (1 << j) <= n; j++) forw(i, 1, n + 1)
        par[i][j] = par[par[i][j - 1]][j - 1];
}

int LCA(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    int log = log2(h[u]);
    forb(i, log, 0) if (h[u] - (1 << i) >= h[v])
        u = par[u][i];

    if (u == v) return u;
    forb(i, log, 0) if (par[u][i] != -1 && par[u][i] != par[v][i])
        u = par[u][i], v = par[v][i];
    return par[u][0];
}

int qrange(vi &v, int a, int b) {
    return upper_bound(all(v), b) - lower_bound(all(v), a);
}

int main() {
//#ifndef ONLINE_JUDGE
    freopen(task".in", "r", stdin);
    freopen(task".out", "w", stdout);
//#endif
    fastIO;
    scan(n), scan(m);
    forw(i, 1, n + 1) scan(T[i]);
    forw(i, 0, n - 1) {
        int u, v; scan(u), scan(v);
        adj[u].pb(v), adj[v].pb(u);
    }

    dfs(1, 0);
    buildLCA();
    for (int a, b, c; m > 0; m--) {
        scan(a), scan(b), scan(c);
        int x = LCA(a, b);
        int p1 = qrange(tin[c], in[x], in[a]), m1 = qrange(tout[c], in[x], in[a]);
        int p2 = qrange(tin[c], in[x], in[b]), m2 = qrange(tout[c], in[x], in[b]);
        cout << (p1 - m1 + p2 - m2 > 0);
    }
}

/*
Solution: O((N + M) logN) (processing queries online)
The graph is first turned into an array with the first and last appearances of each node.
In a given range (from the first appearance of node a to the first appearance of node b where node a is an ancestor of node b),
subtracting the number of last appearances from the first appearances can give the number of nodes on the path from node a to node b.

By storing a separate array for each cow type, we can efficiently query the number of a specific type of cow in a range. (can be done in O(logN) with binary search).
The path from node u to node v can be split into the path from node u to LCA(u, v) and v to LCA(u, v).
LCA is computed with sparse tables in O(N logN) preprocessing and O(1) queries.
If the number of cows of the desired type is greater than or equal to 0, print 1. Else, print 0.
*/
