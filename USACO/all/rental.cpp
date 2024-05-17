#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using ii = pair<ll, ll>;

#define fi first
#define se second

const int N = 1e5 + 7;

int n, m, d;
ll s[N], t[N], x[N], sum[N];
ll res;
ii p[N], pref[N];

int L;
ll sell(int cost) {
	int l = L + 1, r = m; 
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (pref[mid].fi < cost) l = mid + 1;
		else r = mid - 1; 	
	}
	ll ret = (sum[r] - sum[L - 1]) + (cost - pref[r].fi + pref[L - 1].fi) * p[r + 1].se;
	L = r + 1;
	return ret;
}

bool cmp(ii x, ii y) {
	return (x.se == y.se ? x.fi > y.fi : x.se > y.se);
}

int main() {
// #ifndef ONLINE_JUDGE
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
// #endif
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 1; i <= n; i++) scanf("%lld", &s[i]);
    for (int i = 1; i <= m; i++) scanf("%lld%lld", &p[i].fi, &p[i].se);
    for (int i = 1; i <= d; i++) scanf("%lld", &t[i]);

    sort(s + 1, s + n + 1, greater<ll>()); 
	sort(t + 1, t + d + 1, greater<ll>()); 
	sort(p + 1, p + m + 1, cmp);

	for (int i = 1; i <= n; i++) s[i] += s[i - 1];
	for (int i = 1; i <= m; i++) {
		pref[i].fi = pref[i - 1].fi + p[i].fi;
		pref[i].se = pref[i - 1].se + p[i].se;
		sum[i] = sum[i - 1] + p[i].fi * p[i].se;
	}
	for (int i = 1; i <= d; i++) t[i] += t[i - 1];

	ll sold, hire;
   	for (int i = 0; i <= n + 1; i++) {
   		L = 0; sold = sell(s[i]);
   		hire = t[min(n - i, d)];
   		res = max(res, sold + hire);
	}
    printf("%lld", res);
}

