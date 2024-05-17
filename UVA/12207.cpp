#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;

double eps = 1e-9;
int inf = 1000000005;
long long inff = 1000000000000000005LL;
double pi = acos(-1);
int dx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int dy[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

#define fastIO ios::sync_with_stdio(false); cin.tie(0);

int main() {
  fastIO;
  int p, c, id = 1;
  while (cin >> p >> c && p != 0 && c != 0) {
    cout << "Case " << id++ << ":" << endl;
    deque<int> q1;
    for (int i = 1; i <= p && i <= 1000; i++) q1.push_back(i);
    for (int i = 0; i < c; i++) {
      char d; cin >> d;
      if (d == 'N') {
        int x = q1.front();
        cout << x << endl;
        q1.push_back(x);
        q1.pop_front();
      } else if (d == 'E') {
        int x; cin >> x;
        int index = 0;
        for (auto it: q1) {
          if (it == x) {
            q1.erase(q1.begin() + index, q1.begin() + index + 1);
            break;
          }
          ++index;
        }
        q1.push_front(x);
      }
    }
  }
}

