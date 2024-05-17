#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e7;

typedef long long ll;

ll numDiv(ll x) {
  ll cnt = 0;
  for (ll i = 1; i*i <= x; i++) {
    if (x % i == 0) ++cnt;
    if (x % i == 0 && x/i != i) ++cnt;
  }
  return cnt;
}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  #endif

  int tc;
  scanf("%d", &tc);

  while (tc--) {
    ll l, r, pos, mx = 0;
    scanf("%lld %lld", &l, &r);

    for (ll i = l; i <= r; i++) {
      ll tmp = numDiv(i);
      if (tmp > mx) {
        mx = tmp;
        pos = i;
      }
    }
    printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", l, r, pos, mx);
  }
}
