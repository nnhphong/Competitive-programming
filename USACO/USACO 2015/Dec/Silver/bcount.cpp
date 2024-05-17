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

const int N = 1e6 + 7, MOD = 1e9 + 7;

int n, q;
int pre[N][4];

signed main() {
    fastIO;
    if (fopen("bcount.in", "r")) {
        freopen("bcount.in", "r", stdin);
        freopen("bcount.out", "w", stdout);
    }

    cin >> n >> q;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        for (int j = 1; j <= 3; j++)
            pre[i][j] += pre[i - 1][j] + (x == j);
    }

    for (int x, y; q; q--) {
        cin >> x >> y;
        for (int i = 1; i <= 3; i++)
            cout << pre[y][i] - pre[x - 1][i] << " \n"[i == 3];
    }
}


