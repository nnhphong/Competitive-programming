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

const int N = 20 + 7, M = 1e3 + 7, oo = 1e9 + 7;

int n, l, c[N], d[N], times[N][M];
int dp[1 << 20];
vector<int> pos[1 << 20];

signed main() {
    fastIO;
    freopen("movie.in", "r", stdin),
    freopen("movie.out", "w", stdout);
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        cin >> d[i] >> c[i];
        for (int j = 1; j <= c[i]; j++) cin >> times[i][j];
    }

    for (int i = 0; i < MASK(n); i++)
        for (int j = 0; j < n; j++) if (getBit(i, j))
            pos[i].pb(j);

    int ans = oo;
    for (int i = 0; i < MASK(n); i++) {
        for (int j: pos[i]) {
            auto _next = upper_bound(times[j + 1] + 1, times[j + 1] + 1 + c[j + 1], dp[i ^ MASK(j)]); --_next;
            if (*_next > times[j + 1][c[j + 1]]) continue;
            maximize(dp[i], *_next + d[j + 1]);
        }
        if (dp[i] >= l) minimize(ans, numBit(i));
    }
    cout << (ans == oo ? -1 : ans);
}

