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

const int N = 1e2 + 7, oo = 1e9 + 7;

int n, a[N], status[N];

signed main() {
    fastIO;
    freopen("taming.in", "r", stdin),
    freopen("taming.out", "w", stdout);
    cin >> n; memset(status, -1, sizeof status);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != -1) {
            for (int j = i - a[i] + 1; j <= i; j++)
                if (status[j] == 1) { cout << -1; return 0; }
            status[i - a[i]] = 1;
            for (int j = i - a[i] + 1; j <= i; j++) status[j] = 0;
        }
    }

    int mx = 1, mn = 1;
    for (int i = 2; i <= n; i++) {
        if (status[i] == 1) ++mx, ++mn;
        if (status[i] == -1) ++mx;
    }
    cout << mn << ' ' << mx;
}
