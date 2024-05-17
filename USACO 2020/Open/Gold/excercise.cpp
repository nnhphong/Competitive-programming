#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using ii = pair<int, int>;

#define fastIO ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define numBit(x) (__builtin_popcountll(1ll * (x)))
#define getBit(x, i) ((x) >> (i) & 1)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define MASK(x) 1ll << (x)

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

const int N = 1e4 + 7, M = 1e3 + 7, oo = 1e9 + 7;

int n, MOD, a[N], dp[N];
bool isPrime[N];
vector<int> pr;

void sieve() {
    fill(isPrime + 2, isPrime + n + 1, 1);
    for (int i = 2; i <= n; i++) if (isPrime[i]) {
        pr.pb(i);
        if (1ll * i * i > n) continue;
        for (int j = i * i; j <= n; j += i) isPrime[j] = 0;
    }
}

int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return 1ll * x * y % MOD;
}

signed main() {
    fastIO;
    freopen("exercise.in", "r", stdin);
    freopen("exercise.out", "w", stdout);
    cin >> n >> MOD; sieve();

    dp[0] = 1;
    for (int j = 1; j <= sz(pr); j++) {
        for (int i = n; i >= 1; i--) {
            for (int k = pr[j - 1]; k <= i; k *= pr[j - 1]) {
                dp[i] = add(dp[i], mul(k, dp[i - k]));
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) ans = add(ans, dp[i]);
    cout << ans;
}

