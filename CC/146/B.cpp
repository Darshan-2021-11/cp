#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i32 N = 16;
static i32 TC, res[N];
static array<i32, 2> a[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> TC;
  while (TC--) {
    for (i32 i = 0; i < N; ++i) cin >> a[i][0], a[i][1] = i;
    sort(a, a + N);
    res[a[0][1]] = 0;
    for (i32 i = 1, t; i < N; ++i) {
      t = (i + 1) >> 1;
      res[a[i][1]] = 0;
      while (t) ++res[a[i][1]], t >>= 1;
    }
    for (i32 i = 0; i < N; ++i) {
      cout << res[i] << ' ';
    }
    cout << '\n';
  }
}

