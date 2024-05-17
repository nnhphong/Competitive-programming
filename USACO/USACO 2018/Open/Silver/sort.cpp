#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;
typedef pair<ll, ll> ii;

const int N = 1e5 + 7;

int n;
vector<ii> a;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        a.push_back({x, i});
    }

    sort(a.begin(), a.end());

    ll res = 0;
    for (int i = 0; i < n; i++) res = max(res, a[i].se - i);
    cout << res;
}