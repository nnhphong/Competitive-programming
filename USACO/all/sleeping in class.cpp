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

const int N = 1e6 + 7, oo = 1e9 + 7;

int n, a[N];

signed main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n); ll sum = 0, ans = oo;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sum += a[i];
        if (!sum) { cout << 0 << '\n'; continue; }
        for (int i = N - 1; i >= 1; i--) if (sum % i == 0) {
            ll cur = 0, cnt = 0; bool ok = 1;
            for (int j = 1; j <= n; j++) {
                cur += a[j];
                if (cur > i) { ok = 0; break; }
                if (cur == i) cur = 0; else cnt++;
            }
            if (ok) minimize(ans, cnt);
        }
        cout << ans << '\n';
    }
}

