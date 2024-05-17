#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll LIMIT = 4294967295;

ll reverse(ll n) {
	ll x = 0, t = n;
	while (t > 0) {
		x = x * 10 + t % 10;
		t /= 10;
	}
	return x;
}

int main() {
	fastIO;
	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif

	int tc; cin >> tc;
	while (tc--) {
		ll n; cin >> n;
		int iter = 0;
		while (n != reverse(n)) {
			n += reverse(n);
			++iter;
		}
		cout << iter << " " << n << endl;
	}
}