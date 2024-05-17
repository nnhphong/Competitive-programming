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

int seg[4*mxN+1], a[mxN+1];
unordered_map<int, int> fid, lid;
unordered_map<int, int> hashing;

int RMQ(int id, int l, int r, int u, int v) {
  if (u <= l && r <= v) {
    return seg[id];
  }
  if (r < u || l> v) return 0;

  int mid = (l+r)/2;
  return max(RMQ(id*2+1, l, mid, u, v), RMQ(id*2+2, mid+1, r, u, v));
}

int build(int arr[], int id, int l, int r) {
  if (l == r) {
    seg[id] = arr[r];
    return arr[r];
  }

  int mid = (l+r)/2;
  seg[id] = max(build(arr, id*2+1, l, mid), build(arr, id*2+2, mid+1, r));
  return seg[id];
}

int maxOcc(int n, int l, int r) {
  int mxOc = 0;

  if (a[l] == a[r]) mxOc = max(mxOc, (r-l+1));
  else {
    int lo = hashing[a[l]] - l + fid[a[l]], hi = hashing[a[r]] - lid[a[r]] + r;
    l += lo;
    r -= hi;
    mxOc = max({lo, hi, RMQ(0, 0, n-1, l, r)});
  }
  return mxOc;
}

int main() {
  fastIO;

  #ifndef ONLINE_JUDGE
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  #endif // ONLINE_JUDGE

  int n, q;
  while (cin >> n && n != 0) {
    cin >> q;
    forw(i, 0, n) {
      cin >> a[i];
      hashing[a[i]] = 0;
    }

    fid[a[0]] = 0;
    forw(i, 0, n)
      if (i > 0 && a[i] != a[i-1]) fid[a[i]] = i;
      else fid[a[i]] = fid[a[i-1]];

    lid[a[n-1]] = n-1;
    forb(i, n-2, 0)
      if (a[i] != a[i+1]) lid[a[i]] = i;
      else lid[a[i]] = lid[a[i+1]];

    int freq[n+1];
    memset(freq, 0, sizeof freq);
    forw(i, 0, n)
      hashing[a[i]]++;

    forw(i, 0, n)
      freq[i] = hashing[a[i]];

    build(freq, 0, 0, n-1);

    while (q--) {
      int l, r;
      cin >> l >> r;
      cout << maxOcc(n, --l, --r) << endl;
    }
  }
}
