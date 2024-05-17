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

const int N = 1e2 + 7, oo = 1e9 + 7;

int n, m, a[N], dp[N];
bool vis[N];
vector<int> adj[N];

bool canMake(int u) {
    if (a[u]) {
        --a[u];
        return 1;
    } else if (!sz(adj[u]) && !a[u]) return 0;
    for (int v: adj[u]) if (!canMake(v))
        return 0;
    return 1;
}

int main() {
//#ifndef ONLINE_JUDGE
// 	freopen("test.inp", "r", stdin);
// 	freopen("test.out", "w", stdout);
//#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	scanf("%d", &m);
	for (int i = 0, l, x; i < m; i++) {
		scanf("%d%d", &l, &x);
		for (int j = 0, t; j < x; j++) {
			scanf("%d", &t);
			adj[l].pb(t);
		}
	}

    int ans = 0;
    while (canMake(n)) ++ans;
    printf("%d", ans);
}
