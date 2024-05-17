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

const int N = 1e6 + 7, M = 19, oo = 1e9 + 7;

int q, dp[2][M][M], cnt[M];
string s[2], t, x;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
#ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> s[0] >> s[1] >> q;
    for (int i = 0; i < 2; i++) {
        memset(cnt, 0, sizeof cnt);
        for (int j = 0; j < sz(s[i]); j++) {
            for (int k = 0; k < M; k++) 
                dp[i][s[i][j] - 'a'][k] += cnt[k];
            cnt[s[i][j] - 'a']++;
        }
    }
    while (q--) {
        cin >> x;

        bool ok = 1;
        for (int i = 0; i < sz(x); i++)
            for (int j = 0; j < sz(x); j++)
                if (dp[0][x[i] - 'a'][x[j] - 'a'] != dp[1][x[i] - 'a'][x[j] - 'a']) {
                    ok = 0;
                    break;
                }
        if (!ok) printf("N"); else printf("Y");
    }
}