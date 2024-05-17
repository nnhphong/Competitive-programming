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

const int N = 20 + 7, M = 101, oo = 1e9 + 7, MOD = 1e9 + 7;

struct Item {
    int h, w, s;
    bool operator<(const Item &other) {
        if (other.s != s) return s > other.s;
        if (other.w != w) return w < other.w;
        return h > other.h;
    }
} items[N];

int n, H;
ll f[1 << 20];
vector<int> pos[1 << 20];
bool good[1 << 20];

signed main() {
    fastIO;
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
    cin >> n >> H;
    for (int i = 0, h, w, s; i < n; i++) {
        cin >> h >> w >> s;
        items[i] = {h, w, s};
    }
    sort(items, items + n);
    for (int i = 0; i < (1 << n); i++) {
        ll sum = 0;
        for (int j = 0; j < n; j++) if (getBit(i, j))
            pos[i].pb(j), sum += items[j].h;
        good[i] = (sum >= H);
    }

    ll ans = -oo; f[0] = oo;
    for (int i = 0; i < (1 << n); i++) {
        for (int j: pos[i]) {
            maximize(f[i], min(max(0ll, f[i ^ MASK(j)] - items[j].w), 1ll * items[j].s));
        }
        if (good[i]) maximize(ans, f[i]);
    }
    (ans <= 0 ? cout << "Mark is too tall" : cout << ans);
}
