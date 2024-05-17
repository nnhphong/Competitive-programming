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

const int N = 1e5 + 7;

int n, m, k, pnew[N], pold[N], p[N], tmp[N], res[N];
bool done[N];

int lcm(int x, int y) {
    return 1ll * x * y / __gcd(x, y);
}

signed main() {
    fastIO;
    if (fopen("swap.in", "r")) {
        freopen("swap.in", "r", stdin);
        freopen("swap.out", "w", stdout);
    }
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) p[i] = pnew[i] = pold[i] = tmp[i] = i;
    for (int i = 1, l, r; i <= m; i++) {
        cin >> l >> r;
        for (int j = l; j <= l + (r - l) / 2; j++) swap(tmp[l + r - j], tmp[j]);
    }

    for (int i = 1; i <= n; i++) p[tmp[i]] = i;

    int len = -1;
    for (int i = 1; i <= n; i++) if (!done[i]) {
        int cur = 0;
        vector<int> cyc;
        for (int j = i; !done[j]; j = p[j], cur++) {
            done[j] = 1;
            cyc.pb(j);
        }

        reverse(all(cyc));
        int j = i;
        for (int t = 0; t <= k % cur; t++) {
            if (t == k % cur) {
                res[j] = cyc.back();
                cyc.pop_back();
            }
            j = p[j];
            if (j == i) break;
        }
        for (; !cyc.empty(); j = p[j]) {
            res[j] = cyc.back();
            cyc.pop_back();
        }
        len = (len == -1 ? cur : lcm(cur, len));
    }
    for (int i = 1; i <= n; i++) cout << res[i] << '\n';
}


