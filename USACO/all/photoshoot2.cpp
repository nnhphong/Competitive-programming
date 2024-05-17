#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using ii = pair<int, int>;

#define fi first
#define se second
#define pb push_back
#define numBit(x) (__builtin_popcountll(1ll * (x)))
#define getBit(x, i) ((x) >> (i) & 1)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

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

const int N = 5e5 + 7, oo = 1e9 + 7;

int n, a[N], b[N], pos[N];
ii val[N];

int main() {
//#ifndef ONLINE_JUDGE
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
//#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]), pos[b[i]] = i;

    int cnt = 0, mx = 0;
    for (int j = 1; j <= n; j++) {
        cnt += (mx > pos[a[j]]);
        maximize(mx, pos[a[j]]);
    }
    printf("%d", cnt);
}

