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

const int N = 3e5 + 1, oo = 1e9 + 7;

int n, cnt, ymin[N], ymax[N];
ii a[N];

bool operator<(ii x, ii y) {
    return (x.fi == y.fi ? x.se < y.se : x.fi < y.fi);
}

signed main() {
    fastIO;
    freopen("moop.in", "r", stdin);
    freopen("moop.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
    sort(a + 1, a + n + 1); a[n + 1] = {-oo, -oo};

    ymin[1] = a[1].se, ymax[n + 1] = a[n + 1].se;
    for (int i = 2; i <= n; i++) ymin[i] = min(a[i].se, 1ll * ymin[i - 1]);
    for (int i = n; i >= 1; i--) ymax[i] = max(a[i].se, 1ll * ymax[i + 1]);
    for (int i = 1; i <= n; i++) cnt += (ymin[i] > ymax[i + 1]);
    cout << cnt;
}

