#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
using ull = unsigned long long;
 
const int N = 1e5 + 7;

int n, top, placed, pos[N];
vector<int> st[N];

int main() {
// #ifndef ONLINE_JUDGE
	freopen("dishes.in", "r", stdin);
	freopen("dishes.out", "w", stdout);
// #endif
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		if (x < placed) {
			printf("%d", i - 1); return 0;
		}
		for (int j = x; j > 0 && !pos[j]; j--) pos[j] = x;
		while (st[pos[x]].size() && st[pos[x]].back() < x) {
			placed = st[pos[x]].back();
			st[pos[x]].pop_back();
		}
		st[pos[x]].push_back(x);
	}
	printf("%d", n);
}