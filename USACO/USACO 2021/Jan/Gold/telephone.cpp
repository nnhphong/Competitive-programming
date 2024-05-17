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

const int N = 5e4 + 7, M = 50 + 7;
const ll oo = 1e18;

int n, k, b[N];
ll d[N];
char s[M];
vector<int> adj[N];
set<int> st[M];
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> b[i]; d[i] = oo;
        st[b[i]].insert(i);
    }
    for (int i = 1; i <= k; i++){
        cin >> s + 1; 
        for (int j = 1; j <= k; j++)
            if (s[j] == '1') adj[i].push_back(j);  
    }

    queue<int> q; q.push(1); d[1] = 0;
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int v: adj[b[u]]) {
            auto it = st[v].upper_bound(u);
            if (it != st[v].end() && minimize(d[*it], d[u] + 1ll * abs(*it - u))) q.push(*it);

            it = st[v].lower_bound(u);
            if (it != st[v].begin()) {
                --it; 
                if (minimize(d[*it], d[u] + 1ll * abs(u - *it))) q.push(*it);
            }
        }
    }
    
    ll ans = d[n]; 
    for (int i = 1; i <= n; i++)
        if (binary_search(adj[b[i]].begin(), adj[b[i]].end(), b[n]) && d[i] != oo) 
            minimize(ans, d[i] + abs(n - i));
    cout << (ans >= oo ? -1 : ans);
}

