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
#define MASK(x) 1ll << (x)

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

const int N = 1e3 + 7;

int n, m;
ll a[N][N];

ll get(int i1, int j1, int i2, int j2) {
    return a[i2][j2] - a[i1 - 1][j2] - a[i2][j1 - 1] + a[i1 - 1][j1 - 1];
}

signed main() {
    fastIO;
    if (fopen("lazy.in", "r")) {
        freopen("lazy.in", "r", stdin);
        freopen("lazy.out", "w", stdout);
    }
    cin >> n >> m;
    for (int i  = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j], a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];

    ll ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            ll cur = 0;
            for (int k = max(1, j - m), c = (k <= j ? m - (j - k) : m - (k - j)); k <= min(n, j + m); k++) {
                cur += get(max(1, i - c), k, min(i + c, n), k);
                if (k < j) ++c; else --c;
            }
            maximize(ans, cur);
        }
    cout << ans;
}
