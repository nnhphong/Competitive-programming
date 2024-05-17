#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pow(ll x, ll y, ll n) {
  ll res = 1;
  while (y > 0) {
    if (y & 1) res = res * x % n;
    x = x * x % n;
    y >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;

  while (tc--) {
    ll x, y, n;
    cin >> x >> y >> n;
    cout << pow(x, y, n) << '\n';
  }
}
