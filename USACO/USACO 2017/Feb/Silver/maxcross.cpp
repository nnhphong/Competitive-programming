#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using ii = pair<int, int>;

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

const int N = 1e5 + 7, MOD = 2019;

int n, k, b, pre[N];

signed main() {
    fastIO;
    if (fopen("maxcross.in", "r")) {
        freopen("maxcross.in", "r", stdin);
        freopen("maxcross.out", "w", stdout);
    }
    cin >> n >> k >> b; int ans = 1e9;
    for (int i = 1, x; i <= b; i++) cin >> x, pre[x] = 1;
    for (int i = 1; i <= n; i++) pre[i] += pre[i - 1];
    for (int i = k; i <= n; i++) minimize(ans, pre[i] - pre[i - k]);
    cout << ans;
}


