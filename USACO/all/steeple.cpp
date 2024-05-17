#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;

#define task "steeple"
#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i, l, r) for( ll i = (l) ; i < (r) ; i++ )
#define forb(i, r, l) for( ll i = (r) ; i >= (l) ; i-- )
#define numBit(x) (__builtin_popcountll(1ll * (x)))
#define getBit(x, i) ((x) >> (i) & 1)
#define sz(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second
#define ar array
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(x) cerr << #x << " = " << x << '\n';

const int N = 1e5 + 7;
const ll inf = 0x3f3f3f3f;

struct Point {
    int x, y;
} p1[N], p2[N];

int n;

bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return 1;
    return 0;
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // collinear
    return (val > 0) ? 1: 2; // clock or counterclock wise
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4) return 1;
    if (o1 == 0 && onSegment(p1, p2, q1)) return 1;
    if (o2 == 0 && onSegment(p1, q2, q1)) return 1;
    if (o3 == 0 && onSegment(p2, p1, q2)) return 1;
    if (o4 == 0 && onSegment(p2, q1, q2)) return 1;
    return 0;
}

vi adj[N];
int match[N];
bool vis[N];
bool aug(int u) {
    if (vis[u]) return 0;
    vis[u] = 1;
    for (int v: adj[u]) if (match[v] == -1 || aug(match[v])) {
        match[v] = u; return 1;
    }
    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen(task".in", "r", stdin);
    freopen(task".out", "w", stdout);
#endif
    fastIO;
    cin >> n;
    forw(i, 0, n) cin >> p1[i].x >> p1[i].y >> p2[i].x >> p2[i].y;
    forw(i, 0, n) forw(j, 0, n) if (doIntersect(p1[i], p2[i], p1[j], p2[j]))
        adj[i].pb(j);

    int res = 0;
    memset(match, -1, sizeof match);
    forw(i, 0, n) {
        memset(vis, 0, sizeof vis);
        res += aug(i);
    }
    cout << n - res / 2;
}


