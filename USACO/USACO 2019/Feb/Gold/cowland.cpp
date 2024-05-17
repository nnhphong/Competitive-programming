#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(x) (int)x.size()
#define rep(i, begin, end) for (ll i = (begin); i <= (end); i++)
#define rrep(i, begin, end) for (ll i = (begin); i >= (end); i--)

#define numBit(x) (__builtin_popcountll(1ll * (x)))
#define getBit(x, i) ((x) >> (i) & 1)
#define MASK(x) (1ll << (x))

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;

template <class T>
bool minimize(T &a, const T &b) {
    if(a > b) {a = b; return 1;}
    return 0;
}
template <class T>
bool maximize(T &a, const T &b) {
    if(a < b) {a = b; return 1;}
    return 0;
}

const int N = 2e5 + 7, LOG = 20;

int n, q, a[N], b[N], in[N], out[N], h[N], P[N][LOG]; ll bit[N];
vector<int> adj[N];

void update(int i, ll v) {
    b[i] = v;
    for (; i < N; i += i & -i)
        bit[i] ^= v;
}

ll get(int l, int r) {
    ll res = 0;
    while (l <= r) {
        if (r - (r & -r) >= l) {
            res ^= bit[r];
            r -= (r & -r);
        }
        else {
            res ^= b[r];
            --r;
        }
    }
    return res;
}

void dfs(int u) {
    in[u] = ++in[0];
    rep(i, 1, LOG - 1) P[u][i] = P[P[u][i - 1]][i - 1];
    for (int v: adj[u]) if (v != P[u][0]) {
        P[v][0] = u; h[v] = h[u] + 1;
        dfs(v);
    }
    out[u] = ++in[0];
}

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    rrep(i, LOG - 1, 0) if (h[u] - (1 << i) >= h[v])
        u = P[u][i];
    if (u == v) return u;

    rrep(i, LOG - 1, 0)
        if (P[u][i] && P[u][i] != P[v][i])
            u = P[u][i], v = P[v][i];
    return P[u][0];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
    cin >> n >> q;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }

    dfs(1);
    rep(i, 1, n) {
        update(in[i], a[i]);
        update(out[i], a[i]);
    }
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 2) {
            int l = lca(x, y);
            cout << (get(in[l], in[x]) ^ get(in[l], in[y]) ^ a[l]) << '\n';
        }
        else {
            update(in[x], a[x]);
            update(out[x], a[x]);
            a[x] = y;
            update(in[x], a[x]);
            update(out[x], a[x]);
        }
    }
}

