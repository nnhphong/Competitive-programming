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

const int N = 1e3 + 7;

int n, k, pre[N][N];

signed main() {
    fastIO;
    if (fopen("paintbarn.in", "r")) {
        freopen("paintbarn.in", "r", stdin);
        freopen("paintbarn.out", "w", stdout);
    }
    cin >> n >> k;
    for (int i = 1, x1, x2, y1, y2; i <= n; i++) {
        cin >> x1 >> y1 >> x2 >> y2; ++x1, ++y1, ++x2, ++y2;
        pre[x1][y1]++; pre[x2][y2]++;
        pre[x1][y2]--; pre[x2][y1]--;
    }

    int cnt = 0;
    for (int i = 1; i < N; i++)
        for (int j = 1; j < N; j++) {
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            cnt += (pre[i][j] == k);
        }
    cout << cnt;
}

