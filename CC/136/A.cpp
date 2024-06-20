#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using u64 = unsigned long long;
using ll = long long;
using ld = long double;

static u32 TC, hor, ver, ans;
static char c;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;

  while (TC--) {
    for (u32 i = 0; i < 2; ++i) {
      cin >> c;
      hor += c == '1';
    }
    for (u32 i = 0; i < 2; ++i) {
      cin >> c;
      ver += c == '1';
    }
    if (hor == 2) {
      if (ver == 2) ans = 441;
      else if (ver == 1) ans = 231;
      else ans = 21;
    } else if (hor == 1) {
      if (ver == 2) ans = 231;
      else if (ver == 1) ans = 121;
      else ans = 11;
    } else {
      if (ver == 2) ans = 21;
      else if (ver == 1) ans = 11;
      else ans = 1;
    }
    cout << ans << '\n';
    hor = ver = 0;
  }
}
