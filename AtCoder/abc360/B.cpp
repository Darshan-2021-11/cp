#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;        using u32 = unsigned int;       using f32 = float;
using i64 = long long;  using u64 = unsigned long long; using f64 = double;
using i128 = __int128;  using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 101;
static i32 sn, tn, un;
static char s[N], t[N], u[N];
static bool yes;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  while ((s[sn] = getchar()) != ' ') ++sn;
  while ((t[tn] = getchar()) != '\n') ++tn;
  for (i32 i = 1; i < sn; ++i) {
    for (i32 j = 0; j < i; ++j) {
      un = 0, yes = 1;
      for (i32 k = j; k < sn; k += i) {
        if (un == tn) yes = 0;
        if (t[un] == s[k]) ++un;
        else {
          yes = 0;
          break;
        }
      }
      if (!yes || un < tn) continue;
      puts("Yes");
      return 0;
    }
  }
  puts("No");
}
