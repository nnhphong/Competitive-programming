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

const int N = 5e5 + 7, INF = 1e9 + 7;

long long n, p[N][2];
long long res;
string ch;

int bsMax(int i, int j) {
	int l = i + 2, r = n;
	while (l <= r) {
		int mid = l + r >> 1;
		if (p[mid][j] - p[i - 1][j] > 1) r = mid - 1;
		else l = mid + 1;
	}
	return r;
}

int bsMin(int i, int j) {
	int l = i + 2, r = n;
	while (l <= r) {
		int mid = l + r >> 1;
		if (p[mid][j] - p[i - 1][j] >= 1) r = mid - 1;
		else l = mid + 1;
	}
	return r + 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("test.inp", "r", stdin);
// 	freopen("test.out", "w", stdout);
// #endif
	cin >> n >> ch; ch = ' ' + ch;
	for (int i = 1; i <= n; i++) {
		p[i][0] += p[i - 1][0] + (ch[i] == 'G');
		p[i][1] += p[i - 1][1] + (ch[i] == 'H');
	}

	for (int i = 1, l, r; i <= n - 2; i++) {
		res += (bsMax(i, 1) - bsMin(i, 1) + 1) + (bsMax(i, 0) - bsMin(i, 0) + 1);
	}
	printf("%lld", res);
}