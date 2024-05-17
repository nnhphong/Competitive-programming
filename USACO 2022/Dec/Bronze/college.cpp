#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;
typedef pair<ll, ll> ii;

const int N = 1e5 + 7, M = 1e6;
int n, a[N], cnt[M + 2];

int main() {
//    freopen("test.inp", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }

    int tot = n; ll mx, pos;
    for (int i = 0; i <= M; i++) {
        if (1ll * tot * i > mx) {
            mx = 1ll * tot * i;
            pos = i;
        }
        tot -= cnt[i];
        if (tot == 0) break;
    }
    printf("%lld %d\n", mx, pos);
}
