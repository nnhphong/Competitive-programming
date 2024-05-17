#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct rats {
  int x, y, num;
};

int tab[1026][1026], dp[1026][1026];

void solve() {
  int d, n; cin >> d >> n;
  rats a[n];
  memset(tab, 0, sizeof(tab));
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i< n; i++) {
    cin >> a[i].x >> a[i].y >> a[i].num;
    tab[a[i].x][a[i].y] = a[i].num;
  }

  int ans = 0;
  for (int k = 0; k < n; k++) {
    int x = a[k].x;
    int y = a[k].y;
    for (int i = x - d; i <= x + d; i++)
      for (int j = y - d; j <= y + d; j++)
        if (i >= 0 && i <= 1025 && j >= 0 && j <= 1025) dp[i][j] += tab[x][y];
  }

  int mx = 0, px = 0, py = 0;
  for (int i = 0; i <= 1025; i++)
    for (int j = 0; j <= 1025; j++)
      if (dp[i][j] > mx) {
        mx = dp[i][j];
        px = i;
        py = j;
      }
  cout << px << " " << py << " " << mx << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  #ifndef ONLINE_JUDGE
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  #endif // ONLINE_JUDGE

  int tc; cin >> tc;
  while (tc--) solve();
}
