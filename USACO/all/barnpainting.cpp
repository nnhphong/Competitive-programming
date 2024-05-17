#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using ii = pair<int, int>;

#define fi first
#define se second
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

const int N = 1e5 + 7, INF = 1e9 + 7, MOD = 1e9 + 7;

int n, k, color[N], dp[N][4];
std::vector<int> adj[N];

int add(int x, int y) {
	x += y; if (x >= MOD) x -= MOD;
	return x;
}

int mul(int x, int y) {
	return 1ll * x * y % MOD;
}

void DP(int u, int par, int pre_color) {
	if (!pre_color) dp[u][1] = dp[u][2] = dp[u][3] = 1;
	else for (int j = 1; j <= 3; j++) if (j != pre_color) dp[u][j] = 1;

	for (int v: adj[u]) if (v ^ par) {
		DP(v, u, color[v]);

		vector<int> tmp;
		int x = 0;
		for (int j = 1; j <= 3; j++) if (j != color[v]) tmp.push_back(dp[v][j]);
		for (auto it: tmp) x = add(x, it);

		for (int j = 1; j <= 3; j++) if (j != color[v]) {
			dp[u][j] = mul(dp[u][j], x);
		}
	}
}

int main() {
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(color, -1, sizeof color);
	for (int i = 0, b, c; i < k; i++) {
		scanf("%d%d", &b, &c);
		color[b] = c;
	}

	DP(1, 0, 0);
	printf("%lld", dp[1][1] + dp[1][2] + dp[1][3]);
}