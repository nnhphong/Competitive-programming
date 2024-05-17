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

const int N = 3e5 + 1, oo = 1e9 + 7;

int n, a[N];

signed main() {
    fastIO;
//#ifndef ONLINE_JUDGE
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
//#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    stack<int> st; st.push(0); ll ans = 0;
    for (int i = 1; i <= n; i++) {
        while (sz(st) > 1 && a[i] >= a[st.top()]) ans += i - st.top() + 1, st.pop();
        if (st.top()) ans += i - st.top() + 1; st.push(i);
    }
    cout << ans;
}

