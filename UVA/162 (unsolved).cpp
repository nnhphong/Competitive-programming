#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  char ter = '';
  while (1) {
    vector<string> a, b(1);
    cin >> b[0];
    if (b[0] == '#') break;

    for (int i = 1; i < 52; i++) {
      string s; cin >> s;
      if (i & 1) a.push_back(s);
      else b.push_back(s);
    }


  }
}
