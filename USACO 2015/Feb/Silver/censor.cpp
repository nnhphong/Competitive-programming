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

const int N = 1e6 + 7, base = 131, MOD = 1e9 + 7;

string s, t;
ll pw[N], hsh[N], hsh_t;

signed main() {
    fastIO;
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);

    cin >> s >> t; pw[0] = 1; s = ' ' + s, t = ' ' + t;
    for (int i = 1; i < N; i++) pw[i] = pw[i - 1] * base % MOD;
    for (int i = 1; i < sz(t); i++) hsh_t = (hsh_t + (t[i] - 'a' + 1) * pw[i - 1]) % MOD;

    int cur = 1; vector<int> idx;
    for (int i = 1; i < sz(s); i++, cur++) {
        idx.pb(i);
        hsh[cur] = (hsh[cur - 1] + (s[i] - 'a' + 1) * pw[cur - 1]) % MOD;

        if (cur >= sz(t) - 1) {
            ll x = (hsh[cur] - hsh[cur - (sz(t) - 1)] + MOD) % MOD * pw[sz(s) - 1 - cur + 1] % MOD;
            ll y = hsh_t * pw[sz(s) - 1 - (sz(t) - 1) + 1] % MOD;
            if (x == y) {
                for (int i = 1; i < sz(t); i++) idx.pop_back();
                cur -= sz(t) - 1;
            }
        }
    }
    for (int i: idx) cout << s[i];
}


