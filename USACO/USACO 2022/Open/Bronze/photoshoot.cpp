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

int n;
string s, tmp, ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
//#ifndef ONLINE_JUDGE
//    freopen("photoshoot.inp", "r", stdin);
//    freopen("photoshoot.out", "w", stdout);
//#endif
    cin >> n >> s;
    for (int i = 0; i < sz(s); i += 2) {
        if (s[i] == s[i + 1]) continue;
        if (s[i] == 'G' && s[i + 1] == 'H') tmp += "A";
        else tmp += "B";
    }

    for (int i = 0; i < sz(tmp); i++)
        if (!sz(ans) || tmp[i] != ans.back()) ans += tmp[i];
    while (ans.back() == 'B') ans.pop_back();
    printf("%d", sz(ans));
}
