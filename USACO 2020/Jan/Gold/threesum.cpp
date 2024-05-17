#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
const int N = 5e3 + 1;

int n, q, a[N];
long long dp[N][N];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("threesum.in", "r", stdin);
    freopen("threesum.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        gp_hash_table<int, int> mp({},{},{},{},{1 << 13});
        for (int j = i + 1; j <= n; j++)  {
            int tmp = -a[i] - a[j];
            auto it = mp.find(tmp);
            if (it != mp.end()) dp[i][j] = it->second;
            mp[a[j]]++;
        }
    }
    for (int i = n; i >= 1; i--)
        for (int j = i + 1; j <= n; j++)
            dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];

    for (int l, r; q; q--) {
        cin >> l >> r;
        cout << dp[l][r] << '\n';
    }
}

