#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 T = 1, n, an;
static char s[(u32)2e5], m['a' + 26];
static bool p['a' + 26];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;

  while (T--) {
    an = 0;
    cin >> n;
    for (u32 i = 0; i < n; ++i) { cin >> s[i]; p[s[i]] = true; }
    for (u32 l = 'a', r = 'z'; l <= r; ++l, --r) {
      while (l <= 'z' && !p[l]) ++l;
      while (r >= 'a' && !p[r]) --r;
      m[l] = r, m[r] = l;
    }
    for (u32 i = 0; i < n; ++i) { cout << m[s[i]]; }
    cout << '\n';
    memset(p + 'a', 0, 26);
  }
}

