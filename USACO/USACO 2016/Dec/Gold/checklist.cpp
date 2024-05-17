#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

template <class T>
bool minimize(T &a, const T &b) {
    if(a > b) {a = b; return 1;}
    return 0;
}
template <class T>
bool maximize(T &a, const T &b) {
    if(a < b) {a = b; return 1;}
    return 0;
}

const int N = 1e3 + 7;	

#define int long long
int n, m, dp[N][N][2];
ar<int, 2> a[N], b[N];

int dist(ar<int, 2> x, ar<int, 2> y) {
	return pow(abs(x[0] - y[0]), 2) + pow(abs(x[1] - y[1]), 2);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	if (fopen("test.inp", "r"))
		freopen("test.inp", "r", stdin);
	if (fopen("checklist.in", "r")) {
		freopen("checklist.in", "r", stdin);
		freopen("checklist.out", "w", stdout);
	}
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1];
	for (int i = 1; i <= m; i++) cin >> b[i][0] >> b[i][1];

	memset(dp, 0x3f3f3f, sizeof dp);
	if (n > 1) dp[2][0][0] = dist(a[1], a[2]);
	dp[1][1][1] = dist(a[1], b[1]);

	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++) {
			if (i < n) {
				minimize(dp[i + 1][j][0], dp[i][j][0] + dist(a[i + 1], a[i]));
			    minimize(dp[i + 1][j][0], dp[i][j][1] + dist(a[i + 1], b[j]));
			}
			if (j < m) {
				minimize(dp[i][j + 1][1], dp[i][j][0] + dist(b[j + 1], a[i]));
				if (j > 0) minimize(dp[i][j + 1][1], dp[i][j][1] + dist(b[j + 1], b[j]));
			}
		}
	cout << dp[n][m][0];
}

