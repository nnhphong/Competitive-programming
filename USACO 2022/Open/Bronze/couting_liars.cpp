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

const int N = 2e5 + 7, INF = 1e9 + 7;

int n, p[N];
char ch[N];
std::vector<int> v;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("test.inp", "r", stdin);
// 	freopen("test.out", "w", stdout);
// #endif
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ch[i] >> p[i];
		v.pb(p[i]);
	}

	sort(all(v)), v.resize(unique(all(v)) - v.begin());
	for (int i = 1; i <= n; i++) p[i] = lower_bound(all(v), p[i]) - v.begin() + 1;

	int mx = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) 
			if (ch[j] == 'G') cnt += (i >= p[j]);
			else cnt += (i <= p[j]);
		maximize(mx, cnt);
	}
	cout << n - mx;
}