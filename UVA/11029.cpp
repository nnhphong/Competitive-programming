#include <bits/stdc++.h>
#define MOD 1000
using namespace std;

typedef long long ll;

ll binpow1(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;

    b >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
//  freopen("11029.out", "w", stdout);
  ll tc;
  cin >> tc;
  while (tc--) {
    ll n, k; cin >> n >> k;
    ll res1 = binpow1(n, k);
    ll res2 = pow(10, fmod(k * log10(n), 1) + 2);

    printf("%d...%0.3d\n", res2, res1);
  }
}
