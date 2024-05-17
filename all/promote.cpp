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

const int N = 1e6 + 7, M = 130, oo = 1e9 + 7;

int a[5], b[5];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
//#ifndef ONLINE_JUDGE
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
//#endif
    for (int i = 0; i < 4; i++) cin >> a[i] >> b[i];
    int sum = 0;
    for (int i = 3; i > 0; i--) {
        sum += b[i] - a[i];
        cout << sum << '\n';
    }
}

