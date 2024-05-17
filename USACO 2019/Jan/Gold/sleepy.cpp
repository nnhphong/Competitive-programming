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

const int N = 1e5 + 7;

int n, a[N], T[N];
void upd(int pos, int val) {
    for (; pos < N; pos += pos & -pos) T[pos] += val;
}

int get(int pos) {
    int res = 0;
    for (; pos; pos -= pos & -pos) res += T[pos];
    return res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int j = n - 1;
    for (; j >= 1; j--) {
        upd(a[j + 1], 1); 
        if (a[j] > a[j + 1]) break;    
    }

    cout << j << '\n';
    for (int i = 1; i <= j; i++) {
        cout << j - i + get(a[i] - 1);
        if (i < j) cout << ' ';
        upd(a[i], 1);
    }
}        
