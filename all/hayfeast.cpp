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

const int N = 1e5 + 7, INF = 1e9;

int n;
long long m, sum, ans = 1ll * INF * INF;
long long f[N], s[N];

int main() {
	freopen("hayfeast.in", "r", stdin);
	freopen("hayfeast.out", "w", stdout);
	
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d%d", &f[i], &s[i]);

	multiset<int> ms;

	int j = 1;
	for (int i = 1; i <= n; i++) {
		sum += f[i];
		ms.insert(s[i]);

		while (sum - f[j] >= m) {
			sum -= f[j];
			ms.erase(ms.find(s[j++]));
		}
		if (!ms.empty() && sum >= m) minimize(ans, *ms.rbegin());
	}
	printf("%lld", ans);
}