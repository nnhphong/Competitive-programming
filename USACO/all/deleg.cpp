#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using ii = pair<int, int>;

#define fi first
#define se second
#define pb push_back
#define numBit(x) (__builtin_popcountll(1ll * (x)))
#define getBit(x, i) ((x) >> (i) & 1)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }

const int N = 1e6 + 7, M = 130, oo = 1e9 + 7;

int n, sz[N], cur[N];
vector<int> num[N], adj[N];

void dfs(int u, int par) {
    sz[u] = 1;
    for (int v: adj[u]) if (v != par) {
        dfs(v, u);
        sz[u] += sz[v]; num[u].pb(sz[v]);
    }
    if (sz[u] != n) num[u].pb(n - sz[u]);
}

bool can(int k) {
    if ((n - 1) % k != 0) return 0;
    memset(cur, 0, sizeof(int) * (k + 1));
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int t: num[i]) {
            int tmp = t % k; if (!tmp) continue;
            if (cur[k - tmp]) --cur[k - tmp], --cnt;
            else ++cur[tmp], ++cnt;
        }
        if (cnt) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
//#ifndef ONLINE_JUDGE
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);
//#endif
    cin >> n;
    for (int i = 1, u, v; i <= n - 1; i++) {
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    } dfs(1, -1);
    for (int i = 1; i < n; i++) cout << can(i);
}
