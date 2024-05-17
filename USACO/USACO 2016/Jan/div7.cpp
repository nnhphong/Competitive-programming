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

const int N = 1e6 + 7, MOD = 2019;

int n, a[N], pre[N], pos[7];

signed main() {
    fastIO;
    if (fopen("div7.in", "r")) {
        freopen("div7.in", "r", stdin);
        freopen("div7.out", "w", stdout);
    }
    cin >> n; int cur = 0, ans = 0;
    for (int i = 1, x; i <= n; i++) {
        cin >> x; (cur += x) %= 7;
        cerr << cur << endl;
        if (!pos[cur]) pos[cur] = i; else maximize(ans, i - pos[cur]);
    }
    cout << ans;
}

