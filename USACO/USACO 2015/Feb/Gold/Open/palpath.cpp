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

const int N = 5e2 + 3, MOD = 1e9 + 7;

int n;
ll dp[N][N], prv[N][N];
char s[N][N];

void upd(ll &x, ll y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

signed main() {
    fastIO;
    if (fopen("test.inp", "r")) {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
	if (fopen("palpath.in", "r")) {
		freopen("palpath.in", "r", stdin);
		freopen("palpath.out", "w", stdout);
	}
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			cin >> s[i][j];
	
	for (int i = 1; i <= n; i++) prv[i][i] = 1;
	for (int i = n - 1; i >= 1; i--) {
		memset(dp, 0, sizeof dp);
		for (int r1 = i, c1 = 1; r1 >= 1; r1--, c1++) {
			for (int r2 = n, c2 = n - i + 1; r2 >= n - i + 1; r2--, c2++) {
				if (s[r1][c1] == s[r2][c2]) {
					upd(dp[r1][r2], prv[r1][r2]);
					upd(dp[r1][r2], prv[r1 + 1][r2]);
					upd(dp[r1][r2], prv[r1][r2 - 1]);
					upd(dp[r1][r2], prv[r1 + 1][r2 - 1]);
				}		
			}
		 }
		swap(dp, prv);
	}	
	cout << prv[1][n];
}

