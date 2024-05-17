#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

map<char, char> mirror;

bool isPalin(string s) {
  string rs(s);
  reverse(rs.begin(), rs.end());
  return rs == s;
}

bool isMirror(string s)
{
  int n = s.length();
  for (int i = 0, j = n-1; i < (n+1)/2; i++, j--) {
    if (mirror.count(s[i]) == 0 || s[i] != mirror[s[j]]) return false;
  }
  return true;
}

int main() {
  fastIO;

  #ifndef ONLINE_JUDGE
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  #endif // ONLINE_JUDGE

  char from[] = {'A', 'E', 'H', 'I', 'J', 'L',
                 'M', 'O', 'S', 'T', 'U', 'V',
                 'W', 'X', 'Y', 'Z', '1', '2',
                 '3', '5', '8'};
  char to[]   = {'A', '3', 'H', 'I', 'L', 'J',
                 'M', 'O', '2', 'T', 'U', 'V',
                 'W', 'X', 'Y', '5', '1', 'S',
                 'E', 'Z', '8'};
  for (int i = 0; i < sizeof(from)/sizeof(char); i++)
    mirror[from[i]] = to[i];

  string s;
  while (cin >> s) {
    bool isPal = isPalin(s);
    bool isMir = isMirror(s);

    cout << s << " -- "; 
    if (!isPal && !isMir)
        cout << "is not a palindrome." << endl;
    else if (isPal && !isMir)
        cout << "is a regular palindrome." << endl;
    else if (!isPal && isMir)
        cout << "is a mirrored string." << endl;
    else 
        cout << "is a mirrored palindrome." << endl;

    cout << endl;
  }
}
