#pragma GCC optimize("O3")
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

const int N = 5e4 + 7, M = 1e6 + 7, oo = 1e9 + 7, MOD = 1e9 + 7;

int n, a[6], cnt[6];
map<vector<int>, int> dp;

signed main() {
    fastIO;
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);
    cin >> n; vector<int> x;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++)
            cin >> a[j];
        sort(a, a + 5);
        for (int m = 1; m < (1 << 5); m++) {
            x.clear();
            for (int j = 0; j < 5; j++)
                if (getBit(m, j)) x.pb(a[j]);
            dp[x]++;
        }
    }

    ll ans = 1ll * n * (n - 1) / 2;
    for (auto it: dp) {
        if (sz(it.fi) & 1) ans -= 1ll * it.se * (it.se - 1) / 2;
        else ans += 1ll * it.se * (it.se - 1) / 2;
    }
    cout << ans;
}
