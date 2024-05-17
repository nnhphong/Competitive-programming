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

const int N = 1e5 + 7, oo = 1e9 + 7;

int n, a[N]; ll dp[N];
vector<int> pos[N], adj[N];

int mx = -oo, mn = oo;
ii seg1, seg2;

bool intersec(ii seg1, ii seg2) {
    return (((seg1.fi < seg2.se && seg1.se > seg2.fi) || (seg2.fi < seg1.fi && seg2.se > seg1.fi)) &&
            seg1.fi != seg2.fi && seg1.se != seg2.se);
}

signed main() {
    fastIO;
    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]].pb(i);
    for (int i = 1; i <= n; i++) if (!pos[i].empty()) {
        if (sz(pos[i]) == 1) pos[i].pb(pos[i].back());
        adj[pos[i].back()].pb(pos[i][0]);

        if (maximize(mx, pos[i][0])) seg1 = {pos[i][0], pos[i][1]};
        if (minimize(mn, pos[i][1])) seg2 = {pos[i][0], pos[i][1]};
    }

    if (intersec(seg1, seg2)) {
        cout << -1; return 0;
    }

    stack<int> st; ll ans = -2;
    for (int i = 1; i <= n; i++) if (sz(adj[i])) {
        int j = adj[i][0], cnt = -1;
        while (sz(st) && st.top() >= j) maximize(cnt, dp[st.top()]), st.pop();
        st.push(j); dp[j] = cnt + 1;
    }
    while (sz(st)) maximize(ans, dp[st.top()]), st.pop();
    cout << ans + 1;
}

