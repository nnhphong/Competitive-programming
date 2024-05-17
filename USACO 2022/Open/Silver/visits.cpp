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

const int N = 1e5 + 7, oo = 1e9 + 7;

int n, v[N], dsu[N];
vector<pair<int, ii>> edges;

int root(int x) { return (dsu[x] < 0 ? x : dsu[x] = root(dsu[x])); }
bool join(int x, int y) {
    if ((x = root(x)) == (y = root(y))) return 0;
    if (dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y], dsu[y] = x;
    return 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    memset(dsu, -1, sizeof dsu);
    scanf("%d", &n);
    for (int i = 1, j, c; i <= n; i++) {
        scanf("%d%d", &j, &c);
        edges.pb({c, {i, j}});
    }
    sort(all(edges), greater<pair<int, ii>>());
    ll ans = 0;
    for (auto it: edges) if (join(it.se.fi, it.se.se))
        ans += it.fi;
    printf("%lld", ans);
}