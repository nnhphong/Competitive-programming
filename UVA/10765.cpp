#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e4;
const int oo = (1 << 31) - 1;

int cnt = 0, n, m;
vector<int> a[mxN+1];
int pa[mxN+1], d[mxN+1], low[mxN+1], num[mxN+1];

void dfs(int u, int p) {
  int numChild = 0;
  low[u] = num[u] = cnt++;
  for(int v : a[u])
    if (num[v] == -1) {
      dfs(v, u);
      numChild++;

      if (low[v] >= num[u])
          d[u] = (u == p) ? numChild - 1 : d[u] + 1;
      low[u] = min(low[u], low[v]);
    } else if (v != p) low[u] = min(low[u], num[v]);
}

bool cmp(int i, int j) {
  return (d[i] > d[j]) || (d[i] == d[j] && i < j);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  #ifndef ONLINE_JUDGE
  freopen("10765.inp", "r", stdin);
  freopen("10765.out", "w", stdout);
  #endif // ONLINE_JUDGE

  while (cin >> n >> m && n != 0 && m != 0) {
    for (int i = 0; i < mxN+1; i++) a[i].clear();
    memset(low, 0, sizeof low);
    memset(num, -1, sizeof num);
    memset(d, 0, sizeof d);
    cnt = 0;

    int u, v;
    while (cin >> u >> v && u != -1 && v != -1) {
      a[u].push_back(v);
      a[v].push_back(u);
    }

    for (int u = 0; u < n; u++)
      if (num[u] == -1) dfs(u, u);
    int id[n];
    for (int i = 0; i < n; i++)
      id[i] = i;

    sort(id, id+n, cmp);
    for (int i = 0; i < m; i++)
      cout << id[i] << " " << d[id[i]] + 1 << endl;
    cout << endl;
  }
}
