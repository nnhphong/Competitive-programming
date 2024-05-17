#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define getBit(x, i) ((x) >> (i) & 1)
#define MASK(x) (1ll << (x))
typedef long long ll;
typedef pair<ll, ll> ii;

const int N = 1e5 + 7;
int n, k;
string s, res;
set<int> st;

void solve() {
    cin >> n >> k >> s; int cnt = 0;
    st.clear(); res.clear();
    for (int i = 0; i < n; i++) {
        res += '.';
        st.insert(i);
    }
    for (int i = 0; i < n;) {
        if (s[i] == 'G') {
            int j = min(i + k, n - 1);
            res[j] = 'G'; st.erase(j);
            ++cnt; i = j + k + 1;
        }
        else i++;
    }
    for (int i = 0; i < n;) {
        if (s[i] == 'H') {
            int j = min(i + k, n - 1);
            auto it = st.upper_bound(j);
            --it;
            res[*it] = 'H';
            ++cnt; i = *it + k + 1;
            st.erase(it);
        } else i++;
    }
    cout << cnt << '\n' << res << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
//    freopen("test.inp", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
}
