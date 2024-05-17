#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

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

int n, k, d[N][2], deg[N], done[N];
vector<int> adj[N];
queue<int> q;
void bfs(int i) {
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: adj[u]) if (!done[v]) {
            q.push(v); done[v] = 1; 
            d[v][i] = d[u][i] + 1;
        }
    }
}

int dfs(int u) {
    done[u] = 1;
    if (d[u][0] >= d[u][1]) return 1;
    int res = 0;
    for (int v: adj[u]) if (!done[v]) {
        res += dfs(v);
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("atlarge.in", "r", stdin),
    freopen("atlarge.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++deg[v], ++deg[u];
    }
    q.push(k); done[k] = 1, bfs(0);
    while (q.size()) q.pop();
    
    memset(done, 0, sizeof done);
    for (int i = 1; i <= n; i++)
        if (deg[i] == 1) q.push(i), done[i] = 1;
    bfs(1); memset(done, 0, sizeof done); 
    cout << dfs(k);
}
