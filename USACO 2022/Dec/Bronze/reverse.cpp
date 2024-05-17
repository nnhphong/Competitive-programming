#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define getBit(x, i) ((x) >> (i) & 1)
#define MASK(x) (1ll << (x))
typedef long long ll;
typedef pair<ll, ll> ii;

const int N = 1e5 + 7, M = 1e6;
int n, m;
int r[N];
string s[N];

int func(int i, int j, int mask, string b) {
    if (b[i] - '0' == getBit(mask, 0)) return getBit(mask, 1);
    else if (b[j] - '0' == getBit(mask, 2)) return getBit(mask, 3);
    return getBit(mask, 4);
}
int func2(int i, int mask, string b) {
    if (b[i] - '0' == getBit(mask, 0)) return getBit(mask, 1);
    else return getBit(mask, 2);
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> s[i] >> r[i];
    }

    bool ans = 0;
    for (int i = 0; i < MASK(5); i++) {
        if (n == 1) break;
        for (int k = 0; k < n; k++) {
            for (int l = k + 1; l < n; l++) {
                bool ok = 1;
                for (int j = 1; j <= m; j++) {
                    if (func(k, l, i, s[j]) != r[j]) ok = 0;
                }
                ans |= ok;
            }
        }
    }
    for (int i = 0; i < MASK(3); i++) {
        for (int k = 0; k < n; k++) {
            bool ok = 1;
            for (int j = 1; j <= m; j++)
                if (func2(k, i, s[j]) != r[j]) ok = 0;
            ans |= ok;
        }
    }
    cout << (ans ? "OK\n" : "LIE\n");
}
int main() {
//    freopen("test.inp", "r", stdin);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}

