#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static i32 T, i, j, n, m, k, t;
static const char c[] = "BR";
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    if (k < n + m - 2 || (k -= n + m) % 2) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    t = !(m & 1);
    if (k % 4 != 0) {
      for (j = 0; j < n; ++j) {
        for (i = 0; i < m - 1; ++i)
          cout << c[i & 1] << ' ';
        cout << '\n';
      }
      for (j = 0; j < n - 1; ++j) {
        for (i = 0; i < m; ++i)
          cout << c[t] << ' ';
        t = !t;
        cout << '\n';
      }
    } else {
    }
  }
}
