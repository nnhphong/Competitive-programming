#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ls (id << 1)
#define rs (id << 1 | 1)
#define mid ((l + r) >> 1)
typedef long long ll;
typedef pair<ll, ll> ii;

const int N = 1e6 + 7, M = 1e6;
int n, res = n;
int seg[4 * N][2];
vector<int> pts[N];

void upd(int i, int k, int v, int id = 1, int l = 1, int r = M) {
    if (l > i || r < i) return;
    if (l == r) {
        seg[id][k] += v;
        return;
    }
    upd(i, k, v, ls, l, mid);
    upd(i, k, v, rs, mid + 1, r);
    seg[id][k] = seg[ls][k] + seg[rs][k];
}
void walk(int id = 1, int l = 1, int r = M, int l1 = 0, int r1 = 0, int l2 = 0, int r2 = 0) {
    if (l == r) return;
    res = min(res, max({l1 + seg[id][0], r1 + seg[id][1], l2, r2}));
    res = min(res, max({l1, r1, l2 + seg[id][0], r2 + seg[id][1]}));

    int down = max({l1 + seg[rs][0], r1 + seg[rs][1], l2, r2});
    int up = max({l1, r1, l2 + seg[ls][0], r2 + seg[ls][1]});

    if (up >= down)
        walk(ls, l, mid, l1 + seg[rs][0], r1 + seg[rs][1], l2, r2);
    else walk(rs, mid + 1, r, l1, r1, l2 + seg[ls][0], r2 + seg[ls][1]);
}
signed main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    scanf("%d", &n); vector<int> col;
    for (int i = 1, x, y; i <= n; i++) {
        scanf("%d %d", &x, &y);
        upd(y, 1, 1);
        pts[x].push_back(y);
        col.push_back(x);
    }
    sort(col.begin(), col.end());
    col.resize(unique(col.begin(), col.end()) - col.begin());

    res = n;
    for (int i: col) {
        for (int j: pts[i]) {
            upd(j, 0, 1);
            upd(j, 1, -1);
        }
        walk();
    }
    printf("%d", res);
}
