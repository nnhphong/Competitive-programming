#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  #ifndef ONLINE_JUDGE
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  #endif
  int n, m;
  while (cin >> n >> m && n != 0 && m != 0) {
    int a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);

    int indx = 0, mn = 0;
    bool ok = true, visit[m+1];
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < n; i++) {
      while (indx < m && b[indx] < a[i]) ++indx;
      if (visit[indx] || b[indx] < a[i] || b[m-1] < a[i]) ok = false;
      visit[indx] = true;
      mn += b[indx++];
    }
    if (ok && n <= m) cout << mn << endl;
    else cout << "Loowater is doomed!" << endl;
  }
}
