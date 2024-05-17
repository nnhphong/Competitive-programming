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

const int N = 2e3 + 7, MOD = 1e9 + 7;	

int n, dp[N][N][2];
char a[N], b[N];
void upd(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

void solve() {
	cin >> n; string a, b;
	for (int i = 1; i <= n; i++) {
		char c; cin >> c;
		if (c == '0') a.clear();
		if (c == '1') continue;
		if (c != '+') c = '*';
		a += c;
	}

	for (int i = 1; i <= n; i++) {
		char c; cin >> c;
		if (c == '0') b.clear();
		if (c == '1') continue;
		if (c != '+') c = '*';
		b += c;
	}
		
	int m1 = a.size(), m2 = b.size();	
	memset(dp, 0, sizeof dp);
	dp[0][0][0] = 1;
	for (int i = 0; i <= m1; i++) 
		for (int j = 0; j <= m2; j++)
			for (int k: {0, 1}) {
				upd(dp[i][j + 1][1], dp[i][j][k]);
				if (k == 0 || (j > 0 && b[j - 1] != a[i]))
					upd(dp[i + 1][j][0], dp[i][j][k]);
			}
	upd(dp[m1][m2][0], dp[m1][m2][1]);
	cout << dp[m1][m2][0] << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	if (fopen("test.inp", "r"))
		freopen("test.inp", "r", stdin);
	int t; cin >> t;
	while (t--) solve();
}
