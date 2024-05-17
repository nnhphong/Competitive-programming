#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
typedef pair<ll, ll> ii;

template <class T>
bool minimize(T &a, const T &b) {
    if(a > b) {a = b; return 1;}
    return 0;
}
template <class T>
bool maximize(T &a, const T &b) {
    if(a < b) {a = b; return 1;}
    return 0;
}

const int N = 1e5 + 7;

int n, a[N], len[N], child[N];
ll dp[N], ans[N];
vector<int> adj[N];

void dfs(int u, int par) {
    bool isLeaf = 1;
    for (int v: adj[u]) if (v != par) {
        dfs(v, u); isLeaf = 0;
        dp[u] += dp[v];
        child[u] += child[v];
    }
    if (isLeaf) child[u] = 1, dp[u] = len[u]; 
    else if (u != 1) dp[u] += (len[u] + 1) * child[u];
}
void reroot(int u, int par) {
    for (int v: adj[u]) if (v != par) {
        ans[v] = dp[v] + (ans[u] - dp[v]) - (len[v] + 1) * child[v] + 3 * (child[u] - child[v]);
        child[u] -= child[v]; child[v] += child[u];
        reroot(v, u);
        child[v] -= child[u]; child[u] += child[v];
    }
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("dirtraverse.in", "r", stdin),
    freopen("dirtraverse.out", "w", stdout);

    cin >> n; string s;
    for (int i = 1, k; i <= n; i++) {
        cin >> s >> k; len[i] = s.size();
        for (int j = 1, x; j <= k; j++) {
            cin >> x;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
    }

    dfs(1, -1); ans[1] = dp[1]; reroot(1, -1);
    cout << *min_element(ans + 1, ans + n + 1);
}        