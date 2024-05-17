#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define FF first
#define SS second
#define pb push_back
#define sz(x) (int)x.size()
#define oo 1e16
typedef long long ll;
typedef pair<float, int> ii;
const int N = 40000+7, M = 5e3+1;
int n, m, k, t;

vector<int> adj[N];
ll w[3], d[N][3];
queue<int> q;

void bfs(int st) {
    int u, v;
    while(!q.empty()) {
        u = q.front(), q.pop();
        for(int i=0;i<sz(adj[u]);i++) {
            v = adj[u][i];
            if (d[v][st]>d[u][st]+w[st]) {
                d[v][st]=d[u][st]+w[st];
                q.push(v);
            }
        }
    }
}

int main() {
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);
    //fastIO;
    for(int i=0;i<3;i++) scanf("%lld", &w[i]);
    scanf("%d%d", &n, &m);int u, v;ll ans = oo;
    for(int i=1;i<=n;i++)
        d[i][0] = d[i][1] = d[i][2] = oo;
    for(int i=1;i<=m;i++) {
        scanf("%d%d", &u, &v);
        adj[u].pb(v), adj[v].pb(u);
    }
    d[1][0] = d[2][1] = 0, d[n][2] = 0;
    q.push(1), bfs(0);q.push(2), bfs(1);q.push(n), bfs(2);
    for(int i=1;i<=n;i++)
        ans = min(ans, d[i][0]+d[i][1]+d[i][2]);
    printf("%lld", ans);
    return 0;
}
