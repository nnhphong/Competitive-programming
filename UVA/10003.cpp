#include <bits/stdc++.h>

using namespace std;

const int mxN = 55;
int a[mxN], dp[mxN][mxN];

int cut(int lo, int hi) {
  if (lo + 1 == hi) return 0;
  if (dp[lo][hi] != -1) return dp[lo][hi];

  int ans = 1e9;
  for (int i = lo + 1; i < hi; i++)
    ans = min(ans, cut(lo, i) + cut(i, hi) + (a[hi] - a[lo]));
  return dp[lo][hi] = ans;
}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("xego.inp", "r", stdin);
  freopen("xego.out", "w", stdout);
  #endif

  int l, n;
  while (scanf("%d %d", &l, &n) && l != 0) {
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    a[0] = 0;
    a[n+1] = l;
    memset(dp, -1, sizeof dp);
    cout << cut(0, n+1) <<'\n';
  }
}
