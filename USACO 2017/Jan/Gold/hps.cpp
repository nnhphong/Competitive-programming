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

const int N = 2e5 + 7, M = 31, oo = 1e9 + 7, MOD = 1e9 + 7;

int n, k, a[N], dp[N][3][M];
bool done[N][3][M];

int win(int x, int y) {
    return ((x == 0 && y == 2) || (x == 1 && y == 0) || (x == 2 && y == 1));
}

int DP(int pos, int cur, int changes) {
    if (pos > n) return 0;
    int &tmp = dp[pos][cur][changes];
    if (done[pos][cur][changes]) return tmp;
    done[pos][cur][changes] = 1;
    for (int j = 0; j < 3; j++) {
        if (cur != j && changes < k) maximize(tmp, DP(pos + 1, j, changes + 1) + win(cur, a[pos]));
        else if (cur == j) maximize(tmp, DP(pos + 1, j, changes) + win(cur, a[pos]));
    }
    return tmp;
}

signed main() {
    fastIO;
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        if (c == 'P') a[i] = 1;
        if (c == 'S') a[i] = 2;
    }
    cout << max(DP(1, 0, 0), max(DP(1, 1, 0), DP(1, 2, 0)));
}

