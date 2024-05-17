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

const int N = 7500 + 7, MOD = 2019201997;

int n, k, dsu[N], d[N];
bool done[N];

ll dist(ll x, ll y) {
    return (2019201913 * x % MOD + 2019201949 * y % MOD) % MOD;
}

void jarnik() {
    for (int i = 1; i <= n; i++) d[i] = 1e18;
    for (int i = 0; i < n; i++) {
        int idx = 0;
        for (int j = 1; j <= n; j++)
            if (!done[j] && (!idx || d[j] < d[idx])) idx = j;

        done[idx] = 1;
        for (int j = 1; j <= n; j++)
            if (!done[j]) minimize(d[j], dist(min(j, idx), max(j, idx)));
    }
}

signed main() {
    fastIO;
    if (fopen("walk.in", "r")) {
        freopen("walk.in", "r", stdin);
        freopen("walk.out", "w", stdout);
    }
    memset(dsu, -1, sizeof dsu);
    cin >> n >> k; jarnik();

    sort(d + 1, d + n + 1);
    cout << d[n - k + 1];
}

