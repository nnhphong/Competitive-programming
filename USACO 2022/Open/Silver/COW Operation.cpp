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

const int N = 1e6 + 7, oo = 1e9 + 7;

int q, l, r, o[N], w[N], c[N];
string s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("test.inp", "r", stdin);
//     freopen("test.out", "w", stdout);
// #endif
    cin >> s >> q; s = ' ' + s;
    for (int i = 1; i < sz(s); i++) {
        c[i] = c[i - 1] + (s[i] == 'C');
        o[i] = o[i - 1] + (s[i] == 'O');
        w[i] = w[i - 1] + (s[i] == 'W');
        // ow[i] = ow[i - 1] + ((s[i] == 'W' && s[i - 1] == 'O') || (s[i] == 'O' && s[i - 1] == 'W'));
    }
    while (q--) {
        cin >> l >> r;
        int C = c[r] - c[l - 1], W = w[r] - w[l - 1], O = o[r] - o[l - 1];
        int ttlC = C + min(O, W);
        int others = max(O - min(O, W), W - min(O, W));
        // if (l == 2 && r== 3) printf("%d %d\n", ttlC, others);
        if ((ttlC & 1) && !(others & 1)) printf("Y"); else printf("N");
    }
}
