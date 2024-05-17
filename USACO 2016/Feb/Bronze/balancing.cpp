#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using ii = pair<ll, ll>;

#define fastIO ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define numBit(x) (__builtin_popcountll(1ll * (x)))
#define getBit(x, i) ((x) >> (i) & 1)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define MASK(x) (1ll << (x))

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

const int N = 1e6 + 7, oo = 1e9 + 7;

int n, B, a[N], ans = oo;
vector<array<int, 2>> vec;
set<int> d, t;

int calc(int x, int y) {
    array<int, 4> res = {0, 0, 0, 0};
    for (auto [i, j]: vec) {
        res[0] += (i < x && j < y);
        res[1] += (i < x && j > y);
        res[2] += (i > x && j < y);
        res[3] += (i > x && j > y);
    }
    return *max_element(all(res));
}

signed main() {
//    fastIO;
#ifndef ONLINE_JUDGE
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1, x, y; i <= n; i++) {
        scanf("%d%d", &x, &y); vec.pb({x, y});
        d.insert(x - 1); d.insert(x + 1); t.insert(y - 1); t.insert(y + 1);
    }
    sort(all(vec));
    for (int x: d) {
        // let the horizontal line at x
        for (int y: t) minimize(ans, calc(x, y));
    }
    cout << ans;
}

