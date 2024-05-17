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

int n, pre[N][3];

signed main() {
    fastIO;
    if (fopen("hps.in", "r")) {
        freopen("hps.in", "r", stdin);
        freopen("hps.out", "w", stdout);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        pre[i + 1][0] += pre[i][0] + (c == 'S');
        pre[i + 1][1] += pre[i][1] + (c == 'P');
        pre[i + 1][2] += pre[i][2] + (c == 'H');
    }

    int ans = -1;
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            int x = pre[n][(i + 1) % 3] - pre[j][(i + 1) % 3];
            int y = pre[n][(i + 2) % 3] - pre[j][(i + 2) % 3];
            maximize(ans, pre[j][i] + max(x, y));
        }
    }
    cout << ans;
}


