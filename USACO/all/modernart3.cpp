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

const int N = 5e2 + 7, INF = 1e9 + 7;

int n, dp[N][N], a[N];
bool avail[N][N];

int DP(int l, int r) {
	if (l > r) return 0;
	if (l == r) return 1;
	if (l + 1 == r) return (a[l] != a[r] ? 2 : 1);
	if (avail[l][r]) return dp[l][r];
	avail[l][r] = 1, dp[l][r] = INF;

	for (int k = l; k < r; k++) {
		if (a[l] == a[r]) minimize(dp[l][r], DP(l, k) + DP(k + 1, r) - 1);
		else minimize(dp[l][r], DP(l, k) + DP(k + 1, r));
	}
	return dp[l][r];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	printf("%d", DP(1, n));
}