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

int a, b, c;

int main() {
	// freopen("test.inp", "r", stdin);
	// freopen("test.out", "w", stdout);
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);

	scanf("%d%d%d", &a, &b, &c);
	if (abs(a - b) > 2 && abs(b - c) > 2) {
		printf("2\n%d", max(abs(a - b), abs(b - c)) - 1);
	}
	else if (abs(a - b) == 2 && abs(b - c) > 2) {
		printf("1\n%d", abs(b - c) - 1);
	} else if (abs(a - b) > 2 && abs(b - c) == 2) {
		printf("1\n%d", abs(a - b) - 1);
	} else if (abs(a - b) > 1 && abs(b - c) == 1) {
		printf("2\n%d", abs(a - b) - 1);
	} else if (abs(b - c) > 1 && abs(a - b) == 1) {
		printf("2\n%d", abs(b - c) - 1);
	} else printf("0\n0");
}