#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using f32 = float;
using f64 = long double;

static i32 n, m, t, ans, a[10];
static char c;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> n >> m;
  for (i32 i = 0; i < n; ++i) {
    for (i32 j = 0; j < m; ++j) {
      cin >> c;
      a[i] |= (1 & (c == 'o')) << j;
    }
  }
  ans = INT_MAX;
  for (i32 i = 1; i <= (1 << n); ++i) {
    t = 0;
    for (i32 j = 0; j < n; ++j) {
      if (i & (1 << j)) t |= a[j];
    }
    if (t == (1 << m) - 1) {
      ans = min(ans, __builtin_popcount(i));
    }
  }
  cout << ans;
}

