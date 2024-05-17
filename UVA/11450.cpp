#include <bits/stdc++.h>

using namespace std;

void solve() {
  int m, n;
  cin >> m >> n;

  int a[25][25];
  for (int i = 0; i < n; i++) {
    cin >> a[i][0];
    for (int j = 1; j <= a[i][0]; j++) cin >> a[i][j];
  }

  bool dp[n+1][m+1];
  memset(dp, false, sizeof(dp));

  for (int i = 1; i <= a[0][0]; i++) {
    if (m >= a[0][i]) dp[0][m-a[0][i]] = true;
  }

  for (int i = 1; i < n; i++)
    for (int mm = 0; mm <= m; mm++) {
      if (!dp[i-1][mm]) continue;
      for (int j = 1; j <= a[i][0]; j++)
        if (mm >= a[i][j]) dp[i][mm - a[i][j]] = true;
    }

  int ans = 0;
  for (; ans <= m && !dp[n-1][ans]; ++ans);

  if (ans <= m) cout << m - ans << endl;
  else cout << "no solution" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  #ifndef ONLINE_JUDGE
  freopen("11450.inp", "r", stdin);
  freopen("11450.out", "w", stdout);
  #endif // ONLINE_JUDGE

  int tc; cin >> tc;
  while (tc--) solve();
}
