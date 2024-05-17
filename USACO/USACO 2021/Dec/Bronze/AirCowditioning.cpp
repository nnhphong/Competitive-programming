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

const int N = 1e5 + 7, INF = 1e9 + 7;

int n, p[N], t[N], a[N];

int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("test.inp", "r", stdin);
// 	freopen("test.out", "w", stdout);
// #endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &t[i]);

	for (int i = 1; i <= n; i++) a[i] = p[i] - t[i];

	int ans = 0;
	for (int i = 0; i <= n; i++) ans += abs(a[i + 1] - a[i]);
	printf("%d", ans / 2);
}