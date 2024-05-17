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

const int N = 10 + 7, INF = 1e9 + 7;

int n, a[N][N];
char ch[N];
bool color[N], ans[N];

void bfs(int c) {
	ii top = ii(-INF, -INF), bot = ii(INF, INF);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			if (a[i][j] == c) {
				minimize(bot.fi, i), minimize(bot.se, j);
				maximize(top.fi, i), maximize(top.se, j);
			}
	for (int i = bot.fi; i <= top.fi; i++)
		for (int j = bot.se; j <= top.se; j++)
			if (a[i][j] != c) ans[a[i][j]] = 0;
}

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("test.inp", "r", stdin);
// 	freopen("test.out", "w", stdout);
// #endif
	// freopen("art.in", "r", stdin);
	// freopen("art.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", &ch);
		for (int j = 0; j < strlen(ch); j++) {
			a[i][j + 1] = ch[j] - '0';
			color[a[i][j + 1]] = ans[a[i][j + 1]] = 1;
		}
	}

	for (int i = 1; i < 10; i++) 
		if (color[i]) bfs(i);

	int cnt = 0;
	for (int i = 1; i < 10; i++) cnt += ans[i];
	printf("%d", cnt);
}