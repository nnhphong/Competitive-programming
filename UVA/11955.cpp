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

const int mxN = 1e5;

int main() {
  fastIO;

  #ifndef ONLINE_JUDGE
  freopen("11955.inp", "r", stdin);
  freopen("11955.out", "w", stdout);
  #endif // ONLINE_JUDGE

  ll f[55][55] = {0};

  forw(i, 1, 52) {
    f[i][0] = 1;
    forw(j, 1, i)
      f[i][j] = f[i-1][j] + f[i-1][j-1];
  }

//  forw(i, 0, 50) cout << f[50][i] << " ";
//  cout << endl;

  int tc;
  cin >> tc;
  forw(i, 1, tc+1) {
    string s;
    cin >> s;

    int pp = s.find('+'), pc = s.find(')'), k = 0;
    int n = s.length();
    string a = s.substr(1, pp-1);
    string b = s.substr(pp+1, pc-pp-1);
    if (isdigit(s[n-2]))
      k += (s[n-2] - '0');
    k = k * 10 + (s[n-1] - '0');

    cout << "Case " << i << ": ";
    if (k == 1) cout << a << "+" << b << endl;
    else {
      cout << a << "^" << k << "+";
      int x = k-1, y = 1;
      forw(j, 1, k) {
        cout << f[k+1][j] << "*";
        if (x == 1) cout << a;
        else cout << a << "^" << x;

        cout << "*";

        if (y == 1) cout << b;
        else cout << b << "^" << y;

        cout << "+";

        x--;
        y++;

      }
      cout << b << "^" << k << endl;
    }
  }
}

