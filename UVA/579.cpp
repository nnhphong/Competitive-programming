#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;

double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
long long MOD = (ll)(1e9 + 7);
double PI = acos(-1);
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

#define fastIO ios::sync_with_stdio(false); cin.tie(0);
#define first fs
#define second sc

int main() {
  fastIO;
  float h, m;
  float m, h;
  while (scanf("%f:%f", &h, &m) && !(m == 0 && h == 0)) {
    float ans = (h * 5 - m + m / 12) * 6;
    printf("%.3f\n", min(abs(ans), 360-abs(ans)));
  }
}

