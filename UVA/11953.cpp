#include <bits/stdc++.h>

using namespace std;

const int mxN = 100;
const int dx[8] = {-1, 0, 1, 0};
const int dy[8] = {0, 1, 0, -1};

int n;
char grid[mxN+1][mxN+1];

bool safe(int i, int j) {
  return (i >= 0 && i < n && j >= 0 && j < n);
}

void dfs(int x, int y) {
  grid[x][y] = '.';
  for (int i = 0; i < 8; i++) {
    int vi = x + dy[i];
    int vj = y + dx[i];
    if (safe(vi, vj) && grid[vi][vj] != '.') dfs(vi, vj);
  }
}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  #endif
  int tc; cin >> tc;
  int cs = 1;
  while (tc--) {
    cin >> n;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) cin >> grid[i][j];

    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j] == 'x') {
          ++ans; dfs(i, j);
        }
    cout << "Case " << cs++ << ": " << ans << endl;
  }
}
