#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;
typedef pair<ll, ll> ii;

const int N = 1e5 + 7;

int n;
ll T[N];
vector<ii> val;

void upd(int pos, ll val) {
    for (; pos <= n; pos += pos & -pos) 
        T[pos] += val;
}

void upd_range(int l, int r, ll val) {
    upd(l, val); upd(r + 1, -val);
}

ll get(int pos) {
    ll res = 0;
    for (; pos; pos -= pos & -pos)
        res += T[pos];
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        val.push_back({x, i});
    }

    sort(val.begin(), val.end());
    for (int i = 0; i < n; i++)
        upd_range(min(val[i].se, 1ll * i + 1), max(val[i].se, 1ll * i + 1), 1);

    ll res = 0;
    for (int i = 1; i <= n; i++) res = max(res, get(i));
    cout << max(1ll, res / 2);
}       