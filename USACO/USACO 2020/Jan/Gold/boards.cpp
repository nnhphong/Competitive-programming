#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;
typedef pair<ll, ll> ii;

const int N = 5e5 + 7;
int n, p;
ll bit[N], b[N], dp[N];
vector<int> val;
vector<array<int, 4>> event;

void upd(int i, ll v){
    b[i] = v;
    for (; i < N; i += i & -i) bit[i] = min(bit[i], v);
}
ll get(int i) {
    ll res = 1e18;
    for (; i; i -= i & -i) res = min(res, bit[i]);
    return res;
}
int main() {
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
    scanf("%d %d", &n, &p);
    int x1, y1, x2, y2;
    for (int i = 1; i <= p; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        event.push_back({x1, y1, i, 1});
        event.push_back({x2, y2, i, -1});
        val.push_back(y1);
        val.push_back(y2);
    }

    sort(val.begin(), val.end());
    sort(event.begin(), event.end());

    ll res = 1e18;
    for (auto [x, y, id, t]: event) {
        int Y = lower_bound(val.begin(), val.end(), y) - val.begin() + 1;
        if (t == 1) dp[id] = x + y + get(Y);
        else {
            upd(Y, dp[id] - x - y);
            res = min(res, dp[id] + 2 * n - x - y);
        }
    }
    printf("%lld", res);
}

