#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;

#define task "milkorder"
#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i, l, r) for( ll i = (l) ; i < (r) ; i++ )
#define forb(i, r, l) for( ll i = (r) ; i >= (l) ; i-- )
#define numBit(x) (__builtin_popcountll(1ll * (x)))
#define getBit(x, i) ((x) >> (i) & 1)
#define sz(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second
#define ar array
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(x) cerr << #x << " = " << x << '\n';

const int N = 1e5 + 7;

int n, m, in[N];
vi qry[N], adj[N], res;
stack<int> st;

bool good(int mid) {
    vi ans;
    priority_queue<int, vi, greater<int>> q;
    memset(in, 0, sizeof in);
    forw(i, 1, n + 1) adj[i].clear();

    forw(i, 0, mid) forw (j, 0, sz(qry[i]) - 1)
        adj[qry[i][j]].pb(qry[i][j + 1]), in[qry[i][j + 1]]++;

    forw(i, 1, n + 1) if (!in[i]) q.push(i);
    while (sz(q)) {
        int u = q.top(); q.pop();
        ans.pb(u);
        for (int v: adj[u]) if (--in[v] == 0)
            q.push(v);
    }
    if (sz(ans) == n) res = ans;
    return (sz(ans) == n);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen(task".in", "r", stdin);
    freopen(task".out", "w", stdout);
#endif
//    fastIO;
    scanf("%d%d", &n, &m);
    forw(i, 0, m) {
        int sz; scanf("%d", &sz); qry[i].resize(sz);
        forw(j, 0, sz) scanf("%d", &qry[i][j]);
    }

    int l = 0, r = m - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (good(mid)) l = mid + 1; else r = mid - 1;
    }

    forw(i, 0, sz(res)) {
        printf("%d", res[i]);
        if (i ^ sz(res) - 1) printf(" ");
    }
}
// If you feel you are too weak, then be strong
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \|     |// '.
//                 / \|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//
