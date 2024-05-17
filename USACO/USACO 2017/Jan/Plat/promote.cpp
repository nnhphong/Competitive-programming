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

const int N = 1e5 + 7;

int n, a[N], in[N], out[N], pos[N];
vector<int> adj[N];
vector<int> seg[N << 2];

void build(int id, int l, int r) {
    if (l == r) {
        seg[id].pb(a[pos[l]]);
        return;
    }

    int mid = l + r >> 1, k = id << 1;
    build(k, l, mid); build(k | 1, mid + 1, r);
    for (int x: seg[k]) seg[id].pb(x);
    for (int x: seg[k | 1]) seg[id].pb(x);
    sort(seg[id].begin(), seg[id].end());
    seg[id].resize(unique(seg[id].begin(), seg[id].end()) - seg[id].begin());
}

int get(int id, int l, int r, int u, int v, int x) {
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) {
        auto it = upper_bound(seg[id].begin(), seg[id].end(), x);
        return (it == seg[id].end() ? 0 : sz(seg[id]) - (it - seg[id].begin()));
    }

    int mid = l + r >> 1, k = id << 1;
    return get(k, l, mid, u, v, x) + get(k | 1, mid + 1, r, u, v, x);
}

void dfs(int u) {
    in[u] = ++in[0]; pos[in[0]] = u;
    for (int v: adj[u]) dfs(v);
    out[u] = in[0];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 2, n) {
        int p; cin >> p;
        adj[p].pb(i);
    }

    dfs(1); build(1, 1, n);
    rep(i, 1, n) cout << get(1, 1, n, in[i], out[i], a[i]) << '\n';
}

