#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 2000;
static i32 TC, n, x, a[N];
static bool yes;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    yes = false;
    cin >> n;
    x = 0;
    for (i32 i = 0; i < n; ++i) cin >> a[i], x ^= a[i];
    for (i32 i = 0, t = 0; i < n - 1; ++i) {
      t ^= a[i];
      if ((x ^ t) == t) {
        yes = true;
        break;
      }
    }
    for (i32 i = 0, t = 0; i < n - 2; ++i) {
      t ^= a[i];
      for (i32 j = i + 1, u = 0; j < n - 1; ++j) {
        u ^= a[j];
        if (t == u && u == (x ^ u ^ t)) {
          yes = true;
          break;
        }
      }
    }
    cout << (yes ? "YES" : "NO") << '\n';
  }
}

