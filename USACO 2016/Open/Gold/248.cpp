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
 
int n, a[N], dp[N][N];
 
int DP(int l, int r) {
	if (l > r) return 0;
	if (l == r) return a[l];
	if (dp[l][r] != -1) return dp[l][r];

	dp[l][r] = 0;
	for (int k = l; k < r; k++) if (DP(l, k) == DP(k + 1, r)) maximize(dp[l][r], DP(l, k) + 1);
	return dp[l][r];
}

int main() {
	freopen("248.in", "r", stdin);
	freopen("248.out", "w", stdout);

	memset(dp, -1, sizeof dp);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	int ret = 0;
	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++)
		ret = max(ret, DP(i, j));
	printf("%d", ret);
}