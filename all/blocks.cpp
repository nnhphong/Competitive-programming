#include <bits/stdc++.h>
using namespace std;

const int N = 17;

#define sz(x) (int)(x.size())
#define pb push_back

int n;
string s, block[4];

void solve() {
    if (sz(s) == 1) {
        for (int i = 0; i < 4; i++)
            for (char x: block[i]) if (x == s[0]) {
                cout << "YES\n"; return;
            }
        cout << "NO\n";
    } else if (sz(s) == 2) {
        for (int i = 0; i < 4; i++)
            for (int j = i + 1; j < 4; j++) {
                for (char x: block[i])
                    for (char y: block[j]) {
                        string tmp; tmp.pb(x); tmp.pb(y);
                        if (is_permutation(tmp.begin(), tmp.end(), s.begin())) {
                            cout << "YES\n"; return;
                        }
                    }
            }
        cout << "NO\n";
    } else if (sz(s) == 3) {
        for (int i = 0; i < 4; i++)
            for (int j = i + 1; j < 4; j++)
                for (int k = j + 1; k < 4; k++)
                    for (char x: block[i])
                        for (char y: block[j])
                            for (char z: block[k]) {
                                string tmp; tmp.pb(x); tmp.pb(y); tmp.pb(z);
                                if (is_permutation(tmp.begin(), tmp.end(), s.begin())) {
                                    cout << "YES\n"; return;
                                }
                            }
        cout << "NO\n";
    } else if (sz(s) == 4) {
        for (char t: block[0])
            for (char x: block[1])
                for (char y: block[2])
                    for (char z: block[3]) {
                        string tmp; tmp.pb(t); tmp.pb(x); tmp.pb(y); tmp.pb(z);
                        if (is_permutation(tmp.begin(), tmp.end(), s.begin())) {
                            cout << "YES\n"; return;
                        }
                    }
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < 4; i++) cin >> block[i];
    while (n--) {
        cin >> s;
        solve();
    }
}
