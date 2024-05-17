#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pow(ll b, ll p, ll m) {
  ll res = 1;
  while (p > 0) {
    if (p & 1) res = res * b % m;
    b = b * b % m;
    p >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll b, p, m;
  while (cin >> b >> p >> m) cout << pow(b, p, m) << endl;
}
