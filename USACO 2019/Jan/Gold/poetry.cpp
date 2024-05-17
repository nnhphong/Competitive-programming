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

const int N = 5e3 + 7, MOD = 1e9 + 7;

int n, m, k;
int s[N], c[N], dp[N], cnt[N];
map<char, int> g;
map<int, int> f;

int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return 1ll * x * y % MOD;
}

int fexp(int x, int y) {
    int ans = 1;
    for (; y; y >>= 1, x = mul(x, x))
        if (y & 1) ans = mul(ans, x);
    return ans;
}

signed main() {
    fastIO;
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> s[i] >> c[i], f[c[i]]++;

    dp[0] = 1;
    for (int j = 0; j <= k; j++) {
        for (int i = 1; i <= n; i++) if (j >= s[i]) {
            if (j == k) cnt[c[i]] = add(cnt[c[i]], dp[j - s[i]]);
            dp[j] = add(dp[j], dp[j - s[i]]);
        }
    }

    char c; int ans = 1;
    for (int i = 1; i <= m; i++) cin >> c, g[c]++;
    for (auto i: g) {
        int cur = 0;
        for (auto j: f) cur = add(cur, fexp(cnt[j.fi], i.se));
        ans = mul(ans, cur);
    }
    cout << ans;
}

