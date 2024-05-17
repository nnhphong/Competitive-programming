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

const int N = 2e5 + 7, oo = 1e9 + 7, MOD = 1e9 + 7;

int n, p[N], pos[N], prv[N], hilo[N];

signed main() {
    fastIO;
//#ifndef ONLINE_JUDGE
//    freopen("hilo.inp", "r", stdin);
//    freopen("hilo.out", "w", stdout);
//#endif
    cin >> n; stack<int> st; int ans = 0;
    for (int i = 1, x; i <= n; i++) cin >> p[i], pos[p[i]] = i;

    // Claim: if i is LO for some x, then HI in that pair must be at position k such that k < i, p[k] > p[i] and p[k] is minimal
    // calculate prv[i] if i is LO for some x
    // stack is sorted by decreasing pos and decreasing value of perm
    st.push(0);
    for (int i = n; i >= 1; i--) {
        while (st.top() > pos[i]) st.pop();
        prv[pos[i]] = st.top(); st.push(pos[i]);
//        cerr << i << ' ' << prv[pos[i]] << endl;
    }
    while (sz(st) != 1) st.pop();

    cout << 0 << '\n'; // x = 0, there's always no HILO
    for (int x = 1; x <= n; x++) { // for each x changes
        /**
            So now, x is LO <-> find index j (j < pos[x] and j is LO)
            since now x is LO. So for all index k (k > pos[x] and p[k] < x), remove ans from it
        **/
        while (st.top() > pos[x]) {
            ans -= hilo[st.top()];
            st.pop();
        }
        hilo[pos[x]] = (prv[pos[x]] && (st.top() == 0 || prv[st.top()] != prv[pos[x]]));
        ans += hilo[pos[x]]; st.push(pos[x]);
        cout << ans << '\n';
    }
}
