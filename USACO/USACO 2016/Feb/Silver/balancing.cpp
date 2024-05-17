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

const int N = 6e3 + 7, oo = 1e9 + 7;

int n, B, a[N], psa[N][N], ans = oo;
vector<array<int, 2>> vec;
vector<int> comp;

int get(int i1, int j1, int i2, int j2) {
    return psa[i2][j2] - psa[i1 - 1][j2] - psa[i2][j1 - 1] + psa[i1 - 1][j1 - 1];
}

signed main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1, x, y; i <= n; i++) {
        scanf("%d%d", &x, &y); vec.pb({x, y});
        for (int j = -1; j <= 1; j++) comp.pb(x + j), comp.pb(y + j);
    }
    sort(all(comp)); comp.resize(unique(all(comp)) - comp.begin());
    for (auto &[x, y]: vec) {
        x = lower_bound(all(comp), x) - comp.begin();
        y = lower_bound(all(comp), y) - comp.begin();
        if (!(x & 1)) x++; if (!(y & 1)) y++;
        psa[x][y]++;
    }
    for (int i = 1; i < N; i++) for (int j = 1; j < N; j++)
        psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
    for (int i = 2; i < N; i += 2) for (int j = 2; j < N; j += 2) {
        array<int, 4> arr;
        arr[0] = get(1, 1, i, j), arr[1] = get(1, j, i, N - 1);
        arr[2] = get(i, 1, N - 1, j), arr[3] = get(i, j, N - 1, N - 1);
        minimize(ans, *max_element(all(arr)));
    }
    cout << ans;
}

