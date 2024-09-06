#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 200'001;
static i32 TC, n, ans;
static char a[2][N];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    ans = 0;
    cin >> n;
    for (i32 j = 0; j < 2; ++j) for (i32 i = 0; i < n; ++i) cin >> a[j][i];
    if (n < 3) {
      cout << 0 << '\n';
      continue;
    }
    for (i32 i = 2; i < n; ++i) {
      if (a[0][i - 2] == a[0][i] &&
          a[0][i] == 'x' &&
          a[1][i - 2] == a[1][i - 1] &&
          a[1][i - 1] == a[1][i] &&
          a[0][i - 1] == a[1][i - 1] &&
          a[1][i] == '.') ++ans;
      else
      if (a[1][i - 2] == a[1][i] &&
          a[1][i] == 'x' &&
          a[0][i - 2] == a[0][i - 1] &&
          a[0][i - 1] == a[0][i] &&
          a[1][i - 1] == a[0][i - 1] &&
          a[0][i] == '.') ++ans;
    }
    cout << ans << '\n';
  }
}

