#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef complex<ld> cp;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<cp> vcp;
typedef vector<ld> vld;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i,l,r) for( ll i = (l) ; i < (r) ; i++ )
#define forb(i,r,l) for( ll i = (r) ; i >= (l) ; i-- )
#define log2i(x) (32 - __builtin_clz((x)) - 1)
#define log2ll(x) (64 - __builtin_clzll((x)) - 1)
#define Pi 3.141592653589793
#define sz(x) (int)x.size()
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int main() {
  fastIO;

  #ifndef ONLINE_JUDGE
//  freopen("test.inp", "r", stdin);
  #endif // ONLINE_JUDGE

  int tc;
  cin >> tc;
  int cnt = 0;
  while (tc--) {
    int x, y, z;
    cin >> x >> y >> z;

    int d = round((float)((x + y + z) - 100) / 2);

    int mx = min(x, min(y, z));
    int mn = max(0, d);

    cout << "Case #" << ++cnt << ": ";
    if (mn > mx) cout << "The records are faulty." << endl;
    else cout << "Between " << mn << " and " << mx << " times." << endl;
  }
}
