#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using ii = pair<ll, ll>;

#define fastIO ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define numBit(x) (__builtin_popcountll(1ll * (x)))
#define getBit(x, i) ((x) >> (i) & 1)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define MASK(x) (1ll << (x))
#define int long long

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }

const int N = 5e4 + 7, oo = 1e9 + 7;

struct Point {
    int x, y, idx;
    Point() {}
    Point(int x, int y): x(x), y(y) {}
    bool operator<(const Point &other) const {
        return x < other.x;
    }
    bool operator>(const Point &other) const {
        return x > other.x;
    }
} p[N];

int n, k;

int calc(Point p, Point q) {
    Point l1 = Point(p.x - k / 2, p.y - k / 2);
    Point r1 = Point(p.x + k / 2, p.y + k / 2);

    Point l2 = Point(q.x - k / 2, q.y - k / 2);
    Point r2 = Point(q.x + k / 2, q.y + k / 2);
    int x_dist = min(r1.x, r2.x) - max(l1.x, l2.x);
    int y_dist = min(r1.y, r2.y) - max(l1.y, l2.y);
    if (x_dist <= 0 || y_dist <= 0) return -1;
    return x_dist * y_dist;
}

signed main() {
    fastIO;
    freopen("squares.in", "r", stdin);
    freopen("squares.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
    sort(p + 1, p + n + 1);

    set<Point> st; st.insert({p[1].y, p[1].x}); int ans = -1, cnt = 0;
    for (int i = 2; i <= n; i++) {
        while (sz(st) && st.rbegin()->y < p[i].x - k + 1) st.erase(Point(st.rbegin()->x, st.rbegin()->y));
        if (sz(st)) {
            int res = -1;
            for (auto it = st.lower_bound(Point(p[i].y - k + 1, p[i].x)); it != st.end() && p[i].y + k - 1 >= it->x; ++it) {
                maximize(res, calc(p[i], Point(it->y, it->x)));
            }
            if (res != -1) maximize(ans, res), ++cnt;
            if (cnt > 1) { cout << -1; return 0; }
        }
        st.insert({p[i].y, p[i].x});
    }
    cout << (ans != -1 ? ans : 0);
}
