#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

template <class T>
bool minimize(T &a, const T &b) {
    if(a > b) {a = b; return 1;}
    return 0;
}
template <class T>
bool maximize(T &a, const T &b) {
    if(a < b) {a = b; return 1;}
    return 0;
}

const int N = 1e5 + 7, MOD = 1e9 + 7, oo = 0x3f3f3f3f;

int n, a[N][2], d[N][2];
vector<int> row[N], col[N], r, c;
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
	freopen("lasers.in", "r", stdin);
	freopen("lasers.out", "w", stdout);
    cin >> n >> a[0][0] >> a[0][1] >> a[n + 1][0] >> a[n + 1][1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
        r.push_back(a[i][0]);
        c.push_back(a[i][1]);
    }
    r.push_back(a[0][0]); r.push_back(a[n + 1][0]);
    c.push_back(a[0][1]); c.push_back(a[n + 1][1]);
    sort(r.begin(), r.end()); sort(c.begin(), c.end());
    for (int i = 0; i <= n + 1; i++) {
        a[i][0] = lower_bound(r.begin(), r.end(), a[i][0]) - r.begin() + 1;
        a[i][1] = lower_bound(c.begin(), c.end(), a[i][1]) - c.begin() + 1;
        row[a[i][0]].push_back(i);
        col[a[i][1]].push_back(i);
    }

    memset(d, 0x3f, sizeof d);
    deque<ar<int, 2>> q; q.push_front({0, 0}); q.push_front({0, 1});
    d[0][0] = d[0][1] = 0;
    while (q.size()) {
        ar<int, 2> u = q.front(); q.pop_front();
        if (u[0] == n + 1) continue;
        int x = a[u[0]][0], y = a[u[0]][1];
        if (u[1]) {
            int pos = lower_bound(row[x].begin(), row[x].end(), u[0]) - row[x].begin();
            for (int i: {-1, 1}) if (pos + i >= 0 && pos + i < row[x].size()) {
                int v = row[x][pos + i];
                if (minimize(d[v][1], d[u[0]][u[1]])) {
                    q.push_front({v, 1});
                }

                if (minimize(d[v][0], d[u[0]][u[1]] + 1)) {
                    q.push_back({v, 0});
                }
            } 
        } else {
            int pos = lower_bound(col[y].begin(), col[y].end(), u[0]) - col[y].begin();
            for (int i: {-1, 1}) if (pos + i >= 0 && pos + i < col[y].size()) {
                int v = col[y][pos + i];
                if (minimize(d[v][0], d[u[0]][u[1]])) {
                    q.push_front({v, 0});
                }

                if (minimize(d[v][1], d[u[0]][u[1]] + 1)) {
                    q.push_back({v, 1});
                }
            }
        }
    }   
    int res = min(d[n + 1][0], d[n + 1][1]);
    cout << (res == oo ? -1 : res);
}
