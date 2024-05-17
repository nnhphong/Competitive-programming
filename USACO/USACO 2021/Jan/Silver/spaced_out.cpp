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

const int N = 1e3 + 7, oo = 1e9 + 7;

int n, a[N][N], col[N], row[N];

signed main() {
    fastIO;
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        cin >> a[i][j];
    int cur = 0, mx = 0;
    for (int i = 1; i <= n; i += 2)
        for (int j = 1; j <= n; j++) cur += a[i][j], col[j] += a[i][j];

    maximize(mx, cur);
    for (int j = 1; j <= n; j++) {
        int sum = 0;
        for (int i = 2; i <= n; i += 2) sum += a[i][j];
        if (sum > col[j]) cur = cur - col[j] + sum, maximize(mx, cur);
    }

    cur = 0;
    for (int j = 1; j <= n; j += 2)
        for (int i = 1; i <= n; i++) cur += a[i][j], row[i] += a[i][j];
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 2; j <= n; j += 2) sum += a[i][j];
        if (sum > row[i]) cur = cur - row[i] + sum, maximize(mx, cur);
    }
    cout << mx;
}


