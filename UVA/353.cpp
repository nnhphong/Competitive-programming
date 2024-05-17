#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool checkPalin(string TEXT) {
	int i, j, Limit;
	int LenTEXT = TEXT.length();

    Limit = LenTEXT / 2;
    for (i = 0, j = LenTEXT - 1; i < Limit; i++, j--) {
        if (TEXT[i] != TEXT[j]) {
            return false;
        }
    }
    return true;
}

bool checkMir(string TEXT)
{
    int i;
    int LenTEXT = TEXT.length();
    for (i = 0; i < LenTEXT; i++) {
        switch (TEXT[i]) {
            case '3':
                TEXT[i] = 'E';
                break;

            case 'J':
                TEXT[i] = 'L';
                break;

            case '2':
                TEXT[i] = 'S';
                break;

            case '5':
                TEXT[i] = 'Z';
                break;

            case 'E':
            case 'L':
            case 'S':
            case 'Z':

            case 'A':
            case 'H':
            case 'I':
            case 'M':
            case 'O':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case '1':
            case '8':
                break;

            default:
                return false;
        }
    }

    return checkPalin(TEXT);
}

bool isMirrorPalindrome(string TEXT)
{
    int i = 0;
    int LenTEXT = TEXT.length();
    for (i = 0; i < LenTEXT; i++) {
        switch (TEXT[i]) {
            case 'A':
            case 'H':
            case 'I':
            case 'M':
            case 'O':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case '1':
            case '8':
                continue;
            default:
                return false;
        }
    }
    return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  #ifndef ONLINE_JUDGE
  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);
  #endif

  string s; 
  while (cin >> s) {
  	if (checkPalin(s)) 
  		if (isMirrorPalindrome(s)) cout << s << " -- is a mirrored palindrome.";
  		else cout << s << " -- is a regular palindrome.";
  	else if (checkMir(s)) cout << s << " -- is a mirrored string.";
  	else cout << s << " -- is not a palindrome.";
  	cout << endl;
  }
}
