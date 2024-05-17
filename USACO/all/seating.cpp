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

const int N = 5e5 + 7, INF = 1e9 + 7;

struct Data {
	int left, right, val, lazy;
	Data() {}
	Data(int _left, int _right, int _val, int _lazy): left(_left), right(_right), val(_val), lazy(_lazy) {}
} T[N << 2];

int n, m, ans;

Data merge(Data x, Data y, int l, int r) {
	int mid = l + r >> 1;
	int L = mid - l + 1, R = r - mid;

	Data res;
	res.left = (x.left == L ? L + y.left : x.left);
	res.right = (y.right == R ? R + x.right : y.right);
	res.val = max(x.val, max(y.val, x.right + y.left));
	res.lazy = -1;
	return res;
}

void build(int id, int l, int r) {
	if (l == r) {
		T[id] = Data(1, 1, 1, -1);
		return;
	}

	int mid = l + r >> 1, k = id << 1;
	build(k, l, mid);
	build(k | 1, mid + 1, r);
	T[id] = merge(T[k], T[k | 1], l, r);
}

// lazy = 1 <=> Passenger arrive
// lazy = 0 <=> Passenger leave
void down(int id, int l, int r) {
	if (T[id].lazy == -1) return;
	int mid = l + r >> 1, k = id << 1;

	if (T[id].lazy) {
		T[k] = T[k | 1] = Data(0, 0, 0, 1);
	} else {
		int L = mid - l + 1, R = r - mid;
		T[k] = Data(L, L, L, 0);
		T[k | 1] = Data(R, R, R, 0);
	}
	T[id].lazy = -1;
}

/*
Value x:
	0: passenger leave
	1: update for findSeat <=> arrive
*/
void update(int id, int l, int r, int u, int v, bool x) {
	if (l > v || r < u) return;
	if (u <= l && r <= v) {
		if (x) T[id] = Data(0, 0, 0, 1);
		else {
			int tmp = r - l + 1;
			T[id] = Data(tmp, tmp, tmp, 0);
		}
		return;
	}

	int mid = l + r >> 1, k = id << 1; down(id, l, r);
	update(k, l, mid, u, v, x);
	update(k | 1, mid + 1, r, u, v, x);
	T[id] = merge(T[k], T[k | 1], l, r);
	// cerr << id << ' ' << T[id].val << endl;
}

void findSeat(int id, int l, int r, int val) {
	if (l == r) {
		update(1, 1, n, l, l, 1);
		return;
	}

	int mid = l + r >> 1, k = id << 1; down(id, l, r);
	if (T[k].val >= val) findSeat(k, l, mid, val);
	else if (T[k].right + T[k | 1].left >= val) {
		int st = mid - T[k].right + 1;
		update(1, 1, n, st, st + val - 1, 1);
	} else findSeat(k | 1, mid + 1, r, val);
}

int main() {
	freopen("seating.in", "r", stdin);
	freopen("seating.out", "w", stdout);

	scanf("%d%d", &n, &m); build(1, 1, n);
	for (int i = 1, u, v; i <= m; i++) {
		char ch;
		scanf("%s", &ch);
		if (ch == 'A') {
			scanf("%d", &u);
			if (T[1].val < u) ++ans; else findSeat(1, 1, n, u);
		} else {
			scanf("%d%d", &u, &v);
			update(1, 1, n, u, v, 0);		
		}
	}
	printf("%d", ans);
}