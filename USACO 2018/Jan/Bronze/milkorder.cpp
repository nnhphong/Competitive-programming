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
#define int long long

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

const int N = 5e4 + 7, oo = 1e9 + 7;

int n, m, k, ord[N], pos[N], _at[N];

signed main() {
    fastIO;
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    cin >> n >> m >> k; bool ok = 0, ok1 = 0;
    for (int i = 1; i <= m; i++) cin >> ord[i], ok |= (ord[i] == 1);
    for (int i = 1, c, p; i <= k; i++) cin >> c >> p, pos[p] = c, _at[c] = p;
    for (int i = 1; i <= m; i++) if (_at[ord[i]]) {
        ok1 = 1;
        for (int j = _at[ord[i]], k = i - 1; j >= 1 && k >= 1; j--) {
            if (_at[ord[k]]) break;
            if (pos[j]) continue;
            pos[j] = ord[k], _at[ord[k--]] = j;
        }
        if (ok) {
            for (int j = _at[ord[i]], k = i + 1; j <= n && k <= m; j++) {
                if (_at[ord[k]]) break;
                if (pos[j]) continue;
                pos[j] = ord[k], _at[ord[k--]] = j;
            }
        }
    }
    if (!ok1) {
        for (int i = 1, j = 1; i <= n && j <= m; i++)
            if (!pos[i]) pos[i] = ord[j], _at[ord[j++]] = i;
    }
    if (_at[1]) { cout << _at[1]; return 0; }
    for (int i = 1; i <= n; i++)
        if (!pos[i]) { cout << i; return 0; }
}

