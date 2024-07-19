#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using i32 = int;       using u32 = unsigned int;       using f32 = float;
using i64 = long long; using u64 = unsigned long long; using f64 = double;
using i128 = __int128; using u128 = unsigned __int128; using f128 = long double;

static const i64 N = 100'000;
static i64 T, n, a[N], ora, ans;
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.precision(15), cout.setf(ios::fixed);
  cin >> T;
  for (int x = 0; x < T; ++x) {
    ora = 0, ans = 0;
    cin >> n;
    int i;
    for (i = 0; i < n; ++i) {
      cin >> a[i];
      ora |= a[i];
    }
    for (i = 0; i <= 29; ++i) {
      if (ora >> i & 1) continue;
      break;
    }
    int mask = ~((1 << i) - 1);
    for (i = 0; i < n; ++i) {
      if (a[i] & mask) ++ans;
    }
    cout << ans << '\n';
  }
}

