#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;
 
#define task "ride"
#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i, l, r) for( ll i = (l) ; i < (r) ; i++ )
#define forb(i, r, l) for( ll i = (r) ; i >= (l) ; i-- )
#define sz(x) (int)x.size()
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define numBit(x) __builtin_popcount(x)
#define lb lower_bound
#define ub upper_bound
#define ar array
#define endl '\n'
 
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
 
const int N = 1e5 + 7;
const ll inf = 1e9;

string s1, s2;

int mul(int a, int b) {
  return 1LL * a * b % 47;
}

int main() {
// #ifndef ONLINE_JUDGE
  freopen(task".in", "r", stdin);
  freopen(task".out", "w", stdout);
// #endif
  fastIO;

  cin >> s1 >> s2;

  ll ttl1 = 1, ttl2 = 1;
  forw(i, 0, sz(s1))
    ttl1 = mul(ttl1, s1[i] - 'A' + 1);
  forw(i, 0, sz(s2))
    ttl2 = mul(ttl2, s2[i] - 'A' + 1);

  cout << (ttl1 == ttl2 ? "GO" : "STAY") << endl;
}