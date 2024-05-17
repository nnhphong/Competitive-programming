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

const int N = 2e5 + 7, oo = 1e9 + 7, MOD = 1e9 + 7;

int n, res, pre[N], pw[N];
ii seg[N];

#define mul(x, y) 1ll * (x) * (y) % MOD
#define add(x, y) ((x) % MOD + (y) % MOD) % MOD
signed main() {
    fastIO;
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
    cin >> n; pw[0] = 1;
    for (int i = 1; i <= n; i++) cin >> seg[i].fi >> seg[i].se, pre[seg[i].fi]++, pre[seg[i].se]--;
    for (int i = 1; i <= 2 * n; i++) pre[i] += pre[i - 1], pw[i] = mul(pw[i - 1], 2);
    for (int i = 1; i <= n; i++) res = add(res, pw[n - 1 - pre[seg[i].fi - 1]]);
    cout << res;
}
// don't think, just do

