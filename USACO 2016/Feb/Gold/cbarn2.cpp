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

const int N = 2e2 + 7, M = 10, oo = 1e9 + 7, MOD = 1e9 + 7;

int n, m, r[N];
ll pre[N][N], dp[N][M], ans = 1e18;

ll calc(int x, int y) {
    if (x > n) x -= n;
    if (y > n) y -= n;
    if (y <= x) y += n;
    return pre[x][y];
}

signed main() {
    fastIO;
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> r[i], r[i + n] = r[i];
    for (int i = 1; i <= 2 * n; i++)
        for (int j = i; j <= 2 * n; j++)
            for (int k = j, b = j - i; k >= i; k--, b--)
                pre[i][j] += 1ll * b * r[k];

    if (m == 1) {
        for (int i = 1; i <= n; i++) minimize(ans, calc(i, i - 1));
        cout << ans; return 0;
    }
    for (int st = 1; st <= n; st++) {
        for (int i = st; i <= st + n - 1; i++) {
            for (int j = 3; j <= m; j++) dp[i][j] = 1e18;
            dp[i][2] = calc(st, i - 1);
            if (m == 2) minimize(ans, dp[i][2] + calc(i, st - 1));
        }
        for (int i = st + 1; i <= st + n - 1; i++)
            for (int j = 3; j <= m; j++)
                for (int k = i + 1; k <= st + n - 1; k++) {
                    minimize(dp[k][j], dp[i][j - 1] + calc(i, k - 1));
                    if (j == m) minimize(ans, dp[k][j] + calc(k, st - 1));
                }
    }
    cout << ans;
}
